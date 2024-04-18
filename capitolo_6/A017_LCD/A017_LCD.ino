/*
Pilotaggio di display LCD
*/

//aggiungo la libreria per il display
#include <LiquidCrystal.h>

//configuro i pin
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //inizializzo il display con 16 colonne e 2 righe
  lcd.begin(16, 2);
  //stampo un messaggio
  lcd.print("hello, world!");
}

void loop() {}
