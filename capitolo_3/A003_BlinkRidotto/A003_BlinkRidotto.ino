/*
Listato 3.2 - Blink "ridotto"

*/
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, !digitalRead(13));
  delay(200);
}