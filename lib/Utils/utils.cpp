#include <Arduino.h>
#include <utils.h>

void motorControl(Motor motor, int speed) {
  if (speed == 0) {
    digitalWrite(motor.inputPin1, LOW);
	  digitalWrite(motor.inputPin2, LOW);
    analogWrite(motor.speedPin, 255);
  } else if (speed < 0) {
    digitalWrite(motor.inputPin1, HIGH);
	  digitalWrite(motor.inputPin2, LOW);
    analogWrite(motor.speedPin, abs(speed));
  } else {
    digitalWrite(motor.inputPin1, LOW);
	  digitalWrite(motor.inputPin2, HIGH);
    analogWrite(motor.speedPin, abs(speed));
  }
}
