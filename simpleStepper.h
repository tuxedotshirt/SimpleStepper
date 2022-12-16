#ifndef simpleStepper_h
#define simpleStepper_h
#include "Arduino.h"

class simpleStepper {
  public:
    simpleStepper(int pinOne, int pinTwo, int pinThree, int pinFour);

    void forward(int steps, int stepDelay);
    void backward(int steps, int stepDelay);

  private:
    int _pinOne;
    int _pinTwo;
    int _pinThree;
    int _pinFour;

    void writeMotor(int a, int b, int c, int d);
};

#endif
