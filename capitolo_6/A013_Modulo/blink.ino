void blink(int led, int tm) {
  digitalWrite(led, HIGH);
  delay(tm);
  digitalWrite(led, LOW);
  delay(tm);  
}
