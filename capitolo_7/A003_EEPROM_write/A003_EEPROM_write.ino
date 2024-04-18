/*
7.3 - EEPROM Write
*/

//includo la libreria
#include <EEPROM.h>

void setup() {
  //configuro la seriale
  Serial.begin(9600);
  while (!Serial) {}

  //scrivo un valore all'indirizzo desiderato
  int indirizzo = 1;
  int valore = 123;
  EEPROM.write(indirizzo, valore);

  Serial.println("Scrittura effettuata!");
}

void loop() {}
