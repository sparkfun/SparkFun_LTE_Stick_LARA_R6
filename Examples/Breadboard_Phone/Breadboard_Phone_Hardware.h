#pragma once

#include "Breadboard_Phone_Definitions.h"

////////////////////////////////////////////////////////////////////////////////
// Hardware helper functions
////////////////////////////////////////////////////////////////////////////////

void printDisplay(String text)
{
    // Take input string and print it to the display
    display.erase();
    display.setCursor(0, 0);
    display.print(text);
    display.display();
}

void waitForOperator()
{
    UBX_CELL_error_t result = UBX_CELL_SUCCESS;
    String currentOperator = "";

    // Loop until we're connected to an operator
    do
    {
        result = lteStick.getOperator(&currentOperator);

        if (result != UBX_CELL_SUCCESS)
        {
            // Not connected, wait a second and try again
            Serial.println("Not connected, ensure SIM card is inserted");
            printDisplay("Check SIM!");
            delay(1000);
        }
    } while (result != UBX_CELL_SUCCESS);

    // We're connected!
    Serial.print("Connected to: ");
    Serial.println(currentOperator);
}

void ringCallback()
{
    // Change manu index to ring menu to indicate incoming call
    menuIndex = MENU_RING;
}

void startAudioLoopBack()
{
    // Play audio loopback resource
    UBX_CELL_error_t result = lteStick.playAudioResource(2, 0, 0);
    if (result != UBX_CELL_SUCCESS)
    {
        Serial.println("Failed to start audio loopback!");
        Serial.println(result);
    }
}

void stopAudioLoopBack()
{
    // Stop audio loopback resource
    UBX_CELL_error_t result = lteStick.stopAudioResource(2);
    if (result != UBX_CELL_SUCCESS)
    {
        Serial.println("Failed to stop audio loopback!");
        Serial.println(result);
    }
}

void playFreq(uint16_t freq, uint16_t duration, uint8_t volume)
{
    // Play requested tone
    UBX_CELL_error_t result = lteStick.generateToneFreq(freq, duration, volume);
    if (result != UBX_CELL_SUCCESS)
    {
        Serial.println("Failed to play frequency!");
        Serial.println(result);
    }
}

void playTone(char tone, uint16_t duration, uint8_t volume)
{
    // Play requested tone
    UBX_CELL_error_t result = lteStick.generateToneDTMF(tone, duration, volume);
    if (result != UBX_CELL_SUCCESS)
    {
        Serial.println("Failed to play tone!");
        Serial.println(result);
    }
}

void dialNumber()
{
    // Dial provided number
    UBX_CELL_error_t result = lteStick.dial(destinationNumber);
    if (result != UBX_CELL_SUCCESS)
    {
        Serial.println("Failed to dial number!");
        Serial.println(result);

        callActive = false;
        printDisplay("Call fail!");
        neopixelWrite(RGB_BUILTIN, ledBrightness, 0, 0);
        delay(1000);
        neopixelWrite(RGB_BUILTIN, 0, ledBrightness, 0);
        menuIndex = MENU_HOME;
    }
}

void answerCall()
{
    // Answer call
    UBX_CELL_error_t result = lteStick.answer();
    if (result != UBX_CELL_SUCCESS)
    {
        Serial.println("Failed to answer call!");
        Serial.println(result);

        callActive = false;
    }
}

void hangUp()
{
    // Hang up call
    UBX_CELL_error_t result = lteStick.hangUp();
    if (result != UBX_CELL_SUCCESS)
    {
        Serial.println("Failed to hang up!");
        Serial.println(result);
    }
}

void sendText()
{
    Serial.print("Sending text to ");
    Serial.print(destinationNumber);
    Serial.println(":");
    Serial.println(textMessage);
    
    // Send provided text message to provided number
    UBX_CELL_error_t result = lteStick.sendSMS(destinationNumber, textMessage);
    if (result != UBX_CELL_SUCCESS)
    {
        Serial.println("Failed to send text!");

        printDisplay("Text fail!");
        neopixelWrite(RGB_BUILTIN, ledBrightness, 0, 0);
        delay(1000);
        neopixelWrite(RGB_BUILTIN, 0, ledBrightness, 0);
        menuIndex = MENU_HOME;
    }
}

void updateKeypad()
{
    // Get latest button press from keypad
    keypad.updateFIFO();
    char button = keypad.getButton();
    
    // Zero indicates no button press
    if (button > 0)
    {
        Serial.println(button);
        playTone(button, 100, 20);
    }
}

////////////////////////////////////////////////////////////////////////////////
// Hardware begin functions
////////////////////////////////////////////////////////////////////////////////

