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
int interval = 50;
int timerId = 1;
uint32_t dutyR = 0;
uint32_t dutyG = 300;
uint32_t dutyB = 600;

esp_err_t init_led(void);
esp_err_t blink_led(void);
esp_err_t set_timer(void);
esp_err_t set_pwm(void);
esp_err_t set_pwm_duty(void);

void vTimerCallback(TimerHandle_t pxTimer){
    
    dutyR += 10;
    if( dutyR > 1023 )
        dutyR = 0;
    
    dutyG += 10;
    if( dutyG > 1023 )
        dutyG = 0;
    
    dutyB += 10;
    if( dutyB > 1023 )
        dutyB = 0;
    
    blink_led();
    set_pwm_duty();

}

void app_main(void){

    init_led();
    set_pwm();
    set_timer();

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
    
    // channel configure structures declaration
    ledc_channel_config_t channelConfigR = {0};
    ledc_channel_config_t channelConfigG = {0};
    ledc_channel_config_t channelConfigB = {0};

    // channel R structure initialization
    channelConfigR.gpio_num = 33;
    channelConfigR.speed_mode = LEDC_HIGH_SPEED_MODE;
    channelConfigR.channel = LEDC_CHANNEL_0;
    channelConfigR.intr_type = LEDC_INTR_DISABLE;
    channelConfigR.timer_sel = LEDC_TIMER_0;
    channelConfigR.duty = 0;

    // channel G structure initialization
    channelConfigG.gpio_num = 25;
    channelConfigG.speed_mode = LEDC_HIGH_SPEED_MODE;
    channelConfigG.channel = LEDC_CHANNEL_1;
    channelConfigG.intr_type = LEDC_INTR_DISABLE;
    channelConfigG.timer_sel = LEDC_TIMER_0;
    channelConfigG.duty = 0;

    // channel B structure initialization
    channelConfigB.gpio_num = 26;
    channelConfigB.speed_mode = LEDC_HIGH_SPEED_MODE;
    channelConfigB.channel = LEDC_CHANNEL_2;
    channelConfigB.intr_type = LEDC_INTR_DISABLE;
    channelConfigB.timer_sel = LEDC_TIMER_0;
    channelConfigB.duty = 0;

    // PWM channels configurations
    ledc_channel_config( &channelConfigR );
    ledc_channel_config( &channelConfigG );
    ledc_channel_config( &channelConfigB );

    // timer config structure declaration
    ledc_timer_config_t timerConfig = {0};

    // timerConfig structure fields initialization
    timerConfig.speed_mode = LEDC_HIGH_SPEED_MODE;
    timerConfig.duty_resolution = LEDC_TIMER_10_BIT;
    timerConfig.timer_num = LEDC_TIMER_0;
    timerConfig.freq_hz = 20000;    // 20kHz

    // PWM timer configuration
    ledc_timer_config( &timerConfig );

    return ESP_OK;
}

esp_err_t set_pwm_duty(void){

    ledc_set_duty( LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, dutyR);
    ledc_set_duty( LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_1, dutyG);
    ledc_set_duty( LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_2, dutyB);

    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_1);
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_2);

    return ESP_OK;

}