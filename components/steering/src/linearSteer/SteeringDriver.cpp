
#include "LinearActuator.h"
#include "SteeringDriver.h"
#include "Interpolate.h"

SteeringDriver::SteeringDriver(){}

void SteeringDriver::setup(Context &_context){
  context = &_context;
  linearLeft.setup(*context);
  linearRight.setup(*context);  
}

void SteeringDriver::apply(){
  linearLeft.apply();
  linearRight.apply();
}

void SteeringDriver::position(float input){
  input = leftMap.constrainInput(input);
  inputIndex = leftMap.findInputIndex(input);
  linearLeft.position(leftMap.interpolate(input, inputIndex));
  linearRight.position(rightMap.interpolate(input, inputIndex));
}

void SteeringDriver::print(){
  //Serial.print(F("<SteeringDriver:1"));
  //Serial.print(F(";"));
  //Serial.print(1);
  //Serial.print(F(">"));
  linearLeft.print();
  linearRight.print();
}
