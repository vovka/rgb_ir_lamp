#include "flame_effect.h"

FlameEffect::FlameEffect() {
  red = 200;
  green = 2;
  blue = 2;
  pulseAmplitude = 1;
};

int FlameEffect::fRed(long now) {
  red = red + pulseAmplitude * pow(-1, random(2) + 1);
  if (red > 255) red = 255;
  if (red < 100) red = 100;
  return red;
};

int FlameEffect::fGreen(long now) {
  green = green + pulseAmplitude * pow(-1, random(2) + 1);
  if (green > 5) green = 5;
  if (green < 0) green = 0;
  return green;
};

int FlameEffect::fBlue(long now) {
  blue = blue + pulseAmplitude * pow(-1, random(2) + 1);
  if (blue > 1) blue = 1;
  if (blue < 0) blue = 0;
  return blue;
};

void FlameEffect::brightnessUp() {
};

void FlameEffect::brightnessDown() {
};

void FlameEffect::speedUp() {
};

void FlameEffect::speedDown() {
};
