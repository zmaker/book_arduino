/*
LED con segnale PWM
*/

void setup() {
	analogWrite(11, 0);
  delay(1000);
  analogWrite(11, 50);
  delay(1000);
  analogWrite(11, 127);
  delay(1000);
  analogWrite(11, 200);
  delay(1000);
  analogWrite(11, 255);
}

void loop() {}

