
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
int mouse_move_x, mouse_move_y;

//--Setup
void setup() {
  gyro_setup();
}

//--Loop
void loop() {
  gyro_loop();
  int mouse_buttons = read_flex();
  send_data(mouse_move_x, mouse_move_y, mouse_buttons, 0);
}
