/*
  LinearActuator.h - Library for wrapping the functions controlling and sensing a linear actuator.
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#include "LinearActuator.h" 
#include "Context.h"
#include "Sensor.h"

LinearActuator::LinearActuator(int _identifier, int _pinA, int _pinB, int _pinC, int _pinD, int _direction, int _offset){
  identifier = _identifier;

  if(_direction == -1){
    pinA = _pinA; //motor IN1
    pinB = _pinB; //motor IN2    
  }else{
    pinA = _pinB; //motor IN1
    pinB = _pinA; //motor IN2    
  }

  pinC = _pinC; //motor potentiometer
  pinD = _pinD; //motor current sensor
  
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);

  direction = _direction; 
  offset = _offset;
}

void LinearActuator::setBoundSettings(int _minPot, int _maxPot, int _minSpeed){
  minPot = _minPot;
  maxPot = _maxPot;
  minSpeed = _minSpeed;
}

void LinearActuator::setTarget(int target){
  targetPotentiometer = target;
  stateChanged = millis();
} 

void LinearActuator::setup(Context &_context){
  context = &_context;
  move(0);
  potentiometerSensor.setup(pinC);
  currentSensor.setup(pinD);
}

void LinearActuator::changeState(int _state){
  state = _state;
  stateChanged = millis();
  
  if(state == 3){
    targetPotentiometer = potentiometer;
    minSpeed = 0;
  }
}

void LinearActuator::apply(){

  potentiometer = potentiometerSensor.apply();
  timeSinceStateChange = millis() - stateChanged;
  potentiometerSpeed = potentiometer - previousPotentiometer;
  previousPotentiometer = potentiometer;

  // Check if the potentiometerSensor has reached its physical limits 
  if(potentiometer < 10 || potentiometer > 1010)
    state = 11;
  switch(state){
    case 0: 
      // standby uninitialized
      potentiometer = 0;
      targetPotentiometer = 512;
      potentiometerStarting = 0;
      appliedSpeed = 0;
      break;
    case 1:      
      findPositionalBoundsFirst();
      break;
    case 2:
      findPositionalBoundsSecond();
    break;
    case 3:      
      determineMinimumSpeed();       
    break;
    case 4:
      maintainPosition();
    break;
    case 5:
      seekPosition();
      break;
    case 10:
      //Serial.print("Error : Not moving on sufficient throttle");
      throttle(0);
      break;
    case 11:
      //Serial.print("Error : Reached potentiometerSensor limits");
      throttle(0);
      break;
  }

  if(state < 4){
    normPosition = 0;
    normDistance = 0;
    normSpeed = 0;
  }
  applyMove();
  current = currentSensor.apply();  
} 


// Based on the desired speed, applies incremental changes to reach it.
void LinearActuator::applyMove(){
  if(appliedSpeed == 0)
    normSpeed = 0;
  else
    normSpeed = map(abs(appliedSpeed), minSpeed, maxSpeed, 0, 100);    
  
  if(appliedSpeed >= 0){
    digitalWrite(pinA, LOW);
    analogWrite(pinB, abs(appliedSpeed));
  }else{
    digitalWrite(pinB, LOW);
    analogWrite(pinA, abs(appliedSpeed));
  }  
}

void LinearActuator::move(int speed){
  appliedSpeed = constrain(speed, -maxSpeed, maxSpeed);
}

void LinearActuator::throttle(int speed){    
  if(abs(speed) > 1)
    move(map(abs(speed), 0, 100, minSpeed, maxSpeed) * (speed > 0 ? 1: -1));
  else
  move( 0 );  
}

void LinearActuator::setPosition(int pos){
  normPosition = pos;
  int offseted = constrain(pos + offset, 0, 100);
  targetPotentiometer = map(offseted, 0, 100, minPot, maxPot );
  potentiometerStarting = potentiometer;  
  accumulatedSpeed = 0;
}

void LinearActuator::computeDistance(){
  diff = targetPotentiometer - potentiometer;
  normDistance = ((float)abs(diff) / (float)(maxPot - minPot)) * 100.0;  
  completion = 1.0 - (abs( (float)(targetPotentiometer - potentiometer - potentiometerSpeed) / (float)(targetPotentiometer - potentiometerStarting)) );
  if(completion < 0) completion = 1;
}

void LinearActuator::seekPosition(){
  computeDistance();  
  accumulatedSpeed += boostSpeed;

  if( abs(diff) >= 11 ){        
    gate = (timeSinceStateChange < 500) ? (timeSinceStateChange / 500):1;

    if(completion > 0.5 && potentiometerSpeed > 1)
      gate = 1 - completion;
    
    int speed = constrain(accumulatedSpeed, 0, 70);
    speed = speed * gate;
    
    throttle(speed * (diff > 0?1:-1));    
  }else{
    throttle(0);
    changeState(state - 1);     
  }
}

void LinearActuator::maintainPosition(){
  if(abs(targetPotentiometer - potentiometer) < 11){
    normDistance = 0;
    throttle(0);
  }else{
    changeState(state + 1);       
  }
}

void LinearActuator::findPositionalBoundsFirst(){
  if(timeSinceStateChange < 3000 || potentiometerSensor.moving == 1){
    move(direction * initialSpeed);
  }else{
    if(direction == 1)
      maxPot = potentiometerSensor.value - direction * 10;
    else
      minPot = potentiometerSensor.value + direction * 10;
    changeState(state + 1);
  }
}

void LinearActuator::findPositionalBoundsSecond(){
  if(timeSinceStateChange < 3000 || potentiometerSensor.moving == 1){
    move(-direction * initialSpeed);
  }else{
    if(direction == 1)
      minPot = potentiometerSensor.value + direction * 5;
    else
      maxPot = potentiometerSensor.value - direction * 5;
    changeState(state + 1);    
  }
}

void LinearActuator::determineMinimumSpeed(){  
   if(abs(targetPotentiometer - potentiometer) < 30){
     minSpeed = minSpeed + 5;  
     if(minSpeed > 200){        
        changeState(10);// no movement detected            
        move(0);
        return;
     }
     move(direction * minSpeed);
   }else{
       changeState(state + 1);
       throttle(0);       
       setPosition(50);
   }
}

void LinearActuator::print(){
  Serial.print(F("<LinearActuator")); 
  Serial.print(identifier);
  Serial.print(F(";"));
  Serial.print(state);  

  Serial.print(F(";"));
  Serial.print(normPosition);

  Serial.print(F(";"));
  Serial.print(normDistance);
  Serial.print(F(";"));  
  Serial.print(completion);

  Serial.print(F(";"));
  Serial.print(normSpeed);
  Serial.print(F(";"));
  Serial.print(potentiometerSpeed);
  Serial.print(F(";"));

  
  Serial.print(currentSensor.current); 
  Serial.print(F(";"));
  Serial.print(currentSensor.maxCurrent);
  Serial.print(F(";"));
  Serial.print(minPot);
  Serial.print(F(";"));
  Serial.print(maxPot);
  Serial.print(F(";"));  
  Serial.print(minSpeed);
    
  Serial.print(F(">"));
  
}
