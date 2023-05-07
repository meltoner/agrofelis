
#include "Interpolate.h" 

Interpolate::Interpolate(byte _mappingSize, float *_inputMap, int *_outputMap){
  mappingSize = _mappingSize;
  inputMap = _inputMap;
  outputMap = _outputMap;
}

float Interpolate::constrainInput(float input){
  return constrain(input, inputMap[0] + 1, inputMap[mappingSize - 1] -1 );
}

int Interpolate::findInputIndex(float input){
  for(int i = 0 ;i < mappingSize ; i ++)
    if(inputMap[i] >= input)
      return i-1;  
  return mappingSize - 2;
}

int Interpolate::interpolate(float input, int index){
  return map(input, inputMap[index], inputMap[index + 1], outputMap[index], outputMap[index + 1] );
}

int Interpolate::interpolate(float input){
  interpolate(input, findInputIndex(input));
}
