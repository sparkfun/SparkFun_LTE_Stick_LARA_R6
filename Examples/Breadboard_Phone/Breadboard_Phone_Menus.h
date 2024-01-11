#pragma once

#include "Breadboard_Phone_Definitions.h"
#include "Breadboard_Phone_Hardware.h"

////////////////////////////////////////////////////////////////////////////////
// Menu helper functions
////////////////////////////////////////////////////////////////////////////////

void menuHome()
{
    // Display main menu
    String text = "";
    text += "Home\n";
    text += "1-Dial\n";
    text += "2-Text\n";
    text += "3-Audio\n";
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if ((button >= '0') && (button <= '9'))
    {
        menuIndex = (uint8_t)(button - '0');
    }
}

void menuDial()
{
    // Display dial menu with currently entered number (if any)
    String text = "";
    text += "Number?\n";
    if (destinationNumber.length() == 0)
    {
        text += "*-Back\n";
        text += "#-Speed\n";
    }
    else
    {
        text += "*-Delete\n";
        text += "#-Dial\n";
    }
    text += destinationNumber;
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if (button == '*')
    {
        // Return or delete pressed
        if (destinationNumber.length() == 0)
        {
            // Return
            if (textMessage.length() == 0)
            {
                menuIndex = MENU_HOME;
            }
            else
            {
                menuIndex = MENU_TEXT;
            }
        }
        else
        {
            // Delete
            destinationNumber.remove(destinationNumber.length() - 1, 1);
        }
    }
    else if (button == '#')
    {
        // Enter pressed
        if (destinationNumber.length() == 0)
        {
            // No number entered, go to speed dial menu
            menuIndex = MENU_SPEED_DIAL;
        }
        else
        {
            // Number entered
            if (textMessage.length() == 0)
            {
                // No text message, dial number
                printDisplay("Calling...");
                callActive = true;
                dialNumber();
                menuIndex = MENU_CALL;
            }
            else
            {
                // Text message, send text
                printDisplay("Sending...");
                sendText();
                menuIndex = MENU_HOME;
            }
        }
    }
    else if (button > 0)
    {
        // Number pressed, add to number
        destinationNumber += button;
    }
}

void menuSpeedDial()
{
    // Display speed dial menu
    String text = "";
    text += "Contact?\n";
    text += "*-Back\n";
    text += "#-Dial\n";
    text += speedDialNames[speedDialIndex];
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if (button == '*')
    {
        // Return pressed
        menuIndex = MENU_DIAL;
        speedDialIndex = 0;
    }
    else if (button == '#')
    {
        // Enter pressed, set destination number from speed dial contact list
        destinationNumber = speedDialNumbers[speedDialIndex];
        if (textMessage.length() == 0)
        {
            // No text message, dial number
            printDisplay("Calling...");
            callActive = true;
            dialNumber();
            menuIndex = MENU_CALL;
        }
        else
        {
            // Text message, send text
            printDisplay("Sending...");
            sendText();
            menuIndex = MENU_HOME;
        }
    }
    else if (button > 0)
    {
        // Number pressed, set speed dial index
        speedDialIndex = button - '0';
    }
}

void menuCall()
{
    // Display call menu with currently dialed number or speed dial contact name
    String text = "";
    text += "Call\n";
    text += "*-Hang up\n";
    if (speedDialIndex > 0)
    {
        text += speedDialNames[speedDialIndex];
    }
    else
    {
        text += destinationNumber;
    }
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if ((button == '*') || (callActive == false))
    {
        // Hang up pressed or call ended
        hangUp();
        menuIndex = MENU_HOME;
        destinationNumber = "";
        speedDialIndex = 0;
    }
}

