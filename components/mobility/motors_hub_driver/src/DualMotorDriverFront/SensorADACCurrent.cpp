
#include "SensorADACCurrent.h"
#include "Context.h"

void SensorADACCurrent::setup(Context &_context, byte _pin){
  pin = _pin;
  context = &_context;
  apply(); 
}

void SensorADACCurrent::readSensor(){
  read = context->adac.get(pin);
}

int SensorADACCurrent::apply(){
  Sensor::apply();

  current = (2.5 - ((float)value * (5.0 / 1024.0) ) ) / 0.066 ;
    
  if(current < 0)
    negativeOffset = current;    

  current = current - negativeOffset;  

  if(current < 0.3)
    current = 0;

  if(maxCurrent < current)
    maxCurrent = current;
  else
    maxCurrent *= 0.98;  

  return value;
}
