#include "display/DisplayController.h"

DisplayController::DisplayController(LiquidCrystal* lcd) : lcd(lcd) {}

void DisplayController::init() {
    lcd->begin(16, 2);
}

void DisplayController::clear() {
    lcd->clear();
}

void DisplayController::showWelcome() {
    clear();

    lcd->print("System locked");
    lcd->setCursor(0, 1);
    lcd->print("Press * for menu");
}

void DisplayController::showMainScreen(bool isLocked) {
    clear();

    if (isLocked) {
        lcd->print("System LOCKED");
    } else {
        lcd->print("System UNLOCKED");
    }

    lcd->setCursor(0, 1);
    lcd->print("Press * for menu");
}

void DisplayController::showMenuOptions(int state, String command) {
    clear();

    if (state == 1) {
        lcd->print("Options:");
        lcd->setCursor(0, 1);
        lcd->print("0,1,2,3 then */#");
    } else if (state == 2) {
        if (command == "1") {
            lcd->print("Enter password");
            lcd->setCursor(0, 1);
            lcd->print("then press #");
        } else if (command == "2") {
            lcd->print("Old password");
            lcd->setCursor(0, 1);
            lcd->print("then press *");
        } else {
            lcd->print("Command: " + command);
            lcd->setCursor(0, 1);
            lcd->print("Press #");
        }
    } else if (state == 3) {
        if (command == "2") {
            lcd->print("New password");
            lcd->setCursor(0, 1);
            lcd->print("then press #");
        }
    }
}

void DisplayController::showInput(String input, bool hideChars) {
    lcd->setCursor(0, 1);
    lcd->print("Input: ");

    if (hideChars) {
        for (unsigned int i = 0; i < input.length(); i++) {
            lcd->print("*");
        }
    } else {
        lcd->print(input);
    }
}

void DisplayController::showCommandResult(String line1, String line2) {
    clear();

    lcd->print(line1);
    lcd->setCursor(0, 1);
    lcd->print(line2);
}