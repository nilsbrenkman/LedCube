#ifndef CubeController_H
#define CubeController_H

#include "Particle.h"
#include "Constants.h"

class CubeController {
  public:
    CubeController();
    void refresh();
  private:
    byte led_cube[LED_CUBE_SIZE][LED_CUBE_SIZE]; // x[y][z]
    unsigned long last_refresh;
    uint8_t active_layer;
    int count;
};

#endif