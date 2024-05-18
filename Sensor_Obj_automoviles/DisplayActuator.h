#ifndef DisplayActuator_h
#define DisplayActuator_h
#include "Arduino.h"

class DisplayActuator {
  
  public:
    DisplayActuator();
    void init();
    void setCursor(int row, int column);
    void printDistance(float distance);
    void printText(String text);
    void clear();
    private:
};
#endif
