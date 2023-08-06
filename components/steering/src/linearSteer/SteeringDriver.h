
/**
 * SteeringDriver Class wraping the functions operating the linear actuators of the SteeringDrivering module
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023  
 */

#ifndef SteeringDriver_h
#define SteeringDriver_h

#include "Context.h"
#include "LinearActuator.h"
#include "Interpolate.h"

class SteeringDriver{
  public:
    SteeringDriver();
    void setup(Context &_context);
    void apply();
    void print();
    void position(float position);
    int state = 0;

    LinearActuator linearLeft = LinearActuator::LinearActuator(1, 12, 13, A0, A1,  1,  12); // left  // IN1 | IN2 | potentiometer | current | direction | offset
    LinearActuator linearRight = LinearActuator::LinearActuator(2, 10, 11, A2, A3, -1, -5); // right // IN1 | IN2 | potentiometer | current | direction | offset

  private:

    const byte mappingSize = 11;

    float inputValue[11] = {-100, -78.6, -59.5, -36.9, -16.7, 0, 10.7, 44, 63.1, 81, 100};
    int outputLeft[11] = {5, 15, 25, 35, 45, 50, 54, 67, 73, 78, 84};
    int outputRight[11] = {11, 19, 25, 34, 41, 50, 55, 70, 80, 90, 100};
    
    Interpolate leftMap  = Interpolate::Interpolate(mappingSize, inputValue, outputLeft);
    Interpolate rightMap = Interpolate::Interpolate(mappingSize, inputValue, outputRight);

    int inputIndex = 0;
    Context *context;
};

#endif