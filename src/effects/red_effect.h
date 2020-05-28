#include "effect.h"

class RedEffect: public Effect {
  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
  RedEffect();
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
