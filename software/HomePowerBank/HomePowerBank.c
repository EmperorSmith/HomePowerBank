#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/timer.h"
#include "hardware/watchdog.h"
#include "hardware/uart.h"


// I2C port definition
#define I2C_PORT i2c0
#define PIN_I2C_SDA 16
#define PIN_I2C_SCL 17

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    // Put your timeout handler code in here
    return 0;
}


// debug uart port definition
#define DEBUG_UART uart0
#define DEBUG_BAUD_RATE 921000

#define DEBUG_TX_PIN 4
#define DEBUG_RX_PIN 5


int core0_loop()
{
    while (true)
    {




    }

    return 0;

}


int core1_loop()
{
    while (true)
    {

        // pet watchdog
        watchdog_update();

    }

    return 0;

}


int main()
{
    stdio_init_all();


    // I2C Initialization, 400kHz
    i2c_init(I2C_PORT, 400*1000);
    
    gpio_set_function(PIN_I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(PIN_I2C_SCL, GPIO_FUNC_I2C);

    // uncomment two below if no external pullups
    // gpio_pull_up(PIN_I2C_SCL);
    // gpio_pull_up(PIN_I2C_SDA);

    // Get a free channel, panic() if there are none
    int chan = dma_claim_unused_channel(true);
    

    // Timer example code - This example fires off the callback after 2000ms
    add_alarm_in_ms(2000, alarm_callback, NULL, false);
    // For more examples of timer use see https://github.com/raspberrypi/pico-examples/tree/master/timer

    // Watchdog example code
    if (watchdog_caused_reboot()) {
        printf("Rebooted by Watchdog!\n");
        // Whatever action you may take if a watchdog caused a reboot
    }
    
    // Enable the watchdog, pause on debug
    watchdog_enable(100, 1);
    
    // You need to call this function at least more often than the 100ms in the enable call to prevent a reboot
    watchdog_update();

    // Set up our UART
    uart_init(DEBUG_UART, DEBUG_BAUD_RATE);

    gpio_set_function(DEBUG_RX_PIN, GPIO_FUNC_UART);
    gpio_set_function(DEBUG_TX_PIN, GPIO_FUNC_UART);
    
    // start up other core
    multicore_launch_core1(&core1_loop);

    // go to main task loop
    core0_loop();

}

