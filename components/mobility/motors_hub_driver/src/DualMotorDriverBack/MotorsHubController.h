/** 
 * The MotorsHubController Class maintains the objects intended to be controlled externally via the web sockets link
 * 
 * It extends the web sockets message parser to listen for external commands such as setting the desired position of some actuator
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023  
 */


#ifndef MotorsHubController_h
#define MotorsHubController_h

#include "Arduino.h" 
#include "Context.h"
#include "Motor.h"
#include "CommandParser.h"  

class MotorsHubController : public CommandParser{
  public:
    MotorsHubController();
    
    void setup(Context &_context);
    void fastApply();
    void syncMotorsSpeed();
    void apply();

    //int 0 or 1 // boolean
    void setPower(int value);
    
    //int 0 or 1 // boolean
    void setDirection(int value);

    // Set speed input value 0-100. the value is the mapped to the range 0-255
    void setSpeed(int value);

    void runChecks();


    // reflects the internal state of the MotorsHubController
    void print();
    void actionParsedCommand();

    int power, direction, speed, status = 0;
    float motorsSpeedDifference = 0.0;
    float accumulatedDiffSpeed = 0.0;
    
    long targetPosition = 0;

    // Back left
    // POWER 13, DIRECTION 12, SPEED 26, (adac) CURRENT 1, onewire TEMPERATURE INDEX1, HALL A (yellow) 5, B (green) 6, C (blue) 7, ReverseSpin false
    Motor motorA = Motor(13, 12, 26, 1, 1, 5, 6, 7, false, 255);//250

    // Back right
    // POWER 32, DIRECTION 21, SPEED 25, (adac) CURRENT 1, onewire TEMPERATURE INDEX0, HALL A (yellow) 2, B (green) 3, C (blue) 4, ReverSpin true
    Motor motorB = Motor(32, 21, 25, 0, 0, 2, 3, 4, true, 255);
    int maxTopOnSpeed = 10;

  private:
    unsigned long lastAdaptation = millis(); 
    float degree = 0;
    Context *context;
};

#endif