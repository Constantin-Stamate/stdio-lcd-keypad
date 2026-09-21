#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>

class LEDController {
private:
    int lockedPin;
    int unlockedPin;

public:
    LEDController(int lockedPin, int unlockedPin);
    void init();
    void setLocked();
    void setUnlocked();
};

#endif