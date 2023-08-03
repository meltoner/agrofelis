
/*
  <1|1> start left at initialisation mode
  <2|1> start right at initialisation mode
*/

#include "MotorsHubController.h" 
#include "Motor.h"
#include "string.h"
#include "CommandParser.h"  

MotorsHubController::MotorsHubController(){

}

void MotorsHubController::setup(Context &_context){
  context =  &_context;
  motorA.setup(*context);
  motorB.setup(*context); 

}

void MotorsHubController::actionParsedCommand() {
  
  switch(command){
    case 0: break;
    // Motor A //////////////////////
    case 1:
      motorA.setPower(commandInt);
      break;
    case 2:    
      motorA.setDirection(commandInt);
      break;
    case 3:
      motorA.setSpeed(commandInt);
      break; 
    // Motor B //////////////////////
    case 4:
      motorB.setPower(commandInt);
      break;
    case 5:
      motorB.setDirection(commandInt);
      break; 
    case 6:
      motorB.setSpeed(commandInt);
      break;
    // Dual Motor actions motion //////////////////////    
    case 7:      
      setPower(commandInt);
      break;
    case 8:
      setDirection(commandInt);      
      break;
    case 9:      
      setSpeed(commandInt);
      break;
    case 11:
      motorA.moveToPosition(commandInt);
      motorB.moveToPosition(commandInt);
      break;    
  }
  command = 0;
}

void MotorsHubController::fastApply(){
  motorA.fastApply();
  motorB.fastApply();
}

void MotorsHubController::syncMotorsSpeed(){
  if( (context->now - lastAdaptation) < 150 )
    return;

  if(speed == 0)
    return;
    
  lastAdaptation = context->now + 0 ;

  if( motorA.hallsSpeed - motorB.hallsSpeed == 0){
    motorsSpeedDifference = 0;
    return;
  }

  motorsSpeedDifference = ((float)(motorsSpeedDifference + (motorA.hallsSpeed - motorB.hallsSpeed))) / 2;

  // if motors rotate in oposite direction do not syncronise them
  if((motorA.hallsSpeed * motorB.hallsSpeed) < 0)
    return;

  if(abs(motorsSpeedDifference) > 0.5){
    accumulatedDiffSpeed += motorsSpeedDifference;
    if(abs(accumulatedDiffSpeed) > 1.5 ){

      degree = - (motorsSpeedDifference);
      degree = constrain(degree, -4, 4)/3;
      
      if(motorA.direction == 1)
        degree *= -1;

      if(degree > 0){
        motorA.topOnSpeed += degree;
        motorB.topOnSpeed += -degree;
      }else{
        motorA.topOnSpeed += degree;
        motorB.topOnSpeed += -degree;
      }
      motorA.topOnSpeed = constrain(motorA.topOnSpeed, -maxTopOnSpeed, maxTopOnSpeed);
      motorB.topOnSpeed = constrain(motorB.topOnSpeed, -maxTopOnSpeed, maxTopOnSpeed);
      accumulatedDiffSpeed = 0;      
    }    
  }else{
    accumulatedDiffSpeed = 0;
  }  
}


void MotorsHubController::runChecks(){
  // here the servo brakes should apply by the related module
  if(!motorA.isRunnable() || !motorB.isRunnable()){
    setPower(0);
    status = 1;
  }
}

void MotorsHubController::setPower(int value){
  power = value;
  if(power == 0){
    speed = 0;
    motorA.setSpeed(0);
    motorB.setSpeed(0);
  }else{
    status = 0;
  }
  motorA.setPower(power);
  motorB.setPower(power);
}

void MotorsHubController::setDirection(int value){
  direction = value;
  motorA.setDirection(direction);
  motorB.setDirection(direction);
}

void MotorsHubController::setSpeed(int value){
  speed = value;
  motorA.status = 0;
  motorB.status = 0;
  motorA.setSpeed(speed);
  motorB.setSpeed(speed);
}

void MotorsHubController::apply(){
  if(motorA.status == 0 && motorB.status == 0)
    syncMotorsSpeed();

  // Read temperature, current
  motorA.apply();
  motorB.apply();

  if(power == 1)
    runChecks();

  motorA.applySpeed();
  motorB.applySpeed();

}

void MotorsHubController::print(){

  String result = "<MotorsHubController";
    context->appendMessage(
      result + ESP.getEfuseMac() + ";" + power + ";" + direction + ";" + speed + ";" +
        motorsSpeedDifference  + ";" + 
        accumulatedDiffSpeed + ";" + 
        status + ";" + 
        ">"
    );

  motorA.print();
  motorB.print();

  context->sendMessage();
}