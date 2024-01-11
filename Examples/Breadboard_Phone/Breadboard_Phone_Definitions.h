#pragma once

// Arduino libraries used in this project
#include <SparkFun_Qwiic_Keypad_Arduino_Library.h>
#include <SparkFun_Qwiic_OLED.h>
#include <SparkFun_WM8960_Arduino_Library.h>
#include <SparkFun_u-blox_Cellular_Arduino_Library.h>
#include <Wire.h>

// Hardware devices
QwiicMicroOLED display;
KEYPAD keypad;
WM8960 codec;
SparkFun_ublox_LARA_R6401 lteStick;

// Speed dial contact names and numbers. Replace these with the people and
// corresponding phone numbers that you want in your speed dial list!
char speedDialNames[10][11] = {
    "",        // 0
    "Person1", // 1
    "Person2", // 2
    "Person3", // 3
    "Person4", // 4
    "Person5", // 5
    "Person6", // 6
    "Person7", // 7
    "Person8", // 8
    "Person9", // 9
};
char speedDialNumbers[10][11] = {
    "",           // 0
    "0123456789", // 1
    "0123456789", // 2
    "0123456789", // 3
    "0123456789", // 4
    "0123456789", // 5
    "0123456789", // 6
    "0123456789", // 7
    "0123456789", // 8
    "0123456789", // 9
};

// Which speed dial index is currently selected
uint8_t speedDialIndex = 0;

// Brightness for the RGB LED on the ESP32 Thing Plus C
uint8_t ledBrightness = 50;

// Phone number and text message placeholders
String destinationNumber = "";
String textMessage = "";

// Whether or not a call is currently active
bool callActive = false;

// Menu index
uint8_t menuIndex = 0;

// Enum to define various menu indices
typedef enum
{
    // Visible menus
    MENU_HOME = 0,
    MENU_DIAL,
    MENU_TEXT,
    MENU_AUDIO,
    // Hidden menus (accessed outside home screen)
    MENU_LOOPBACK = 10,
    MENU_CALL,
    MENU_RING,
    MENU_SPEED_DIAL,
    MENU_TONE
} menu_index_t;

// Variables used for rudimentary T-9 text entry
int8_t numPresses = -1;
uint8_t lastButtonPressed = 0;
uint32_t lastPressTime = 0;
uint32_t pressTimeMax = 500;

// T-9 keypad letter definitions
char keypadLetters[10][4] = {
    {' ', 0, 0, 0},       // 0
    {'.', ',', '!', '?'}, // 1
    {'a', 'b', 'c', 0},   // 2
    {'d', 'e', 'f', 0},   // 3
    {'g', 'h', 'i', 0},   // 4
    {'j', 'k', 'l', 0},   // 5
    {'m', 'n', 'o', 0},   // 6
    {'p', 'q', 'r', 's'}, // 7
    {'t', 'u', 'v', 0},   // 8
    {'w', 'x', 'y', 'z'}  // 9
};
