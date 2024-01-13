#include "abstract_program.h"

LEDCUBE_NAMESPACE_BEGIN

void AbstractProgram::init(CubeController *cube_controller_p) {
  cube_controller_p = cube_controller_p;
}

void AbstractProgram::loop() {
  system_tick_t now = millis();
  if (now - last_tick > 500) {
    last_tick = now;
    tick();
  }
}

LEDCUBE_NAMESPACE_END