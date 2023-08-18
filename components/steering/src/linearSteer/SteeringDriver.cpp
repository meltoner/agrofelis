
#include "LinearActuator.h"
#include "SteeringDriver.h"
#include "Interpolate.h"

SteeringDriver::SteeringDriver(){}

void SteeringDriver::setup(Context &_context){
  context = &_context;
  linearLeft.setup(*context);
  linearRight.setup(*context);

  // auto derived values and persisted here - can be auto derived or saved to EPROM
  linearLeft.setBoundSettings(367, 784, 80);
  linearRight.setBoundSettings(309, 727, 80);
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
  if(state > 3){
    setLeftPosition(50);
    setRightPosition(50);
  }
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
  leftPosition = leftMap.interpolate(syncedPosition, inputIndex);
  rightPosition = rightMap.interpolate(syncedPosition, inputIndex);
  linearLeft.setPosition(leftPosition);
  linearRight.setPosition(rightPosition);
}

void SteeringDriver::apply(){
  status = (linearLeft.state + linearRight.state) / 2;
  if(
    linearLeft.state == 5 && linearRight.state == 5 && 
    linearLeft.completion >0 && linearRight.completion > 0
  ){
    linearLeft.boostSpeed = linearRight.completion / linearLeft.completion;    
    linearRight.boostSpeed = linearLeft.completion / linearRight.completion;
    linearLeft.boostSpeed *= linearLeft.boostSpeed;
    linearLeft.boostSpeed = constrain(linearLeft.boostSpeed, 0.1, 10);
    linearRight.boostSpeed *= linearRight.boostSpeed;
    linearRight.boostSpeed = constrain(linearRight.boostSpeed, 0.1, 10);
  }else{
    linearLeft.boostSpeed = 1.2;
    linearRight.boostSpeed = 1.2;
  }
  linearLeft.apply();
  linearRight.apply();
}
 

void SteeringDriver::print(){
  Serial.print(F("<SteeringDriver1"));  
  Serial.print(F(";"));
  Serial.print(status);

  Serial.print(F(";"));
  Serial.print(syncedPosition);
  Serial.print(F(";"));
  
  Serial.print(F(">"));

  linearLeft.print();
  linearRight.print();
}
