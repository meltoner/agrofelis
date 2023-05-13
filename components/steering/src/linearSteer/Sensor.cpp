/*
 * Sensor - Class wrapping the functions conveying a sensor 
 * Reads an analogue port when apply is called. 
 * Maintains a gated smoothing read out of the sensor by comparing the previous mean with with current read value.
 * Moreover, maintains a boolean flag, when a movement is being detected based on the absolute difference of the first derivative.
 * Last, it prints out the object internal state, on print() reflecting the sensor's port, its smoothed value, its un-smoothed 
 * sensor value and last if the sensor is detecting a movement.
 * A print example of a sensor <Sensor:56;372;373;0> port 56, processed value 372, raw value 373, no movement detected.
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#include "Sensor.h" 
#include "Context.h"

Sensor::Sensor(){}

void Sensor::setup(int pin_){
  _pin = pin_;
  pinMode(_pin, INPUT);
  read = analogRead(_pin);
  apply();
}

void Sensor::processValue(){
  
  float keep = 1; // 1/10
  int absdiff = abs(read - value);

  if(absdiff > 10)
    keep = 4; // 4/10

  value = (value * ( (10.0 - keep ) / 10.0) + read * (keep / 10.0) );
  value = (read + value) / 2;

}

int Sensor::apply(){
  read = analogRead(_pin);
  processValue();
  moving = abs(read - prevValue) > 2;
  prevValue = value;
  return value;
}

void Sensor::print(){
  Serial.print(F("<Sensor:")); 
  Serial.print(_pin);
  Serial.print(F(";"));
  Serial.print(value);
  Serial.print(F(";"));
  Serial.print(read);
  Serial.print(F(";"));
  Serial.print(moving);
  Serial.print(F(">"));
}
