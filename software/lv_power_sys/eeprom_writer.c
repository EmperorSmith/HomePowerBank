#include <avr/eeprom.h>


int main()
{

    // ----- Smith Empire Laboratory information -----
    // takes up first 64B of EEPROM

    // write SELabs unit code information
    eeprom_busy_wait();
	eeprom_write_word(0,1);     // project code, uint16
	eeprom_busy_wait();
	eeprom_write_byte(2,0);     // hw rev, uint8
	eeprom_busy_wait();
	eeprom_write_byte(3,0);     // sw rev, uint8
	eeprom_busy_wait();
	eeprom_write_word(4,2025);  // year, uint16
	eeprom_busy_wait();
	eeprom_write_byte(6,10);     // month, uint8
	eeprom_busy_wait();
	eeprom_write_byte(7,20);    // day, uint8
    eeprom_busy_wait();
	eeprom_write_dword(8,0);    // serial number, uint32
	eeprom_busy_wait();
    
    // write SELabs header; values are stored little endian, so 4th character first
    //
    // for example, first line writes "Smit" of "SmithEmpireLabs"; visually, however,
    // the characters look like "timS"; comments show characters if you were to
    // read out the entire eeprom byte by byte, lowest byte first
    //
    // full string: "SmithEmpireLabs www.thesmithempire.net (c) 2025 "
    
	eeprom_write_dword(16,0x74696d53);  // "Smit"
	eeprom_busy_wait();
	eeprom_write_dword(20,0x706d4568);  // "hEmp"
	eeprom_busy_wait();
	eeprom_write_dword(24,0x4c657269);  // "ireL"
	eeprom_busy_wait();
	eeprom_write_dword(28,0x20736261);  // "abs "
	eeprom_busy_wait();
	eeprom_write_dword(32,0x2e777777);  // "www."
	eeprom_busy_wait();
	eeprom_write_dword(36,0x73656874);  // "thes"
	eeprom_busy_wait();
	eeprom_write_dword(40,0x6874696d);  // "mith"
	eeprom_busy_wait();
	eeprom_write_dword(44,0x69706d65);  // "empi"
	eeprom_busy_wait();
	eeprom_write_dword(48,0x6e2e6572);  // "re.n"
	eeprom_busy_wait();
	eeprom_write_dword(52,0x28207465);  // "et ("
	eeprom_busy_wait();
	eeprom_write_dword(56,0x32202963);  // "c) 2"
	eeprom_busy_wait();
	eeprom_write_dword(60,0x20353230);  // "025 "
	eeprom_busy_wait();

    // ----- ADC calibration information -----
    // NOTE : values below are nominal, not per-unit calibrated
    
    // ADC channel gains
    eeprom_write_word(64,1282);         // ADC ch 0 (USB VBUS) gain, uV / LSb
	eeprom_busy_wait();
    eeprom_write_word(66,1282);         // ADC ch 1 (USB CC1) gain, uV / LSb
	eeprom_busy_wait();
    eeprom_write_word(68,1282);         // ADC ch 2 (USB CC2) gain, uV / LSb
	eeprom_busy_wait();
    eeprom_write_word(70,1221);         // ADC ch 3 (backup cell) gain, uV / LSb
	eeprom_busy_wait();
    eeprom_write_word(72,410);          // ADC ch 4 (internal sup/10) gain, uV / LSb
	eeprom_busy_wait();
    
    // ADC channel offsets
    eeprom_write_word(80,0);            // ADC ch 0 (USB VBUS) offset, mV
	eeprom_busy_wait();
    eeprom_write_word(82,0);            // ADC ch 1 (USB CC1) offset, mV
	eeprom_busy_wait();
    eeprom_write_word(84,0);            // ADC ch 2 (USB CC2) offset, mV
	eeprom_busy_wait();
    eeprom_write_word(86,0);            // ADC ch 3 (backup cell) offset, mV
	eeprom_busy_wait();
    eeprom_write_word(88,0);            // ADC ch 4 (internal sup/10) offset, mV
	eeprom_busy_wait();
    
    // ( next section of EEPROM writing )
    // ( wait after each write just to be sure )
    // ( command format is eeprom_write_####(addr,data) )
    // ( options for #### are "byte" and "word" and "dword" for 1B/2B/4B respectively )
    
    return 0;

}