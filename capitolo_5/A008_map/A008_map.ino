/*
utilizzo di map()
*/

void setup() {
  int luminosita = 20;
  int pwm = map(luminosita, 0, 100, 0, 255);
	analogWrite(11, pwm);
}

void loop() {}

