/*
8.5 - Lettura temperatura con LM35
*/

void setup() {
  //imposto la seriale
  Serial.begin(9600);
}

void loop() {
  //leggo il valore su A0
  int v = analogRead(A0);
  Serial.println(v);  

  //ricavo la tensione in mV - 10mV per ogni grado Celsius
  double vt = (float)(5000.0d/1024.0d)*(float)v;
  Serial.print("tensione: ");
  Serial.print(vt);
  Serial.println(" mV");
  //converto la tensione in gradi
  double temp = vt/10.0d;
  Serial.print("temp: ");
  Serial.print(temp);
  Serial.println("°C");

  delay(1000);
}
