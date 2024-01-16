#include "abstract_program.h"

LEDCUBE_NAMESPACE_BEGIN

void AbstractProgram::loop() {
  if (next_tick < millis()) {
    next_tick = millis() + frequency();
    tick();
  }
}

LEDCUBE_NAMESPACE_END