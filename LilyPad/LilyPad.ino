
//TO DO:
//-test EVERYTHING

//TEST:
//-Data send
//-Read flex
//-Gyro
//-enable/ack signals - initial sync
//-Use of all works on lilypad


//----------------------HEADER CONTENT-------------------//
//--Libraries


//--Pins
#define THUMB_PIN   A3
#define INDEX_PIN   A2
#define MIDDLE_PIN  A1
#define VIBE_PIN    8
#define CLK         9
#define DATA        12
#define ACK         10

//--Flex sensor thresholds
const int THUMB_THRESHOLD = 210;
const int INDEX_THRESHOLD = 375;
const int MIDDLE_THRESHOLD = 425;

//--Vibration constants
const int VIBE_MAX = 1023;
const int VIBE_LENGTH = 750;
//-------------------------------------------------------//

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

//--Globals
int mouse_move_x, mouse_move_y;

//--Setup
void setup() {
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(ACK, INPUT);
  gyro_setup();
  //sync();
}

//--Loop
void loop() {
  gyro_loop();
  int mouse_buttons = read_flex();
  //send_data(mouse_move_x, mouse_move_y, mouse_buttons, 0);
  mosue_command(mouse_buttons, mouse_move_x, mouse_move_y);
  if (mouse_buttons & 0b11 != 0) vibe();
}
