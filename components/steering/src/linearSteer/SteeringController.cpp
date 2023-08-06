#include "SteeringController.h" 
#include "string.h"
#include "SteeringDriver.h"
#include "SerialCommandParser.h" 

SteeringController::SteeringController(){}

void SteeringController::setup(Context &_context){
  steer.setup(*context);
}

void SteeringController::actionParsedCommand() {

  switch(command){
    case 0: break;
    case 1: 
      break;

    // Individual motors ///////////////////////
    case 11: 
      steer.setLeftState(commandInt);
      break;
    case 12: 
      steer.setRightState(commandInt);
      break;
    case 13: 
      steer.setLeftPosition(commandInt);
      break;
    case 14: 
      steer.setRightPosition(commandInt);
      break;
    // Syncronised motion //////////////////////
    case 15:
      steer.setState(commandInt);
      break;
    case 16:
      steer.setPosition(commandInt);
      break;
  }
  command = 0;
}

void SteeringController::apply(){
  parse();
  if(command > 0)
    actionParsedCommand();
}
