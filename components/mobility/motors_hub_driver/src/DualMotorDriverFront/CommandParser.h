/*
  CommandParser.h - Library for wrapping the functions controlling the CommandParser 
  It parses compact commands to parse, of the form <1|256> where the first parameter corresponds to the update action 
  to apply and the next, to an int value.
*/

#ifndef CommandParser_h
#define CommandParser_h

#include "Arduino.h" 

class CommandParser{
  public:
    CommandParser();
    
    void parseData(char *str);
    virtual void actionParsedCommand();

    int command = 0;
    int commandInt = 0;

  private: 
    char *token;
    char *remaining;
    char *remove;
    char *removeRemaining;
};

#endif