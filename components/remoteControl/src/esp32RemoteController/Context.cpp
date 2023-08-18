#include "Context.h"

Context::Context(){}
  
void Context::setup(AsyncWebSocket &_ws){
  ws = &_ws;
}

void Context::reflectSensor(float value, byte precission){
  Serial.print(value, value == 0?0:precission);
  Serial.print(" ");
}

void Context::apply(){
}

void Context::appendMessage(String part){
  message += part;  
}

void Context::sendMessage(){  
  ws->textAll(message);
  message = "";
}
