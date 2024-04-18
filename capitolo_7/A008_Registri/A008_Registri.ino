/*
7.8 - Impostazione dei pin utilizzando i registri
      Per AVR / Arduino Uno Rev 3, Nano
*/

void setup() {
  //imposto la seriale
  Serial.begin(9600);
  while (!Serial);

  //imposto il pin 13 come uscita
  //PORTB - PB5 - D13
  DDRB = B00100000;  
}

void loop() {
  //attivo il pin 13
  PORTB = B00100000;
  delay(500);
  //spengo il pin 13
  PORTB = B00000000;
  delay(500);
}
