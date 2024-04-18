/*
7.18 - Blink per Attiny85
*/

void setup() {                
  //imposto il pin 0
  //il pin 0 è in realtà il pin numero 5 del chip
  pinMode(0, OUTPUT);     
}

void loop() {
  digitalWrite(0, HIGH); // accendo il LED
  delay(1000);           // attendo un secondo
  digitalWrite(0, LOW);  // spengo il LED
  delay(1000);           // attendo un secondo e poi ripeto il loop
}
