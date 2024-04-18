/*
10.3 - Ricevitore per Arduino UNO R3
*/

//includo la libreria
#include <SoftwareSerial.h>
//definisco i pin con nomi di comodo
#define SOFTRX 10
#define SOFTTX 11
//istanzio la porta seriale 
SoftwareSerial SerialS(SOFTRX, SOFTTX);

void setup() {
  //imposto la porta per il serial monitor
  Serial.begin(9600);
  //imposto la porta software
  SerialS.begin(9600);
}

void loop() {
  //attendo un byte...
  if (SerialS.available()) {    
    //scrivo il byte dalla SoftwareSerial nella Serial
    Serial.write(SerialS.read());
  }
}

