#include "Context.h"

Context::Context(){  
  
}
  
void Context::setup(AsyncWebSocket &_ws){
  ws = &_ws;
  dallasTemp.begin();
  dallasTemp.setWaitForConversion(false);
  dallasTemp.requestTemperatures();  
  lastTempRequest = millis();
}

void Context::updateTemperatures(){
  if (millis() - lastTempRequest >= 2000){
    temperatures[0] = dallasTemp.getTempCByIndex(0);
    temperatures[1] = dallasTemp.getTempCByIndex(1);
    lastTempRequest = millis();
    dallasTemp.requestTemperatures(); 
  }  
}

void Context::reflectSensor(float value, byte precission){
  Serial.print(value, value == 0?0:precission);
  Serial.print(" ");
}

void Context::apply(){
  updateTemperatures();
  //Serial.println(F("")); 
}

void Context::appendMessage(String part){
  message += part;  
}

void Context::sendMessage(){  
  ws->textAll(message);
  message = "";
}
