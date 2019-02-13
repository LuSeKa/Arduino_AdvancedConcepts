# Arduino_AdvancedConcepts
A litttle Arduino project to exemplify some intermediate/advanced programming concepts for Arduino.

## Exemplified Concepts
* Scheduling (cooperative multitasking) using Metro
* State machines
* Classes
* Using the serial plotter
* Paramter setting via the serial input
* Using a config.h file

### In Detail

The Arduino runs two tasks: It lets its LED blink (with variable frequency) and runs three function generators (sine, cosine and square wave).

The blink task is implemented as a simple state machine.

The function generators are all instances of the same class funcGenerator.

The output is formatted so that it can be viewed on the IDE's built-in serial plotter.

At the same time the user can set paramters and control the output via the IDE's serial monitor.

The program can be configured via a config file - no need to touch any outher files (e.g. comment out things here and there...)


## External Dependencies

### Metro library for cooperative multitasking (forked from the original work by thomasfredericks):
https://github.com/LuSeKa/Metro (clone into the library folder of your Arduino IDE)

## Usage

### Basic
To simply see the program in action, cmpile and upload to the Arduino. Open the serial plotter (under Tools in the Arduino IDE) (115200baud) and watch the curves evolve.

![grafik](https://user-images.githubusercontent.com/8363989/52743026-64f99e00-2fd9-11e9-9c10-b28ac932af57.png)

### Configured
Open the config.h and play with the parameters. For example, set a much lower frequency in line 8. Compile, upload, and watch the effect in the plotter.

![grafik](https://user-images.githubusercontent.com/8363989/52742959-40052b00-2fd9-11e9-8b1a-37e6a35ae545.png)

### Interactive
Open a serial monitor (115200bps and Newline on enter) and type

g0

This will deactivate the spam.

![grafik](https://user-images.githubusercontent.com/8363989/52743743-06cdba80-2fdb-11e9-960d-79b1037fe6e8.png)

![ExampleTerminalOutput](https://user-images.githubusercontent.com/8363989/52742703-a3db2400-2fd8-11e9-93e0-5cd8025d24f4.png)

(Alternatively, set PRINT_ON_STARTUP in line 9 of config.h to false.)

Set some new values, e.g. increase the amplitudes to 100 with

a100

![grafik](https://user-images.githubusercontent.com/8363989/52742868-0c2a0580-2fd9-11e9-9d6c-cb85d7a89320.png)


Reactivate the outputs, e.g. with

g10

and spot the difference!

![grafik](https://user-images.githubusercontent.com/8363989/52743139-a722df80-2fd9-11e9-9b04-020616cde573.png)
