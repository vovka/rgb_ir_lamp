#include "effect.h"

class WhiteEffect: public Effect {
  int brightness;

  void lightUp();
  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
  WhiteEffect();
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
