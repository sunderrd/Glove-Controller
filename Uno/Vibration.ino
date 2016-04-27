
//----------VIBRATION----------//
//---Controls vibration module
//-----------------------------//

//--Master vibration controller, with command param
void vibe(int vibe_command) {
  //maybe use switch?
  switch (vibe_command) {
    LEFT_CLICK:
    RIGHT_CLICK:
      click_feedback();
      break;
    default:
      no_vibe();
  }
}

void setup_vibe() {
  drv.begin();
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG);
}

void no_vibe() {
  drv.setWaveform(0, 0);
  drv.go();
}

void click_feedback() {
  // set the effect to play
  drv.setWaveform(0, 84);           // play effect 84 
  drv.setWaveform(1, 1);            // play effect 1
  drv.setWaveform(2,0);             // end waveform  

  drv.go();
}

