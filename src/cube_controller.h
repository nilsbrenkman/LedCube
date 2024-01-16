#ifndef CubeController_H
#define CubeController_H

#include "Particle.h"
#include "constants.h"
#include "cube_types.h"

static cube_t led_cube = {};
static unsigned long last_refresh = 0;
static uint8_t active_layer = -1;

void refresh();
bool led(uint8_t x, uint8_t y, uint8_t z);
void update(uint8_t x, uint8_t y, uint8_t z, LedCubeOperation operation);
void update(cube_address_t address, LedCubeOperation operation);
void print_to_serial();

LEDCUBE_NAMESPACE_BEGIN

// class CubeController {

// public:
//   // static CubeController *cube_controller() {
//   //   static CubeController cube_controller = CubeController();
//   //   cube_controller.led_cube = {};
//   //   cube_controller.active_layer = -1;
//   //   return &cube_controller;
//   // };

//   CubeController();
//   void refresh();
//   bool led(uint8_t x, uint8_t y, uint8_t z);
//   void update(uint8_t x, uint8_t y, uint8_t z, LedCubeOperation operation);
//   void update(cube_address_t address, LedCubeOperation operation);
//   void print_to_serial();
// };

LEDCUBE_NAMESPACE_END

#endif
