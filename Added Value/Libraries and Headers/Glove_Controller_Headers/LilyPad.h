//
//  LilyPad.h
//  
//
//  Created by Ryan Sunderhaus on 4/22/16.
//
//

#ifndef LilyPad_h
#define LilyPad_h

//--Libraries


//--Pins
#define THUMB_PIN   A3
#define INDEX_PIN   A2
#define MIDDLE_PIN  A1
#define VIBE_PIN    9
#define LIGHT_PIN   12
#define RX      0
#define TX      1

//--Flex sensor thresholds
const int THUMB_THRESHOLD = 235;
const int INDEX_THRESHOLD = 425;
const int MIDDLE_THRESHOLD = 375;

//--Vibration constants
const int VIBE_MAX = 1000;
const int VIBE_LENGTH = 150;


#endif /* LilyPad_h */
