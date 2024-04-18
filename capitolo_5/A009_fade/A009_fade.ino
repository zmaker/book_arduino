/*
fade LED
*/

void setup() {
}

void loop() {
  for (int i = 0; i < 256; i++) {
    analogWrite(11, i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(11, i);
    delay(5);
  }
}
