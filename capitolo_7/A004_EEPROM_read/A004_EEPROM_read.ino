/*
7.4 - EEPROM Read
*/

//includo la libreria
#include <EEPROM.h>

void setup() {
  //configuro la seriale
  Serial.begin(9600);
  while (!Serial) {}

  //leggo un valore all'indirizzo desiderato
  int indirizzo = 1;
  int valore = EEPROM.read(indirizzo);

  Serial.print("valore: ");
  Serial.println(valore);
}

void loop() {}
