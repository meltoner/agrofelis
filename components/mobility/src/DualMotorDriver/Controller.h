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

// That means you can't use the ADC on any of the ADC2 channels while WiFi is on: 
//GPIO 4, GPIO 0, GPIO 2, GPIO 15, GPIO 13, GPIO 12, GPIO [14], GPIO [27], GPIO 25 and GPIO 26.
//But you can use ADC1, which uses pins GPIO 36, GPIO [37], GPIO [38], GPIO 39, GPIO 32, GPIO 33, GPIO 34 and GPIO 35.

//    Motor motorA = Motor(13, 12, 26, 36, 0, 4, 5, 6); // POWER 13, DIRECTION 12, SPEED 26, CURRENT 33, TEMPINDEX0, HALL A 39, B 34, C 35
//    Motor motorB = Motor(19, 21, 25, 33, 1, 1, 2, 3); // POWER 19, DIRECTION 21, SPEED 25, CURRENT 14, TEMPINDEX1, HALL A 32, B 33, C 27

    Motor motorA = Motor(13, 12, 26, 0, 0, 2, 3, 4); // POWER 13, DIRECTION 12, SPEED 26, (adac)CURRENT 0, TEMPINDEX0, HALL A 2, B 3, C 4
    Motor motorB = Motor(32, 21, 25, 1, 1, 5, 6, 7); // POWER 32, DIRECTION 21, SPEED 25, (adac)CURRENT 1, TEMPINDEX1, HALL A 5, B 6, C 7

  private:
    Context *context;
};

#endif