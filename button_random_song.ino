/*
  Keyboard Message to play a random song in a Raspberry (or any computer) 

  For the Arduino Leonardo and Micro.

  Requirements: 
  
  - Arduino Leonardo or Micro, Raspberry pi (or any computer). Speakers or earphones.  
  - Install vlc (``sudo apt install vlc``).
  - Clone this repo in your ``/home/pi`` directory (modify if needed).
  
  Sends a message to vlc to play a random song when a button is pressed.

  The circuit:
  - Button attached from pin 4 to +5V
  - 10 kilohm resistor attached from pin 4 to ground
  - Connect to a Raspberry Pi
  - Connect the speakers
  - Push the button for a random song
  - Push again for a new random song
  - Push reset button to stop

  created 21 Sept 2020
  by programandoconro

*/

#include "Keyboard.h"
boolean off = false;
const int buttonPin = 4;

void setup() {
  pinMode(buttonPin, INPUT);
  Keyboard.begin();
}

void loop() {
  if (off == false) {
    delay(1000);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('c');
    Keyboard.releaseAll();
    off = true;
  }

  if (buttonState == true) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('c');
    Keyboard.releaseAll();
    delay(500);
    Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack && vlc . -Z");
    delay(1000);
  }

}
