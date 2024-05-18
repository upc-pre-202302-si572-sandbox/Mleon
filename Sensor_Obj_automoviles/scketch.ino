/*
 * vehicle-distance-sensor-system
 *
 * Embedded Application that monitors set of 4 
 * ultrasonic distance sensors showing readed values
 * on a display actuator.
 *
 * https://wokwi.com/projects/398003241149240321
 */

#include "DisplayActuator.h"
#include "DistanceSensor.h"

#define FL_TRIGGER_PIN 5
#define FR_TRIGGER_PIN 3
#define BL_TRIGGER_PIN 9
#define BR_TRIGGER_PIN 7

#define FL_ECHO_PIN 4
#define FR_ECHO_PIN 2
#define BL_ECHO_PIN 8
#define BR_ECHO_PIN 6

DisplayActuator displayActuator;
DistanceSensor flDistanceSensor(FL_TRIGGER_PIN, FL_ECHO_PIN);
DistanceSensor frDistanceSensor(FR_TRIGGER_PIN, FR_ECHO_PIN);
DistanceSensor rlDistanceSensor(BL_TRIGGER_PIN, BL_ECHO_PIN);
DistanceSensor rrDistanceSensor(BR_TRIGGER_PIN, BR_ECHO_PIN);

void setup() {
  displayActuator.init();
}

void loop() {
  updateDashboard();
}

void updateDashboard() {
  displayActuator.setCursor(2, 0);
  displayActuator.printText("FL");
  displayActuator.setCursor(1, 1);
  displayActuator.printDistance(flDistanceSensor.readDistanceInCentimeters());
  displayActuator.setCursor(14, 0);
  displayActuator.printText("FR");
  displayActuator.setCursor(13, 1);
  displayActuator.printDistance(frDistanceSensor.readDistanceInCentimeters());
  displayActuator.setCursor(2, 2);
  displayActuator.printText("BL");
  displayActuator.setCursor(1, 3);
  displayActuator.printDistance(rlDistanceSensor.readDistanceInCentimeters());
  displayActuator.setCursor(14, 2);
  displayActuator.printText("BR");
  displayActuator.setCursor(13, 3);
  displayActuator.printDistance(rrDistanceSensor.readDistanceInCentimeters());
}
