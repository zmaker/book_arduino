/*
7.16 - Arduino si comporta come una tastiera
*/

//includo la libreria
#include <Keyboard.h>

void setup() {  
  //imposto il pin 2 come ingresso e gli collego un pulsante (tra 2 e GND)
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  //se premo il pulsante...
  if (digitalRead(2)) {
    //attivo la modalità tastiera
    Keyboard.begin();
    //invio un testo
    Keyboard.print("Hello Keyboard!");
    //termino la tastiera
    Keyboard.end();
  }
}
