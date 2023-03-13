#include <Arduino.h>
#include <Servo.h>

#include "utils.h"

const int button1Pin = 2;
const int button2Pin = 3;
int button1State = 0;
int button2State = 0;

const int leftMotorPin = 9;
Servo leftMotor;

void setup() {
  Serial.begin(9600);
  Serial.println("Started Serial Port");

  pinMode(button1Pin, INPUT);

  pinMode (leftMotorPin, OUTPUT);
  leftMotor.attach(leftMotorPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // Serial.println(buttonState);

  if (button1State == HIGH) {
    motorControl(leftMotor, 100);  
  } else if (button2State == HIGH) {
    motorControl(leftMotor, -100);
  } else {
    motorControl(leftMotor, 0);
  }

  delay(50);
}

