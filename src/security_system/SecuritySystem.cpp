#include "../security_system/SecuritySystem.h"

#include "../config.h"

SecuritySystem::SecuritySystem(LEDController* ledCtrl, DisplayController* dispCtrl)
    : ledController(ledCtrl), displayController(dispCtrl),
      currentPassword(DEFAULT_PASSWORD), isLocked(true) {}

void SecuritySystem::init() {
    ledController->init();
    ledController->setLocked();
}

bool SecuritySystem::isSystemLocked() {
    return isLocked;
}

void SecuritySystem::lockSystem() {
    isLocked = true;
    ledController->setLocked();
    displayController->showCommandResult("Locked!", "System secured");
}

void SecuritySystem::unlockSystem(String password) {
    if (password == currentPassword) {
        isLocked = false;
        ledController->setUnlocked();
        displayController->showCommandResult("Unlocked!", "Access granted");
    } else {
        displayController->showCommandResult("Error!", "Wrong password");
    }
}

void SecuritySystem::changePassword(String oldPassword, String newPassword) {
    if (isLocked) {
        displayController->showCommandResult("Access denied!", "Unlock system");
        return;
    }

    if (oldPassword != currentPassword) {
        displayController->showCommandResult("Error!", "Wrong old password");
        return;
    }

    if (newPassword.length() < MIN_PASSWORD_LENGTH) {
        displayController->showCommandResult("Error!", "Min 4 characters");
        return;
    }

    currentPassword = newPassword;
    displayController->showCommandResult("Success!", "Password changed");
}

void SecuritySystem::showStatus() {
    if (isLocked) {
        displayController->showCommandResult("Status: LOCKED", "Red LED is ON");
    } else {
        displayController->showCommandResult("Status: OPEN", "Green LED is ON");
    }
}