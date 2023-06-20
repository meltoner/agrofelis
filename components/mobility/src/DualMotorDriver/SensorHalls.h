/*
  SensorHalls.h - Library for wraping the functions controling the SensorHalls 
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#ifndef SensorHalls_h
#define SensorHalls_h

#include "Arduino.h" 

class SensorHalls{
  public:
    SensorHalls();
    void setup(byte _pin1, byte _pin2, byte _pin3);

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
    byte pin1;
    byte pin2;
    byte pin3;
    
};

#endif
