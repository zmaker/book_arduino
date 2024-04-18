/*
10.6 - Terminale per modulo BlueTooth 

Per Arduino R3
*/

// configurazione della porat seriale 
#include <SoftwareSerial.h>
SoftwareSerial SSerial(6, 7); // RX, TX

void setup() {
  //attivo il serial monitor
  Serial.begin(38400);
  //attendo la seriale
  while (!Serial) {}
  //stampo un messaggio
  Serial.println("OK");
  //attivo la software serial sulla vel del modulo BT
  SSerial.begin(38400);
}

void loop() {
  //attendo caratteri dal modulo BT  
 if (sSerial.available()) {
    //se arrivano li giro al Serial Monitor
    Serial.write(sSerial.read());
  }
  //attendo caratteri da Sesrial Monitor
  if (Serial.available()) {
    //se arrivano li giro a BT
    sSerial.write(Serial.read());
  }
  
}
