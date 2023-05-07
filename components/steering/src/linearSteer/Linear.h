/*
  Linear.h - Library for wraping the functions controling the Linear 
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef Linear_h
#define Linear_h
#include "Sensor.h"
#include "Context.h"

class Linear{
  public:
    Linear(int _identifier, int _pinA, int _pinB, int _pinC, int _pinD, int _direction, int _offset);
    void setup(Context &_context);    
    void apply();
    void changeState(int _state);
    void setTarget(int target);
    void move(int speed);
    void applyMove();
    void print();
    
    void throttle(int speed);
    void position(int pos);

    Sensor sensor = Sensor::Sensor();

    // Writable and readable    
    int state = 0;
    
    int normPosition = 0;

    // redable only
    int normSpeed = 0;
    int normDistance = 0;
    // amper
    int offset = 0;

  private:
    int identifier;
    int pinA;
    int pinB;
    int pinC;
    int pinD;
    int direction;
    Context *context;

    unsigned long stateChanged = millis();
    unsigned long timeSinceStateChange = 0;

    int potentiometer = 0;
    int targetPotentiometer = 512;
    int potentiometerStarting = 512;
    int diff = 0; 
 
    int minPot = 0;
    int maxPot = 0;

    int minSpeed = 0;
    int maxSpeed = 255;

    int initialSpeed = 150;
    int appliedSpeedPrevious = 0;
    int appliedSpeed = 0;

};

#endif
