/*
  * Adac - Class for wrapping the functions utilising the MCP3008 8channel 10bit analog Adac paired with a level shifter connected using the SPI interface
  * 
  * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef Adac_h
#define Adac_h
#include "Arduino.h" 
#include <Adafruit_MCP3008.h>

class Adac {
  public:    
    Adac();    
    int get(byte position); 
  private:
    Adafruit_MCP3008 adc;
};

#endif
