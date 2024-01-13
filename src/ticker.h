#ifndef Ticker_H
#define Ticker_H

#include "abstract_program.h"
#include "constants.h"
#include "dogica.h"

LEDCUBE_NAMESPACE_BEGIN

class Ticker : public AbstractProgram {
public:
  Ticker();
  void tick();

private:
  uint16_t nextChar;
  draw_buf_t *buffer;
};

LEDCUBE_NAMESPACE_END

#endif
