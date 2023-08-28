
#include "TiltServo.h"
#include "Context.h"

TiltServo::TiltServo(int _pin, int _minimum, int _maximum){  
  pin = _pin;
  minimum = _minimum;
  maximum = _maximum;
}

void TiltServo::setup(Context &_context){
  context = &_context;
  servo.setPeriodHertz(50);    // standard 50 hz servo
  servo.attach(pin, 500, 2400); // attaches the servo on pin 18 to the servo object
  setTiltServo(50);
}

void TiltServo::setTiltServo(int _value){  
    value = constrain(_value, 0, 100);
    servo.write(map(_value, 0, 100, minimum, maximum));
}

void TiltServo::apply(){}

void TiltServo::print(){
  Serial.print(F("<TiltServo"));
  Serial.print(pin);
  Serial.print(F(";"));
  Serial.print(value);
  Serial.print(F(">"));
}