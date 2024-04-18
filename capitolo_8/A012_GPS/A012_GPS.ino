/*
8.12 - Lettura GPS versione per UNO R3

//libreria
http://arduiniana.org/libraries/tinygps/
*/

//includo la libreria
#include <TinyGPS.h> 
//per comunicare con il gps creeremo una seconda porta seriale "software"
#include <SoftwareSerial.h> 

//latitudine e logitudine
float lat = 0.0,lon = 0.0; 

//configuro la porta abbinandola a due pin 
SoftwareSerial gpsSerial(3,4); //pin 3: rx, pin 4: tx 

//creo l'oggetto GPS per comunicare co il modulo
TinyGPS gps; 

void setup(){ 
  //configuro la porta seriale
  Serial.begin(9600);
  //configuro la porta seriale "software"
  gpsSerial.begin(9600); 
} 
void loop(){ 
  //attendo dati dalla seriale del GPS
  while (gpsSerial.available()){   
    //ricevo un carattere
    char c = gpsSerial.read();
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