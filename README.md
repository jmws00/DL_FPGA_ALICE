# Laser Control System on FPGA Artix-7

## Project Description
Project based on the Arty S7 board with MicroBlaze processor. The system generates a series of laser control pulses according to parameters entered by the user via UART. A Verilog counter generates N pulses with duration T2 within interval T1. If T1 is longer than the pulse generation time, the signal remains low until the end of T1.

## Features
* Generation of N laser pulses
* Configurable total series duration (T1)
* Definable single pulse duration (T2)
* UART interface communication
* Control through terminal commands
* Implementation in Verilog and on MicroBlaze processor

## System Architecture
### Hardware
* Development board: Artix-7 FPGA
* Processor: MicroBlaze (soft processor)
* Communication interface: UART

## Operating Principle
1. User enters parameters through UART terminal:
   * N: number of pulses in series
   * T1: total series duration
   * T2: single pulse duration
2. System generates a series of N pulses with duration T2 each
3. If T1 is longer than the time needed to generate all pulses, the signal remains at 0 until the end of T1

## Configuration and Usage
1. Connect to the system via UART
2. Use terminal to send configuration commands

## Authors
Jakub Marszałek

Wiktor Szmyd
