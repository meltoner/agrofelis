/*
  Blink.h - Library for wrapping the functions controlling the Blink 
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef Blink_h
#define Blink_h

#include "Arduino.h" 
#include "Context.h"

class Blink{
  public:
    Blink(byte pin);
    void setup(Context &_context);
    void apply();
  private:
    Context *context;
    byte _pin;
};

#endif