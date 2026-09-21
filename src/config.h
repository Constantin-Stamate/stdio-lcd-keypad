#ifndef CONFIG_H
#define CONFIG_H

// LCD Pins
#define LCD_RS 7
#define LCD_E 6
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2

// LED Pins
#define LED_LOCKED 9    // Red LED
#define LED_UNLOCKED 8  // Green LED

// Keypad Configuration
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

// Password Settings
#define MIN_PASSWORD_LENGTH 4
#define DEFAULT_PASSWORD "1234"

#endif