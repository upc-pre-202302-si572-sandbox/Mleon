#include <Arduino.h>
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int assignedTriggerPin, int assignedEchoPin) {
  _triggerPin = assignedTriggerPin;
  _echoPin = assignedEchoPin;
}

long DistanceSensor::readUltrasonicDistance() {
  // Clear trigger pin
  pinMode(_triggerPin, OUTPUT);
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);
  // Set trigger pin to high state for 10 microseconds
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_triggerPin, LOW); 
  pinMode(_echoPin, INPUT);
  return pulseIn(_echoPin, HIGH);
}

float DistanceSensor::readDistanceInCentimeters() {
  return readUltrasonicDistance()/58;
}