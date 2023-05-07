/*
  Blink.h - Library for wrapping the functions controlling Blink 
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#include "Arduino.h"
#include "Blink.h" 
#include "Context.h"

Blink::Blink(byte pin){
  _pin = pin;
}

void Blink::setup(Context &_context){
  context = &_context;
  pinMode(_pin, OUTPUT);
  apply();
}

void Blink::apply(){
  digitalWrite(_pin, !digitalRead(_pin));
}
