#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include "config.h"
#include "led/LEDController.h"
#include "display/DisplayController.h"
#include "security_system/SecuritySystem.h"
#include "command_handler/CommandHandler.h"

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

byte rowPins[KEYPAD_ROWS] = {A3, A2, A1, A0};
byte colPins[KEYPAD_COLS] = {13, 12, 11, 10};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

LEDController ledController(LED_LOCKED, LED_UNLOCKED);
DisplayController displayController(&lcd);
SecuritySystem securitySystem(&ledController, &displayController);
CommandHandler commandHandler(&securitySystem, &displayController);

void setup() {
    displayController.init();
    
    securitySystem.init();
    
    displayController.showWelcome();
    delay(2000);
    displayController.showMainScreen(securitySystem.isSystemLocked());
}

void loop() {
    char key = keypad.getKey();
    if (key) {
        commandHandler.handleKeyPress(key);
    }
}