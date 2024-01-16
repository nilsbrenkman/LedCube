#ifndef AbstractProgram_H
#define AbstractProgram_H

#include "cube_controller.h"

LEDCUBE_NAMESPACE_BEGIN

class AbstractProgram {
public:
  void loop();

protected:
  virtual void tick();
  virtual int frequency();

  uint32_t next_tick = 0;
};

LEDCUBE_NAMESPACE_END

#endif
