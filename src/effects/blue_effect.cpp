#include "blue_effect.h"

BlueEffect::BlueEffect() {
  red = 0;
  green = 0;
  blue = 255;
};

int BlueEffect::fRed(long now) {
  return 0;
};

int BlueEffect::fGreen(long now) {
  return 0;
};

int BlueEffect::fBlue(long now) {
  return blue;
};

void BlueEffect::brightnessUp() {
 if (blue < (255 - 16)) blue += 16; else blue = 255;
};

void BlueEffect::brightnessDown() {
  if (blue > 16) blue -= 16; else blue = 0;
};

void BlueEffect::speedUp() {
};

void BlueEffect::speedDown() {
};
