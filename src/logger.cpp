#include "logger.h"

Logger::Logger() {
};

Logger::Logger(Stream* s) {
  stream = s;
};

String Logger::info(String msg) {
  stream->println(msg);
  return msg;
};

String Logger::info(int msg, int base) {
  stream->println(msg, base);
  return String(msg, base);
};
