/*
8.1 - Lettura potenziometro

Collegare un potenziometro al pin A0 
*/

void setup() { 	
  //imposto la seriale
	Serial.begin(9600);
  // attendo che la seriale sia pronta
  while (!Serial);
}

void loop() { 
  //leggo il valore sul pin
	int n = analogRead(A0);
  //lo stampo
	Serial.println(n);
  //attendo alcuni ms tra una lettura e l'altra
	delay(200);
}