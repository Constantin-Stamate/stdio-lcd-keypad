#include "command_handler/CommandHandler.h"

CommandHandler::CommandHandler(SecuritySystem* secSys, DisplayController* dispCtrl)
    : securitySystem(secSys), displayController(dispCtrl), commandState(0) {}

void CommandHandler::resetCommand() {
    commandState = 0;
    inputBuffer = "";
    command = "";
    param1 = "";
    param2 = "";
}

void CommandHandler::handleKeyPress(char key) {
    if (key == '*') {
        handleAsterisk();
    } else if (key == '#') {
        handleHash();
    } else {
        handleRegularKey(key);
    }
}

void CommandHandler::handleAsterisk() {
    if (commandState == 0) {
        commandState = 1;
        inputBuffer = "";
        command = "";
        param1 = "";
        param2 = "";
        displayController->showMenuOptions(1, "");
    } else if (commandState == 1) {
        command = inputBuffer;
        inputBuffer = "";
        commandState = 2;
        displayController->showMenuOptions(2, command);
    } else if (commandState == 2) {
        param1 = inputBuffer;
        inputBuffer = "";
        commandState = 3;
        displayController->showMenuOptions(3, command);
    }
}

void CommandHandler::handleHash() {
    if (commandState > 0) {
        if (commandState == 1) {
            command = inputBuffer;
        } else if (commandState == 2) {
            param1 = inputBuffer;
        } else if (commandState == 3) {
            param2 = inputBuffer;
        }
        
        executeCommand();
        resetCommand();
        delay(2000);
        displayController->showMainScreen(securitySystem->isSystemLocked());
    }
}

void CommandHandler::handleRegularKey(char key) {
    if (commandState > 0) {
        inputBuffer += key;
        bool hideChars = ((command == "1" || command == "2") && commandState >= 2);
        displayController->showInput(inputBuffer, hideChars);
    }
}

void CommandHandler::executeCommand() {
    if (command == "0") {
        securitySystem->lockSystem();
    } else if (command == "1") {
        securitySystem->unlockSystem(param1);
    } else if (command == "2") {
        securitySystem->changePassword(param1, param2);
    } else if (command == "3") {
        securitySystem->showStatus();
    } else {
        displayController->showCommandResult("Command", "Unknown!");
    }
}