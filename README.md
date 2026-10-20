# Embedded-M05 ⚡

<p align="center">
  <img src="assets/atmega328p.png" alt="ATmega328P board illustration" width="330" height="170" style="border-radius: 12px;" />
</p>

This module introduces analog-to-digital conversion and sensor reading on AVR microcontrollers. It focuses on the ADC peripheral, conversion timing, and the transmission of measured values to a host system for monitoring or debugging.

The main goal is to understand how embedded firmware reads analog inputs, converts them into digital values, and exposes them through a serial interface.

## What you learn 🧠

This repository introduces the key concepts of ADC and sensor acquisition on AVR systems:

- ADC initialization and reference selection
- Conversion enable and prescaler setup
- Reading analog values from input channels
- Left-adjusted result handling for 8-bit output
- Value formatting and serial printing
- Sensor monitoring and telemetry-style firmware patterns

## Project setup 🛠️

This repository contains several small exercises under separate folders such as `ex00`, `ex01`, and `ex02`.

Each exercise focuses on a practical stage of ADC and MCU interfacing, often combining analog reading with UART output for debugging or data display.

## Build commands 🔧

From the project root, you can compile an exercise with:

```bash
make -C ex00 hex
```

To flash the firmware to the board:

```bash
make -C ex00 flash
```

To build and flash in one step:

```bash
make -C ex00 all
```

To clean generated build files:

```bash
make -C ex00 clean
```

If you are inside the exercise folder itself, the commands are simply:

```bash
make hex
make flash
make all
make clean
```

## Required tools 🧰

You need the AVR toolchain installed on your machine:

- `avr-gcc`
- `avr-libc`
- `avr-objcopy`
- `avrdude`

On Debian/Ubuntu-based systems:

```bash
sudo apt update
sudo apt install gcc-avr avr-libc avrdude
```

## Hardware used 🖥️

This project targets an ATmega328P-based board, typically an Arduino-compatible board.

Typical hardware components:

- ATmega328P microcontroller
- Potentiometer or analog sensor
- ADC-capable input pin
- USB serial interface for reading measured values
- Breadboard and jumper wires

## Useful resources 📚

- ATmega328P datasheet: https://www.microchip.com/en-us/product/ATmega328P
- AVR libc documentation: https://www.nongnu.org/avr-libc/user-manual/
- AVR-GCC toolchain: https://gcc.gnu.org/wiki/avr-gcc
- avrdude documentation: https://github.com/avrdudes/avrdude

## Notes 📝

- ADC conversions depend on a correct reference voltage and clock prescaler configuration.
- This module ties together analog input, data conversion, and debugging output, which is a common pattern in embedded systems.
- Data produced by the MCU is often displayed in a serial terminal such as `minicom`, `screen`, or a custom Python script.
