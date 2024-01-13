#include "cube_controller.h"

LEDCUBE_NAMESPACE_BEGIN

CubeController::CubeController() {
  active_layer = -1;
  update(ALL_CUBE, CLEAR);
}

void CubeController::refresh() {
  unsigned long now = micros();
  if (now - last_refresh < REFRESH_RATE) {
    return;
  }

  last_refresh = now;
  active_layer = (active_layer + 1) % LED_CUBE_SIZE;

  digitalWrite(LED_LATCH_PIN, LOW);

  // We need to write all 9 regissters in reverse order, starting with the layer register
  write_to_register(idx_to_bit(active_layer))

  // Then the 8 rows, in reverse order
  for (int row = LED_CUBE_SIZE; row > 0; row--) {
    write_to_register(led_cube[row - 1][active_layer]);
  }

  digitalWrite(LED_LATCH_PIN, HIGH);
}

bool CubeController::led(uint8_t x, uint8_t y, uint8_t z) {
  byte row = led_cube[y][z];
  return bit_check(row, x);
}

void CubeController::update(uint8_t x, uint8_t y, uint8_t z, LedCubeOperation operation) {
  update({ idx_to_bit(x), idx_to_bit(y), idx_to_bit(z) }, operation);
}

void CubeController::update(CubeAddress address, LedCubeOperation operation) {
  for (int z = 0; z < LED_CUBE_SIZE; z++) {
    if (bit_check(address.z, z)) {
      for (int y = 0; y < LED_CUBE_SIZE; y++) {
        if (bit_check(address.y, y)) {
          switch (operation) {
            case LedCubeOperation::set:
              led_cube[y][z] |= address.x;
              break;
            case LedCubeOperation::toggle:
              led_cube[y][z] ^= address.x;
              break;
            case LedCubeOperation::clear:
              led_cube[y][z] &= ~address.x;
              break;
          }
        }
      }
    }
  }
}

LEDCUBE_NAMESPACE_END