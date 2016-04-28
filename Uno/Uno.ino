
//TO DO:

//TEST:
//-Data read
//-parce data
//-bluetooth output
//-Ack/en

/* Created by:
 * Scott McCartney
 * Dharini Parthasarathy
 * Adin Richardson
 * Ryan Sunderhaus
 */

//---------------UNO---------------//
//---Provides primary control of
//-----arduino Uno
//---Includes output control
//---Communicates with LilyPad
//---------------------------------//

#include <Uno.h> //primary header file

//--Globals
unsigned long prev_com_ms;
int mouse_move_x, mouse_move_y, mouse_buttons, vibe_command;

//--Setup
void setup() {
  Serial.begin(9600);
  pinMode(CLK, INPUT);
  pinMode(DATA, INPUT);
  pinMode(ACK, OUTPUT);
  setup_vibe();
  sync();
}

//--Loop
void loop() {
  read_data();
  mouse_command(mouse_buttons, mouse_move_x, mouse_move_y);
  vibe(vibe_command);
  //Serial.println(mouse_buttons);
}
