/*
 * Setup: 
 * 1. Install Keypad Library
 *  1.1 Click Sketch -> Include Library -> Manage Libraries
 *  1.2 Search "Keypad"
 *  1.3 Install library by Mark Stanley, Alexander Brevig
 */

 /* 
  *  Useful Resources:
  *  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
  *  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
  *  For Media Keys, check out https://github.com/NicoHood/HID 
  */

#include "Keyboard.h"
#include "Keypad.h" 

const byte ROWS = 3; 
const byte COLUMNS = 2; 

/* 
 *  The matrix below is rotated by 90 degrees 
 *  so that the top left key on the
 *  keyboard is 1.
 */
char keys[ROWS][COLUMNS] = {
  {'3', '6'},
  {'2', '5'},
  {'1', '4'}
};

byte rowPins[ROWS] = {7,8,9};
byte colPins[COLUMNS] = {5,6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS );

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case '1':
        /* Type "Hello World" */
        Keyboard.println("Hello World!");
        break;
      case '2':
        /* Perform Copy Action, depending on operating system */
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('c');
        break;
      case '3':
        /* Perform Paste Action, depending on operating system */
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('v');
        break;
      case '4':
        Keyboard.press('4');
        break;
      case '5':
        Keyboard.press('5');
        break;
      case '6':
        /* Highlight everything and delete depending on operating system */
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('a');
        Keyboard.press(KEY_BACKSPACE);
        break;
    }
     Keyboard.releaseAll(); 
    delay(100);
  }
}
