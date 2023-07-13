/*
  SensorHalls.h - Library for wrapping the functions controlling the SensorHalls
  The class uses the multiplexer to get the corresponding digital value
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#ifndef SensorHalls_h
#define SensorHalls_h
#include "Context.h"
#include "Arduino.h" 

class SensorHalls{
  public:
    SensorHalls();
    void setup(Context &_context, byte pin5, byte pin6, byte pin7);

    /*
    * Reads the SensorHalls 3 read values calls the process function computing a change of degree positive or regular.
    */
    void apply();

    /*
    * Converts the readings to a positive or negative move
    */    
    void processValue();

    void print();
    
    int a = 0;
    int b = 0;
    int c = 0;
    
  private:
    Context *context;
    byte pin1;
    byte pin2;
    byte pin3;
    
};

#endif
