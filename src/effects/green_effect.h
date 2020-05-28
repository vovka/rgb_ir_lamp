#include "effect.h"

class GreenEffect: public Effect {
  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
  GreenEffect();
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
