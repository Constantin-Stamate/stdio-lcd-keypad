#ifndef DISPLAY_CONTROLLER_H
#define DISPLAY_CONTROLLER_H

#include <LiquidCrystal.h>
#include <Arduino.h>

class DisplayController {
private:
    LiquidCrystal* lcd;

public:
    DisplayController(LiquidCrystal* lcd);
    void init();
    void clear();
    void showWelcome();
    void showMainScreen(bool isLocked);
    void showMenuOptions(int state, String command);
    void showInput(String input, bool hideChars);
    void showCommandResult(String line1, String line2);
};

#endif