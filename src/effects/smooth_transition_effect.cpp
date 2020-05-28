#include "smooth_transition_effect.h"

SmoothTransitionEffect::SmoothTransitionEffect() {
  red = 255;
  green = 255;
  blue = 255;
  firstStep = 0;
  setSteps();
}

void SmoothTransitionEffect::setSteps() {
  if (firstStep < sizeof(steps) - 3) {
    stepRed = steps[firstStep];
    stepGreen = steps[firstStep + 1];
    stepBlue = steps[firstStep + 2];
  }
};

int SmoothTransitionEffect::fRed(long now) {
  return pwmStep(red, stepRed, &(directionRed));
};

int SmoothTransitionEffect::fGreen(long now) {
  return pwmStep(green, stepGreen, &(directionGreen));
};

int SmoothTransitionEffect::fBlue(long now) {
  return pwmStep(blue, stepBlue, &(directionBlue));
};

int SmoothTransitionEffect::pwmStep(int value, int step, bool *direction) {
  if (*direction) {
    value += step;
  } else {
    value -= step;
  }
  if (value > PWM_LIMIT) {
    value -= step + 1;
    *direction = !(*direction);
  } else if (value < 0) {
    value += step + 1;
    *direction = !(*direction);
  }
  return value;
}

void SmoothTransitionEffect::brightnessUp() {
};

void SmoothTransitionEffect::brightnessDown() {
};

void SmoothTransitionEffect::speedUp() {
  firstStep++;
  setSteps();
};

void SmoothTransitionEffect::speedDown() {
  firstStep--;
  setSteps();
};
