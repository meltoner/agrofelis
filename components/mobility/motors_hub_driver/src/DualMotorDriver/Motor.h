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
    // power, direction, speed, current, onewire temperature index, and hall a, hall b , hall c accessed via the adac module
    // followed by the physical direction of the wheel. symetrical will have oposite spins by default.
    // last the max speed can be set to syncronise two motors such the same input speed corresponds to equal/synchronised 
    // end speed wheel rotation

    Motor(byte _pin1, byte _pin2, byte _pin3, byte pin4, 
          byte _temperatureIndex, 
          byte _pin5, byte _pin6, byte _pin7, 
          bool _opositeSpin, unsigned int _maxSpeed );

    void setup(Context &_context);
    // reads the halls sensor positioning info
    void fastApply();
    //  applies the desired speed, reads the temperature, reads the current sensor
    void apply();
    // progressively applies the desired speed
    void applySpeed();
    // sets the desired position for the motor.
    void moveToPosition(long position);
    // applies the speed or moves until desired speed is achieved
    void applyPosition();

    // Performs all check to see if the motor is ok to Run
    bool isRunnable();

    void print();

    //int 0 or 1 // boolean
    void setPower(int value);
    
    //int 0 or 1 // boolean
    void setDirection(int value);

    // Set speed input value 0-100. the value is the mapped to the range 0-255
    void setSpeed(int value);

    SensorADACCurrent currentSensor = SensorADACCurrent();
    SensorHalls hallsSensor = SensorHalls();
    
    int status = 0;
    
    unsigned long targetSet = millis();
    unsigned long positionChecked = millis();

    int speedStart = 0;
    int speedDiff = 0;

    unsigned int applyWithin = 500;
    unsigned int maxSpeed = 255;

    int power, 
        direction,
        intermediateSpeed, 
        speed, rawSpeed = 0;

    float topOnSpeed = 0; 

    int degrees = 0;
    float temperature = 0;
    int initialDirection = 0;
    long targetPosition = 0;

    //-------------
    
    int hallsSpeed = 0;
    long previousPosition = 0;

    int targetPositionDiff, previousTargetPositionDiff, predictedDifference, boostSpeed = 0;
    float predictionError = 0;
    int corretiveSpeed = 0;
    
    const int thresholdMaxCurrent  = 15;
    const int thresholdMaxTemperature = 50;

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
    bool opositeSpin = false;

};

#endif