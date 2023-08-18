#include "Arduino.h"
#include "CommandParser.h" 
#include <string.h>

CommandParser::CommandParser(){}

void CommandParser::parseData(char *str) {
  token = strtok_r(str, "|", &remaining);
  while (token) {    
    remove = strtok_r(token, "<", &removeRemaining);
    command = atoi(remove);
    token = strtok_r(NULL, ">", &remaining);
    commandInt = atoi(token);
    actionParsedCommand();
    token = strtok_r(NULL, "|", &remaining);
  }
}

void CommandParser::actionParsedCommand(){}
