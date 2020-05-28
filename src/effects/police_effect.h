#include "effect.h"
#include <Arduino.h>

class PoliceEffect: public Effect {
  int period, pulsePeriod, minPulseValue, maxPulseValue;

  int fRed(long);
  int fGreen(long);
  int fBlue(long);
  int pulsing(int);

public:
  PoliceEffect();
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
