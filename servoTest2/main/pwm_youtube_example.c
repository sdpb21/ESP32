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
    
    ledc_channel_config_t channelConfigR = {0};
    ledc_channel_config_t channelConfigG = {0};
    ledc_channel_config_t channelConfigB = {0};

    channelConfigR.gpio_num = 33;
    channelConfigR.speed_mode = LEDC_HIGH_SPEED_MODE;
    channelConfigR.channel = LEDC_CHANNEL_0;
    channelConfigR.intr_type = LEDC_INTR_DISABLE;
    channelConfigR.timer_sel = LEDC_TIMER_0;
    channelConfigR.duty = 0;

    channelConfigG.gpio_num = 25;
    channelConfigG.speed_mode = LEDC_HIGH_SPEED_MODE;
    channelConfigG.channel = LEDC_CHANNEL_1;
    channelConfigG.intr_type = LEDC_INTR_DISABLE;
    channelConfigG.timer_sel = LEDC_TIMER_0;
    channelConfigG.duty = 0;

    channelConfigB.gpio_num = 26;
    channelConfigB.speed_mode = LEDC_HIGH_SPEED_MODE;
    channelConfigB.channel = LEDC_CHANNEL_2;
    channelConfigB.intr_type = LEDC_INTR_DISABLE;
    channelConfigB.timer_sel = LEDC_TIMER_0;
    channelConfigB.duty = 0;

    return ESP_OK;
}