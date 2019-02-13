#include <Metro.h>
#include "config.h"
#include "funcGenerator.h"

enum ledStates {ON, OFF}; // states of the blink state machine

// metros for scheduling of the two tasks
Metro ledMetro = Metro(DEFAULT_BLINK_INTERVAL);
Metro generatorMetro = Metro(DEFAULT_PRINT_INTERVAL);

// instanciate three function generators
funcGenerator sine = funcGenerator(0, DEFAULT_FREQUENCY, DEFAULT_AMPLITUDE);
funcGenerator cosine = funcGenerator(1, DEFAULT_FREQUENCY, DEFAULT_AMPLITUDE);
funcGenerator squ = funcGenerator(2, DEFAULT_FREQUENCY, DEFAULT_AMPLITUDE);

void setup() {
  Serial.begin(BAUDRATE);
  pinMode(LED_PIN, OUTPUT);
  if (!PRINT_ON_STARTUP) { // configured via config.h
    generatorMetro.deactivate();
  }
}

void loop() {
  interface_ASCII(); // serial interface

  // tasks
  blinkTask();
  generatorTask();
}

void blinkTask() { // blink state machine
  static int ledState = OFF;
  if (ledMetro.check()) {
    switch (ledState) {
      case ON:
        digitalWrite(LED_PIN, LOW);
        ledState = OFF;
        break;
      case OFF:
        digitalWrite(LED_PIN, HIGH);
        ledState = ON;
        break;
    }
  }
}

void generatorTask() { // run the function generators and print to serial, formatted for the serial plotter
  if (generatorMetro.check()) {
    Serial.print(sine.compute());
    Serial.print('\t');
    Serial.print(cosine.compute());
    Serial.print('\t');
    Serial.print(squ.compute());
    Serial.print('\n');
  }
}
