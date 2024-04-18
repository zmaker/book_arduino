/*
8.2 - Lettura encoder rotativo

Collegare un potenziometro l'encoder ai pin 3 e 4
*/

//la variabile modificata dall'encoder
int valore = 0;
//serve un confronto con il valore della variabile al passo precedente
int letturaPrecedente = HIGH;

void setup() { 
  //imposto i pin
	pinMode (3,INPUT_PULLUP);
	pinMode (4,INPUT_PULLUP);
  //inizializzo la seriale
	Serial.begin(9600);
}

void loop() { 
  //leggo il pin 3
	int n = digitalRead(3);
  //confronto la lettura precedente con quella corrente
	if ((letturaPrecedente == HIGH) && (n == LOW)) {
    //valuto il pin 4 e modifico la variabile valore
		if (digitalRead(4) == HIGH) {
			valore--;
		} else {
			valore++;
		}
    //stampo valore
		Serial.println(valore);		
	} 
  //salvo la lettura corrente 
	letturaPrecedente = n;
}
