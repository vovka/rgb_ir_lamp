#include <Arduino.h>
#include <IRremote.h>
#include "logger.h"

class IRController {
  IRrecv irrecv = new IRrecv(0);
  decode_results results;
  static const int codePower = 0x2FD48B7,
      codeVolumeUp = 0x2FD58A7,
      codeVolumeDown = 0x2FD7887,
      codeChannelUp = 0x2FDD827,
      codeChannelDown = 0x2FDF807,
      codeButton0 = 0x2FD00FF,
      codeButton1 = 0x2FD807F,
      codeButton2 = 0x2FD40BF,
      codeButton3 = 0x2FDC03F,
      codeButton4 = 0x2FD20DF,
      codeButton5 = 0x2FDA05F,
      codeButton6 = 0x2FD609F,
      codeButton7 = 0x2FDE01F,
      codeButton8 = 0x2FD10EF,
      codeButton9 = 0x2FD906F,
      codeUp = 0xFFFF9867,
      codeDown = 0xFFFFB847,
      codeInfo = 0x6897,

      onPower = 1,
      onVolumeUp = 2,
      onVolumeDown = 3,
      onChannelUp = 4,
      onChannelDown = 5,
      onButton0 = 6,
      onButton1 = 7,
      onButton2 = 8,
      onButton3 = 9,
      onButton4 = 10,
      onButton5 = 11,
      onButton6 = 12,
      onButton7 = 13,
      onButton8 = 14,
      onButton9 = 15,
      onUp = 16,
      onDown = 17,
      onInfo = 18;

  int translateCodeToAction(int);
  Logger* logger;

public:
  IRController();
  IRController(int, Logger*);
  int poll();
};
