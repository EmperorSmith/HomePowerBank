#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "SysPower.h"

int SysPowerInit()
{
    // set USB port management pins
    gpio_set_dir(USB_DIR_SW_PIN,0);

    gpio_set_dir(USB_BUS_EN_PIN,1);
    gpio_put(USB_BUS_EN_PIN,0);

    gpio_set_dir(USB_CC_DIR_PIN,1);
    gpio_put(USB_CC_DIR_PIN,0);

    // set up HV buck enable pin, start with HV buck off
    gpio_set_dir(HV_BUCK_EN_PIN,1);
    gpio_put(HV_BUCK_EN_PIN,0);

    // set up trickle charger enable pin, start with trickle charger off
    gpio_set_dir(TRICKLE_CHG_EN_PIN,1);
    gpio_put(TRICKLE_CHG_EN_PIN,0);

    // set up ADC
    adc_gpio_init(USB_BUS_V_PIN);
    adc_gpio_init(USB_CC1_V_PIN);
    adc_gpio_init(USB_CC2_V_PIN);
    adc_gpio_init(BKUP_CELL_V_PIN);

    adc_init();

    

    return 0;
}