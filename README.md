# adf4351
Arduino Library for the ADF4351 Wideband Frequency Synthesizer chip

## Introduction

This library supports the [ADF4351 Chip](https://goo.gl/tkMjw6) from Analog Devices on Arduinos. The chip is a wideband (35 MHz to 4.4 GHz ) Phase-Locked Loop (PLL) and Voltage Controlled Oscillator (VCO), covering a very wide range frequency range
under digital control. Just add an external PLL loop filter, Reference frequency source and a power supply for a very useful 
frequency generator for applications as a Local Oscillator or Sweep Generator.  

The chip generates the frequency using a programmable Fractional-N and Integer-N Phase-Locked Loop (PLL) and Voltage Controlled Oscillator (VCO) with an external loop filter and frequency reference. The chip is controlled by 
a SPI interface, which is controlled by a microcontroller such as the Arduino.

The library provides an SPI control interface for the ADF4351, and also provides functions to calculate and set the
frequency, which greatly simplifies the integration of this chip into a design. The calculations are done using the excellent 
[Big Number Arduino Library](https://github.com/nickgammon/BigNumber) by Nick Gammon, as the integter calculations require
great than 32bit integers that are not available on the Arduino.  The library also exposes all of the PLL variables, such as FRAC, Mod and INT, so they examined as needed.  

For projects, you should consider using the  [SV1AFN ADF4351 PLL Synthesizer Module](https://www.sv1afn.com/adf4351m.html), a low cost PCB module built and designed by Makis Katsouris, SV1AFN. This board provides a loop filter, as well as providing
most of the chip control pins, SPI inteface and RF input/output ports.  This library was developed using this board.  

A low phase noise stable oscillator  is required for this module. Typically, an Ovenized Crystal Oscillator (OCXO) in the 10 MHz to 100 MHz range is used.  

## Features

+ Frequency Range: 35 MHz to 4.4 GHz
+ Output Level: -4 dBm to 5 dBm (in 3 dB steps) 
+ In-Band Phase Noise: -100 dBc/Hz (3 kHz from 2.1 Ghz carrier)
+ PLL Modes: Fraction-N and Integer-N (set automatically)
+ Step Frequency: 1 kHz to 100 MHz  
+ Signal On/Off control

##

The library is documented in the [docs directory](doc/html/), and was created using Doxygen. 
An example program using the library is provided in the source directory [example4351.ino](src/example4351.ino).

## Installation
Copy the `src/` directory to your Arduino sketchbook directory  (named the directory `example4351`), and install the libraries in your Arduino library directory.  You can also install the adf4351 files separatly  as a library.

## References

+ [ADF4351 Product Page](https://goo.gl/tkMjw6) Analog Devices
+ [SV1AFN ADF4351 Board](https://www.sv1afn.com/adf4351m.html) by Makis Katsouris, SV1AFN
+ [Big Number Arduino Library](https://github.com/nickgammon/BigNumber) by Nick Gammon
