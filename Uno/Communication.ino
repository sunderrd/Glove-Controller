
//----------COMMUNICATION----------//
//---Controls communication with
//-----the Arduino LilyPad
//---------------------------------//

void sync() {
  while (digitalRead(CLK) == LOW);
  while (digitalRead(CLK) == HIGH) {
    digitalWrite(ACK, HIGH);
  }
  digitalWrite(ACK, LOW);
}

void read_data() {
  unsigned long data_in = 0;
  for (int i=0; i<32; i++) {
    while (digitalRead(CLK) == HIGH) {
      data_in |= (digitalRead(DATA) << i);
    }
  }
  parce_data(data_in);
  Serial.println(data_in);
}

void parce_data(unsigned long data_in) {
  mouse_move_x = (data_in >> 0) % 256;
  mouse_move_y = (data_in >> 8) % 256;
  mouse_buttons = (data_in >> 16) % 256;
  vibe_command = (data_in >> 24) % 256;
}

boolean ms_timer() {
  unsigned long temp = millis();
  if (temp != prev_com_ms) {
    prev_com_ms = temp;
    return true;
  }
  return false;
}