void menuRing()
{
    // Display ring alert message
    String text = "";
    text += "RING RING\n";
    text += "*-Hang up\n";
    text += "#-Answer\n";
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if (button == '*')
    {
        // Hang up pressed
        neopixelWrite(RGB_BUILTIN, 0, ledBrightness, 0);
        hangUp();
        menuIndex = MENU_HOME;
    }
    else if (button == '#')
    {
        // Answer pressed
        neopixelWrite(RGB_BUILTIN, 0, ledBrightness, 0);
        callActive = true;
        answerCall();
        menuIndex = MENU_CALL;
    }

    // Create pulsing effect with RGB LED
    neopixelWrite(RGB_BUILTIN, 0, 0, (millis() / 4) & 0xFF);
}

void menuText()
{
    // Display text menu with currently entered text (if any)
    String text = "";
    text += "Text\n";
    if (textMessage.length() > 0)
    {
        text += "*-Delete\n";
    }
    else
    {
        text += "*-Back\n";
    }
    text += "#-Send\n";
    text += textMessage;
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if (button == '*')
    {
        // Return or delete pressed
        if (textMessage.length() > 0)
        {
            // Delete
            textMessage.remove(textMessage.length() - 1, 1);
        }
        else
        {
            // Return
            menuIndex = MENU_HOME;
        }
    }
    else if (button == '#')
    {
        // Enter pressed
        menuIndex = MENU_DIAL;
    }
    else if (button > 0)
    {
        // Check if this should be a new character, either from a timeout or a
        // new button got pressed
        if ((millis() > (lastPressTime + pressTimeMax)) || (button != lastButtonPressed))
        {
            // Reset counter
            numPresses = -1;
            lastButtonPressed = 0;
        }
        else
        {
            // Still selecting this character, remove last character from text.
            // It will be replaced below
            textMessage.remove(textMessage.length() - 1, 1);
        }

        // Reset timer
        lastPressTime = millis();

        // Remember this button was pressed last
        lastButtonPressed = button;

        // Increment counter and wrap to 4 presses
        numPresses++;
        numPresses %= 4;

        // Get number pressed
        uint8_t number = button - '0';
        if (keypadLetters[number][numPresses] == 0)
        {
            // End of letters for this number, reset counter
            numPresses = 0;
        }

        // Add this letter to end of text message
        char letter = keypadLetters[number][numPresses];
        textMessage += letter;
    }
}

void menuAudio()
{
    // Display audio menu
    String text = "";
    text += "Audio\n";
    text += "*-Back\n";
    text += "1-Loopback";
    text += "2-Tone\n";
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if (button == '*')
    {
        // Return pressed
        menuIndex = MENU_HOME;
    }
    else if (button == '1')
    {
        // Loopback pressed
        menuIndex = MENU_LOOPBACK;
        startAudioLoopBack();
    }
    else if (button == '2')
    {
        // Tone pressed
        menuIndex = MENU_TONE;
    }
}

void menuLoopback()
{
    // Display loopback menu
    String text = "";
    text += "Loopback\n";
    text += "*-Back\n";
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if (button == '*')
    {
        // Return pressed
        menuIndex = MENU_AUDIO;
        stopAudioLoopBack();
    }
}

void menuTone()
{
    // Display tone menu
    String text = "";
    text += "Tone\n";
    text += "*-Back\n";
    printDisplay(text);

    // Check for button press
    char button = keypad.getButton();
    if (button == '*')
    {
        // Return pressed
        menuIndex = MENU_AUDIO;
    }
}

void selectMenu()
{
    // Select menu based on menu index
    switch (menuIndex)
    {
    case MENU_HOME:
        menuHome();
        break;
    case MENU_DIAL:
        menuDial();
        break;
    case MENU_TEXT:
        menuText();
        break;
    case MENU_AUDIO:
        menuAudio();
        break;
    case MENU_LOOPBACK:
        menuLoopback();
        break;
    case MENU_TONE:
        menuTone();
        break;
    case MENU_CALL:
        menuCall();
        break;
    case MENU_RING:
        menuRing();
        break;
    case MENU_SPEED_DIAL:
        menuSpeedDial();
        break;
    default:
        menuIndex = MENU_HOME;
        break;
    }
}
