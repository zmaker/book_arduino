/*
8.11 - Lettura bussola I2C 
modello: GY-273 con QMC5883L

//libreria
https://github.com/mechasolution/Mecha_QMC5883L
*/

//includo le librerie per i2c e per la bussola
#include <Wire.h>
#include <MechaQMC5883.h>

//creo l'oggetto che rappresenta la bussola
MechaQMC5883 qmc;

void setup() {
  //avvio l'i2c
  Wire.begin();
  //configuro la porta seriale
  Serial.begin(9600);
  //inizializzo la bussola
  qmc.init();
  //qmc.setMode(Mode_Continuous,ODR_200Hz,RNG_2G,OSR_256);
}

int x, y, z, a;
float rad;

void loop() {
  //la bussola fornisce una lettura su 3 assi
  qmc.read(&x, &y, &z);
  //ricavo l'angolo 
  rad = atan2(y,x); 
  //converto l'angolo in sessagesimali
  a = rad * (180.0 / PI);
  //riporto il valore tra 0 e 360
  if (a < 0) {
    a = 360 + a;  
  }
  if (a > 360) {
    a = a - 360;
  }

  Serial.print("angolo: ");
  Serial.println(a);
  //intervallo di lettura
  delay(300);
}