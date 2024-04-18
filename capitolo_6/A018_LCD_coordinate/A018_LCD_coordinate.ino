/*
Pilotaggio di display LCD con coordinate
*/

//aggiungo la libreria per il display
#include <LiquidCrystal.h>

//configuro i pin
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//un contatore da incrementare
int contatore = 0;

void setup() {
  //inizializzo il display con 16 colonne e 2 righe
  lcd.begin(16, 2);
  //stampo un messaggio
  lcd.print("conteggio:");
}

void loop() {
  //mi sposto alla prima colonna (0) della seconda riga (1)
  lcd.setCursor(0, 1);
  //stampo il contatore
  lcd.print(contatore);
  //incremento il contatore
  contatore++;
  //pausa di 1s
  delay(1000);

}
