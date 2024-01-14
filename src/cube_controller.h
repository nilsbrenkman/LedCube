#ifndef CubeController_H
#define CubeController_H

#include "Particle.h"
#include "constants.h"

LEDCUBE_NAMESPACE_BEGIN

typedef struct {
  uint8_t x;
  uint8_t y;
  uint8_t z;
} cube_address_t;

class CubeController {
public:
  CubeController();
  void refresh();
  bool led(uint8_t x, uint8_t y, uint8_t z);
  void update(uint8_t x, uint8_t y, uint8_t z, LedCubeOperation operation);
  void update(cube_address_t address, LedCubeOperation operation);

private:
  byte led_cube[LED_CUBE_SIZE][LED_CUBE_SIZE]; // x[y][z]
  unsigned long last_refresh;
  uint8_t active_layer;
};

LEDCUBE_NAMESPACE_END

#endif
