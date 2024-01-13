#ifndef AbstractProgram_H
#define AbstractProgram_H

#include "cube_controller.h"

LEDCUBE_NAMESPACE_BEGIN

class AbstractProgram {
public:
  void init(CubeController *cube_controller_p);
  void loop();
  virtual void tick();

protected:
  CubeController *cube_controller_p;
  system_tick_t last_tick;
};

LEDCUBE_NAMESPACE_END

#endif
