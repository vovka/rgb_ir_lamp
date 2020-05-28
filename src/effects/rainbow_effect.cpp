#include "rainbow_effect.h"

RainbowEffect::RainbowEffect() {
  red = 0;
  green = 0;
  blue = 0;
  period = 1000;
  changedAt = 0;
  currentSet = 0;
};

// void RainbowEffect::tick(Logger* logger) {
//   if (millis() - changedAt > changePeriod) {
//     if (currentSet >= 7) {
//       currentSet = 0;
//     }
//     int* colorsSet = colorsSets[currentSet++];
//     red = colorsSet[0];
//     green = colorsSet[1];
//     blue = colorsSet[2];
//     changedAt = millis();
//     logger->info("red: " + String(red) + ", green: " + String(green) + ", blue: " + String(blue) + ", changePeriod: " + String(changePeriod));
//   }
// };

int RainbowEffect::fRed(long now) {
  if (now - changedAt > period) {
    changedAt = now;
    if (++currentSet >= 7) currentSet = 0;
    colorsSet = colorsSets[currentSet];
  }

  return colorsSet[0];
};

int RainbowEffect::fGreen(long now) {
  return colorsSet[1];
};

int RainbowEffect::fBlue(long now) {
  return colorsSet[2];
};

void RainbowEffect::brightnessUp() {
};

void RainbowEffect::brightnessDown() {
};

void RainbowEffect::speedUp() {
  if (period > 0) period -= 200;
};

void RainbowEffect::speedDown() {
  period += 200;
};
