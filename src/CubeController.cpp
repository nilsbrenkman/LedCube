#include "CubeController.h"

const int REFRESH_RATE = 1000;

CubeController::CubeController() {
  active_layer = -1;
  count = 0;
  led_cube[0][0] = 0x01;
}

void CubeController::refresh() {
  unsigned long now = micros();
  if (now - last_refresh < REFRESH_RATE) {
    return;
  }

  last_refresh = now;
  active_layer = (active_layer + 1) % LED_CUBE_SIZE;

  digitalWrite(LED_LATCH_PIN, LOW);

  byte out = led_cube[0][0];

  shiftOut(LED_DATA_PIN, LED_CLOCK_PIN, MSBFIRST, out);

  digitalWrite(LED_LATCH_PIN, HIGH);

  if (count == 7) {
    count = -7;
  }
  if (count < 0) {
    led_cube[0][0] = led_cube[0][0] >> 1;
  } else {
    led_cube[0][0] = led_cube[0][0] << 1;
  }
  count += 1;
}