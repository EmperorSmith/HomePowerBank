#ifndef _SYSPOWER_H
#define _SYSPOWER_H

#define USB_DIR_SW_PIN 23
#define USB_BUS_EN_PIN 24
#define USB_CC_DIR_PIN 25

#define USB_CC1_V_PIN 26
#define USB_CC1_V_CH 0
#define USB_CC2_V_PIN 27
#define USB_CC2_V_CH 1
#define USB_BUS_V_PIN 28
#define USB_BUS_V_CH 2

#define BKUP_CELL_V_PIN 29
#define BKUP_CELL_V_CH 3

#define HV_BUCK_EN_PIN 18

#define TRICKLE_CHG_EN_PIN 19

int SysPowerInit();



#endif