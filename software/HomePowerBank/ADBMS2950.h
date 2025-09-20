// ADBMS2950 Header File
//
// This header file contains register and command information for dealing with the ADBMS2950 pack monitor IC.
//

#ifndef _ADBMS2950_H

#define _ADBMS2950_H

// --- Comm structure ---

#define ADBMS2950_DPEC_bmsk 0x03ff
#define ADBMS2950_DPEC_bpos 0

#define ADBMS2950_CCNT_bmsk 0xfc00
#define ADBMS2950_CCNT_bpos 10

#define ADBMS2950_CMD_bmsk 0x07ff
#define ADBMS2950_CMD_bpos 0


// --- core IC commands ---

// command "SRST" : soft reset
#define ADBMS2950_CMD_SRST_code 0x0027

// command "RSTCC" : reset command counter
#define ADBMS2950_CMD_RSTCC_code 0x002e

// command "SNAP" : freeze result registers
#define ADBMS2950_CMD_SNAP_code 0x002d

// command "UNSNAP" : unfreeze result registers
#define ADBMS2950_CMD_UNSNAP_code 0x002f


// --- ADC interaction ---

#define ADBMS2950_VB1_LSB_UV 100
#define ADBMS2950_VB2_LSB_UV -85
#define ADBMS2950_I1_LSB_UV 1
#define ADBMS2950_I2_LSB_UV -1

// command "ADI1" : start VB1 and I1 ADCs
#define ADBMS2950_CMD_ADI1_code 0x0260
#define ADBMS2950_CMD_ADI1_RD_bmsk 0x0100
#define ADBMS2950_CMD_ADI1_RD_bpos 8

// command "ADI2" : start VB2 and I2 ADCs
#define ADBMS2950_CMD_ADI2_code 0x0168

// bit definitions for ADIx command options
#define ADBMS2950_CMD_ADIx_OPT3_bmsk 0x0080
#define ADBMS2950_CMD_ADIx_OPT3_bpos 7
#define ADBMS2950_CMD_ADIx_OPT2_bmsk 0x0010
#define ADBMS2950_CMD_ADIx_OPT2_bpos 4
#define ADBMS2950_CMD_ADIx_OPT1_bmsk 0x0002
#define ADBMS2950_CMD_ADIx_OPT1_bpos 1
#define ADBMS2950_CMD_ADIx_OPT0_bmsk 0x0001
#define ADBMS2950_CMD_ADIx_OPT0_bpos 0

// command "ADV" : start V1 and V2
#define ADBMS2950_CMD_ADV_code 0x0403
#define ADBMS2950_CMD_ADV_OW_gmsk 0x00c0
#define ADBMS2950_CMD_ADV_OW_gpos 6
#define ADBMS2950_CMD_ADV_VCH_gmsk 0x000f
#define ADBMS2950_CMD_ADV_VCH_gpos 0

// open wire configurations for ADV command
#define ADBMS2950_ADV_OW_OFF 0x0
#define ADBMS2950_ADV_OW_POS 0x1            // note: do not use this when converting VREF: will inject current into reference and cause errors
#define ADBMS2950_ADV_OW_NEG 0x2

// channel configurations for V1 / V2 ADCs (ADV command)
#define ADBMS2950_ADV_CH_V1V1 0x0
#define ADBMS2950_ADV_CH_V2V2 0x1
#define ADBMS2950_ADV_CH_V3V3 0x2
#define ADBMS2950_ADV_CH_V4V4 0x3
#define ADBMS2950_ADV_CH_V5V5 0x4
#define ADBMS2950_ADV_CH_V6V6 0x5
#define ADBMS2950_ADV_CH_V7V9 0x6
#define ADBMS2950_ADV_CH_V8V10 0x7
#define ADBMS2950_ADV_CH_VRVR 0x8
#define ADBMS2950_ADV_CH_VALL 0x9
#define ADBMS2950_ADV_CH_V246 0xa
#define ADBMS2950_ADV_CH_V123456 0xb
#define ADBMS2950_ADV_CH_V1234 0xc
#define ADBMS2950_ADV_CH_V135 0xd
#define ADBMS2950_ADV_CH_V5678 0xe
#define ADBMS2950_ADV_CH_V678 0xf

// command "ADX" : start auxiliary ADC
#define ADBMS2950_CMD_ADX_code 0x0530

// command "CLRVX" : clear V1, V2, and AUX ADC results
#define ADBMS2950_CMD_CLRVX_code 0x0712

// --- Configuration Interaction

// command "WRCFGA" : write configuration register A
#define ADBMS2950_CMD_WRCFGA_code 0x0001

// overcurrent enable
#define ADBMS2950_CFGA_OCEN_byte 0
#define ADBMS2950_CFGA_OCEN_bmsk 0x80

// VS5 measurement reference
#define ADBMS2950_CFGA_VS5_byte 0
#define ADBMS2950_CFGA_VS5_bmsk 0x40

// VS4 measurement reference
#define ADBMS2950_CFGA_VS4_byte 0
#define ADBMS2950_CFGA_VS4_bmsk 0x20

