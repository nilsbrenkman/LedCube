#include "abstract_program.h"

LEDCUBE_NAMESPACE_BEGIN

void AbstractProgram::init(CubeController *cube_controller_p) {
  cube_controller_p = cube_controller_p;
  next_tick = 0;
}

void AbstractProgram::loop() {
  if (next_tick < millis()) {
    next_tick = millis() + frequency();
    tick();
  }
}

LEDCUBE_NAMESPACE_END