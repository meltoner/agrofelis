
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

bool Motor::isRunnable(){
  return ! (
    power == 0 ||
    //hallsSensor.error == 2 || // TODO should be lenient if its once every n times instead of disabling the check
    //hallsSensor.error == 1 || // problematic if for few ms there is an error all will be powered off. 
    temperature > thresholdMaxTemperature ||
    currentSensor.maxCurrent > thresholdMaxCurrent);
}

void Motor::setPower(int value){
  setSpeed(0);
  status = 0;
  power = value;
  digitalWrite(pin1, power > 0 ? HIGH : LOW);
}

void Motor::setDirection(int value){  
  if(!opositeSpin)
    digitalWrite(pin2, value > 0 ? HIGH:LOW);
  else
    digitalWrite(pin2, value > 0 ? LOW:HIGH);

  direction = value;
}

void Motor::setSpeed(int value){
  
  speedStart = intermediateSpeed;
  speedDiff = value - speedStart;

  applyWithin = abs(speedDiff) * 30; //(100 diff in 3000ms )

  // if braking do it faster
  if(speedDiff < 0)
    applyWithin = applyWithin * 0.4;
  
  targetSet = millis();

  speed = value;
}

void Motor::applySpeed(){
  // Motor driver requires progressive change of throttle otherwise won't follow it.
  // here we impose any change to be applied progressivelly over a time span that will
  // always be followed by the motor driver and the motor.

  if(status != 0)
    return;
  
  hallsSpeed = previousPosition - hallsSensor.position;
  previousPosition = hallsSensor.position;

  if(speed > 10 && abs(hallsSpeed) < map(speed, 11, 100, 2, 10)){
    intermediateSpeed++;
  }else{
    if(speed == 0)
      intermediateSpeed = intermediateSpeed * 0.5;
  }
  
  intermediateSpeed = constrain(intermediateSpeed, 0, 100);
//  if(speed != intermediateSpeed ){
//    unsigned long timePassed = (millis() - targetSet);
//    if(timePassed > applyWithin)
//      intermediateSpeed = speed;     
//    else
//      intermediateSpeed = speedStart + (int)(((float)(speedDiff)) * ((float)timePassed / (float)applyWithin));
//  }

//  if(currentSensor.maxCurrent > thresholdMaxCurrent * 0.7 )
//    intermediateSpeed *= 0.8;
//
//  if(currentSensor.maxCurrent > thresholdMaxCurrent * 0.5 )
//    intermediateSpeed *= 0.9;

  rawSpeed = intermediateSpeed;

  // add motors synchronisation factor externally set
  if(intermediateSpeed > 0)
    rawSpeed += topOnSpeed;

  rawSpeed = constrain(rawSpeed, 0, 100);

  // set voltage just before motor begin to rotate. 255 should be 3.3v 90 should be 1.16v
  rawSpeed = map(rawSpeed, 0, 100, 90, maxSpeed);
  analogWrite(pin3, rawSpeed);

}

void Motor::moveToPosition(long position){
  hallsSensor.position = 0;  
  targetPosition = position;
  boostSpeed = 0;

  //retain the direction of the motor before asking to reach a particular position
  if(status == 0)
    initialDirection = direction;

  // change statis of motor to reach a particular position
  status = 1;
}

void Motor::applyPosition(){
  if(status == 1 && (context->now - positionChecked) > 300){        
    positionChecked = context->now;

// todo should account in the predictedDifference value the asked speed since we know it
// or could account what was the previous predictedDifference value and how far it was off.
// to weight accordingly. currently static 0.8

    targetPositionDiff = -(targetPosition - hallsSensor.position);    
    predictedDifference = (targetPositionDiff - previousTargetPositionDiff);
    previousTargetPositionDiff = targetPositionDiff;

    targetPositionDiff = constrain(targetPositionDiff, -500, 500);
    targetPositionDiff += predictedDifference * constrain(targetPositionDiff, -100, 100) / 50.0;

    if(((direction == 0 ? 1 : -1) * targetPositionDiff) < 0){
      // must change direction
      if(intermediateSpeed > 0 || hallsSpeed != 0 ){
        if(speed != 0)
          setSpeed(0);
        corretiveSpeed = 0;
        return; // exit
      }else{
        boostSpeed = 0;
        setDirection(direction == 0 ? 1 : 0);
      }     
    }
    
    if(abs(predictedDifference) < 2)
      boostSpeed += 2;
      
    if(currentSensor.maxCurrent > (thresholdMaxCurrent * 0.7))
      boostSpeed *= 0.7;

    if(abs(targetPosition - hallsSensor.position) > 6)
      corretiveSpeed = 5 + boostSpeed + (int)((float)abs(targetPositionDiff) / 9)  ;
    else 
      corretiveSpeed = 0;

     corretiveSpeed = constrain(corretiveSpeed, 0, 60);
    
    if(corretiveSpeed > 0){
      setSpeed( corretiveSpeed );
    }else{
      // reached position
      corretiveSpeed = 0;
      status = 0;
      boostSpeed = 0;
      setSpeed(0);
      setDirection(initialDirection);
    }
  }
}

void Motor::fastApply(){
  if(power == 1)
    hallsSensor.apply();  
}

void Motor::apply(){
  applyPosition();
  currentSensor.apply();
  temperature = context->temperatures[temperatureIndex];
}

void Motor::print(){
  String result = "<Motor";
  context->appendMessage(
    result + context->identifier + pin1 + ";" + power + ";" + direction + ";" + speed + ";" +
      currentSensor.current + ";" + currentSensor.maxCurrent + ";"+ temperature + ";" +
      //hallsSensor.a + ";" + hallsSensor.b + ";" + hallsSensor.c + ";" +      
      intermediateSpeed + ";" +
      hallsSpeed + ";" +
      hallsSensor.position + ";" +
      hallsSensor.error + ";" +
      topOnSpeed + ";" +
      rawSpeed + ";" +
      status + ";" +
      targetPositionDiff + ";" +
      corretiveSpeed + ";" +
      applyWithin + ";" +
      ">"
  );

}
