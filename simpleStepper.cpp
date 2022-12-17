#include "Arduino.h"
#include "simpleStepper.h"
/*
Public Function
Constructor
Initializes stepper motor object.
Input variables: four I/O pin numbers corresponding to driver board inputs.
			pinOne   = IN1
			pinTwo   = IN2
			pinThree = IN3
			pinFour  = IN4
Output: none 
*/
simpleStepper::simpleStepper(int pinOne, int pinTwo, int pinThree, int pinFour) {
	pinMode(pinOne, OUTPUT);
	pinMode(pinTwo, OUTPUT);
	pinMode(pinThree, OUTPUT);
	pinMode(pinFour, OUTPUT);

	_pinOne = pinOne;
	_pinTwo = pinTwo;
	_pinThree = pinThree;
	_pinFour = pinFour;
}

/*
Public Function
Rotates motor clockwise.
Input variables:  
			steps: the number of steps you would like the motor to take.
			stepDelay: the time delay between steps. Must be > 0. 1 is fastest rotation, larger number is slower roation.
Output: none
*/
void simpleStepper::forward(int steps, int stepDelay) {
  while (steps > 0) {
    writeMotor(1, 0, 0, 0);
    delay(stepDelay);
    writeMotor(1, 1, 0, 0);
    delay(stepDelay);
    writeMotor(0, 1, 0, 0);
    delay(stepDelay);
    writeMotor(0, 1, 1, 0);
    delay(stepDelay);
    writeMotor(0, 0, 1, 0);
    delay(stepDelay);
    writeMotor(0, 0, 1, 1);
    delay(stepDelay);
    writeMotor(0, 0, 0, 1);
    delay(stepDelay);
    writeMotor(1, 0, 0, 1);
    delay(stepDelay);
    steps--;
  }
}

/*
Public Function
Rotates motor counter-clockwise.
Input variables:  
			steps: the number of steps you would like the motor to take.
			stepDelay: the time delay between steps. Must be > 0. 1 is fastest roation, larger number is slower roation.
Output: none
*/
void simpleStepper::backward(int steps, int stepDelay) {
  while (steps > 0) {
    writeMotor(1, 0, 0, 0);
    delay(stepDelay);
    writeMotor(1, 0, 0, 1);
    delay(stepDelay);
    writeMotor(0, 0, 0, 1);
    delay(stepDelay);
    writeMotor(0, 0, 1, 1);
    delay(stepDelay);
    writeMotor(0, 0, 1, 0);
    delay(stepDelay);
    writeMotor(0, 1, 1, 0);
    delay(stepDelay);
    writeMotor(0, 1, 0, 0);
    delay(stepDelay);
    writeMotor(1, 1, 0, 0);
    delay(stepDelay);
    steps--;
  }
}

/*
Private Function - not callable
Writes each output to stepper motor pins.
Input variables:
			a,b,c,d: 0 (off) or 1 (on)
Output: none
*/
void simpleStepper::writeMotor(int a, int b, int c, int d) {
  digitalWrite(_pinOne, a);
  digitalWrite(_pinTwo, b);
  digitalWrite(_pinThree, c);
  digitalWrite(_pinFour, d);
}
