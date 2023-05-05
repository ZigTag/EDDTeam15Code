struct Motor {
  int inputPin1;
  int inputPin2;
  int speedPin;
};

void motorControl(Motor motor, int speed);