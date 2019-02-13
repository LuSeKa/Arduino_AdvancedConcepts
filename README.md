# Arduino_AdvancedConcepts
A litttle Arduino projects, showing some intermediate/advanced programming techniques

## Exemplified Concepts
* Scheduling (cooperative multitasking) using Metro
* Paramter setting via the serial input
* Using a config.h file
* Using the serial plotter
* Classes

## External Dependencies

### Metro library for cooperative multitasking (forked from the original work by thomasfredericks):
https://github.com/LuSeKa/Metro

## Usage

### Basic
To simply see the program in action, cmpile and upload to the Arduino. Open the serial plotter (under Tools in the Arduino IDE) (115200baud) and watch the curves evolve.

### Configured
Open the config.h and play with the parameters. For example, set a much lower frequency in line 8. Compile, upload, and watch the effect in the plotter.

### Interactive
Open a serial monitor (115200bps) and type

g0

This will deactivate the spam.
(Alternatively, set PRINT_ON_STARTUP in line 9 of config.h to false.)
Set some new values, e.g. increase to amplitudes to 100 with

a100

Reactivate the outputs, e.g. with

g10

and spot the difference!
