#include <Arduino.h>
#include <ESP32Servo.h>

#define servoDataPin 26

Servo servo1;

void setup() {

  servo1.attach(servoDataPin);  // attach or "link" the pin to the servo

  servo1.write(0);              // set the servo angle to 0 degrees

}

void loop() {

  delay(2000);      // 2 seconds delay
  servo1.write(90); // sets the servo angle to 90 degrees

  delay(2000);      // 2 seconds delay
  servo1.write(180);// sets the servo angle to 180 degrees

  delay(2000);      // 2 seconds delay
  servo1.write(90); // sets the servo angle to 90 degrees

  delay(2000);      // 2 seconds delay
  servo1.write(0);  // sets the servo angle to 0 degrees

}
