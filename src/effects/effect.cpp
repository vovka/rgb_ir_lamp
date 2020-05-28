#include "effect.h"

void Effect::tick(Logger* logger) {
  logger->info("Effect::tick");

  long now = millis();
  red = fRed(now);
  green = fGreen(now);
  blue = fBlue(now);

  logger->info("now: " + String(now));
  logger->info("red: " + String(red) + ", green: " + String(green) + ", blue: " + String(blue));
  // logger->info("redPeriod: " + String(redPeriod));
  // logger->info("greenPeriod: " + String(greenPeriod));
  // logger->info("bluePeriod: " + String(bluePeriod));
  // logger->info("firstStep: " + String(firstStep));
  // logger->info("steps[firstStep]: " + String(steps[firstStep]));
  // logger->info("steps[firstStep + 1]: " + String(steps[firstStep + 1]));
  // logger->info("steps[firstStep + 2]: " + String(steps[firstStep + 2]));
}
