#ifndef SECURITY_SYSTEM_H
#define SECURITY_SYSTEM_H

#include <Arduino.h>
#include "led/LEDController.h"
#include "display/DisplayController.h"

class SecuritySystem {
private:
    String currentPassword;
    bool isLocked;
    LEDController* ledController;
    DisplayController* displayController;

public:
    SecuritySystem(LEDController* ledCtrl, DisplayController* dispCtrl);
    void init();
    bool isSystemLocked();
    void lockSystem();
    void unlockSystem(String password);
    void changePassword(String oldPassword, String newPassword);
    void showStatus();
};

#endif