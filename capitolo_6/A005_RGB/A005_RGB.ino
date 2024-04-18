/*
pilotaggio LED RGB
*/

void setup() {
  randomSeed(analogRead(A0));
}

void loop() {
  //genero tre numeri casuali
  int r = random(255);
  int g = random(255);
  int b = random(255);
  //imposto i segnali PWM sui pin
  analogWrite(9, r);
  analogWrite(10, g);
  analogWrite(11, b);
  //una pausa per rendere visibile il colore
  delay(300);
}