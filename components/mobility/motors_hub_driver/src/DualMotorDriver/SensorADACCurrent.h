/*
  * SensorADACCurrent - Class for wrapping the functions conveying a current sensor and more specifically
  * the [ACS712 5A  Range Hall Current Sensor Module] The class extends the Sensor class to transform the value to amper based on the AC712 dynamics. 
  * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef SensorADACCurrent_h
#define SensorADACCurrent_h

#include "Arduino.h" 
#include "Context.h"
#include "Sensor.h"
#include "Context.h"

class SensorADACCurrent : public Sensor
{
  public:

    /* The function applies the following formula (2.5 - ((float)value * (5.0 / 1024.0) ) ) / 0.066 to the float value. 
    * The function moreover add and offset based on the maximoum negative read out after the formula has been applied.
    * Last the formula considers values less than 0.2 amper as zero to exlude the noise while on rest.    
    */    
    int apply();
    void setup(Context &_context, byte _pin);
    void readSensor();

    float current = 0;
  private:
    Context *context;
    float negativeOffset = 0;
};

#endif
