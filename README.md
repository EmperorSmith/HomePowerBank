# HomePowerBank

This project is a combined hardware-software effort around designing a control / management system for a home power bank. Unlike commercial USB power banks, this one is intended to serve as a sort of "generator substitute," having a stack of batteries large enough to supply an inverter during situations that otherwise lack power (general outage, off-grid living, etc).

# Design Goals

## Primary Goals

- Monitor a multi-cell battery stack
    - Measure cell voltage
    - Measure stack voltage
    - Measure stack current
    - Measure temperatures
    - Estimate cell state-of-charge
- Report monitored state to user
- Accept and react to user input for basic operations
- Protect pack against fault conditions
    - Overvoltage / Overcharge
    - Undervoltage / Undercharge
    - Overcurrent
    - Overtemperature
- Integrate control of external charger and inverter
    - Connect & disconnect battery stack bus and external devices
    - Produce on/off control output to charger
    - Take in fault input from charger
    - Produce on/off control output to inverter
    - Take in fault input from inverter

## Secondary Goals

- Provide bidirectional USB-C charging port
    - Supply external loads with 5V 1.5A power
    - Trickle-charge bank from external supply
- Take control commands from external communication interface
- Implement advanced diagnostics
- Implement flexible / extensible stack architecture
    - Adapt to different cell and IC counts
    - Adapt to different cell chemistries

# Tools

As much as possible, the tools used to produce the design should be freely available.

- Circuit schematic and layout creation will take place in [KiCAD](www.kicad.org)
- Block diagrams and similar drawing should use [draw.io](www.diagrams.net)
- Circuit simulations should be conducted in a free SPICE tool, like [ngspice](https://ngspice.sourceforge.io/) or [LTSpice](https://www.analog.com/en/resources/design-tools-and-calculators/ltspice-simulator.html)
- Documentation should be created using the Markdown language / format

# Philosophy

## System Design

When in doubt, design should err on the side of over-engineering, especially for the prototype phase.

## Project Code of Conduct

"Be excellent to each other" *- Bill S. Preston, Esq.*

## Usability

The system in basic form should be fully usable from the standpoint of a non-engineer, but should also offer the capabilities for a knowledgeable person to modify / alter the system to their desires.
