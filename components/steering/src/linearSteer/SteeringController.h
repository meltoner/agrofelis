/** 
 * The SteeringController Class maintains the objects intended to be controlled externally via the Serial link
 * 
 * It uses a Serial parser to listen for external commands such as setting the desired position of some actuator
 * This SteeringController expects two pieces of data - an int, and an int
 * Examples involve initialising the two submoldules <15|1> or set the desired steering hard left and hard right with <16|-100> or <16|100>
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023 agrofelis
 * 
 */

/*
  Teting examples
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

#ifndef SteeringController_h
#define SteeringController_h

#include "Arduino.h" 
#include "Context.h"
#include "Brakes.h"
#include "SteeringDriver.h"
#include "SerialCommandParser.h" 

class SteeringController : public SerialCommandParser{
  public:
    // Create a new steering module controller
    SteeringController();
    // Passes the context
    void setup(Context &_context);
    // applies the parsing and the apply methods of its objects
    void apply();
    // Remote invocations via the parser
    void actionParsedCommand();
    //calls the print methods of its objects
    void print();
    // The steering module
    SteeringDriver steer = SteeringDriver::SteeringDriver();
    Brakes brakes = Brakes::Brakes();
  private:
    Context *context;
};

#endif