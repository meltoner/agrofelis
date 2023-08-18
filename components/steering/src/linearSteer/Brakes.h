/*
  Brakes.h - Object representing two wheel brakes actuating by two servo motors.  
  Author - Konstantinos Papageorgiou kp at rei.gr 2023 Agrofelis
*/

#ifndef Brakes_h
#define Brakes_h

#include "Arduino.h"
#include <Servo.h>
#include "Context.h"
#include "Brake.h"

class Brakes{
  public:
    // Create the object controlling two servo motors as brakes
    Brakes();
    // The context references
    void setup(Context &_context);    
    // sets the value of the servos
    void setBrake(int value);
    // reflects the intenal state of the actuators
    void print();
    // The left back wheel brake
    Brake brakeLeft = Brake(6, 110, 76);
    // The right back wheel brake
    Brake brakeRight = Brake(7, 110, 76);
  private:
    int value = 0;
    Context *context;
};

#endif