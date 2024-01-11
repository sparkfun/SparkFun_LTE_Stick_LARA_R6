// Include other helper files in this project directory
#include "Breadboard_Phone_Definitions.h"
#include "Breadboard_Phone_Hardware.h"
#include "Breadboard_Phone_Menus.h"

void setup()
{
    // Begin serial and print a message so we know it's working
    Serial.begin(115200);
    Serial.println("Breadboard Phone Demo!");

    // Begin all the hardware on the Breadboard Phone
    beginHardware();
}

void loop()
{
    // Get user input
    updateKeypad();
    
    // Update the display
    selectMenu();

    // No need to go super fast here
    delay(10);
}
