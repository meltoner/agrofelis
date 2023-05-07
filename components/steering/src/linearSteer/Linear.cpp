/*
  Linear.h - Library for wrapping the functions controlling and sensing a linear actuator.
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023

  The class is initialised with the following board port mappings. 
  The first two control the direction and speed of the [DRV8871 H-Bridge Brushed DC Motor Driver] using two pwm ports. 
  The next the analogue [Linear Potentiometer B10K Ohm] and the analogue [ACS712 5A  Range Hall Current Sensor Module].

  The module operates based on 4 states dictating its function. On states one and two, the min and max potentiometer bounds are identified.
  On state three, the minimum throttle leading to a movement is derived. On state four the object enters when its objective position has been achieved. 
  On state five, the object reaches to the target position. States 10 and 11 correspond to erroneous states, such when an 
  actuation is not detected when its expected or when the sensor value reads values close to its physical values.

  The module's regular update frequency is 100 ms
*/

#include "Linear.h" 
#include "Context.h"
#include "Sensor.h"

Linear::Linear(int _identifier, int _pinA, int _pinB, int _pinC, int _pinD, int _direction, int _offset){
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

void Linear::setTarget(int target){
  targetPotentiometer = target;
} 

void Linear::setup(Context &_context){
  context = &_context;
  move(0);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  sensor.setup(pinC);
}

void Linear::changeState(int _state){
  state = _state;
  stateChanged = millis();
}

/*
  The module operates based on 4 states dictating its function. On states one and two, the min and max potentiometer bounds are identified.
  On state three, the minimum throttle leading to a movement is derived. On state four the object enters when its objective position has been achieved. 
  On state five, the object reaches to the target position. States 10 and 11 correspond to erroneous states, such when an 
  actuation is not detected when its expected or when the sensor value reads values close to its physical values.
*/

void Linear::apply(){

  potentiometer = sensor.apply();
  timeSinceStateChange = millis() - stateChanged;

  // Check if the sensor has reached its physical limits 
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
      if(timeSinceStateChange < 3000 || sensor.moving == 1){
        move(-direction * initialSpeed);
      }else{

        if(direction == 1)
          minPot = sensor.value + direction * 5;
        else
          maxPot = sensor.value - direction * 5;

        changeState(state + 1);
        
        move(direction * initialSpeed);

      }
      break;

    case 2: // find bounds B potentiometer  
      if(timeSinceStateChange < 3000 || sensor.moving == 1){
      }else{

        if(direction == 1)
          maxPot = sensor.value - direction * 10;
        else
          minPot = sensor.value + direction * 10;

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
      //Serial.print("Error : Reached sensor limits");
      throttle(0);
      break;
  }
  applyMove();
} 

// Controls the direction and raw speed of the linear motor constrained to +/- 255
void Linear::move(int speed){
  appliedSpeed = constrain(speed, -maxSpeed, maxSpeed);
}

// Based on the desired speed, applies incremental changes to reach it.
void Linear::applyMove(){

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

// Actuates the a speed value by inputting a 0 to 100 range. 
//The raw value is mapped based on the min speed that lead to a feedback sensor difference.
void Linear::throttle(int speed){  
  //normSpeed = abs(speed);
  int mappedSpeed = 0;

  if(abs(speed) > 1)
    mappedSpeed = map(abs(speed), 0, 100, minSpeed-20, maxSpeed) * (speed > 0 ? 1: -1);

  move( mappedSpeed );  
}

// Sets the target potentiometer value, by inputting a 0 to 100 range mapped 
// based on the min and max value of the feedback sensor detected at boot up.
void Linear::position(int pos){
  normPosition = pos;  
  int offseted = constrain(pos + offset, 0, 100);
  targetPotentiometer = map(offseted, 0, 100, minPot, maxPot );
  potentiometerStarting = potentiometer;
}

void Linear::print(){
  Serial.print(F("<Linear:")); 
  Serial.print(identifier);
  Serial.print(F(";"));
  Serial.print(state);

  if(state<4){

  }else{
    Serial.print(F(";"));
    Serial.print(normPosition);
    Serial.print(F(";"));
    Serial.print(normDistance);
    Serial.print(F(";"));
    Serial.print(normSpeed);
    //sensor.print();    
  }

  Serial.print(F(">"));
}
