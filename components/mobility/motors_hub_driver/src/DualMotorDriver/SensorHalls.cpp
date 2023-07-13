/*
 * SensorHalls - Class wrapping the functions conveying a SensorHalls 
 * Reads an analogue port when apply is called. 
 * Maintains a gated smoothing read out of the SensorHalls by comparing the previous mean with with current read value.
 * Moreover, maintains a boolean flag, when a movement is being detected based on the absolute difference of the first derivative.
 * Last, it prints out the object internal state, on print() reflecting the SensorHalls's port, its smoothed value, its un-smoothed 
 * SensorHalls value and last if the SensorHalls is detecting a movement.
 * A print example of a SensorHalls <SensorHalls:56;372;373;0> port 56, processed value 372, raw value 373, no movement detected.
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#include "SensorHalls.h" 


SensorHalls::SensorHalls(){}

void SensorHalls::setup(Context &_context, byte _pin1, byte _pin2, byte _pin3){
  context = &_context;
  pin1 = _pin1;
  pin2 = _pin2;
  pin3 = _pin3;
  apply();
}

void SensorHalls::processValue(){
  //print();
  //Serial.println("");
}

void SensorHalls::apply(){
  a = context->adac.get(pin1);
  b = context->adac.get(pin2);
  c = context->adac.get(pin3);
  processValue();
}

void SensorHalls::print(){
  Serial.print(F("<SensorHalls")); 
  Serial.print(pin1);
  Serial.print(F(";"));

  Serial.print(a);
  Serial.print(F(";"));
  Serial.print(b);
  Serial.print(F(";"));
  Serial.print(c);
  Serial.print(F(">"));
}
