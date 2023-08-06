/*
  SteeringController.h - Library for wraping the functions controling the SteeringController 
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef SteeringController_h
#define SteeringController_h

#include "Arduino.h" 
#include "Context.h"
#include "SteeringDriver.h"
#include "SerialCommandParser.h" 

class SteeringController{
  public:
    SteeringController();
    void setup(Context &_context);
    void apply();
    void actionParsedCommand();
    SteeringDriver steer = SteeringDriver::SteeringDriver();
  private:
    Context *context;
    SerialCommandParser parser = SerialCommandParser();
};

#endif