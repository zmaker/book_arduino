/*
Pulsanti "analogici"
*/

//definisco una soglia di guardia per leggere i valori analogici
const int soglia = 10;

void setup() {
  //configuro la seriale
  Serial.begin(115200);
  while (!Serial);
}

void loop() {
  //leggo l'ingresso analogico
  int level = analogRead(A0);

  //togliere i commenti per rilevare i valori generati dai pulsanti
  //Serial.println(level);
  //delay(300);

  //se il valore è compreso tra due livelli posso riconoscere che pulsante è stato premuto
  if ((level > 255 - soglia) && (level < 255 + soglia)) {
  	//pulsante BT3
    Serial.println("BT3");
  } else if ((level > 509 - soglia) && (level < 509 + soglia)) {
  	//pulsante BT2
    Serial.println("BT2");
  } else if ((level > 765 - soglia) && (level < 765 + soglia)) {
  	//pulsante BT1
    Serial.println("BT1");
  } 
}


