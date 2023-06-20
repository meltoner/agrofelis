/** 
 * The Controller Class maintains the objects intended to be controlled externally via the web sockets link
 * 
 * It extends the web sockets message parser to listen for external commands such as setting the desired position of some actuator
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023  
 */


#ifndef Controller_h
#define Controller_h

#include "Arduino.h" 
#include "Context.h"
#include "Motor.h"
#include "CommandParser.h" 

class Controller : public CommandParser{
  public:
    Controller();
    void setup(Context &_context);
    void apply();
    void print();
    void actionParsedCommand();
 
    Motor motorA = Motor(13, 12, 26, 36, 0, 39, 34, 35);
    Motor motorB = Motor(19, 21, 27, 14, 1, 32, 33, 27);

  private:
    Context *context;
};

#endif