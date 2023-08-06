/*
  SerialCommandParser.h - Library for wrapping the functions controlling the SerialCommandParser 
  It parses compact commands to parse, of the form <1|1> where the first parameter corresponds to the update action 
  to apply and the next an int value.   
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023 Agrofelis
*/

#ifndef SerialCommandParser_h
#define SerialCommandParser_h

#include "Arduino.h" 

class SerialCommandParser{
  public:
    SerialCommandParser();
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