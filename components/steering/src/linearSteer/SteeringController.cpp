/** 
 * The SteeringController Class maintains the objects intended to be controlled externally via the Serial link
 * 
 * It uses a Serial parser to listen for external commands such as setting the desired position of some actuator
 * This SteeringController expects two pieces of data - an int, and an int
 * Enter data in this style <1|1> <11|1> <15|1>
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023  
 */


/*
 
  <11|1> start left at initialisation mode
  <12|1> start right at initialisation mode
  
  <15|1> make both left and right at initialisation mode
  
  <16|-10> SteeringDriver 10 points on the left side
  <16|-20>
  <16|-50> SteeringDriver 50 % left
  <16|-70>
  <16|-100>
  <16|10>
  <16|40>
  <16|50>
  <16|80>
  <16|20>
  <16|0>
  <16|100>
*/

#include "SteeringController.h" 
#include "string.h"
#include "SteeringDriver.h"
#include "SerialCommandParser.h" 

SteeringController::SteeringController(){}

void SteeringController::setup(Context &_context){
  steer.setup(*context);
}

void SteeringController::actionParsedCommand() {

  switch(parser.command){
    case 0: break;
    case 1: 
      break;
    
    /////////////////////////

    case 11: 
      steer.linearLeft.changeState(parser.commandInt);
      break;
    case 12: 
      steer.linearRight.changeState(parser.commandInt);
      break;

    case 13: 
      steer.linearLeft.position(parser.commandInt);
      break;
    case 14: 
      steer.linearRight.position(parser.commandInt);
      break;

    /////////////////////////

    case 15:
      steer.linearLeft.changeState(parser.commandInt);
      steer.linearRight.changeState(parser.commandInt);
      break;

    case 16:
      steer.position((float)parser.commandInt);
      break;

  }
  parser.command = 0;

}

void SteeringController::apply(){
  parser.apply();
  if(parser.command > 0)
    actionParsedCommand();
}
