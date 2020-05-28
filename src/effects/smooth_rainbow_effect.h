#include "effect.h"
#include <WString.h>
#include <Arduino.h>

class SmoothRainbowEffect: public Effect {
  int amplitude;
  long period;

  int fRed(long);
  int fGreen(long);
  int fBlue(long);

  public:
    SmoothRainbowEffect();
    void brightnessUp();
    void brightnessDown();
    void speedUp();
    void speedDown();
};
