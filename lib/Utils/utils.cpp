#include <Arduino.h>
#include <Servo.h>

void motorControl(Servo motor, int value) {
  motor.write(map(value, -255, 255, 1000, 2000));
}
