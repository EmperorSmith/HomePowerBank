# HomePowerBank

This project is a combined hardware-software effort around designing a control / management system for a home power bank. Unlike commercial USB power banks, this one is intended to serve as a sort of "generator substitute," having a stack of batteries large enough to supply an inverter during situations that otherwise lack power (general outage, off-grid living, etc).

# Design Goals

- Monitor a multi-cell battery stack
    - Measure cell voltage
    - Measure stack voltage
    - Measure stack current
    - Measure temperatures
    - Estimate cell state-of-charge
- Report monitored state to user
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

# Tools

As much as possible, the tools used to produce the design should be freely available.

- Circuit schematic and layout creation will take place in KiCAD
- Block diagrams and similar drawing should use draw.io
- Documentation should be created using the Markdown language / format


# Philosophy

## System Design

When in doubt, design should err on the side of over-engineering, especially for the prototype phase.

## Project Code of Conduct

"Be excellent to each other" *- Bill S. Preston, Esq.*

## Usability

The system in basic form should be fully usable from the standpoint of a non-engineer, but should also offer the capabilities for a knowledgeable person to modify / alter the system to their desires