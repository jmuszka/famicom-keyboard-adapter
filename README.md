# Famicom Keyboard Adapter

This is an open-source firmware project for the **Pro Micro ATMEGA32u4** microcontroller to enable the **Famicom Family BASIC Keyboard** to interface with modern USB devices by implementing USB HID protocols. The project is written in C using the AVR-GCC toolchain.

Currently, I am waiting for necessary parts to arrive before I formally embark on this project. For now, I have written a basic program to repeatedly blink the LEDs on my board to ensure that my toolchain, compiler configurations, and OS permissions are properly set up.

## About

For those unfamiliar with 1980s gaming history, the Nintendo Family Computer (Famicom) was the Japanese version of the Nintendo Entertainment System (NES), featuring a bold red and white, angular design compared to the more VCR-like appearance of the NES.

In Japan, Famicom owners could buy a game cartridge that contained a word processor and other software that could transform the console into a home computer. Users would plug the Family BASIC Keyboard into the Famicom in order to interact with this software.

Many of these keyboards still exist as antiques, but they use an old DA15 connector that virtually no modern hardware is compatible with (and moreover, the Family BASIC Keyboard uses a proprietary matrix to map key presses to characters).

After purchasing one of these keyboards, I set out to create a USB adapter to use the keyboard on a modern personal computer and turn this device into more than just a collectors' item.

## Hardware

- Famicom Family BASIC Keyboard
- DA15 receiver
- Pro Micro ATmega32u4 5V 16MHz microcontroller
- 170-point breadboard and jumper wires
- 100k Ohm resistors
- USB-A to Micro-USB connector

I will document the assembly as I go. I also plan on 3D-printing a case for the board.

## Dependencies & Installation

Dependencies:
- avr-gcc 14.2.0 (for compiling the C code)
- avrdude 8.0 (for flashing the compiled binaries to the board)
- avr-libc 2.1.1 (AVR C programming library)

After installing the dependencies, follow these steps:
1. `git clone https://github.com/jmuszka/famicom-keyboard-adapter.git`
2. `cd famicom-keyboard-adapter/`
3. Run `make` to compile the source code
    - The makefile assumes your board is connected to `/dev/ttyACM0`
    - Plug in your board and check which port it is connected to, and change accordingly
    - Also change the `F_CPU` if your board has a frequency other than `16 MHz`
4. Reset your board
    - Some boards have a physical reset button
    - In my case, I had to short the GROUND and RESET pins twice using a multimeter (a jumper cable should also work)
    - This puts the board into bootloader mode for 8 seconds
5. Flash the program onto the board with `make flash`

After following these steps, you will now have a Family BASIC Keyboard adapter.
