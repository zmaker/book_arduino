/*
Lettura valori analogici da un sensore
*/ 

void setup() {
  //imposto la seriale
	Serial.begin(9600);
}

void loop() {
  //leggo l'ingresso A0 e lo salvo in una variabile
	int luce = analogRead(A0);	
  //stampo il valore rilevato
	Serial.print(“livello luce: ”);
	Serial.println(luce);	
  //una piccola pausa tra una lettura e la successiva
	delay(200);
}
