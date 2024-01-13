/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
// #include "application.h"
#include "Constants.h"
#include "CubeController.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

CubeController * cube_controller;

// setup() runs once, when the device is first turned on
void setup() {

  Serial.begin(9600);

  pinMode(LED_DATA_PIN,  OUTPUT);
  pinMode(LED_CLOCK_PIN, OUTPUT);
  pinMode(LED_LATCH_PIN, OUTPUT);

  cube_controller = new CubeController();

  delay(500);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  cube_controller->refresh();

}
