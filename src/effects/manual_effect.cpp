#include "manual_effect.h"

ManualEffect::ManualEffect() {
  red = 1;
  green = 1;
  blue = 1;
  currentValue = 0;
}

int ManualEffect::fRed(long now) {
  String readString;
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the String readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
    Serial.println(readString);  //so you can see the captured String
    int n = readString.toInt();  //convert readString into a number
    Serial.println(n); //so you can see the integer
    *(values[currentValue]) = n;
    currentValue++;
    if (currentValue > 2) currentValue = 0;
    readString="";
  }

  return red;
};

int ManualEffect::fGreen(long now) {
  return green;
};

int ManualEffect::fBlue(long now) {
  return blue;
};

// void ManualEffect::tick(Logger* logger) {
//   logger->info("ManualEffect::tick");
//
//   String readString;
//   while (Serial.available()) {
//     char c = Serial.read();  //gets one byte from serial buffer
//     readString += c; //makes the String readString
//     delay(2);  //slow looping to allow buffer to fill with next character
//   }
//
//   if (readString.length() >0) {
//     Serial.println(readString);  //so you can see the captured String
//     int n = readString.toInt();  //convert readString into a number
//     Serial.println(n); //so you can see the integer
//     *(values[currentValue]) = n;
//     currentValue++;
//     if (currentValue > 2) currentValue = 0;
//     readString="";
//   }
// }

void ManualEffect::brightnessUp() {
};

void ManualEffect::brightnessDown() {
};

void ManualEffect::speedUp() {
};

void ManualEffect::speedDown() {
};
