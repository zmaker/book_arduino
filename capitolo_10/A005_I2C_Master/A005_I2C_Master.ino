/*
10.4 - Client I2C
*/

//includo la libreria
#include <Wire.h>

//indirizzo 123 decimale del sensore da leggere
#define I2C_ADDR 0x7B

//buffre per ricevere i dati
uint8_t buff[2];

//comando per led
int cmd;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  cmd = HIGH;
}

void loop() {
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(cmd);
  Wire.endTransmission(); 
  cmd = !cmd;

  delayMicroseconds(500);

  Wire.requestFrom(I2C_ADDR, 2);

  int i = 0;
  while (Wire.available()) {
    //quando è presente un dato avvia
    //la lettura
    char c = Wire.read();
    buff[i] = (uint8_t)c;
    i++;
    Serial.print((int)c);Serial.print(" ");
  }
  Serial.print("\n");
  
  delay(3000);
}