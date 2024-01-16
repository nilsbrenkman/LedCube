#include "cube_controller.h"

LEDCUBE_NAMESPACE_BEGIN

void refresh() {
  unsigned long now = micros();
  if (now - last_refresh < REFRESH_RATE) {
    return;
  }

  last_refresh = now;
  active_layer = (active_layer + 1) % 2;

  digitalWrite(LED_LATCH_PIN, LOW);

  // We need to write all 9 regissters in reverse order, starting with the layer
  // register
  write_to_register(0x01 << active_layer);
  // Serial.printf("%X\n", 0x01 << active_layer);

  // Then the 8 rows, in reverse order
  for (int y = 3; y > 0; y--) {
    write_to_register(led_cube.z[active_layer].y[y - 1].x);
    // Serial.printf("%X\n", led_cube.z[active_layer].y[y - 1].x);
  }

  digitalWrite(LED_LATCH_PIN, HIGH);
}

bool led(uint8_t x, uint8_t y, uint8_t z) {
  return bit_check(led_cube.z[z].y[y].x, x);
}

void update(uint8_t x, uint8_t y, uint8_t z, LedCubeOperation operation) {
  update({idx_to_bit(x), idx_to_bit(y), idx_to_bit(z)}, operation);
}

void update(cube_address_t address, LedCubeOperation operation) {
  for (uint8_t z : BIT_RANGE) {
    if (bit_check(address.z, z)) {
      for (uint8_t y : BIT_RANGE) {
        if (bit_check(address.y, y)) {
          switch (operation) {
          case LedCubeOperation::set:
            led_cube.z[z].y[y].x |= address.x;
            break;
          case LedCubeOperation::toggle:
            led_cube.z[z].y[y].x ^= address.x;
            break;
          case LedCubeOperation::clear:
            led_cube.z[z].y[y].x &= ~address.x;
            break;
          }
        }
      }
    }
  }
}

void print_to_serial() {
  for (uint8_t z : BIT_RANGE) {
    Serial.printf("%u | ", z);
    for (uint8_t y : BIT_RANGE) {
      Serial.printf("%X ", led_cube.z[z].y[y].x);
    }
    Serial.print("|\n");
  }
}

LEDCUBE_NAMESPACE_END