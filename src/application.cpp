#include "application.h"

Application::Application() { };

Application::Application(int r, int g, int b, int button, int battery) {
  red_pin_number = r;
  green_pin_number = g;
  blue_pin_number = b;
  battery_indicator_pin_number = battery;

  pinMode(red_pin_number, OUTPUT);
  pinMode(green_pin_number, OUTPUT);
  pinMode(blue_pin_number, OUTPUT);
  pinMode(battery_indicator_pin_number, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  currentEffectNumber = 0;
  // debounceTime = 0;

  irController = IRController(button, &Application::logger);

  currentEffect = effects[0];
};

void Application::tick() {
  currentEffect->tick(&Application::logger);
  analogWrite(red_pin_number, currentEffect->red);
  analogWrite(green_pin_number, currentEffect->green);
  analogWrite(blue_pin_number, currentEffect->blue);
};

// void Application::changeEffect(int delta) {
//   long currentTime = millis();
//   if (currentTime - debounceTime > 200) {
//     currentEffectNumber = currentEffectNumber + delta;
//     if (currentEffectNumber >= effects_amount) { currentEffectNumber = 0; }
//     if (currentEffectNumber < 0) { currentEffectNumber = effects_amount - 1; }
//   }
//   currentEffect = effects[currentEffectNumber];
//   Application::logger.info("currentEffectNumber: " + String(currentEffectNumber));
//   debounceTime = currentTime;
// };

void Application::changeEffect(int delta) {
  currentEffectNumber = currentEffectNumber + delta;
  if (currentEffectNumber >= effects_amount) { currentEffectNumber = 0; }
  if (currentEffectNumber < 0) { currentEffectNumber = effects_amount - 1; }
  currentEffect = effects[currentEffectNumber];
};

void Application::pollIR() {
  int action = irController.poll();
  switch (action) {
    case Application::onPowerActionNumber:
      onPower();
      break;
    case Application::onUpActionNumber:
      onUp();
      break;
    case Application::onDownActionNumber:
      onDown();
      break;
    case Application::onVolumeUpActionNumber:
      onVolumeUp();
      break;
    case Application::onVolumeDownActionNumber:
      onVolumeDown();
      break;
    case Application::onChannelUpActionNumber:
      onChannelUp();
      break;
    case Application::onChannelDownActionNumber:
      onChannelDown();
      break;
    case Application::onButton0ActionNumber:
      onButton0();
      break;
    case Application::onButton1ActionNumber:
      onButton1();
      break;
    case Application::onButton2ActionNumber:
      onButton2();
      break;
    case Application::onButton3ActionNumber:
      onButton3();
      break;
    case Application::onButton4ActionNumber:
      onButton4();
      break;
    case Application::onButton5ActionNumber:
      onButton5();
      break;
    case Application::onButton6ActionNumber:
      onButton6();
      break;
    case Application::onButton7ActionNumber:
      onButton7();
      break;
    case Application::onButton8ActionNumber:
      onButton8();
      break;
    case Application::onButton9ActionNumber:
      onButton9();
      break;
    case Application::onInfoActionNumber:
      onInfo();
      break;
    default:
      ;
  }
};

void Application::onPower() {
  Application::logger.info("Event onPower");
  analogWrite(red_pin_number, 0);
  analogWrite(green_pin_number, 0);
  analogWrite(blue_pin_number, 0);

  // Allow wake up pin to trigger interrupt on low.
  attachInterrupt(digitalPinToInterrupt(2), wakeUp, LOW);

  // Enter power down state with ADC and BOD module disabled.
  // Wake up when wake up pin is low.
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  // Disable external pin interrupt on wake up pin.
  detachInterrupt(digitalPinToInterrupt(2));

  // Do something here
  // Example: Read sensor, data logging, data transmission.
};

void Application::wakeUp()
{
    // Just a handler for the pin interrupt.
  Application::logger.info("Woke up");
}

void Application::onUp() {
  Application::logger.info("Event onUp");
  currentEffect->speedUp();
};

void Application::onDown() {
  Application::logger.info("Event onDown");
  currentEffect->speedDown();
};

void Application::onVolumeUp() {
  Application::logger.info("Event onVolumeUp");
  currentEffect->brightnessUp();
};

void Application::onVolumeDown() {
  Application::logger.info("Event onVolumeDown");
  currentEffect->brightnessDown();
};

void Application::onChannelUp() {
  Application::logger.info("Event onChannelUp");
  changeEffect(1);
};

void Application::onChannelDown() {
  Application::logger.info("Event onChannelDown");
  changeEffect(-1);
};

void Application::onButton0() {
  Application::logger.info("Event onButton0");
};

void Application::onButton1() {
  Application::logger.info("Event onButton1");
  currentEffect = effects[0];
};

void Application::onButton2() {
  Application::logger.info("Event onButton2");
  currentEffect = effects[1];
};

void Application::onButton3() {
  Application::logger.info("Event onButton3");
  currentEffect = effects[2];
};

void Application::onButton4() {
  Application::logger.info("Event onButton4");
  currentEffect = effects[3];
};

void Application::onButton5() {
  Application::logger.info("Event onButton5");
  currentEffect = effects[4];
};

void Application::onButton6() {
  Application::logger.info("Event onButton6");
  currentEffect = effects[5];
};

void Application::onButton7() {
  Application::logger.info("Event onButton7");
  currentEffect = effects[6];
};

void Application::onButton8() {
  Application::logger.info("Event onButton8");
  currentEffect = effects[7];
};

void Application::onButton9() {
  Application::logger.info("Event onButton9");
};

void Application::onInfo() {
  Application::logger.info("Event onInfo");
  digitalWrite(battery_indicator_pin_number, HIGH);
  // delay(1000);
  digitalWrite(battery_indicator_pin_number, LOW);
};
