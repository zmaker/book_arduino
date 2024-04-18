/*
10.7 - Controllo LED da BT

Per Arduino R3
*/

// configurazione della porta seriale 
#include <SoftwareSerial.h>
SoftwareSerial SSerial(6, 7); // RX, TX

void setup() {
  /configuro la seriale 
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("OK");
  //configuro la seriale verso il modulo BT
  SSerial.begin(9600);
  //imposto il pin 13
  pinMode(13, OUTPUT);
}

void loop() {
  //attendo caratteri dal BT
  if (SSerial.available()) {
    //leggo il carattere ricevuto
    char ch = SSerial.read();
    //interpreto il carattere
    if (ch == 'a') digitalWrite(13, HIGH);
    if (ch == 's') digitalWrite(13, LOW);   
    //stampo il carattere ricevuto sul serial monitor
    Serial.write(ch);
  }
  
}

