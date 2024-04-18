/*
7.6 - PROGMEM
*/

//includo la libreria
#include <avr/pgmspace.h>

//creo una stringa con PROGMEM
const char messaggio[] PROGMEM = {"Hello World!"};

void setup() {
  //imposto la seriale
  Serial.begin(9600);
  while (!Serial);

  //leggo il contenuto della stringa un byte per volta
  for (int i = 0; i < 12; i++) {
    char ch = pgm_read_byte_near(messaggio + i);
    //stampo il byte
    Serial.print(ch);
  }

  //Posso ottenere in automatico la lunghezza della stringa con
  //strlen_P(messaggio)
  for (int i = 0; i < strlen_P(messaggio); i++) {
    char ch = pgm_read_byte_near(messaggio + i);
    //stampo il byte
    Serial.print(ch);
  }
    
}

void loop() {}
