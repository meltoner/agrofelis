/*
  SteerControl.h - Library for wraping the functions controling the SteerControl
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#include "Arduino.h"
#include "Linear.h"
#include "SteerControl.h"

SteerControl::SteerControl(){
}

void SteerControl::setup(Context &_context){
  context = &_context;
  linearA.setup(*context);
  linearB.setup(*context);  
}

void SteerControl::apply(){
  linearA.apply();
  linearB.apply();
}

void SteerControl::print(){
  Serial.print(F("<SteerControl:1"));
  Serial.print(F(";"));
  Serial.print(1);
  Serial.print(F(">"));
  linearA.print();
  linearB.print();
}

