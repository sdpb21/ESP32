#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "freertos/timers.h"
#include "driver/ledc.h"

#define led1 2
uint8_t led_level = 0;
static const char *tag = "Main";
TimerHandle_t xTimers;
int interval = 500;
int timerId = 1;

esp_err_t init_led(void);
esp_err_t blink_led(void);
esp_err_t set_timer(void);
esp_err_t set_pwm(void);

void vTimerCallback(TimerHandle_t pxTimer){
    //
}

void app_main(void){
    //
}

esp_err_t init_led(void){
    //
}

esp_err_t blink_led(void){
    //
}

esp_err_t set_timer(void){
    //
}

esp_err_t set_pwm(void){
    //
}