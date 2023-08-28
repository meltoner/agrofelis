#include "FrontSensorsController.h" 
#include "string.h"
#include "SerialCommandParser.h" 

FrontSensorsController::FrontSensorsController(){}

void FrontSensorsController::setup(Context &_context){
  tiltServo.setup(*context); 
}

void FrontSensorsController::actionParsedCommand() {

  switch(command){
    case 0: break;

    // tiltServo
    case 41:
      tiltServo.setTiltServo(commandInt);      
      break;

  }
  command = 0;
}

void FrontSensorsController::apply(){
  parse();
  if(command > 0)
    actionParsedCommand();  
}

void FrontSensorsController::print(){
  tiltServo.print();  
}
