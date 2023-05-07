/*
  Invoker.h - Library for wraping the functions controling the Invoker
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#ifndef Invoker_h
#define Invoker_h

#include "Arduino.h"
#include "Context.h"

class Invoker{
  public:
    Invoker();
    void setup(Context &_context);
    int apply();
  private:
    Context *context;
    
};

#endif