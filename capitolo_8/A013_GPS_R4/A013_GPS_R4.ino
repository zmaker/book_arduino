/*
8.13 - Lettura GPS versione per UNO R4

//libreria
http://arduiniana.org/libraries/tinygps/
*/

//includo la libreria
#include <TinyGPS.h> 

//latitudine e logitudine
float lat = 0.0,lon = 0.0; 

//creo l'oggetto GPS per comunicare co il modulo
TinyGPS gps; 

void setup(){ 
  //configuro la porta seriale
  Serial.begin(9600);
  //configuro la porta seriale sui pin 0 e 1
  Serial1.begin(9600); 
} 
void loop(){ 
  //attendo dati dalla seriale del GPS
  while (Serial1.available()){   
    //ricevo un carattere
    char c = Serial1.read();
    //lo stampo sul serial monitor   
    Serial.print(c);
    //passo il carattere all'oggetto GPS che li accoda e decodifica
    if (gps.encode(c)) {  
      //quando ho abbastanza dati stampo lat e long
      gps.f_get_position(&lat,&lon); 
      //stampo le informazioni
      Serial.print("Position: "); 
      Serial.print("Latitude:"); 
      Serial.print(lat,6); 
      Serial.print(";"); 
      Serial.print("Longitude:"); 
      Serial.println(lon,6);     
    } 
  } 
  //attendo un secondo
  delay(1000); 
} 