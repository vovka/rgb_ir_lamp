#include "effect.h"
#include "Arduino.h"

class RainbowEffect: public Effect {
  unsigned long changedAt, period;
  int colorsSets[7][3] = {
    {255,          0,        0},
    {256 / 10 * 9, 256 / 10, 0},
    {256 / 5 * 4,  256 / 5,  0},
    {0,            255,      0},
    {0,            256 / 3,  256 / 3 * 2},
    {0,            0,        255},
    {256 / 2,      0,        255 / 2}
  };
  int* colorsSet;
  int currentSet;

  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
  RainbowEffect();
  void tick(Logger* logger);
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
