/*
  Sensors.h - Library for wraping multiple Sensors inputs. More Specifically maping 4 potentiometers and three switches.
  Author - Konstantinos Papageorgiou kp at rei.gr 2023
*/

#ifndef Sensors_h
#define Sensors_h
//#include "Sensor.h" 
#include "Arduino.h" 
#include "Context.h"

class Sensors{
  public:
    Sensors();
    void setup(Context &_context);
    void readSensor();
    void detectChange();
    void apply();
    void print();
    //Sensor inputs[7];// = Sensor();
    int potentiometerPins[5] = {34, 39, 35, 32, 36};
    int togglePins[3] = { 16, 33}; // using also 36 joystic button but was noisy 

    int values[7] = {0, 0, 0, 0, 0, 0, 0};
    int prev_values[7] = {0, 0, 0, 0, 0, 0, 0};
    int compare_prev_values[7] = {0, 0, 0, 0, 0, 0, 0};
    bool togglePower = false;
    bool toggleSteeringMax = true;
    int joysticButtonAces = 0;
    int powerButtonAces = 0;


  private:
    Context *context;
};

#endif