void beginDisplay()
{
    Serial.println("Connecting to display...");

    // Loop until we're connected to the display
    bool success = false;
    do
    {
        // Attempt to connect to display
        success = display.begin();

        if (success == false)
        {
            Serial.println("Unable to communicate with display, double check wiring");

            neopixelWrite(RGB_BUILTIN, ledBrightness, 0, 0);
            delay(1000);
        }
    } while (success == false);

    Serial.println("Display connected!");
    neopixelWrite(RGB_BUILTIN, 0, 0, ledBrightness);

    // Display message to indicate we're starting up
    printDisplay("Starting\nhardware\n...");
}

void beginKeypad()
{
    Serial.println("Connecting to keypad...");

    // Loop until we're connected to the keypad
    bool success = false;
    do
    {
        // Attempt to connect to keypad
        success = keypad.begin();

        if (success == false)
        {
            Serial.println("Unable to communicate with keypad, double check wiring");
            printDisplay("Keypad\nmissing!");

            neopixelWrite(RGB_BUILTIN, ledBrightness, 0, 0);
            delay(1000);
        }
    } while (success == false);

    Serial.println("Keypad connected!");
    neopixelWrite(RGB_BUILTIN, 0, 0, ledBrightness);

    // Nothing else needed for now
}

void beginCodec()
{
    Serial.println("Connecting to audio codec...");

    // Loop until we're connected to the audio codec
    bool success = false;
    do
    {
        // Attempt to connect to audio codec
        success = codec.begin();

        if (success == false)
        {
            Serial.println("Unable to communicate with audio codec, double check wiring");
            printDisplay("Codec\nmissing!");

            neopixelWrite(RGB_BUILTIN, ledBrightness, 0, 0);
            delay(1000);
        }
    } while (success == false);

    Serial.println("Audio codec connected!");
    neopixelWrite(RGB_BUILTIN, 0, 0, ledBrightness);

    // Need to enable VREF and VMID for codec to work
    codec.enableVREF();
    codec.enableVMID();

    // Connect LIN1 (microphone input) to ADC
    codec.enableLMIC();
    codec.connectLMN1();
    codec.disableLINMUTE();
    codec.setLINVOLDB(0.00);
    codec.setLMICBOOST(WM8960_MIC_BOOST_GAIN_0DB);
    codec.connectLMIC2B();
    codec.enableAINL();
    codec.enableAdcLeft();

    // Enable left output mixer
    codec.enableLOMIX();
    codec.disableLB2LO();
    codec.disableLoopBack();
    codec.enableLD2LO();

    // Create SYSCLK (12.288MHz) from MCLK (24.000MHz)
    // See pages 56-62 of datasheet
    codec.setSMD(WM8960_PLL_MODE_FRACTIONAL);
    codec.setPLLPRESCALE(WM8960_PLLPRESCALE_DIV_2);
    codec.setSYSCLKDIV(WM8960_SYSCLK_DIV_BY_2);
    codec.setPLLN(8);
    codec.setPLLK(0x31, 0x26, 0xE8);
    codec.setCLKSEL(WM8960_CLKSEL_PLL);
    codec.enablePLL();

    // Set ADC/DAC sampling rate (12.288MHz / (256 * 3) = 16kHz)
    // LARA-R6 has fixed sampling rate of 16kHz
    codec.setADCDIV(3);
    codec.setDACDIV(3);

    // Create amplifier clock (12.288MHz / 16 = 768kHz)
    codec.setDCLKDIV(WM8960_DCLKDIV_16);

    // Enable I2S interface
    codec.setWL(WM8960_WL_16BIT);
    codec.enablePeripheralMode();

    // Connect DAC to speaker
    codec.enableDacLeft();
    codec.disableDacMute();
    codec.enableSpeakers();
    codec.setSpeakerVolumeDB(0);
}

void beginLTEStick()
{
    Serial.println("Connecting to LTE Stick...");

    // Loop until we're connected to the LTE Stick
    bool success = false;
    do
    {
        // Attempt to connect to LTE Stick
        success = lteStick.begin(Serial2, 115200);

        if (success == false)
        {
            Serial.println("Unable to communicate with LTE Stick, press ON button and check wiring");
            printDisplay("LTE Stick\nmissing!");

            neopixelWrite(RGB_BUILTIN, ledBrightness, 0, 0);
        }
    } while (success == false);

    Serial.println("LTE Stick connected!");

    // Set callback for ring events
    lteStick.setRingCallback(ringCallback);
}

void beginHardware()
{
    // Set RGB LED pin to output
    pinMode(RGB_BUILTIN, OUTPUT);

    // Initialize I2C bus
    Wire.begin();

    // Initialize all hardware. Display should be first for debug info
    beginDisplay();
    beginKeypad();
    beginCodec();
    beginLTEStick();

    // All hardware initilized, wait until we're connected to an operator
    waitForOperator();

    // Success!
    Serial.println("Hardware initialized!");
    neopixelWrite(RGB_BUILTIN, 0, ledBrightness, 0);
    printDisplay("Ready!");
}
