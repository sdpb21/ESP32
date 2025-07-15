#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "freertos/timers.h"

/**
 * TimerHandle_t xTimerCreate(  const char * const pcTimerName,
 *                              TickType_t xTimerPeriodInTicks,
 *                              BaseType_t xAutoReload,
 *                              void * pvTimerID,
 *                              TimerCallbackFunction_t pxCallbackFunction );
 *
 * Creates a new software timer instance, and returns a handle by which the
 * created software timer can be referenced.
 *
 * Internally, within the FreeRTOS implementation, software timers use a block
 * of memory, in which the timer data structure is stored.  If a software timer
 * is created using xTimerCreate() then the required memory is automatically
 * dynamically allocated inside the xTimerCreate() function.  (see
 * https://www.FreeRTOS.org/a00111.html).  If a software timer is created using
 * xTimerCreateStatic() then the application writer must provide the memory that
 * will get used by the software timer.  xTimerCreateStatic() therefore allows a
 * software timer to be created without using any dynamic memory allocation.
 *
 * Timers are created in the dormant state.  The xTimerStart(), xTimerReset(),
 * xTimerStartFromISR(), xTimerResetFromISR(), xTimerChangePeriod() and
 * xTimerChangePeriodFromISR() API functions can all be used to transition a
 * timer into the active state.
 *
 * @param pcTimerName A text name that is assigned to the timer.  This is done
 * purely to assist debugging.  The kernel itself only ever references a timer
 * by its handle, and never by its name.
 *
 * @param xTimerPeriodInTicks The timer period.  The time is defined in tick
 * periods so the constant portTICK_PERIOD_MS can be used to convert a time that
 * has been specified in milliseconds.  For example, if the timer must expire
 * after 100 ticks, then xTimerPeriodInTicks should be set to 100.
 * Alternatively, if the timer must expire after 500ms, then xPeriod can be set
 * to ( 500 / portTICK_PERIOD_MS ) provided configTICK_RATE_HZ is less than or
 * equal to 1000.  Time timer period must be greater than 0.
 *
 * @param xAutoReload If xAutoReload is set to pdTRUE then the timer will
 * expire repeatedly with a frequency set by the xTimerPeriodInTicks parameter.
 * If xAutoReload is set to pdFALSE then the timer will be a one-shot timer and
 * enter the dormant state after it expires.
 *
 * @param pvTimerID An identifier that is assigned to the timer being created.
 * Typically this would be used in the timer callback function to identify which
 * timer expired when the same callback function is assigned to more than one
 * timer.
 *
 * @param pxCallbackFunction The function to call when the timer expires.
 * Callback functions must have the prototype defined by TimerCallbackFunction_t,
 * which is "void vCallbackFunction( TimerHandle_t xTimer );".
 *
 * @return If the timer is successfully created then a handle to the newly
 * created timer is returned.  If the timer cannot be created because there is
 * insufficient FreeRTOS heap remaining to allocate the timer
 * structures then NULL is returned.
 *
 * Example usage:
 * @verbatim
 */ #define NUM_TIMERS 5

 // An array to hold handles to the created timers.
 TimerHandle_t xTimers[ NUM_TIMERS ];

 // An array to hold a count of the number of times each timer expires.
 int32_t lExpireCounters[ NUM_TIMERS ] = { 0 };

 // Define a callback function that will be used by multiple timer instances.
 // The callback function does nothing but count the number of times the
 // associated timer expires, and stop the timer once the timer has expired
 // 10 times.
 void vTimerCallback( TimerHandle_t pxTimer )
 {
 int32_t lArrayIndex;
 const int32_t xMaxExpiryCountBeforeStopping = 10;

     // Optionally do something if the pxTimer parameter is NULL.
     configASSERT( pxTimer );

     // Which timer expired?
     lArrayIndex = ( int32_t ) pvTimerGetTimerID( pxTimer );

     // Increment the number of times that pxTimer has expired.
     lExpireCounters[ lArrayIndex ] += 1;

     // If the timer has expired 10 times then stop it from running.
     if( lExpireCounters[ lArrayIndex ] == xMaxExpiryCountBeforeStopping )
     {
         // Do not use a block time if calling a timer API function from a
         // timer callback function, as doing so could cause a deadlock!
         xTimerStop( pxTimer, 0 );
     }
 }

void main( void )
{
int32_t x;

     // Create then start some timers.  Starting the timers before the scheduler
     // has been started means the timers will start running immediately that
     // the scheduler starts.
     for( x = 0; x < NUM_TIMERS; x++ )
     {
         xTimers[ x ] = xTimerCreate(    "Timer",             // Just a text name, not used by the kernel.
                                         (5000 / portTICK_PERIOD_MS), // The timer period in ticks (5 seconds).
                                         pdTRUE,              // The timers will auto-reload themselves when they expire.
                                         ( void * ) x,        // Assign each timer a unique id equal to its array index.
                                         vTimerCallback       // Each timer calls the same callback when it expires.
                                     );

         if( xTimers[ x ] == NULL )
         {
             // The timer was not created.
         }
         else
         {
             // Start the timer.  No block time is specified, and even if one was
             // it would be ignored because the scheduler has not yet been
             // started.
             if( xTimerStart( xTimers[ x ], 0 ) != pdPASS )
             {
                 // The timer could not be set into the Active state.
             }
         }
     }

     // ...
     // Create tasks here.
     // ...

     // Starting the scheduler will start the timers running as they have already
     // been set into the active state.
     vTaskStartScheduler();

     // Should not reach here.
     for( ;; );
}
// * @endverbatim
//*/
