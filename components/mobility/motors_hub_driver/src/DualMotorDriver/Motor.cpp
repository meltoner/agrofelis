
#include "Arduino.h"
#include "Motor.h" 

#include "Context.h"

Motor::Motor(
    byte _pin1, byte _pin2, byte _pin3, byte _pin4, 
    byte _temperatureIndex, 
    byte _pin5, byte _pin6, byte _pin7, 
    bool _opositeSpin,
    unsigned int _maxSpeed
  ){
  pin1 = _pin1;
  pin2 = _pin2;
  pin3 = _pin3;
  temperatureIndex = _temperatureIndex;
  pin4 = _pin4;
  pin5 = _pin5;
  pin6 = _pin6;
  pin7 = _pin7;
  opositeSpin = _opositeSpin;
  maxSpeed = _maxSpeed;
}

void Motor::setup(Context &_context){
  context = &_context;
  hallsSensor.setup(*context, pin5, pin6, pin7, opositeSpin);

  pinMode(pin1, OUTPUT); // POWER MOTOR  
  pinMode(pin2, OUTPUT); // DIRECTION MOTOR  
  pinMode(pin3, OUTPUT); // SPEED MOTOR
  
  currentSensor.setup(*context, pin4);

  setPower(power);
  setDirection(direction);
  setSpeed(speed);

  apply();
}

void Motor::setPower(int value){
  digitalWrite(pin1, value>0?HIGH:LOW);
  power = value;
}

void Motor::setDirection(int value){
  
  if(!opositeSpin)
    digitalWrite(pin2, value > 0 ? HIGH:LOW);
  else
    digitalWrite(pin2, value > 0 ? LOW:HIGH);

  direction = value;
}

void Motor::setSpeed(int value){
  if(hallsSensor.error != 0)
    value = 0;

  speedStart = intermediateSpeed;
  speedDiff = value - speedStart;
  targetSet = millis();

  speed = value;
}

void Motor::applySpeed(){
  // Motor driver requires progressive change of throttle otherwise won't follow it.
  // here we impose any change to be applied progressivelly over a time span that will
  // always be followed by the motor driver and the motor.

  if(speed != intermediateSpeed ){
    unsigned long timePassed = (millis() - targetSet);
    
    if(timePassed > applyWithin){
      intermediateSpeed = speed;     
    }else{
      intermediateSpeed = speedStart + (int)(((float)(speedDiff)) * ((float)timePassed/(float)applyWithin));
    }
    analogWrite(pin3, map(intermediateSpeed, 0, 100, 0, maxSpeed));
  }
  
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
      hallsSensor.error + ";" +
      intermediateSpeed + ">"
  );

}
