#include <Arduino.h>

#include "utils.h"

const int button1Pin = 2;
const int button2Pin = 3;
int button1State = 0;
int button2State = 0;

const int motor1InputPin1 = 7;
const int motor1InputPin2 = 8;
const int motor1SpeedPin = 9;
Motor motor1 = {motor1InputPin1, motor1InputPin2, motor1SpeedPin};

void setup() {
  Serial.begin(9600);
  Serial.println("Started Serial Port");

  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  pinMode (motor1InputPin1, OUTPUT);
  pinMode (motor1InputPin2, OUTPUT);
  pinMode (motor1SpeedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // Serial.println(button1State);

  // Serial.println(button2State);

  if (button1State == HIGH) {
    // Open
    motorControl(motor1, 255);  
  } else if (button2State == HIGH) {
    // Close
    motorControl(motor1, -255);
  } else {
    motorControl(motor1, 0);
  }

  delay(50);
}

