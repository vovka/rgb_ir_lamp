#include "effect.h"
#include <Arduino.h>

class ManualEffect: public Effect {
  int* values[3] = {&red, &green, &blue};
  int currentValue;

  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
    ManualEffect();
    // void tick(Logger* logger);
    void brightnessUp();
    void brightnessDown();
    void speedUp();
    void speedDown();
};
