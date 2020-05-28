#include "police_effect.h"

PoliceEffect::PoliceEffect() {
  period = 1000;
  pulsePeriod = 200;
  minPulseValue = 50;
  maxPulseValue = 255;
};

int PoliceEffect::fRed(long now) {
  now = now % period;
  if (now <= period / 2) {
    return pulsing(now);
  } else {
    return 0;
  }
};

int PoliceEffect::pulsing(int now) {
  int i = now / pulsePeriod;
  if (i % 2 == 0) {
    return minPulseValue;
  } else {
    return maxPulseValue;
  }
};

int PoliceEffect::fGreen(long now) {
  return 0;
};

int PoliceEffect::fBlue(long now) {
  now = now % period;
  if (now > period / 2) {
    return pulsing(now);
  } else {
    return 0;
  }
};

void PoliceEffect::brightnessUp() {
  if (minPulseValue < (50 - 3)) minPulseValue += 3; else minPulseValue = 50;
  if (maxPulseValue < (255 - 16)) maxPulseValue += 16; else maxPulseValue = 255;
};

void PoliceEffect::brightnessDown() {
  if (minPulseValue > 3) minPulseValue -= 3; else minPulseValue = 0;
  if (maxPulseValue > 16) maxPulseValue -= 16; else maxPulseValue = 0;
};

void PoliceEffect::speedUp() {
  if (period > 200) period -= 200; else period = 0;
  if (pulsePeriod > 40) pulsePeriod -= 40; else pulsePeriod = 0;
};

void PoliceEffect::speedDown() {
  period += 200;
  pulsePeriod += 40;
};
