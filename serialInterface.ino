void interface_ASCII() {
  /*
     Just the paramter returns the value of this parameter
     The parameter followed by a value sets the paramter to this value
     Lines need to end with '\n'
  */
  int numInput = 0;
  float fnumInput = 0;
  if (Serial.available()>1) { // data is available
    char command = Serial.read();
    switch (command)
    {
      case 'b':
        if (Serial.available() && Serial.peek() != '\n') {
          numInput = Serial.parseInt();
          if (numInput>0){
          ledMetro.reactivate(); // make sure the Metro is running
          Serial.print("Setting blink interval to "); Serial.println(numInput);
          ledMetro.setInterval(numInput);
          }
          else{
            ledMetro.deactivate();
            Serial.println("Deactivate blinking");
          }
        }
        else {
          Serial.print("Print interval in ms: "); Serial.println(ledMetro.getInterval());
        }
        break;

        case 'g':
        if (Serial.available() && Serial.peek() != '\n') {
          numInput = Serial.parseInt();
          if (numInput>0){
          generatorMetro.reactivate(); // make sure the Metro is running
          Serial.print("Setting function generator output interval to "); Serial.println(numInput);
          generatorMetro.setInterval(numInput);
          }
          else{
            generatorMetro.deactivate();
            Serial.println("Deactivate function generator output");
          }
        }
        else {
          Serial.println(generatorMetro.getInterval());
        }
        break;

        case 'a':
        if (Serial.available() && Serial.peek() != '\n') {
          fnumInput = Serial.parseFloat();
          Serial.print("Setting signal amplitudes to "); Serial.println(fnumInput);
          sine.setAmplitude(fnumInput);
          cosine.setAmplitude(fnumInput);
          squ.setAmplitude(fnumInput);
        }
        else{
          Serial.println("Invlid Input - missing paramter");
        }
        break;

        case 'f':
        if (Serial.available() && Serial.peek() != '\n') {
          fnumInput = Serial.parseFloat();
          Serial.print("Setting signal frequencies to "); Serial.println(fnumInput);
          sine.setFrequency(fnumInput);
          cosine.setFrequency(fnumInput);
          squ.setFrequency(fnumInput);
        }
        else{
          Serial.println("Invlid Input - missing paramter");
        }
        break;

      default:
        Serial.println("ERROR: invalid command");
        break;
    }
    // clear the input buffer, in case something is left there
    while (Serial.available())
    {
      Serial.read();
    }
  }
}

