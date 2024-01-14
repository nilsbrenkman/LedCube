#ifndef AbstractProgram_H
#define AbstractProgram_H

#include "cube_controller.h"

LEDCUBE_NAMESPACE_BEGIN

class AbstractProgram {
public:
  void init(CubeController *cube_controller_p);
  void loop();

protected:
  virtual void tick();
  virtual int frequency();

  CubeController *cube_controller_p;
  uint32_t next_tick;
};

LEDCUBE_NAMESPACE_END

#endif
