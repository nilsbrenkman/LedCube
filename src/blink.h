#ifndef Ticker_H
#define Ticker_H

#include "Particle.h"
#include "abstract_program.h"
#include "abstract_program.h"
#include "cube_types.h"
#include "singletons.h"

LEDCUBE_NAMESPACE_BEGIN

class Blink : public AbstractProgram {
public:
  Blink();

protected:
  void tick();
  int frequency();

};

LEDCUBE_NAMESPACE_END

#endif
