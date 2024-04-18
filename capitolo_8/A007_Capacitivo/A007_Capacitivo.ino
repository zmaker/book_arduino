/*
8.7 - SEnsore Capacitivo

Installare la lib CapacitiveSensor
https://github.com/PaulStoffregen/CapacitiveSensor
*/

//aggiungo la libreria
#include <CapacitiveSensor.h> 

//creo l'oggetto che rappresenta il sensore
CapSense cs = CapSense(4,2);
 
void setup() {
  //attivo la seriale
	Serial.begin(9600);
  //disattivo l'autocalibrazione
	cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
  //configuro il pin per il LED
	pinMode(13, OUTPUT); 
}
 
void loop() {
  //leggo il sensore chiedendo 30 campioni/letture
	int sens =  cs.capSense(30);
  //valuto il valore letto
	if (sens > 1000) {
    //accendo il led
		digitalWrite(13, HIGH);
	} else {
    //spengo il led
		digitalWrite(13, LOW);
	}
  //una pausa tra una rilevazione e l'altra
	delay(100);
}

