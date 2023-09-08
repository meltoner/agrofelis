/*
  TiltServo.h - Object representing a TiltServo actuating a servo motor tilting a lidar and a mpu 9250. The object can be initialised with a limited target range, as much as to tilt the TiltServo to desired position.
  The class was used with a TIANKONGRC RDS-8120 20KG ROBOT DIGITAL SERVO
  Author - Konstantinos Papageorgiou kp at rei.gr 2023 Agrofelis
*/

#ifndef TiltServo_h
#define TiltServo_h


#include <ESP32Servo.h>
#include "Context.h"

class TiltServo{
  public:
    // Create the object based on pwm pin and the minumum and maximum values corresponding to a release and a TiltServo respectively.
    TiltServo(int _pin, int _minimum, int _maximum);
    // The context references
    void setup(Context &_context);
    // peforms any actions such as to detache after one second of the actuation
    void apply();
    // sets the value of the servo
    void setTiltServo(int value);
    // reflects the intenal state of the actuator
    void print();

  private:
    int minimum = 0;
    int maximum = 180;
    int pin;
    int value = 0;
    Servo servo;
    Context *context;
};

#endif