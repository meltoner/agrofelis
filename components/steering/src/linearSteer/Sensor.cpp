/*
  Sensor - Class for wrapping the functions conveying a sensor 
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
  Reads an analogue port when apply is called. 
  Maintains a gated smoothing read out of the sensor by comparing the previous mean with with current read value.
  Moreover, maintains a boolean flag, when a movement is being detected based on the absolute difference of the first derivative.
  Last, it prints out the object internal state, on print() reflecting the sensor's port, its smoothed value, its un-smoothed 
  sensor value and last if the sensor is detecting a movement.
  Example
  <Sensor:56;372;373;0>
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

int Sensor::apply(){
  read = analogRead(_pin);

  // Smoothing function
  float keep = 1;
  int absdiff = abs(read - value);  
  if(absdiff > 10)
    keep = 4;
  else 
    if(absdiff > 50)
      keep = 0.1;

  value = (value * ( (10.0 - keep ) / 10.0) + read * (keep / 10.0) );
  value = (read + value) / 2;
  
  // Smoothing function

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
