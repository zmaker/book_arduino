/*
LED controllato da un pulsante
*/

void setup() {
	pinMode(13, INPUT);
	pinMode(2, OUTPUT);
}

void loop() {
	int tasto1 = digitalRead(13);
	if (tasto1 == HIGH) {
		digitalWrite (2, HIGH);
		delay(1000);
    } else { 
	  digitalWrite (2, LOW);
    }
}
