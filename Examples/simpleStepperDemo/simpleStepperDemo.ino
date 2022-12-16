#include <simpleStepper.h>

simpleStepper motor(2, 3, 4, 5);

void setup() {
}

void loop() {
  motor.forward(100, 2);
  delay(1000);
  motor.backward(100,2);
  delay(1000);
}
