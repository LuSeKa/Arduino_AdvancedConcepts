#include "funcGenerator.h"

// constructor
funcGenerator::funcGenerator(int t, float f, float a) {
  type = t;
  frequency = f;
  amplitude = a;
}

// setters
void funcGenerator::setFrequency(float f){
  this->frequency = f;
}

void funcGenerator::setAmplitude(float a){
  this->amplitude = a;
}

void funcGenerator::setType(int t){
  this->type = constrain(t,0,2);
}

// the generator's main task
float funcGenerator::compute() {
  float result;
  float phase = 2.0 * PI * this->frequency * (float)millis() / 1000.0; // goes from 0 to 2pi with specified frequency
  switch (type) {
    case 0: // sine
      result = this->amplitude * sin(phase);
      break;
    case 1: // cosine
      result = this->amplitude * cos(phase);
      break;
    case 2: // square wave
      if (fmod(phase, 2*PI) < PI) {
        result = this->amplitude;
      }
      else {
        result = 0;
      }
      break;
    default:
      result = 0;
      break;
  }
  return (result);
}

