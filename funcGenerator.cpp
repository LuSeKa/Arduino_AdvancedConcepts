#include "funcGenerator.h"

funcGenerator::funcGenerator(int t, float f, float a) {
  type = t;
  frequency = f;
  amplitude = a;
}

void funcGenerator::setFrequency(float f){
  this->frequency = f;
}

void funcGenerator::setAmplitude(float a){
  this->amplitude = a;
}

void funcGenerator::setType(int t){
  this->type = constrain(t,1,2);
}

float funcGenerator::compute() {
  float result;
  float phase = 2.0 * PI * this->frequency * (float)millis() / 1000.0;
  switch (type) {
    case 0:
      result = this->amplitude * sin(phase);
      break;
    case 1:
      result = this->amplitude * cos(phase);
      break;
    case 2:
      if (fmod(phase, PI) < PI / 2) {
        result = 0;
      }
      else {
        result = this->amplitude * 1;
      }
      break;
    default:
      result = 0;
      break;
  }
  return (result);
}

