#ifndef DistanceSensor_h
#define DistanceSensor_h
#include "Arduino.h"

class DistanceSensor {
  public:
    DistanceSensor(int assignedTriggerPin, int assignedEchoPin);
    long readUltrasonicDistance();
    float readDistanceInCentimeters();
  private:
    int _triggerPin;
    int _echoPin;
};
#endif