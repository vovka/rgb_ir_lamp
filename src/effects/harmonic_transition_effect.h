#include "effect.h"
#include <WString.h>
#include <Arduino.h>

class HarmonicTransitionEffect: public Effect {
  long redPeriod, greenPeriod, bluePeriod;
  int amplitude, firstStep;
  int steps[9] = {1,2,3,5,7,11,13,17,19};

  void setSteps();
  int fRed(long);
  int fGreen(long);
  int fBlue(long);

  public:
    HarmonicTransitionEffect();
    void brightnessUp();
    void brightnessDown();
    void speedUp();
    void speedDown();
};
