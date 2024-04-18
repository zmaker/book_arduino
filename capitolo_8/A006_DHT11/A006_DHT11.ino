/*
8.6 - Lettura temperatura e umidità con DHT11

Installare la lib SimpleDHT

collegamento sensore DHT11,
- VCC: 5V or 3V
- GND: GND
- DATA: 2
*/

//aggiungo la libreria
#include <SimpleDHT.h>

//creo l'oggetto che rappresenta il sensore
SimpleDHT11 dht11;

void setup() {
  //imposto la porta seriale
  Serial.begin(9600);
}

void loop() {
  //preparo due variabili per la lettura dei valori
  byte temp = 0;
  byte umid = 0;
  //una variabile per gli errori
  int err = SimpleDHTErrSuccess;
  //leggo il sensore collegato sul pin 2
  if ((err = dht11.read(2, &temp, &umid, NULL)) == SimpleDHTErrSuccess) {
    //se non ci sono errori stampo le letture 
    Serial.print("temp: ");     
    Serial.print((int)temp); Serial.print("C, hum: ");
    Serial.print((int)umid); Serial.println("%");
  } else {
    //errore di lettura
    Serial.print("Errore lettura DHT11 failed, err=");
    Serial.println(err);
  }

  // attendo 2 sec prima di leggere i dati
  delay(2000);
}

