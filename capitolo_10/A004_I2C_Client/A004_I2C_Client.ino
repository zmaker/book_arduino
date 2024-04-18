/*
10.4 - Client I2C
*/

//includo la libreria
#include <Wire.h>

//indirizzo 123 decimale del client
#define I2C_ADDR 0x7B

//variabile conteggio
uint8_t count = 0;

void setup() {
  //preparo la seriale
  Serial.begin(115200);
  //inizializzo il client con il suo indirizzo
  Wire.begin(I2C_ADDR);
  //hookup funzione di risposta
  Wire.onRequest(inviaRisposta);
  //hookup funzione di ricezione dati da Master
  Wire.onReceive(riceviDati);
  //imposto il led sul pin 13
  pinMode(13, OUTPUT);
}

void loop() {}

//invia risposta al master
void inviaRisposta() {
  //un codice fisso
  Wire.write(0x01);
  //la variabile count
  Wire.write(count%255);
  //aumento il conteggio
  count++;
}

//ricevi i dati dal master
void riceviDati(int num_bytes) {
  if (num_bytes == 1) {
    int cmd = Wire.read();
    //accendo/spengo il LED
    if (cmd == 0) digitalWrite(13, LOW);
    else if (cmd == 1) digitalWrite(13, HIGH);
  }
}

