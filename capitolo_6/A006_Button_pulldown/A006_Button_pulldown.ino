/*
Pulsante pull down + LED
*/

void setup() {
    //configuro il pin per il pulsante
    pinMode(13, INPUT);
    //configuro il pin per il lED
	pinMode(2, OUTPUT);
}

void loop() {
    //verifico lo stato del pulsante
    if (digitalRead(13) == HIGH) {
      //accendo il LED
      digitalWrite (2, HIGH);		
    } else { 
      //spengo il LED
      digitalWrite (2, LOW);
    }
}
