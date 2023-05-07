/*
  Context.h - Library for wraping the functions controling the Context / enviroment information
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef Context_h
#define Context_h

#include "Arduino.h" 

class Context{
  public:
    Context();
    void setup();
    void apply();
    void reflectSensor(float value, byte precission);
  
    // Invoker variables - execution functions frequencies
    int intervals[6] = {10, 52, 104, 500, 1008, 5000};
    unsigned long now = millis();
    unsigned long timers[8] = {now, now, now, now};
    // exposed variables 

  private:
    byte _pin;
};

#endif
