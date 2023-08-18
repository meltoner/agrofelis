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
    void setup(byte _pin);
    virtual void readSensor();
    /*
    * Reads the sensor read value, calls the process function computing the sensor value, records the values as the previous value for the next call.
    * The function moreover determines if the sensor value has sufficient difference to mark the sensor as moving.
    */
    int apply();

    /*
    * The function read raw value, updates the sensor value, determines if its moving and upldates the previous value variable.
    * Default implementation determines how much change to keep based on the previous value recorded and their difference.
    */
    
    void processValue();

    void print();
    
    int read = 0;
    int value = 0;
    int prevValue = 0;
    bool moving = false;

    byte pin;
  private:
    
};

#endif
