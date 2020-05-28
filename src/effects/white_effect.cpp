#include "white_effect.h"

WhiteEffect::WhiteEffect() {
  brightness = 255;
  lightUp();
};

void WhiteEffect::lightUp() {
  red = brightness;
  green = brightness;
  blue = brightness;
}

int WhiteEffect::fRed(long now) {
  return red;
};

int WhiteEffect::fGreen(long now) {
  return green;
};

int WhiteEffect::fBlue(long now) {
  return blue;
};

void WhiteEffect::brightnessUp() {
  if (brightness < (255 - 16)) brightness += 16; else brightness = 255;
  lightUp();
};

void WhiteEffect::brightnessDown() {
  if (brightness > 16) brightness -= 16; else brightness = 0;
  lightUp();
};

void WhiteEffect::speedUp() {
};

void WhiteEffect::speedDown() {
};
