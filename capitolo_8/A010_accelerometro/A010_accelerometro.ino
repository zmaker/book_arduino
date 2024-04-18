/*
8.10 - Lettura accelerometro analogico ADXL335
*/

void setup() {
  //imposto la seriale
  Serial.begin(9600);
}

void loop() {
  //leggo i valori sui tre assi
  int x = analogRead(A0);
  int y = analogRead(A1);
  int z = analogRead(A2);
  //li stampo sul serial monitor  
  Serial.print("x:");
  Serial.print(x);
  Serial.print("\ty:");
  Serial.print(y);
  Serial.print("\tz:");
  Serial.println(z);
  //intervallo tra le letture
  delay(300);
}
