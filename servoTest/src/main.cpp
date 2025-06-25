/*
#include <Arduino.h>
#include <ESP32Servo.h>
*/

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "freertos/timers.h"
#include "driver/ledc.h"

#define servoDataPin 26

//Servo servo1;

void setup() {
/*
  servo1.attach(servoDataPin);  // attach or "link" the pin to the servo

  servo1.write(0);              // set the servo angle to 0 degrees
*/
}

void loop() {
/*
  delay(500);      //  a half second delay
  servo1.write(90); // sets the servo angle to 90 degrees

  delay(500);      // a half second delay
  servo1.write(180);// sets the servo angle to 180 degrees

  delay(500);      // a half second delay
  servo1.write(90); // sets the servo angle to 90 degrees

  delay(500);      // a half second delay
  servo1.write(0);  // sets the servo angle to 0 degrees
*/
}
