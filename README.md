# Arduino_AdvancedConcepts
An Arduino project to exemplify some intermediate/advanced programming concepts for Arduino.
No hardware other than an Arduino required.

For many Makers, Arduino projects are one of the first contacts with coding and remain relatively basic.
However, with a few a little more advanced concepts in (Arduino) programming, many Arduino projects can be brouhgt to the next level (i.e. more organized, more efficient and more reliable).

This project is a concise way to exemplifiy the following good-to-know techniques that are applicable to many programs:

## Exemplified Concepts
* Scheduling (cooperative multitasking) using Metro (avoid delay())
* State machines (a mighty concept for more complex tasks)
* Classes (avoid duplicated code)
* Using the serial plotter (for visualization and debugging)
* Paramter setting via the serial input (to save time when tuning parameters)
* Using a config.h file (all configurations in one place)

### In Detail

The Arduino runs two tasks: It lets its LED blink (with variable frequency) and runs three function generators (sine, cosine and square wave).

The blink task is implemented as a simple state machine.

The function generators are all instances of the same class funcGenerator.

The output is formatted so that it can be viewed on the IDE's built-in serial plotter.

At the same time, the user can set paramters and control the output via the IDE's (or any other) serial monitor.

The program can be configured via a config file - no need to touch any other files (e.g. comment out things here and there...)


## External Dependencies

* Metro library for cooperative multitasking (forked from the original work by thomasfredericks):
https://github.com/LuSeKa/Metro (clone into the library folder of your Arduino IDE)

## Usage

### Basic
To simply see the program in action, cmpile and upload to the Arduino. Open the serial plotter (under Tools in the Arduino IDE) (115200baud) and watch the curves evolve.

![grafik](https://user-images.githubusercontent.com/8363989/52767530-1a087680-302b-11e9-809c-94fbe7bd699b.png)

### Configured
Open the config.h and play with the parameters. For example, set a much lower frequency in line 8. Compile, upload, and watch the effect in the plotter.

![grafik](https://user-images.githubusercontent.com/8363989/52767603-4d4b0580-302b-11e9-8abf-f92f605308e4.png)

### Interactive
Open a serial monitor (115200bps and Newline on enter) and type

g0

![grafik](https://user-images.githubusercontent.com/8363989/52743826-35e42c00-2fdb-11e9-9d82-84106a4d4909.png)

This will deactivate the spam.

![ExampleTerminalOutput](https://user-images.githubusercontent.com/8363989/52742703-a3db2400-2fd8-11e9-93e0-5cd8025d24f4.png)

(Alternatively, set PRINT_ON_STARTUP in line 9 of config.h to false.)

Set some new values, e.g. increase the amplitudes to 100 with

a100

![grafik](https://user-images.githubusercontent.com/8363989/52742868-0c2a0580-2fd9-11e9-9d6c-cb85d7a89320.png)


Reactivate the outputs, e.g. at an interval of 10ms with

g10

and spot the difference!

![grafik](https://user-images.githubusercontent.com/8363989/52743939-7e9be500-2fdb-11e9-9e00-1c12dd019c4c.png)

If you want to see the difference on the plotter, you have to change the amplitude in the config.h, compile and upload.

![grafik](https://user-images.githubusercontent.com/8363989/52767677-84211b80-302b-11e9-8ace-94c06b5db63f.png)

### LED
The command

b

will return the current blink interval.

You can make the LED blink much faster, e.g. by typing

b50

![grafik](https://user-images.githubusercontent.com/8363989/52746634-40ee8a80-2fe2-11e9-85d2-2476c1a4943d.png)

