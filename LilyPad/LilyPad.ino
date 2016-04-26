
//TO DO:
//-enable/ack signals - initial sync
//-accel/gyro

//TEST:
//-Data send
//-Read flex


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
unsigned long prev_com_ms;

//--Setup
void setup() {
  setup_gyro();
}

//--Loop
void loop() {
  int vibe_command = read_flex();
  send_data(mouse_move_x, mouse_move_y, mouse_buttons, vibe_command);
}
