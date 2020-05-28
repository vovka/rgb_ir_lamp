#pragma once
#include <WString.h>
#include <Stream.h>

class Logger {
  Stream* stream;

public:
  Logger();
  Logger(Stream*);
  String info(String);
  String info(int, int);
};
