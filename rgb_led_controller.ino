#include "src/application.h"

Logger Application::logger(&Serial);
Application app;

void setup() {
  Serial.begin(9600);
  app = Application(9, 5, 6, 2, 4);
  // attachInterrupt(digitalPinToInterrupt(2), changeEffect, RISING);
}

void loop() {
  app.tick();
  app.pollIR();
  // Application::logger.info("+");
}

// void changeEffect() {
//   app.changeEffect(1);
// }
