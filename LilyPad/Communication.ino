
//----------COMMUNICATION----------//unneeded?
//---Controls communicaiton with
//-----the Arduino Uno
//---------------------------------//
/*
void sync() {
  while(digitalRead(ACK) == LOW) {
    digitalWrite(CLK, HIGH);
  }
  digitalWrite(CLK, LOW);
}

void send_data(int mouse_move_x, int mouse_move_y, int mouse_buttons, int vibe_command) {
  unsigned long data_out = unify_data(mouse_move_x, mouse_move_y, mouse_buttons, vibe_command);
  for (int i=0; i<32; i++) {
    digitalWrite(DATA, ((1 << i) & data_out) != 0);
    digitalWrite(CLK, HIGH);
    //delay(1); //needed?
    digitalWrite(CLK, LOW);
  }
}

unsigned long unify_data(int mouse_move_x, int mouse_move_y, int mouse_buttons, int vibe_command) {
  unsigned long data_out = 0;
  data_out |= (mouse_move_x << 0);
  data_out |= (mouse_move_y << 8);
  data_out |= (mouse_buttons << 16);
  data_out |= (vibe_command << 24);
  return data_out;
}
*/
