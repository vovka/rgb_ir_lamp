#include "smooth_rainbow_effect.h"

SmoothRainbowEffect::SmoothRainbowEffect() {
  amplitude = 255;
  period = 10000;
}

int SmoothRainbowEffect::fRed(long now) {
  double x = (double)(now % period) / (double)period;
  int value = int( double(amplitude) * sin(2 * PI * x) );
  if (value < 0) value = 0;
  return value;
};

int SmoothRainbowEffect::fGreen(long now) {
  double x = (double)(now % period) / (double)period;
  int value = int( double(amplitude) * sin(2 * PI * x - 2 * PI / 3) );
  if (value < 0) value = 0;
  return value;
};

int SmoothRainbowEffect::fBlue(long now) {
  double x = (double)(now % period) / (double)period;
  int value = int( double(amplitude) * sin(2 * PI * x + 2 * PI / 3) );
  if (value < 0) value = 0;
  return value;
};

void SmoothRainbowEffect::brightnessUp() {
  if (amplitude < (255 - 16)) amplitude += 16; else amplitude = 255;
};

void SmoothRainbowEffect::brightnessDown() {
  if (amplitude > 16) amplitude -= 16; else amplitude = 0;
};

void SmoothRainbowEffect::speedUp() {
  if (period > 1000) period -= 1000; else period = 0;
};

void SmoothRainbowEffect::speedDown() {
  period += 1000;
};
