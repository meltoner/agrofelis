/*
  Context.h - Library for wraping the functions controling the Enviroment context
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#include "Context.h"

Context::Context(){  

}

void Context::setup(){
    Serial.begin(9600);
}

void Context::reflectSensor(float value, byte precission){
  Serial.print(value, value == 0?0:precission);
  Serial.print(" ");
}

void Context::apply(){ // takes 4% of memory

  Serial.println(F("")); 
}

