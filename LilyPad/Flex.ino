
//----------FLEX SENSORS----------//
//---Controls flex sensor inputs
//--------------------------------//


int read_flex() {
  int vibe_command = 0;
  
  int thumb_val = analogRead(THUMB_PIN);
  int index_val = analogRead(INDEX_PIN);
  int middle_val = analogRead(MIDDLE_PIN);

  //-Create vibe_command
  if (thumb_val < THUMB_THRESHOLD) vibe_command |= (1 << 0);
  if (index_val < INDEX_THRESHOLD) vibe_commad |= (1 << 1);
  if (middle_val < MIDDLE_THRESHOLD) vibe_command |= (1 << 2);

  return vibe_command;
}

