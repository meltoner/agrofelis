/*
  Context.h - Library for wrapping the functions controlling the Context / environment information
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/


#ifndef Context_h
#define Context_h

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebSrv.h>
#include "Arduino.h" 

class Context{
  public:
    Context();
    void handleIntervalElapsed(float temperature, bool valid, int deviceIndex);

    void setup(AsyncWebSocket &_ws);
    void apply();
    void reflectSensor(float value, byte precission);
    void appendMessage(String part);
    void sendMessage();
    
    // Invoker variables - execution functions frequencies    
    int intervals[6] = {10, 52, 104, 500, 1008, 5000};    

    unsigned long now = millis();
    unsigned long timers[8] = {now, now, now, now};
 
    String identifier = "";
  private:

    String message;
    byte _pin;
    AsyncWebSocket *ws;
};

#endif
