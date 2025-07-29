#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

#define led1 2

uint8_t led_level = 0;
TimerHandle_t xTimers;

esp_err_t init_led(void);
esp_err_t blink_led(void);
esp_err_t set_timer(void);

void app_main(void)
{
    init_led();
    set_timer();
}

esp_err_t init_led(void)
{

    gpio_reset_pin(led1);
    gpio_set_direction(led1, GPIO_MODE_OUTPUT);

    return ESP_OK;
}

esp_err_t blink_led(void)
{

    led_level = !led_level;
    gpio_set_level(led1, led_level);

    return ESP_OK;
}

esp_err_t set_timer(void)
{

    xTimers = xTimerCreate("Timer",         // Just a text name, not used by the kernel.
                           (100 * (x + 1)), // The timer period in ticks.
                           pdTRUE,          // The timers will auto-reload themselves when they expire.
                           (void *)x,       // Assign each timer a unique id equal to its array index.
                           vTimerCallback   // Each timer calls the same callback when it expires.
    );

    if (xTimers == NULL)
    {
        // The timer was not created.
    }
    else
    {
        // Start the timer.  No block time is specified, and even if one was
        // it would be ignored because the scheduler has not yet been
        // started.
        if (xTimerStart(xTimers, 0) != pdPASS)
        {
            // The timer could not be set into the Active state.
        }
    }

    return ESP_OK;
}