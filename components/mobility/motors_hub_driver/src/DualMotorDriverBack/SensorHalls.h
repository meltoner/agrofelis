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
    void setup(Context &_context, byte pin5, byte pin6, byte pin7, bool _opositeSpin );

    /*
    * Reads the SensorHalls 3 read values calls the process function computing a change of degree positive or negative.
    */
    void apply();

    /*
    * Converts the readings to a positive or negative move
    */    
    void processValue();

    void print();
    int rotations = 0;
    
    // hall sensor readings
    int a = 0;
    int b = 0;
    int c = 0;
    // One full revolutions is approximately 200 ticks
    long position = 0;

    // hall binary to int one direction moving sequence 4 6 2 3 1 5 4
    // mapping of that sequence to order such that the forth item corresponds to the 1st position.
    byte mapping[7] = {5, 3, 4, 1, 6, 2};

    // binnary to int conversion based on hall sensor values
    int intHall = 0;
    byte currentOrderedHall = 0;
    byte previousOrderedHall = 0;

    // error 1 out of range problem with adac"
    // error 2 invalid reading to account
    // error 0 no problem
    // error 3 skipping steps
    byte error = 0;
    bool opositeSpin = false;

  private:
    Context *context;
    byte pin1;
    byte pin2;
    byte pin3;
    
};

#endif
