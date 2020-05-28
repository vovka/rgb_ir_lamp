#include "effect.h"

class FlameEffect: public Effect {
  int pulseAmplitude;

  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
  FlameEffect();
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
