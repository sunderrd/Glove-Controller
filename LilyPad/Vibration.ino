
//----------VIBRATION----------//
//---Controls vibration module
//-----------------------------//

void vibe() {  
  //-Ramp up
  if (vibe_start) {
    for (int i=0; i<VIBE_MAX; i+=10) {
      analogWrite(VIBE_PIN, i);
    }
    vibe_start = false;
    vibe_time = millis();
  }

  if (timer(VIBE_LENGTH, &vibe_time)) {
    analogWrite(VIBE_PIN, 0);
  }
}

//--(from Ryan's alarm clock)
//--Returns true if time_length has passed since last true value returned
boolean timer(int timer_length, unsigned long *last_value) {
  boolean out = false;
  unsigned long temp = millis();
  if (temp >= *last_value + timer_length) {
    *last_value = temp;
    out = true;
  }
  last_value = NULL;
  return out;
}
