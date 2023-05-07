/**
 * Interpolate Class for interpolating a value based on an input - output mapping pairs.
 * The interpolation function enabled to map an input non linearly across a input range and linearly within sub bounds of it.
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023  
 */

#ifndef Interpolate_h
#define Interpolate_h

#include "Arduino.h" 

class Interpolate{
  public:

  /**
   * Initialises the interpolate class with the size, the inputs and outputs of the mapping pairs.
   *
   * @param _mappingSize specifies the size of the input output mappings.
   * @param _inputMap reference to the array containing the input points.
   * @param _outputMap reference to the array containing the output points.   
   */
    Interpolate(byte _mappingSize, float *_inputMap, int *_outputMap);

   /**
   * Constrains the input based on the first and last point of the inputs mapping.
   *
   * @param input specifies input value to be constrained.
   * @return the constrained input value value.
   */
    float constrainInput(float input);

   /**
   * Scans the input mappings to identify in which slot the input falls within.
   *
   * @param input specifies the input value to be searched.
   * @return the derived index of the searched value within the input mappings.
   */
    int findInputIndex(float input);

    /**
    * Interpolates an input value by knowing its index within the input mappings.
    *
    * @param input specifies the input value to be interpolated.
    * @param index specifies the index of the input value found within the input mappings.
    * @return the interpolated input value
    */
    int interpolate(float input, int index);

    /**
    * Interpolates an input value based on the input output mappings
    *
    * @param input specifies the input value to be interpolated.
    * @return the interpolated input value
    */
    int interpolate(float input);

  private:
    byte mappingSize = 0;
    float * inputMap;
    int * outputMap;
};

#endif