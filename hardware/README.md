# System Blocks


## Internal Power Supply

### Description

This system will take the battery bank voltage and convert it to 5V to supply various aspects of the system (microcontroller, USB port, maybe even the BMS chips).

With the battery bank currently targeted at a 16S LFP configuration, this limits the maximum voltage to about 55V. Conventional buck regulators should be able to convert at this ratio and voltage range. If other system rails are needed, secondary voltage regulators will be added

### Specifications

- Input Voltage : 32V to 56V
- Input Current : (as needed)
- Output Voltage : 5V +/- 0.2V
- Output Current : at least 1.5A, no more than 3A


## Trickle Charge Circuit

### Description

This system will take in 5V from the USB port and boost it up to about 55V to trickle-charge the battery bank.

The power conversion topology chosen is a flyback converter. The step-up ratio is just too large to use a conventional boost converter.

Ideally, the output of the buck regulator will have a constant-current-limiting circuit attached to it to accommodate a wide range of battery bank voltages.

### Specifications

- Input Voltage : 5.0V +/- 0.25V
- Input Current : no more than 1A average
- Output Voltage : 53V +/- 2V
- Output Current : no more than 50mA

