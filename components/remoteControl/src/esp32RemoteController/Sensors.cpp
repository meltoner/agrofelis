/*
 * Sensors - Class wrapping the functions for reading all sensors 
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#include "Sensors.h" 
#include "Context.h" 


Sensors::Sensors(){}

void Sensors::setup(Context &_context){
    context = &_context;

    for(int i = 0; i < 5;i++)
        pinMode(potentiometerPins[i], INPUT);

    for(int i = 0; i < 2;i++)
        pinMode(togglePins[i], INPUT_PULLDOWN);

}

void Sensors::readSensor(){

  for(int i = 0; i < 5;i++){
    values[i] = map( analogRead(potentiometerPins[i]), 0, 4095, i < 2 ?-100:0, 100 );    
    
    // joystic x,y erase small deviation or ofset
    if(i < 2 && abs(values[i]) < 15)
        values[i] = 0;
    
    if(i == 4) // joystic button
      values[i] = values[i] == 0 ? 1:0;
    else
      values[i] = values[i] * 0.4 + prev_values[i] * 0.6;

    prev_values[i] = values[i];
  }
  
  for(int i = 0; i < 2;i++){
    values[5 + i] = digitalRead(togglePins[i]);
    prev_values[5 + i] = values[5 + i];
  } 
}

void Sensors::apply(){
  readSensor();
}

void Sensors::detectChange(){
  for(int i = 0; i < 7; i++){
    if(compare_prev_values[i] != values[i]){

      switch(i){
        case 0: // X                          
          context->appendMessage("<26|");
          context->appendMessage((String)(!toggleSteeringMax?values[i]:constrain(values[i], -50,50)));
          context->appendMessage(">");
          context->sendMessage();

          break; 

        case 1: // Y
          context->appendMessage(values[i]>0?"<8|0>":"<8|1>");
          context->sendMessage();
          
          context->appendMessage("<9|");
          context->appendMessage((String)(constrain(abs(values[i]), 0, values[2])));
          context->appendMessage(">");
          context->sendMessage();
          
          break;

        case 2: // Limit speed
          context->appendMessage("<9|");
          context->appendMessage((String)(constrain(abs(values[1]), 0, values[2])));
          context->appendMessage(">");
          context->sendMessage();
          break;

        case 3: // Limit break
          context->appendMessage("<29|");
          context->appendMessage((String)(values[3] * values[6]));
          context->appendMessage(">");
          context->sendMessage();
          break;

        case 4: // Joystic button
          if(values[i]==1)
            toggleSteeringMax = !toggleSteeringMax;
          break;

        case 5: // 1st button
          context->appendMessage("<25|5>");          
          context->sendMessage();
          if(values[i]==1){
            togglePower =! togglePower;          
            context->appendMessage(togglePower?"powerOn":"powerOff");
            context->sendMessage();

            context->appendMessage(togglePower?"<7|1>":"<7|0>");
            context->sendMessage();         
          }
          break;

        case 6: // 2nd button

          context->appendMessage("<29|");
          context->appendMessage((String)(values[3]*values[6]));
          context->appendMessage(">");
          context->sendMessage();
          break;

      }
      Serial.print(i);
      Serial.print(":");
      Serial.print(values[i]);
      Serial.print(" "); 

    }
    compare_prev_values[i] = values[i];
  }
}

void Sensors::print(){
  for(int i = 0; i < 7;i++){
    Serial.print(" ");
    Serial.print(values[i]);
  }

}
