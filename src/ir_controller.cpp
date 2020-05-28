#include "ir_controller.h"

IRController::IRController(){};

IRController::IRController(int pin, Logger* logger){
  irrecv = IRrecv(pin);
  irrecv.enableIRIn(); // Start the receiver
  this->logger = logger;
};

int IRController::poll() {
  int action = -1;
  if (irrecv.decode(&results)) {
    int code = results.value;
    action = translateCodeToAction(code);
    logger->info(code, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
  return action;
};

int IRController::translateCodeToAction(int code) {
  switch (code) {
    case IRController::codePower:
      return IRController::onPower;
      break;
    case IRController::codeUp:
      return IRController::onUp;
      break;
    case IRController::codeDown:
      return IRController::onDown;
      break;
    case IRController::codeVolumeUp:
      return IRController::onVolumeUp;
      break;
    case IRController::codeVolumeDown:
      return IRController::onVolumeDown;
      break;
    case IRController::codeChannelUp:
      return IRController::onChannelUp;
      break;
    case IRController::codeChannelDown:
      return IRController::onChannelDown;
      break;
    case IRController::codeButton0:
      return IRController::onButton0;
      break;
    case IRController::codeButton1:
      return IRController::onButton1;
      break;
    case IRController::codeButton2:
      return IRController::onButton2;
      break;
    case IRController::codeButton3:
      return IRController::onButton3;
      break;
    case IRController::codeButton4:
      return IRController::onButton4;
      break;
    case IRController::codeButton5:
      return IRController::onButton5;
      break;
    case IRController::codeButton6:
      return IRController::onButton6;
      break;
    case IRController::codeButton7:
      return IRController::onButton7;
      break;
    case IRController::codeButton8:
      return IRController::onButton8;
      break;
    case IRController::codeButton9:
      return IRController::onButton9;
      break;
    case IRController::codeInfo:
      return IRController::onInfo;
      break;
    default:
      return 0;
  }
};
