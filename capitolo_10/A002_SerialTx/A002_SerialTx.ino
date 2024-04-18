/*
10.2 - Trasmettitore

Utilizza un Arduino UNO.
Lo sketch trasmette su Seriale una seq. di numeri
*/

#if defined(ARDUINO_ARCH_RENESAS)
  #define SERIAL Serial1  
#else 
  #define SERIAL Serial
#endif 

//un contatore
int count = 0;

void setup() {
  //imposto la seriale a 9600 baud  
  SERIAL.begin(9600);
  delay(2000);
}

void loop() {
  //invio il valore di count sulla seriale
  SERIAL.println(count);
  //incremento il conteggio
  count++;
  //attendo un secondo
  delay(1000);
}
