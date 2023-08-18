/*
  Brake.h - Object representing a wheel brake actuating a servo motor. The object can be initialised with a limited target range, as much as to lift the brake.
  The class was used with a  TIANKONGRC RDS-8120 20KG ROBOT DIGITAL SERVO
  Author - Konstantinos Papageorgiou kp at rei.gr 2023 Agrofelis
*/

#ifndef Brake_h
#define Brake_h

#include "Arduino.h"
#include <Servo.h>
#include "Context.h"

class Brake{
  public:
    // Create the object based on pwm pin and the minumum and maximum values corresponding to a release and a brake respectively.
    Brake(byte _pin, int _minimum, int _maximum);
    // The context references
    void setup(Context &_context);
    // peforms any actions such as to detache after one second of the actuation
    void apply();
    // sets the value of the servo
    void setBrake(int value);
    // reflects the intenal state of the actuator
    void print();

  private:
    int minimum = 0;
    int maximum = 180;
    byte pin;
    int value = 0;
    Servo servo;
    Context *context;
};

#endif