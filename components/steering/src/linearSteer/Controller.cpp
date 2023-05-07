/** 
 * The Controller Class maintains the objects intended to be controlled externally via the Serial link
 * 
 * It uses a Serial parser to listen for external commands such as setting the desired position of some actuator
 * This Controller expects 3 pieces of data - an int, an integer and a floating point value
 * Enter data in this style <1, 1> <11, 1> <12, 1> or <1, 1, 1.1> <15, 20>
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023  
 */


/*

  <11, 1>
  <12, 1>
  
  <15, 1>
  <16, -10>
  <16, -20>
  <16, -50>
  <16, -250>
  <16, 10>
  <16, 40>
  <16, 50>
  <16, 0>

*/

#include "Controller.h" 
#include "string.h"
#include "Steer.h"
#include "SerialParser.h" 

Controller::Controller(){}

void Controller::setup(Context &_context){
  steer.setup(*context);
}

void Controller::actionParsedCommand() {

  // Serial.println("Command ");
  // Serial.print(parser.command);
  // Serial.print(" ");
  // Serial.print(parser.commandInt);
  // Serial.print(" ");
  // Serial.print(parser.commandFloat);
  // Serial.println("");

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

void Controller::apply(){
  parser.apply();
  if(parser.command > 0)
    actionParsedCommand();
}
