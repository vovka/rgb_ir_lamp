#pragma once
#include <Arduino.h>
#include <HardwareSerial.h>
#include "../logger.h"

class Effect {
  virtual int fRed(long) = 0;
  virtual int fGreen(long) = 0;
  virtual int fBlue(long) = 0;

public:
  int red = 0
    , green = 0
    , blue = 0
    ;

  void tick(Logger* logger);
  virtual void brightnessUp() = 0;
  virtual void brightnessDown() = 0;
  virtual void speedUp() = 0;
  virtual void speedDown() = 0;
};
