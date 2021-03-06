
//----------FLEX SENSORS----------//
//---Controls flex sensor inputs
//--------------------------------//


int read_flex() {
  int mouse_buttons = 0;
  
  int thumb_val = analogRead(THUMB_PIN);
  int index_val = analogRead(INDEX_PIN);
  int middle_val = analogRead(MIDDLE_PIN);

  //-Create vibe_command
  if (index_val < INDEX_THRESHOLD) {
    if (middle_val < MIDDLE_THRESHOLD) mouse_buttons |= (1 << 1);
    else mouse_buttons |= (1 << 0);
  }

  move_go = thumb_val >= THUMB_THRESHOLD;

  /*Serial.print(thumb_val);
  Serial.print(" ");
  Serial.print(index_val);
  Serial.print(" ");
  Serial.print(middle_val);
  Serial.print(" ");
  Serial.println(mouse_buttons);*/

  return mouse_buttons;
}

