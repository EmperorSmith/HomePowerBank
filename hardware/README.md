# System Blocks


## Internal Power Supply

### Description

This system will take the battery bank voltage and convert it to 5V to supply various aspects of the system (microcontroller, USB port, maybe even the BMS chips).

With the battery bank currently targeted at a 16S LFP configuration, this limits the maximum voltage to about 55V. Conventional buck regulators should be able to convert at this ratio and voltage range. It is also permissible to use a flyback regulator, although this will present additional challenges over a buck regulator.

If other system rails are needed, secondary voltage regulators will be added.

There will be a secondary LV battery backup system to ensure that faults with the main bank will not cause immediate shutdown of the system. This is to ensure good shutdown and startup behavior and preserve information about the system.

### Requirements

- Input Voltage : 32V to 56V
- Input Current : (as needed)
- Output Voltage : 5V +/- 0.2V
- Output Current : at least 1.5A, no more than 3A


## Trickle Charge Circuit

### Description

This system will take in 5V from the USB port and boost it up to about 55V to trickle-charge the battery bank.

The power conversion topology chosen is a flyback converter. The step-up ratio is just too large to use a conventional boost converter.

Ideally, the output of the buck regulator will have a constant-current-limiting circuit attached to it to accommodate a wide range of battery bank voltages.

### Requirements

- Input Voltage : 5.0V +/- 0.25V
- Input Current : no more than 1A average
- Output Voltage : 53V +/- 2V
- Output Current : no more than 50mA


## USB Interface

### Description

A USB C socket will be present on the unit. It will be capable of both supplying power to an external load and drawing power from an external source.

### Requirements

Despite having a USB C connector, the port will not have full USB 3 communication capabilities. If communication is added, it will be USB 2.x compliant only.

While the port will be able to both source and sink power, USB PD communication will not be implemented. Instead, a user-activated switch will determine the direction of the power flow. On switch toggle, the USB port will fully disconnect, then reconfigure the CC pins as necessary and monitor for connection.

When sourcing power, the interface will use CC pin resistor strapping to communicate the availability of up to 1.5A of current at 5.0V to downstream devices.

When sinking power, the interface will measure the CC pin voltage and respect the current limits communicated in that manner. The trickle charge circuit will not activate unless at least 1.5A of current is available from the upstream device.

The USB port will include a power switch and current sense amplifier to monitor operation. Fault conditions will trigger a port shutdown. Reconnection will be attempted after a timeout.

## Microcontroller

### Description

A local microcontroller will handle all operation and monitoring of the battery bank and attached systems (charger, inverter, USB-attached device). It will interface with users only in the most basic of manners (buttons / switches / LED indicators). More complex interactions will require an external device, to which the microcontroller will provide information for futher processing and display. The microcontroller will retain key state information across power cycles.