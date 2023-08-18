
#include "Arduino.h"
#include "Brake.h"
#include <Servo.h>
#include "Context.h"

Brake::Brake(byte _pin, int _minimum, int _maximum){  
  pin = _pin;
  minimum = _minimum;
  maximum = _maximum;
}

void Brake::setup(Context &_context){
  context = &_context;
  servo.attach(pin);
  setBrake(0);
}

void Brake::setBrake(int _value){  
    value = _value;
    servo.write(map(_value, 0, 100, minimum, maximum));
}

void Brake::apply(){}

void Brake::print(){
  Serial.print(F("<Brake"));
  Serial.print(pin);
  Serial.print(F(";"));
  Serial.print(value);
  Serial.print(F(">"));
}