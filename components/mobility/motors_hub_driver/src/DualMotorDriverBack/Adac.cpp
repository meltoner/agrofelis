#include "Adac.h"
#include "Context.h"

Adac::Adac(){
  adc.begin();
}

int Adac::get(byte position){
  return adc.readADC(position);
}
