/*
  SerialParser.h - Library for wrapping the functions controlling the SerialParser 
  It parses compact commands to parse, of the form <1,1> where the first parameter corresponds to the update action 
  to apply and the next an int value. 
  Simplified version of ex5 https://forum.arduino.cc/t/serial-input-basics-updated/382007/3
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#ifndef SerialParser_h
#define SerialParser_h

#include "Arduino.h" 

class SerialParser{
  public:
    SerialParser();
    void apply();
    // variables to hold the parsed data
    int command = 0;
    int commandInt = 0;

  private:
    
    void recvWithStartEndMarkers();
    void parseData();

    char receivedChars[32];
    char tempChars[32];        // temporary array for use when parsing
    boolean newData = false;

    const char startMarker = '<';
    const char endMarker = '>';
};

#endif