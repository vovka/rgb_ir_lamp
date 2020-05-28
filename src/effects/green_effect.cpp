#include "green_effect.h"

GreenEffect::GreenEffect() {
  red = 0;
  green = 255;
  blue = 0;
}

int GreenEffect::fRed(long now) {
  return 0;
};

int GreenEffect::fGreen(long now) {
  return green;
};

int GreenEffect::fBlue(long now) {
  return 0;
};

void GreenEffect::brightnessUp() {
  if (green < (255 - 16)) green += 16; else green = 255;
};

void GreenEffect::brightnessDown() {
  if (green > 16) green -= 16; else green = 0;
};

void GreenEffect::speedUp() {
};

void GreenEffect::speedDown() {
};
