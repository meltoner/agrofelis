/**
 * SteeringDriver Class wrapping the functions operating the linear actuators of the SteeringDrivering module
 * The class holds the linear actuator references their Ackerman mappings steps and the means to interpolate their ratios on a -100 to 100 positioning.
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023  Agrofelis
 */

#ifndef SteeringDriver_h
#define SteeringDriver_h

#include "Context.h"
#include "LinearActuator.h"
#include "Interpolate.h"

class SteeringDriver{
  public:
    SteeringDriver();
    // initialisation function
    void setup(Context &_context);
    // Triggers the motors apply function
    void apply();
    // Reflects the internal state of the module and its sub modules
    void print();
    // Set the desired position of the steering / linear actuators to be derived to Ackerman positions
    void setPosition(int position);
    // Alters the state of the left module
    void setLeftState(int state);
    // Alters the state of the right module
    void setRightState(int state);
    // Alters the state of both modules
    void setState(int state);
    // Set the desired position of the left module
    void setLeftPosition(int position);
    // Sets the desired position of the right module
    void setRightPosition(int position);

    int status = 0;

    // Left wheel // identifier | IN1 1 | IN2 8 | potentiometer 13 | current A0 | direction A1 | direction | offset
    LinearActuator linearLeft = LinearActuator::LinearActuator(1, 12, 8, A0, A1,  1,  12);

    // Right wheel // identifier | IN1 2 | IN2 10 | potentiometer 11 | current A2 | direction | offset
    LinearActuator linearRight = LinearActuator::LinearActuator(2, 10, 11, A2, A3, -1, -5);

  private:
    // requested synced position to apply
    int syncedPosition = 0;
    // Position of left and right module based on the ackerman geometry
    float leftPosition = 0;
    float rightPosition = 0;

    // The length of the input ouput mappings samples
    const byte mappingSize = 11;

    // Mappings corresponding to input value and left and right positions such that the 
    // Ackerman geometry is followed based on the actual fabrication of the vehicle.

    float inputValue[11] = {-100, -78.6, -59.5, -36.9, -16.7, 0, 10.7, 44, 63.1, 81, 100};
    int outputLeft[11] = {5, 15, 25, 35, 45, 50, 54, 67, 73, 78, 84};
    int outputRight[11] = {11, 19, 25, 34, 41, 50, 55, 70, 80, 90, 100};
    
    // the position range in the mappings best matching the desired input.
    int inputIndex = 0;

    Interpolate leftMap  = Interpolate::Interpolate(mappingSize, inputValue, outputLeft);
    Interpolate rightMap = Interpolate::Interpolate(mappingSize, inputValue, outputRight);

    Context *context;
};

#endif