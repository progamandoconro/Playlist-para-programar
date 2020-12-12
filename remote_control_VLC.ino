//Arduino Remote control for Raspberry pi with VLC music player. 
//Clone this repo and modify this script to look music in your folder. 

//Programandoconro 2020 (modified from Elegoo 2016)

//www.elegoo.com
//2016.12.9

#include "IRremote.h"
#include "Keyboard.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
boolean PLAY = false;
boolean POWER = false;

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes

{

  switch (results.value)

  {

    case 0xFFA25D: Serial.println("POWER");

      if (POWER == false) {
        POWER = true;
      }
      else {
        POWER = false;
      }

      if (POWER == true) {
        Keyboard.press(KEY_LEFT_CTRL); Keyboard.write('c'); Keyboard.releaseAll(); delay(500);
        Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack && vlc . -Z"); delay(500);

      }

      if (POWER == false) {
        Keyboard.println("quit");
      }

      break;


    case 0xFF02FD: Serial.println("PAUSE");

      if (PLAY == false) {
        PLAY = true;
      }
      else {
        PLAY = false;
      }

      if (PLAY == true) {

        Keyboard.println("play");

      }

      if (PLAY == false) {
        Keyboard.println("pause");

      }
      break;

    case 0xFFE21D: Serial.println("FUNC/STOP"); Keyboard.println("quit"); break;
    case 0xFF629D: Serial.println("VOL+"); Keyboard.println("volup"); break;
    case 0xFF22DD: Serial.println("FAST BACK"); Keyboard.println("prev"); break;
    case 0xFFC23D: Serial.println("FAST FORWARD");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack && vlc . -Z");
      break;
    case 0xFFE01F: Serial.println("DOWN");
      break;
    case 0xFFA857: Serial.println("VOL-");   Keyboard.println("voldown"); break;
    case 0xFF906F: Serial.println("UP");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Ray_Charles && vlc . -Z");
      break;
    case 0xFF9867: Serial.println("EQ");    break;
    case 0xFFB04F: Serial.println("ST/REPT"); Keyboard.println("prev"); break;
    case 0xFF6897: Serial.println("0");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Sakura && vlc . -Z");

      break;
    case 0xFF30CF: Serial.println("1");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Nihongo && vlc . -Z");
      break;
    case 0xFF18E7: Serial.println("2");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Beatles && vlc . -Z");
      break;
    case 0xFF7A85: Serial.println("3");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Elton_John && vlc . -Z");
      break;
    case 0xFF10EF: Serial.println("4");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Kate_Bush && vlc . -Z");
      break;
    case 0xFF38C7: Serial.println("5");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Rock && vlc . -Z");
      break;
    case 0xFF5AA5: Serial.println("6");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Venezuela && vlc . -Z");
      break;
    case 0xFF42BD: Serial.println("7");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Bob_Marley && vlc . -Z");
      break;
    case 0xFF4AB5: Serial.println("8");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Espana && vlc . -Z");
      break;
    case 0xFF52AD: Serial.println("9");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println("cd /home/pi/Playlist-para-programar/Soundtrack/Match_Box_20 && vlc . -Z");
      break;
    case 0xFFFFFFFF: Serial.println(" REPEAT"); break;

    default:
      Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR();
    irrecv.resume(); // receive the next value
  }
}/* --(end main loop )-- */




