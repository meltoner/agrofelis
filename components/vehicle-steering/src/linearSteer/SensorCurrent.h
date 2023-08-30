/*
  * SensorCurrent - Class for wrapping the functions conveying a current sensor and more specifically
  * the [ACS712 5A  Range Hall Current Sensor Module] The class extends the Sensor class to transform the value to amper based on the AC712 dynamics. 
  * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef SensorCurrent_h
#define SensorCurrent_h

#include "Arduino.h" 
#include "Context.h"
#include "Sensor.h"

class SensorCurrent : public Sensor
{
  public:

    /* The function applies the following formula (2.5 - ((float)value * (5.0 / 1024.0) ) ) / 0.066 to the float value. 
    * The function moreover add and offset based on the maximoum negative read out after the formula has been applied.
    * Last the formula considers values less than 0.2 amper as zero to exlude the noise while on rest.    
    */    
    int apply();

    float current = 0;
    float maxCurrent = 0;
    
  private:
    float negativeOffset = 0;
};

#endif
