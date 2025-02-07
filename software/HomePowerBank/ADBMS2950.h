// ADBMS2950 Header File
//
// This header file contains register and command information for dealing with the ADBMS2950 pack monitor IC.
//

#ifndef _ADBMS2950_H

#define _ADBMS2950_H

// --- Comm structure ---

#define ADBMS_DPEC_bmsk 0x03ff
#define ADBMS_DPEC_bpos 0

#define ADBMS_CCNT_bmsk 0xfc00
#define ADBMS_CCNT_bpos 10

#define ADBMS_CMD_bmsk 0x07ff
#define ADBMS_CMD_bpos 0


// --- core IC commands ---

// command "SRST" : soft reset
#define ADBMS_CMD_SRST_code 0x0027

// command "RSTCC" : reset command counter
#define ADBMS_CMD_RSTCC_code 0x002e

// command "SNAP" : freeze result registers
#define ADBMS_CMD_SNAP_code 0x002d

// command "UNSNAP" : unfreeze result registers
#define ADBMS_CMD_UNSNAP_code 0x002f


// --- ADC interaction ---

#define ADBMS_VB1_LSB_UV 100
#define ADBMS_VB2_LSB_UV -85
#define ADBMS_I1_LSB_UV 1
#define ADBMS_I2_LSB_UV -1

// command "ADI1" : start VB1 and I1 ADCs
#define ADBMS_CMD_ADI1_code 0x0260
#define ADBMS_CMD_ADI1_RD_bmsk 0x0100
#define ADBMS_CMD_ADI1_RD_bpos 8

// command "ADI2" : start VB2 and I2 ADCs
#define ADBMS_CMD_ADI2_code 0x0168

// bit definitions for ADIx command options
#define ADBMS_CMD_ADIx_OPT3_bmsk 0x0080
#define ADBMS_CMD_ADIx_OPT3_bpos 7
#define ADBMS_CMD_ADIx_OPT2_bmsk 0x0010
#define ADBMS_CMD_ADIx_OPT2_bpos 4
#define ADBMS_CMD_ADIx_OPT1_bmsk 0x0002
#define ADBMS_CMD_ADIx_OPT1_bpos 1
#define ADBMS_CMD_ADIx_OPT0_bmsk 0x0001
#define ADBMS_CMD_ADIx_OPT0_bpos 0

// command "ADV" : start V1 and V2
#define ADBMS_CMD_ADV_code 0x0403
#define ADBMS_CMD_ADV_OW_gmsk 0x00c0
#define ADBMS_CMD_ADV_OW_gpos 6
#define ADBMS_CMD_ADV_VCH_gmsk 0x000f
#define ADBMS_CMD_ADV_VCH_gpos 0

// open wire configurations for ADV command
#define ADBMS_ADV_OW_OFF 0x0
#define ADBMS_ADV_OW_POS 0x1            // note: do not use this when converting VREF: will inject current into reference and cause errors
#define ADBMS_ADV_OW_NEG 0x2

// channel configurations for V1 / V2 ADCs (ADV command)
#define ADBMS_ADV_CH_V1V1 0x0
#define ADBMS_ADV_CH_V2V2 0x1
#define ADBMS_ADV_CH_V3V3 0x2
#define ADBMS_ADV_CH_V4V4 0x3
#define ADBMS_ADV_CH_V5V5 0x4
#define ADBMS_ADV_CH_V6V6 0x5
#define ADBMS_ADV_CH_V7V9 0x6
#define ADBMS_ADV_CH_V8V10 0x7
#define ADBMS_ADV_CH_VRVR 0x8
#define ADBMS_ADV_CH_VALL 0x9
#define ADBMS_ADV_CH_V246 0xa
#define ADBMS_ADV_CH_V123456 0xb
#define ADBMS_ADV_CH_V1234 0xc
#define ADBMS_ADV_CH_V135 0xd
#define ADBMS_ADV_CH_V5678 0xe
#define ADBMS_ADV_CH_V678 0xf

// command "ADX" : start auxiliary ADC
#define ADBMS_CMD_ADX_code 0x0530

// command "CLRVX" : clear V1, V2, and AUX ADC results
#define ADBMS_CMD_CLRVX_code 0x0712

#define ADBMS_CMD_ 0x0

#define ADBMS_CMD_ 0x0

#define ADBMS_CMD_ 0x0






#endif