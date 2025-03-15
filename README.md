# 8-Bit Binary Light Switch
A simple AVR-based project that uses binary inputs to control individual LEDs.

## Overview

This project implements a binary decoder using an AVR microcontroller. It reads the state of 3 input switches (providing 8 possible combinations) and lights up a corresponding LED based on the binary value.

## Hardware Requirements

* AVR microcontroller (e.g., ATmega328P, Arduino Uno, etc.)
* 6 LEDs connected to PORTD pins 2-7
* 6 220 Ohm Resistors connected between the pins and anode of LED
* 3 10k pull down resistors connected in parallel with ground and each switch output pin
* 3-position slide switch connected to PORTB pins 0-2 pins 8-10

## Wiring

* Inputs: Connect switches to PORTB pins 0-2 (PB0, PB1, PB2)
* Outputs: Connect LEDs to PORTD pins 2-7 (PD2, PD3, PD4, PD5, PD6, PD7)
<img src="./8BitBinaryDecoder.jpg"/>
Please ignore the photoresistor in the bottom left of the breadboard

## [DEMO]("https://youtube.com/shorts/cXtNjOI3j3I?si=PnNXgZMgpXgUl6An")
Just a youtube video for now. Check it out...

## How It Works

1. The program reads the state of the three-position slide switch connected to PORTB (pins 0-2)
2. Based on the binary value (0-7) of these switches, it turns on the corresponding LED:

* Value 0: All LEDs off
* Value 1: LED on PD2 turns on
* Value 2: LED on PD3 turns on
* Value 3: LED on PD4 turns on
* Value 4: LED on PD5 turns on
* Value 5: LED on PD6 turns on
* Value 6: LED on PD7 turns on
* Value 7: No LED assigned in current implementation



## Building and Flashing
```bash Compile the code
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o 8BitBinaryLightSwitch.elf main.c
# Create hex file
avr-objcopy -O ihex 8BitBinaryLightSwitch.elf 8BitBinaryLightSwitch.hex
# Flash to microcontroller (adjust programmer settings as needed)
avrdude -c [programmer] -p m328p -U flash:w:8BitBinaryLightSwitch.hex
```

## Code Explanation
The program:

1. Configures PORTD pins 2-7 as outputs for the LEDs
2. Configures PORTB pins 0-2 as inputs for the switches
3. In an infinite loop:

* Reads the switch state
* Uses a switch statement to determine which LED to light
* Updates the LED outputs
* Adds a small delay for debounce



## Troubleshooting

* If no LEDs turn on, check your wiring and ensure the power is connected.
* If only some LEDs work, verify individual LED connections and resistors.
* If the LED behavior is erratic, ensure you have proper pull-up or pull-down resistors on your slide switches.

## License
[MIT License](LICENSE)
