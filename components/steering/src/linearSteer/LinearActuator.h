/*
 * LinearActuator.h - Library for wrapping the functions controlling and sensing a linear actuator.
 * Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
 *
 * The class is initialised with the following board port mappings. 
 * The first two control the direction and speed of the [DRV8871 H-Bridge Brushed DC Motor Driver] using two pwm ports. 
 * The next the analogue [LinearActuator Potentiometer B10K Ohm] and the analogue [ACS712 5A  Range Hall Current Sensor Module].
 *
 * The module operates based on 4 states dictating its function. On states one and two, the min and max potentiometer bounds are identified.
 * On state three, the minimum throttle leading to a movement is derived. On state four the object enters when its objective position has been achieved. 
 * On state five, the object reaches to the target position. States 10 and 11 correspond to erroneous states, such when an 
 * actuation is not detected when its expected or when the sensor value reads values close to its physical values.
 *
 * The module's regular update frequency is 100 ms
 * 
 * An example of its print out 
 * <LinearActuator:2;4;50;0;0;0.00>
 * Translating to 
 * LinearActuator 2 (right side) at 
 * state 4 (target reahed) 
 * at position 50, from 0 to 100
 * with distance from target 0
 * running at speed 0
 * comsuming 0 amper.
 *
 *  <LinearActuator:2;5;11;19;74;1.04>
 *  Likewise this translates to right linear, at target seeking state to reach position 11, having distance 19 from it
 *  moving at speed 74 out of 100, consuming 1 amper.
*/

#ifndef LinearActuator_h
#define LinearActuator_h
#include "Sensor.h"
#include "SensorCurrent.h"
#include "Context.h"

class LinearActuator{
  public:

    /*
    * Constructor setting the input and outputs of the linear actuator module, its driver and its sensors.
    *
    * @param _identifier 1 left or 2 right
    * @param _pinA motor driver IN1 pwm
    * @param _pinB motor driver IN2 pwm
    * @param _pinC analogue potentiometer input
    * @param _pinD analogue current sensor input
    * @param _direction direction [1,-1] 
    * @param _offset offset from center [-100,100] allow corrective tolerances
    *
    */
    LinearActuator(int _identifier, int _pinA, int _pinB, int _pinC, int _pinD, int _direction, int _offset);
    void setup(Context &_context);

    /*
     * The module operates based on 4 states dictating its function. On states one and two, the min and max potentiometer bounds are identified.
     * On state three, the minimum throttle leading to a movement is derived. On state four the object enters when its objective position has been achieved. 
     * On state five, the object reaches to the target position. States 10 and 11 correspond to erroneous states, such when an 
     * actuation is not detected when its expected or when the sensor value reads values close to its physical values.
     */    
    void apply();
    
    /*
    * Alter the state of the actuator.
    */
    void changeState(int _state);
    
    /*
    * Sets a desired target to be reached
    */
    void setTarget(int target);
    
    /*
     * Controls the direction and raw speed of the linear motor constrained to +/- 255
     */
    void move(int speed);
    
    /*
    * Based on the desired speed, applies incremental changes to reach it.
    */
    void applyMove();
    
    /*
    * Reflects the internal state of the module
    */
    void print();
    
    /*
    * Actuates a speed by inputting a value from a 0 to 100 range. 
    * The raw value is mapped based on the min speed that lead to a feedback sensor difference.
    */    
    void throttle(int speed);

    /*
    * Sets the target potentiometer value, by inputting a 0 to 100 range mapped 
    * based on the min and max value of the feedback sensor detected at boot up. 
    */
    void setPosition(int pos);

    /*
    * Derives the distance from target position and adjusts according the direction and throttle to reach it.
    */
    void seekPosition();
    
    /*
    * Tracks the distance from the target, to be within a small threshold otherwises changes the state of the module to seek it
    */
    void maintainPosition();

    /*
    * Progressively raises the speed leading to a 40 positional difference thus finding the minimum value required to move the actuator.
    */
    void determineMinimumSpeed();
    
    /*
    * Determines the min or max potentiometer value according to the orientation / direction of the actuator.
    */
    void findPositionalBoundsFirst();
    /*
    * Determines the min or max potentiometer value according to the orientation / direction of the actuator.
    */
    void findPositionalBoundsSecond();

    /*
    * Sets the minimum maximum potentiometer values as well as the minimum speed to achieve movement.
    * These settings are auto-derived using the initialization sequence, but can also be preset using this function.
    */
    void setBoundSettings(int _minPot, int _maxPot, int _minSpeed);
    
    /*
    * The function calculates the difference between the target potentiometer and the actual.
    * It moreover calculates the absolute difference and its projection to 0-100 based on the min and max potentiometer values.
    */
    void computeDistance();

    Sensor potentiometerSensor = Sensor::Sensor();
    SensorCurrent currentSensor = SensorCurrent::SensorCurrent();

    int state = 0;    
    int normPosition = 0;
    
    float accumulatedSpeed=0;
    float completion = 0;

    int normSpeed = 0;
    int normDistance = 0;
    int offset = 0;
    
    int potentiometer, previousPotentiometer, potentiometerSpeed, rawSpeed  = 0;    
    float boostSpeed = 1;

    int minPot = 0;
    int maxPot = 0;

    int minSpeed = 0;
    int maxSpeed = 255;

    unsigned long timeSinceStateChange = 0;
  private:
    int identifier;
    int pinA;
    int pinB;
    int pinC;
    int pinD;
    int direction;
    Context *context;
    
    double gate = 1.0;
    unsigned long stateChanged = millis();

    int current = 0;
    int targetPotentiometer = 512;
    int potentiometerStarting = 512;
    int diff,absdiff = 0;

    int initialSpeed = 150;
    int appliedSpeed = 0;

};

#endif
