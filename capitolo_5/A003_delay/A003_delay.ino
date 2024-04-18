/*
Accendo un LED e lo spengo dopo 2 secondi
*/
void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
}

void loop() {
}
