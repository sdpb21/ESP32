#include <Arduino.h>
#include <ESP32Servo.h>

#define servoDataPin 26

Servo servo1;

void setup() {

  servo1.attach(servoDataPin);
}

void loop() {
  // put your main code here, to run repeatedly:
}
