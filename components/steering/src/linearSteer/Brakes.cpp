
#include "Arduino.h"
#include "Brakes.h"
#include "Brake.h"
#include <Servo.h>
#include "Context.h"

Brakes::Brakes(){}

void Brakes::setup(Context &_context){
  context = &_context;
  brakeLeft.setup(*context);
  brakeRight.setup(*context);
  setBrake(0);
}

void Brakes::setBrake(int _value){  
    value = _value;
    brakeLeft.setBrake(value);
    brakeRight.setBrake(value);
} 

void Brakes::print(){
  Serial.print(F("<Brakes"));
  Serial.print(value);
  Serial.print(F(">"));
  brakeLeft.print();
  brakeRight.print();
}