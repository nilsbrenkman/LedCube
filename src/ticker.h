#ifndef Ticker_H
#define Ticker_H

#include "Particle.h"
#include "abstract_program.h"
#include "constants.h"
#include "dogica.h"
#include "font.h"

LEDCUBE_NAMESPACE_BEGIN

class Ticker : public AbstractProgram {
public:
  Ticker();

protected:
  void tick();
  int frequency();

private:
  void append_to_ticker(uint8_t bit);
  void print_to_serial();

  cube_address_t ticker_data[22];
  uint16_t next_char_idx;
  byte_buffer_t buffer = {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}};
};

LEDCUBE_NAMESPACE_END

#endif
