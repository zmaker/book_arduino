/*
7.17 - Arduino si comporta come un mouse
*/

//includo la libreria
#include <Mouse.h>

void setup() {
  //imposto il pin per il pulsante di attivazione
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  //se premo il tatso...
  if (digitalRead(2)) {
    //attivo il mouse
    Mouse.begin();
    //sposto il cursore di 100 pixel a destra e in alto
    Mouse.move(100,100,0);
    //termino il mouse
    Mouse.end();
  }
}
