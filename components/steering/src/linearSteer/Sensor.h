/*
  Sensor.h - Library for wraping the functions controling the Sensor 
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h" 
#include "Context.h"

class Sensor{
  public:
    Sensor();
    void setup(int pin_);
    int apply();
    void print();
    bool moving = false;
    int value = 0;
    int prevValue = 0;
    int read = 0;
  private:
    int _pin;
    
};

#endif
