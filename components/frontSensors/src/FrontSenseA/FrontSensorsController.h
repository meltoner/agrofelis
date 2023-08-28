/** 
 * The FrontSensorsController Class maintains the objects intended to be controlled externally via the Serial link. 
 * 
 * It uses a Serial parser to listen for external commands such as setting the desired position of some actuator
 * This FrontSensorsController expects two pieces of data - an int, and an int 
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023 agrofelis
 * 
 */

/*
  Teting examples
  <11|1> start left at initialisation mode   
*/

#ifndef FrontSensorsController_h
#define FrontSensorsController_h

#include "Arduino.h" 
#include "Context.h"
#include "TiltServo.h"
#include "SerialCommandParser.h" 

class FrontSensorsController : public SerialCommandParser{
  public:
    // Create a new steering module controller
    FrontSensorsController();
    // Passes the context
    void setup(Context &_context);
    // applies the parsing and the apply methods of its objects
    void apply();
    // Remote invocations via the parser
    void actionParsedCommand();
    //calls the print methods of its objects
    void print();
    // The steering module
    TiltServo tiltServo = TiltServo(25, 45, 135);
  private:
    Context *context;
};

#endif