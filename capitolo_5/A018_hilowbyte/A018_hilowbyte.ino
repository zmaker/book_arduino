/*
Estraiamo i byte hi e low
*/ 

void setup() {
  //imposto la porta seriale
  Serial.begin(9600);
  while(!Serial);
  //il numero da elaborare:
  unsigned int n = 6543;
  Serial.println(n);
  //lo posso esprimere direttamente in esadecimale
  n = 0x198F;
  //stamperemo lo stesso valore!
  Serial.println(n);
  //oppure in binario
  n = 0B0001100110001111;
  Serial.println(n);
  
  //estraggo il byte alto
  byte val = highByte(n);
  Serial.println(val);
  //stampo per verifica il valore in hex
  Serial.println(0x19);

  //estraggo il byte basso
  val = lowByte(n);
  Serial.println(val);
  //stampo per verifica il valore in hex
  Serial.println(0x8F);
  
}

void loop() {
}