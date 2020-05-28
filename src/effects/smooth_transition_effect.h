#include "effect.h"

class SmoothTransitionEffect: public Effect {
  bool   directionRed = true
       , directionGreen = true
       , directionBlue = true
  ;
  int stepRed, stepGreen, stepBlue, firstStep;
  const int PWM_LIMIT = 255;
  int steps[9] = {1,2,3,5,7,11,13,17,19};

  int pwmStep(int, int, bool*);
  void setSteps();
  int fRed(long);
  int fGreen(long);
  int fBlue(long);

public:
  SmoothTransitionEffect();
  void brightnessUp();
  void brightnessDown();
  void speedUp();
  void speedDown();
};
