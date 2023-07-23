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
    void fastApply();
    void apply();
    void print();
    void actionParsedCommand();

    //back left
    Motor motorA = Motor(13, 12, 26, 1, 1, 5, 6, 7, false, 250); // POWER 13, DIRECTION 12, SPEED 26, (adac) CURRENT 1, onewire TEMPERATURE INDEX1, HALL A (yellow) 5, B (green) 6, C (blue) 7, ReverseSping false
    //back right
    Motor motorB = Motor(32, 21, 25, 0, 0, 2, 3, 4, true, 255); // POWER 32, DIRECTION 21, SPEED 25, (adac) CURRENT 1, onewire TEMPERATURE INDEX0, HALL A (yellow) 2, B (green) 3, C (blue) 4, ReverSpin true

  private:
    Context *context;
};

#endif