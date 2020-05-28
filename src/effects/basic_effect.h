#include "effect.h"

class BasicEffect: public Effect {
  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
