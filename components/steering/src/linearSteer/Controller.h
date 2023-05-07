/*
  Controller.h - Library for wraping the functions controling the Controller 
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef Controller_h
#define Controller_h

#include "Arduino.h" 
#include "Context.h"
#include "Steer.h"
#include "SerialParser.h" 

class Controller{
  public:
    Controller();
    void setup(Context &_context);
    void apply();
    void actionParsedCommand();
    Steer steer = Steer::Steer();
  private:
    Context *context;
    SerialParser parser = SerialParser();
};

#endif