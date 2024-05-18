#ifndef blinker_h
#define blinker_h
class Blinker {
  public:
    Blinker();
    void setupLed();
    void red();
    void yellow();
    void green();
    void makePause();
};
#endif