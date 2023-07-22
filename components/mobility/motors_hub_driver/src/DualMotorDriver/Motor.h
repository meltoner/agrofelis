/*
  Motor.h - Library for wrapping the functions controlling the Motor 
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef Motor_h
#define Motor_h

#include "Arduino.h" 
#include "Context.h"
#include "SensorADACCurrent.h" 
#include "SensorHalls.h" 

class Motor{
  public:
    // power, direction, speed, current, onewire temperature index, and hall a, hall b , hall c accessed via a multiplexer
    Motor(byte _pin1, byte _pin2, byte _pin3, byte pin4, byte _temperatureIndex, byte _pin5, byte _pin6, byte _pin7 );
    void setup(Context &_context);
    void fastApply();
    void apply();
    void print();

    //int 0 or 1 // boolean
    void setPower(int value);
    //int 0 or 1 // boolean
    void setDirection(int value);
    // Set speed input value 0-100. the value is the mapped to the range 0-255
    void setSpeed(int value);

    SensorADACCurrent currentSensor = SensorADACCurrent();
    SensorHalls hallsSensor = SensorHalls();
    
    int power, direction, speed = 0;
    int degrees = 0;
    float temperature = 0;

  private:
    Context *context;
    
    byte pin1;
    byte pin2;
    byte pin3;
    byte temperatureIndex;
    byte pin4;
    int pin5;
    int pin6;
    int pin7;

};

#endif