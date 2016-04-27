//
//  Uno.h
//  
//
//  Created by Ryan Sunderhaus on 4/22/16.
//
//

#ifndef Uno_h
#define Uno_h

//--Libraries
#include <Wire.h>
#include "Adafruit_DRV2605.h"

//--Pins
#define RX      0
#define TX      1
#define CLK     2
#define DATA    3

Adafruit_DRV2605 drv;

//--Vibration commands
const int LEFT_CLICK = 0b100;
const int RIGHT_CLICK = 0b010;

#endif /* Uno_h */
