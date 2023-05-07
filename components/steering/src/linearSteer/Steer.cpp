
#include "Linear.h"
#include "Steer.h"
#include "Interpolate.h"

Steer::Steer(){}

void Steer::setup(Context &_context){
  context = &_context;
  linearLeft.setup(*context);
  linearRight.setup(*context);  
}

void Steer::apply(){
  linearLeft.apply();
  linearRight.apply();
}

void Steer::position(float input){
  input = leftMap.constrainInput(input);
  inputIndex = leftMap.findInputIndex(input);
  linearLeft.position(leftMap.interpolate(input, inputIndex));
  linearRight.position(rightMap.interpolate(input, inputIndex));
}

void Steer::print(){
  //Serial.print(F("<Steer:1"));
  //Serial.print(F(";"));
  //Serial.print(1);
  //Serial.print(F(">"));
  linearLeft.print();
  linearRight.print();
}
