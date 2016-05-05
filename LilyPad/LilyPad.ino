
//TO DO:
//-test EVERYTHING

//TEST:
//-Read flex
//-Gyro
//-enable/ack signals - initial sync

/* Created by:
 * Scott McCartney
 * Dharini Parthasarathy
 * Adin Richardson
 * Ryan Sunderhaus
 */
 
//-------------LILYPAD-------------//
//---Provides primary control of
//-----the Arduino LilyPad
//---Includes input control
//---Communicates with Uno
//---------------------------------//
#include <LilyPad.h> //primary header file

//--GlobalsSerial.println(mouse_buttons);
int mouse_move_x, mouse_move_y;
unsigned long vibe_time;
boolean vibe_start;

//--Setup
void setup() {
  Serial.begin(9600);
  pinMode(LIGHT_PIN, OUTPUT);
  gyro_setup();
}

//--Loop
void loop() {
  gyro_loop();
  int mouse_buttons = read_flex();
  mouse_command(mouse_buttons, mouse_move_x, mouse_move_y);
  //Serial.println(mouse_move_x);
  if (mouse_buttons & 0b11 != 0) vibe_start = true;
  vibe();
}
