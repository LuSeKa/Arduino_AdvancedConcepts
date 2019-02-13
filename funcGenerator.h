#include <Arduino.h>
#include <math.h>
/*
 * A simple class to generate real-time functions
 * Supported types are (0) sine, (1) cosine and (2) square
 */
class funcGenerator
{
  private:
    float frequency;
    float amplitude;
    int type;
  public:
    funcGenerator(int t, float f, float a);
    float compute();
    void setFrequency(float f);
    void setAmplitude(float a);
    void setType(int t);
};
