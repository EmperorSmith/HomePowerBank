#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "CellMon.h"
#include "ADBMS6830.h"

int CellMonInit()
{


    // cell monitor SPI initialization
    spi_init(CELL_SPI_PORT, 2000*1000);
    gpio_set_function(PIN_C_CIPO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_C_CS,   GPIO_FUNC_SIO);
    gpio_set_function(PIN_C_SCK,  GPIO_FUNC_SPI);
    gpio_set_function(PIN_C_COPI, GPIO_FUNC_SPI);
    
    // Chip select is active-low, so set high at first
    gpio_set_dir(PIN_C_CS, GPIO_OUT);
    gpio_put(PIN_C_CS, 1);




    return 0;
    
}

void cs_en()
{
    asm volatile ("nop \n nop \n nop");
    gpio_put(PIN_C_CS,0);
    asm volatile ("nop \n nop \n nop");

}

void cs_dis()
{
    asm volatile ("nop \n nop \n nop");
    gpio_put(PIN_C_CS,1);
    asm volatile ("nop \n nop \n nop");

}