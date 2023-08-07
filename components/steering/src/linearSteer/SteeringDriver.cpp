
#include "LinearActuator.h"
#include "SteeringDriver.h"
#include "Interpolate.h"

SteeringDriver::SteeringDriver(){}

void SteeringDriver::setup(Context &_context){
  context = &_context;
  linearLeft.setup(*context);
  linearRight.setup(*context);  
}

void SteeringDriver::setLeftState(int state){
  linearLeft.changeState(state);
}

void SteeringDriver::setRightState(int state){
  linearRight.changeState(state);
}

void SteeringDriver::setState(int state){
  setLeftState(state);
  setRightState(state);
}

void SteeringDriver::setLeftPosition(int position){
  linearLeft.setPosition(position);

}
void SteeringDriver::setRightPosition(int position){
  linearRight.setPosition(position);  
}

void SteeringDriver::setPosition(int position){
  syncedPosition = leftMap.constrainInput((float)position);
  inputIndex = leftMap.findInputIndex(syncedPosition);

  leftPosistion = leftMap.interpolate(syncedPosition, inputIndex);
  rightPosition = rightMap.interpolate(syncedPosition, inputIndex);

  distanceRatio = (linearLeft.potentiometer - leftPosistion) / (linearRight.potentiometer - rightPosition);

  linearLeft.setPosition(leftPosistion);
  linearRight.setPosition(rightPosition);

}

void SteeringDriver::apply(){
  linearLeft.apply();
  linearRight.apply();

  status = (linearLeft.state + linearRight.state)/2;

  // should measure the speed
  // should know how distant is each each actuator based on Ackerman
}
 

void SteeringDriver::print(){
  Serial.print(F("<SteeringDriver1"));  
  Serial.print(F(";"));
  Serial.print(status);

  Serial.print(F(";"));
  Serial.print(syncedPosition);
  Serial.print(F(";"));
  Serial.print(leftPosistion);
  Serial.print(F(";"));
  Serial.print(rightPosition);
  Serial.print(F(";"));
  Serial.print(distanceRatio);
  Serial.print(F(">"));

  linearLeft.print();
  linearRight.print();
}
