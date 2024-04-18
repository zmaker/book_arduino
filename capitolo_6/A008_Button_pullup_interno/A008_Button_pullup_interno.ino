/*
Pulsante pull up interno + LED
*/

void setup() {
  //configuro il pin per il pulsante
  //con pullup interno
  pinMode(12, INPUT_PULLUP);
  //configuro il pin per il lED
 	pinMode(13, OUTPUT);
}

void loop() {
  //verifico lo stato del pulsante
  if (!digitalRead(12)) {
    //accendo il LED
    digitalWrite (13, HIGH);		
  } else { 
    //spengo il LED
    digitalWrite (13, LOW);
  }
}
