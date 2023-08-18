#include "SteeringController.h" 
#include "string.h"
#include "SteeringDriver.h"
#include "Brake.h"
#include "SerialCommandParser.h" 

SteeringController::SteeringController(){}

void SteeringController::setup(Context &_context){
  steer.setup(*context);
  brakes.setup(*context); 
}

void SteeringController::actionParsedCommand() {

  switch(command){
    case 0: break;

    // Individual motors ///////////////////////
    case 21: 
      steer.setLeftState(commandInt);
      break;
    case 22: 
      steer.setRightState(commandInt);
      break;
    case 23: 
      steer.setLeftPosition(commandInt);
      break;
    case 24: 
      steer.setRightPosition(commandInt);
      break;
    // Syncronised motion //////////////////////
    case 25:
      steer.setState(commandInt);
      break;
    case 26:
      steer.setPosition(commandInt);
      break;

    // Brakes
    case 27:
      brakes.brakeLeft.setBrake(commandInt);
      break;
    case 28:
      brakes.brakeRight.setBrake(commandInt);
      break;
    case 29:
      brakes.setBrake(commandInt);      
      break;

  }
  command = 0;
}

void SteeringController::apply(){
  parse();
  if(command > 0)
    actionParsedCommand();  
}

void SteeringController::print(){
  steer.print();
  brakes.print();  
}
