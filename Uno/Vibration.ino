
//----------VIBRATION----------//
//---Controls vibration module
//-----------------------------//

//--Master vibration controller, with command param
void vibe(int vibe_command) {
  //maybe use switch?
  switch (vibe_command) {
    LEFT_CLICK:
      
      break;
    RIGHT_CLICK:
      
      break;
    default:
      ;
  }
}

void setup_vibe() {
  drv.begin();
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG);
}

void click_feedback() {
  // set the effect to play
  drv.setWaveform(0, 84);           // play effect 84 
  drv.setWaveform(1, 1);            // play effect 1
  drv.setWaveform(2,0);             // end waveform  

  drv.go();
}

