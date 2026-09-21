#include "LEDController.h"

LEDController::LEDController(int lockedPin, int unlockedPin)
    : lockedPin(lockedPin), unlockedPin(unlockedPin) {}

void LEDController::init() {
    pinMode(lockedPin, OUTPUT);
    pinMode(unlockedPin, OUTPUT);
}

void LEDController::setLocked() {
    digitalWrite(lockedPin, HIGH);
    digitalWrite(unlockedPin, LOW);
}

void LEDController::setUnlocked() {
    digitalWrite(lockedPin, LOW);
    digitalWrite(unlockedPin, HIGH);
}