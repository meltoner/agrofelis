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

void LinearActuator::setTarget(int target){
  targetPotentiometer = target;
} 

void LinearActuator::setup(Context &_context){
  context = &_context;
  move(0);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  potentiometerSensor.setup(pinC);
  currentSensor.setup(pinD);
}

void LinearActuator::changeState(int _state){
  state = _state;
  stateChanged = millis();
}

void LinearActuator::apply(){

  potentiometer = potentiometerSensor.apply();

  timeSinceStateChange = millis() - stateChanged;

  // Check if the potentiometerSensor has reached its physical limits 
  if(potentiometer < 10 || potentiometer > 1010)
    state = 11;

  switch(state){
    case 0: 
      // standby uninitialized
        potentiometer = 0;
        targetPotentiometer = 512;
        potentiometerStarting = 0;
      break;

    case 1: // find bounds A potentiometer  
      if(timeSinceStateChange < 3000 || potentiometerSensor.moving == 1){
        move(-direction * initialSpeed);
      }else{

        if(direction == 1)
          minPot = potentiometerSensor.value + direction * 5;
        else
          maxPot = potentiometerSensor.value - direction * 5;

        changeState(state + 1);
        move(direction * initialSpeed);
      }
      break;

    case 2: // find bounds B potentiometer  
      if(timeSinceStateChange < 3000 || potentiometerSensor.moving == 1){
      }else{

        if(direction == 1)
          maxPot = potentiometerSensor.value - direction * 10;
        else
          minPot = potentiometerSensor.value + direction * 10;

        changeState(state + 1);
        targetPotentiometer = potentiometer;
      }
    break;

    case 3: // Find minimum speed leading to 40 value difference
       if(abs(targetPotentiometer - potentiometer) < 30){

         minSpeed = minSpeed + 5;
         // Protection no movement detected at sufficient speed
         if(minSpeed > 200){
            changeState(10);            
            move(0);
            break;
         }
         move(-direction * minSpeed);
       }else{
           changeState(state + 1);
           throttle(0);           
           //position(direction>0?0:100);
           position(50);
       }
    break;

    case 4: //if target has been reached
      if(abs(targetPotentiometer - potentiometer) < 11){
        normDistance = 0;
        throttle(0);
      }else{
          changeState(state + 1);       
      }
    break;

    case 5: // go to target
      diff = targetPotentiometer - potentiometer;
      int absdiff = abs(diff);

      normDistance = ((float)absdiff/(float)(maxPot-minPot))*100.0;//map(absdiff, 0, (maxPot-minPot), 0, 100);
      
      if( absdiff >= 11 ){        

        long timeDistance = millis() - stateChanged;
        double weight = 1.0;

        // Fade in first 2000 ms
        if(timeDistance < 2000)
          weight = timeDistance / 3000.0;
        
        // initial speed based on distance hard limited to 10-90
        int speed = constrain(absdiff, 10, 100);

        // reduce weight when surpassing half way
        if(absdiff < 80)
          weight = weight / 2;

        // Expand weight as time pass
        if(timeDistance > 3000)
          weight = weight + (double)(timeDistance-3000) / 15000.0;

        weight = constrain(weight, 0.1, 3);

        speed = (double)speed * weight;
        
        if(diff > 0)
          throttle(speed);
        else
          throttle(-speed);

      }else{
        throttle(0);
        changeState(state - 1);     
      }

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
  applyMove();
  current = currentSensor.apply();
  current = currentSensor.apply();
} 


void LinearActuator::move(int speed){
  appliedSpeed = constrain(speed, -maxSpeed, maxSpeed);
}

// Based on the desired speed, applies incremental changes to reach it.
void LinearActuator::applyMove(){

  if(appliedSpeed == 0)
    appliedSpeedPrevious = 0;
  else
    appliedSpeedPrevious = ((float)appliedSpeed  * 0.5 + (float)appliedSpeedPrevious * 0.5) ;

  normSpeed = map(abs(appliedSpeedPrevious), 0, maxSpeed, 0, 100);

  if(appliedSpeedPrevious >= 0){
    digitalWrite(pinA, LOW);
    analogWrite(pinB, abs(appliedSpeedPrevious));
  }else{
    digitalWrite(pinB, LOW);
    analogWrite(pinA, abs(appliedSpeedPrevious));
  }  
}

void LinearActuator::throttle(int speed){  
  int mappedSpeed = 0;
  if(abs(speed) > 1)
    mappedSpeed = map(abs(speed), 0, 100, minSpeed-20, maxSpeed) * (speed > 0 ? 1: -1);

  move( mappedSpeed );  
}

void LinearActuator::position(int pos){
  normPosition = pos;  
  int offseted = constrain(pos + offset, 0, 100);
  targetPotentiometer = map(offseted, 0, 100, minPot, maxPot );
  potentiometerStarting = potentiometer;
}

void LinearActuator::print(){
  Serial.print(F("<LinearActuator:")); 
  Serial.print(identifier);
  Serial.print(F(";"));
  Serial.print(state);  

  if(state < 4){

    Serial.print(F(";"));
    Serial.print(currentSensor.current);

  }else{
    Serial.print(F(";"));
    Serial.print(normPosition);
    Serial.print(F(";"));
    Serial.print(normDistance);
    Serial.print(F(";"));
    Serial.print(normSpeed);
    Serial.print(F(";"));
    Serial.print(currentSensor.current);    
  }

  Serial.print(F(">"));
}
