/*
  SteerControl.h - Library for wraping the functions controling the SteerControl 
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef SteerControl_h
#define SteerControl_h

#include "Context.h"
#include "Linear.h"

class SteerControl{
  public:
    SteerControl();
    void setup(Context &_context);
    void apply();
    void print();
  private:
    Context *context;
    Linear linearA = Linear::Linear(1, 10, 11, A2, A3, -1, -5); // right // IN1 | IN2 | potentiometer | current | direction | offset
    Linear linearB = Linear::Linear(2, 12, 13, A0, A1,  1,  8); // left  // IN1 | IN2 | potentiometer | current | direction | offset
};

#endif