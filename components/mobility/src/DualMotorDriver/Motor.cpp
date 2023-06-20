
#include "Arduino.h"
#include "Motor.h" 

#include "Context.h"

Motor::Motor(byte _pin1, byte _pin2, byte _pin3, byte pin4, byte _temperatureIndex, byte pin5, byte pin6, byte pin7 ){
  pin1 = _pin1;
  pin2 = _pin2;
  pin3 = _pin3;
  temperatureIndex = _temperatureIndex;
  
  currentSensor.setup(pin4);
  hallsSensor.setup(pin5, pin6, pin7);
}

void Motor::setup(Context &_context){
  context = &_context;

  // POWER MOTOR
  pinMode(pin1, OUTPUT);

  // DIRECTION MOTOR
  pinMode(pin2, OUTPUT);

  // DIRECTION MOTOR
  pinMode(pin3, OUTPUT);  

  apply();
}

void Motor::setPower(int value){
  digitalWrite(pin1, value);
  power = value;
}

void Motor::setDirection(int value){
  digitalWrite(pin2, value);
  direction = value;
}

void Motor::setSpeed(int value){
  digitalWrite(pin3, map(value, 0, 100, 0, 255));
  speed = value;
}

void Motor::apply(){
  hallsSensor.apply();  
  currentSensor.apply();
  temperature = context->temperatures[temperatureIndex];
}

void Motor::print(){
  String result = "<Motor";
  context->appendMessage(
    result + pin1 + ";" + power + ";" + direction + ";" + speed + ";" + currentSensor.current + ";" + temperature + ";" + hallsSensor.a + ";" + hallsSensor.b + ";" + hallsSensor.c + "" + ">"
  );

}
