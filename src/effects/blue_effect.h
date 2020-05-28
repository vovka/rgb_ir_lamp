#include "effect.h"

class BlueEffect: public Effect {
  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
  BlueEffect();
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
