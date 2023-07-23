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

void SensorHalls::setup(Context &_context, byte _pin1, byte _pin2, byte _pin3, bool _opositeSpin ){
  context = &_context;
  pin1 = _pin1;
  pin2 = _pin2;
  pin3 = _pin3;  
  opositeSpin = _opositeSpin;
  apply();
}

void SensorHalls::processValue(){  
  currentOrderedHall = mapping[intHall - 1];
  if(currentOrderedHall != previousOrderedHall){

    int difference = currentOrderedHall - previousOrderedHall;

    int tik = 0;
    if(difference == 1)
      tik = -1;
    else 
      if(difference == -1)
        tik = 1;
      else
        if(difference < -5)
          tik = -1;
        else
          error = 3;

    if(opositeSpin)
      tik = tik * -1;

    position += tik;

    previousOrderedHall = currentOrderedHall;    
  }

}

void SensorHalls::apply(){
  // Get Readings
  a = context->adac.get(pin1);
  b = context->adac.get(pin2);
  c = context->adac.get(pin3);

  if(a > 1200 || b > 1200 || c > 1200){
    error = 1; // "out of range problem with adac"
  }else{
    // Threshold binary to int
    intHall = 0;
    if(a > 100)intHall += 4;
    if(b > 100)intHall += 2;
    if(c > 100)intHall += 1;

    if(intHall == 0 || intHall == 7){
      error = 2; // invalid reading to account
    }else{
      error = 0;
      processValue();
    }
  }
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
  Serial.print(F(";"));
  Serial.print(position);
  Serial.print(F(">"));
}
