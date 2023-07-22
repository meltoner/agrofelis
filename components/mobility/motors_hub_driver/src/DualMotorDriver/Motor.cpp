
#include "Arduino.h"
#include "Motor.h" 

#include "Context.h"

Motor::Motor(byte _pin1, byte _pin2, byte _pin3, byte _pin4, byte _temperatureIndex, byte _pin5, byte _pin6, byte _pin7){
  pin1 = _pin1;
  pin2 = _pin2;
  pin3 = _pin3;
  temperatureIndex = _temperatureIndex;
  pin4 = _pin4;
  pin5 = _pin5;
  pin6 = _pin6;
  pin7 = _pin7;
}

void Motor::setup(Context &_context){
  context = &_context;
  hallsSensor.setup(*context, pin5, pin6, pin7);  
  pinMode(pin1, OUTPUT); // POWER MOTOR  
  pinMode(pin2, OUTPUT); // DIRECTION MOTOR  
  pinMode(pin3, OUTPUT); // SPEED MOTOR
  currentSensor.setup(*context, pin4);
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
  analogWrite(pin3, map(value, 0, 100, 0, 255));
  speed = value;
}

void Motor::fastApply(){
  hallsSensor.apply();  
}

void Motor::apply(){  
  currentSensor.apply();
  temperature = context->temperatures[temperatureIndex];
}

void Motor::print(){
  String result = "<Motor";
  context->appendMessage(
    result + pin1 + ";" + power + ";" + direction + ";" + speed + ";" +
      currentSensor.current + ";" + temperature + ";" +

      hallsSensor.a + ";" + hallsSensor.b + ";" + hallsSensor.c + ";" +
      
      hallsSensor.position + ";" +
      hallsSensor.error + ">"
  );

}
