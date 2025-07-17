#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

#define servoDataPin 26

//Servo servo1;
/*
  servo1.attach(servoDataPin);  // attach or "link" the pin to the servo

  servo1.write(0);              // set the servo angle to 0 degrees
*/

void app_main(void)
{
/*
  delay(500);      //  a half second delay
  servo1.write(90); // sets the servo angle to 90 degrees
*/
  vTaskDelay(500 / portTICK_PERIOD_MS);   // 1/2 second delay
/*
  delay(500);      // a half second delay
  servo1.write(180);// sets the servo angle to 180 degrees
*/
  vTaskDelay(500 / portTICK_PERIOD_MS);   // 1/2 second delay
/*
  delay(500);      // a half second delay
  servo1.write(90); // sets the servo angle to 90 degrees
*/
  vTaskDelay(500 / portTICK_PERIOD_MS);   // 1/2 second delay
/*
  delay(500);      // a half second delay
  servo1.write(0);  // sets the servo angle to 0 degrees
*/
  vTaskDelay(500 / portTICK_PERIOD_MS);   // 1/2 second delay
  
}
