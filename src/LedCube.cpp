/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "/Users/nils/Projects/LedCube/src/LedCube.ino"
/*
 * Project myProject
 * Author: Your Name
 * Date:
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "abstract_program.h"
#include "blink.h"
#include "constants.h"
#include "cube_controller.h"
#include "dogica.h"
#include "font.h"
#include "singletons.h"
#include "ticker.h"

// Let Device OS manage the connection to the Particle Cloud
void setup();
void loop();
#line 21 "/Users/nils/Projects/LedCube/src/LedCube.ino"
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

LEDCUBE_NAMESPACE_BEGIN

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// CubeController *cube_controller_p = &CubeController::cube_controller();

AbstractProgram *program;

system_tick_t last_tick;

// setup() runs once, when the device is first turned on
void setup() {

  Serial.begin(9600);

  pinMode(LED_DATA_PIN, OUTPUT);
  pinMode(LED_CLOCK_PIN, OUTPUT);
  pinMode(LED_LATCH_PIN, OUTPUT);

  delay(1500);

  // (CubeController::cube_controller()).print_to_serial();
  update({ALL_BITS, ALL_BITS, ALL_BITS}, CLEAR);

  delay(500);

  program = new Blink();

  // cube_controller->update({0b01010101, 0b00110011, 0b00001111}, SET);

  delay(500);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  // cube_controller_p->refresh();

  program->loop();

  // cube_controller_p->print_to_serial();

  // delay(5000);
}

LEDCUBE_NAMESPACE_END