// VS3 measurement reference
#define ADBMS2950_CFGA_VS3_byte 0
#define ADBMS2950_CFGA_VS3_bmsk 0x10

// VS2 measurement reference
#define ADBMS2950_CFGA_VS2_byte 0
#define ADBMS2950_CFGA_VS2_bmsk 0x0c

// VS1 measurement reference 
#define ADBMS2950_CFGA_VS1_byte 0
#define ADBMS2950_CFGA_VS1_bmsk 0x03

// possible VS measurement references
#define ADBMS2950_CFGA_VS_REF_SGND 0
#define ADBMS2950_CFGA_VS_REF_1V25 1
#define ADBMS2950_CFGA_VS_REF_ALT1 2    // only valid for VS1 and VS2
#define ADBMS2950_CFGA_VS_REF_ALT2 3    // only valid for VS1 and VS2

// test mode diagnostic enable
#define ADBMS2950_CFGA_INJTM_byte 1
#define ADBMS2950_CFGA_INJTM_bmsk 0x80

// ECC diagnostic
#define ADBMS2950_CFGA_INJECC_byte 1
#define ADBMS2950_CFGA_INJECC_bmsk 0x40

// thermal shutdown diagnostic
#define ADBMS2950_CFGA_INJTS_byte 1
#define ADBMS2950_CFGA_INJTS_bmsk 0x10

// supply monitor diagnostic
#define ADBMS2950_CFGA_INJMON_byte 1
#define ADBMS2950_CFGA_INJMON_bmsk 0x0c

// supply monitor injection options
#define ADBMS2950_CFGA_INJMON_NORM 0
#define ADBMS2950_CFGA_INJMON_MISMTCH 1
#define ADBMS2950_CFGA_INJMON_UV 2
#define ADBMS2950_CFGA_INJMON_OV 3

// oscillator monitor diagnostic
#define ADBMS2950_CFGA_INJOSC_byte 1
#define ADBMS2950_CFGA_INJOSC_bmsk 0x03

// oscillator monitor injection options
#define ADBMS2950_CFGA_INJOSC_NORM 0
#define ADBMS2950_CFGA_INJOSC_FAST 1
#define ADBMS2950_CFGA_INJOSC_SLOW 2
#define ADBMS2950_CFGA_INJOSC_STK 3

// V1/V2 open wire soak time
#define ADBMS2950_CFGA_SOAK_byte 2
#define ADBMS2950_CFGA_SOAK_bmsk 0xE0

// soak time options
#define ADBMS2950_CFGA_SOAK_OFF 0
#define ADBMS2950_CFGA_SOAK_100U 1
#define ADBMS2950_CFGA_SOAK_500U 2
#define ADBMS2950_CFGA_SOAK_1M 3
#define ADBMS2950_CFGA_SOAK_2M 4
#define ADBMS2950_CFGA_SOAK_10M 5
#define ADBMS2950_CFGA_SOAK_20M 6
#define ADBMS2950_CFGA_SOAK_150M 7

// VS10 measurement reference
#define ADBMS2950_CFGA_VS10_byte 2
#define ADBMS2950_CFGA_VS10_bmsk 0x10

// VS9 measurement reference
#define ADBMS2950_CFGA_VS9_byte 2
#define ADBMS2950_CFGA_VS9_bmsk 0x08

// VS8 measurement reference
#define ADBMS2950_CFGA_VS8_byte 2
#define ADBMS2950_CFGA_VS8_bmsk 0x04

// VS7 measurement reference
#define ADBMS2950_CFGA_VS7_byte 2
#define ADBMS2950_CFGA_VS7_bmsk 0x02

// VS6 measurement reference
#define ADBMS2950_CFGA_VS6_byte 2
#define ADBMS2950_CFGA_VS6_bmsk 0x01

// GPO6 control
#define ADBMS2950_CFGA_GPO6C_byte 3
#define ADBMS2950_CFGA_GPO6C_bmsk 0x60

// GPO5 control
#define ADBMS2950_CFGA_GPO5C_byte 3
#define ADBMS2950_CFGA_GPO5C_bmsk 0x10

// GPO4 control
#define ADBMS2950_CFGA_GPO4C_byte 3
#define ADBMS2950_CFGA_GPO4C_bmsk 0x08

// GPO3 control
#define ADBMS2950_CFGA_GPO3C_byte 3
#define ADBMS2950_CFGA_GPO3C_bmsk 0x04

// GPO2 control
#define ADBMS2950_CFGA_GPO2C_byte 3
#define ADBMS2950_CFGA_GPO2C_bmsk 0x02

// GPO1 control
#define ADBMS2950_CFGA_GPO1C_byte 3
#define ADBMS2950_CFGA_GPO1C_bmsk 0x01

// GPOx output options
#define ADBMS2950_CFGA_GPOC_LO 0
#define ADBMS2950_CFGA_GPOC_HI 1        // either high impedance or high logic (depending on config)
#define ADBMS2950_CFGA_GPOC_200KHZ 2    // only valid for GPO6


#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk

#define ADBMS2950_CFGA__byte
#define ADBMS2950_CFGA__bmsk



#define ADBMS2950_CMD_ 0x0

#define ADBMS2950_CMD_ 0x0






#endif