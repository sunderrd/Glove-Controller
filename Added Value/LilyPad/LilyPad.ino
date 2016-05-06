
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
//---------------------------------//
#include <LilyPad.h> //primary header file

//--Globals
int mouse_move_x, mouse_move_y;
unsigned long vibe_time;
boolean vibe_start;
boolean setRef;
boolean move_go;

//--Setup
void setup() {
  Serial.begin(9600);
  pinMode(LIGHT_PIN, OUTPUT);
  gyro_setup();
}

//--Loop
void loop() {
  gyro_loop();
  if (!move_go) {
    mouse_move_x = 0;
    mouse_move_y = 0;
  }
  int mouse_buttons = read_flex();
  if (setRef) mouse_command(mouse_buttons, mouse_move_x, mouse_move_y);
  //Serial.println(mouse_move_x);
  if (mouse_buttons & 0b11 != 0) vibe_start = true;
  vibe();
}
