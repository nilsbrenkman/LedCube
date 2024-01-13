/*
 * Project myProject
 * Author: Your Name
 * Date:
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "constants.h"
#include "cube_controller.h"
#include "dogica.h"
#include "font.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

LEDCUBE_NAMESPACE_BEGIN

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

CubeController *cube_controller;

system_tick_t last_tick;

// setup() runs once, when the device is first turned on
void setup() {

  Serial.begin(9600);

  pinMode(LED_DATA_PIN, OUTPUT);
  pinMode(LED_CLOCK_PIN, OUTPUT);
  pinMode(LED_LATCH_PIN, OUTPUT);

  cube_controller = new CubeController();
  cube_controller->update({0b01010101, ALL_BITS, ALL_BITS}, CLEAR);

  delay(5900);

  font_glyph_dsc_t glyph = {};
  draw_buf_t buffer = {};
  font_get_glyph_dsc(&dogica, &glyph, 0x0047);
  font_get_glyph_bitmap(&glyph, &buffer);

  Serial.printlnf("Found letter width %d", buffer.size);
  for (int i = 0; i < 8; i++) {
    Serial.print("//");
    for (int j = 0; j < buffer.size; j++) {
      if (bit_check(buffer.bitmap[j], i)) {
        Serial.print(" #");
      } else {
        Serial.print(" .");
      }
    }
    Serial.println("");
  }
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  cube_controller->refresh();

  system_tick_t now = millis();

  if (now - last_tick > 500) {
    last_tick = now;
    cube_controller->update(ALL_CUBE, TOGGLE);
  }
}

LEDCUBE_NAMESPACE_END
