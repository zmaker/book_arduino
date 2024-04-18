/*
7.5 - EEPROM - uso di put e get
*/

//includo la libreria
#include <EEPROM.h>

void setup() {
  //configuro la seriale
  Serial.begin(9600);
  while (!Serial) {}

  Serial.print("Dimensioni del tipo int: ");
  Serial.println(sizeof(int));

  //scrivo 3 interi
  //creo un form con passo pari alla dimensione del dato
  for (int i = 0; i < 3*sizeof(int); i = i+sizeof(int)) {
    Serial.print("scrivo all'indirizzo ");
    Serial.println(i);
    int dato = i * 1000;
    EEPROM.put(i, dato);
  }

  //leggo 3 interi
  //creo un form con passo pari alla dimensione del dato
  for (int i = 0; i < 3*sizeof(int); i = i+sizeof(int)) {
    int dato = i * 1000;
    EEPROM.get(i, dato);
    Serial.print("leggo all'indirizzo ");
    Serial.print(i);
    Serial.print(" dato: ");
    Serial.println(dato);    
  }
}

void loop() {}
