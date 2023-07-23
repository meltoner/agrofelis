
/*
  <1|1> start left at initialisation mode
  <2|1> start right at initialisation mode
*/

#include "Controller.h" 
#include "Motor.h"
#include "string.h"



#include "CommandParser.h" 

Controller::Controller(){

}

void Controller::setup(Context &_context){
  context =  &_context;
  motorA.setup(*context);
  motorB.setup(*context);  

}

void Controller::actionParsedCommand() {
  Serial.print("called deriving action Parsed Command ");
  Serial.print(command);
  
  Serial.print(" ");
  Serial.println(commandInt);

  switch(command){
    case 0: break;

    ////////////////////////

    case 1:
      motorA.setPower(commandInt);
      break;

    case 2:    
      motorA.setDirection(commandInt);
      break;

    case 3:
      motorA.setSpeed(commandInt);
      break; 


    case 4:
      motorB.setPower(commandInt);
      break;

    case 5:
      motorB.setDirection(commandInt);
      break; 

    case 6:
      motorB.setSpeed(commandInt);
      break; 

    ////////////////////////
    
    case 7:
      motorA.setPower(commandInt);
      motorB.setPower(commandInt);
      break;

    case 8:
      motorA.setDirection(commandInt);
      motorB.setDirection(commandInt);
      break;

    case 9:
      motorA.setSpeed(commandInt);
      motorB.setSpeed(commandInt);
      break;

    case 11: 
      
      break;
    case 12: 
 
      break;

    case 13: 
 
      break;
    case 14: 
 
      break;

 
  }
  command = 0;

}

void Controller::fastApply(){
  motorA.fastApply();
  motorB.fastApply();
}

void Controller::apply(){
  motorA.applySpeed();
  motorB.applySpeed();

  motorA.apply();
  motorB.apply();
  // Test for temperature or current peak and pause

}

void Controller::print(){
  motorA.print();
  motorB.print();
  context->sendMessage();
}