#include "harmonic_transition_effect.h"

HarmonicTransitionEffect::HarmonicTransitionEffect() {
  red = 0;
  green = 0;
  blue = 0;
  amplitude = 255;
  firstStep = 0;
  setSteps();
}

void HarmonicTransitionEffect::setSteps() {
  redPeriod = long(steps[firstStep]) * 10000;
  greenPeriod = long(steps[firstStep + 1]) * 10000;
  bluePeriod = long(steps[firstStep + 2]) * 10000;
};

int HarmonicTransitionEffect::fRed(long now) {
  return int( double(amplitude) / 2 * sin(2 * PI * (now % redPeriod) / redPeriod) + double(amplitude) / 2);
};

int HarmonicTransitionEffect::fGreen(long now) {
  return int( double(amplitude) / 2 * sin(2 * PI * (now % greenPeriod) / greenPeriod) + double(amplitude) / 2);
};

int HarmonicTransitionEffect::fBlue(long now) {
  return int( double(amplitude) / 2 * sin(2 * PI * (now % bluePeriod) / bluePeriod) + double(amplitude) / 2);
};

void HarmonicTransitionEffect::brightnessUp() {
  if (amplitude < (255 - 16)) amplitude += 16; else amplitude = 255;
};

void HarmonicTransitionEffect::brightnessDown() {
  if (amplitude > 16) amplitude -= 16; else amplitude = 0;
};

void HarmonicTransitionEffect::speedUp() {
  if (firstStep < sizeof(steps) / sizeof(steps[0]) - 3) firstStep++;
  setSteps();
};

void HarmonicTransitionEffect::speedDown() {
  if (firstStep > 0 ) firstStep--;
  setSteps();
};
