#include "red_effect.h"

RedEffect::RedEffect() {
  red = 16;
  green = 0;
  blue = 0;
};

int RedEffect::fRed(long now) {
  return red;
};

int RedEffect::fGreen(long now) {
  return 0;
};

int RedEffect::fBlue(long now) {
  return 0;
};

void RedEffect::brightnessUp() {
  if (red < (255 - 16)) red += 16; else red = 255;
};

void RedEffect::brightnessDown() {
  if (red > 16) red -= 16; else red = 0;
};

void RedEffect::speedUp() {
};

void RedEffect::speedDown() {
};
