void interface_ASCII() {
  /*
     Manages the human-readable interactive serial interface.

     Just the paramter returns the value of this parameter.
     The parameter followed by a value sets the paramter to this value.
     Lines need to end with '\n' (newline).
  */
  int numInput = 0;
  float fnumInput = 0;
  if (Serial.available() > 1) { // data is available
    char command = Serial.read();
    switch (command)
    {
      case 'b':
        if (Serial.available() && Serial.peek() != '\n') {
          numInput = Serial.parseInt();
          if (numInput > 0) {
            ledMetro.reactivate(); // make sure the Metro is running
            ledMetro.setInterval(numInput);
            if (VERBOSE) {
              Serial.print("Setting blink interval to "); Serial.print(numInput); Serial.println(" ms");
            }
          }
          else {
            ledMetro.deactivate();
            if (VERBOSE) {
              Serial.println("Deactivate blinking");
            }
          }
        }
        else {
          if (VERBOSE) {
            Serial.print("Blink interval in ms: "); Serial.println(ledMetro.getInterval());
          }
        }
        break;

      case 'g':
        if (Serial.available() && Serial.peek() != '\n') {
          numInput = Serial.parseInt();
          if (numInput > 0) {
            generatorMetro.reactivate(); // make sure the Metro is running
            generatorMetro.setInterval(numInput);
            if (VERBOSE) {
              Serial.print("Setting function generator output interval to "); Serial.println(numInput);
            }
          }
          else {
            generatorMetro.deactivate();
            if (VERBOSE) {
              Serial.println("Deactivate function generator output");
            }
          }
        }
        else {
          if (VERBOSE) {
            Serial.println(generatorMetro.getInterval());
          }
        }
        break;

      case 'a':
        if (Serial.available() && Serial.peek() != '\n') {
          fnumInput = Serial.parseFloat();
          sine.setAmplitude(fnumInput);
          cosine.setAmplitude(fnumInput);
          squ.setAmplitude(fnumInput);
          if (VERBOSE) {
            Serial.print("Setting signal amplitudes to "); Serial.println(fnumInput);
          }
        }
        else {
          if (VERBOSE) {
            Serial.println("Invlid Input - missing paramter");
          }
        }
        break;

      case 'f':
        if (Serial.available() && Serial.peek() != '\n') {
          fnumInput = Serial.parseFloat();
          sine.setFrequency(fnumInput);
          cosine.setFrequency(fnumInput);
          squ.setFrequency(fnumInput);
          if (VERBOSE) {
            Serial.print("Setting signal frequencies to "); Serial.println(fnumInput);
          }
        }
        else {
          if (VERBOSE) {
            Serial.println("Invlid Input - missing paramter");
          }
        }
        break;

      default:
        if (VERBOSE) {
          Serial.println("ERROR: invalid command");
        }
        break;
    }
    // clear the input buffer, in case something is left there
    while (Serial.available())
    {
      Serial.read();
    }
  }
}
