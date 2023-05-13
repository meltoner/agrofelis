/*
  SerialParser.h - Library for wraping the functions conveying the SerialParser
  Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023
*/

#include "Arduino.h"
#include "SerialParser.h" 

SerialParser::SerialParser(){
}

void SerialParser::recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;

    char rc;
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();
        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= 32) {
                    ndx = 32 - 1;
                }
            }else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void SerialParser::parseData() {        
    char * strtokIndx;
    strtokIndx = strtok(tempChars, ",");  // get the first part - the string
    command = atoi(strtokIndx);
    strtokIndx = strtok(NULL, ",");       // this continues where the previous call left off
    commandInt = atoi(strtokIndx);        // convert this part to an integer
}

void SerialParser::apply(){
  recvWithStartEndMarkers();
  if (newData == true) {    
    commandInt = 0;
    strcpy(tempChars, receivedChars);
    parseData();
    newData = false;
  }
}