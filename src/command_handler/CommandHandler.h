#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <Arduino.h>
#include "security_system/SecuritySystem.h"
#include "display/DisplayController.h"

class CommandHandler {
private:
    SecuritySystem* securitySystem;
    DisplayController* displayController;
    String inputBuffer;
    int commandState;
    String command;
    String param1;
    String param2;

    void resetCommand();

public:
    CommandHandler(SecuritySystem* secSys, DisplayController* dispCtrl);
    void handleKeyPress(char key);
    void handleAsterisk();
    void handleHash();
    void handleRegularKey(char key);
    void executeCommand();
};

#endif