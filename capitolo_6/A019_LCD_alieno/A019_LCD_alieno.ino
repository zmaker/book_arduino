/*
Creazione di un carattere personalizzato
*/

// Aggiungo la libreria per il display
#include <LiquidCrystal.h>

// Configuro i pin
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//definisco la maschera di bit per il carattere
uint8_t alieno [8] = {
B01110,
B10101,
B10101,
B11111,
B01010,
B10001,
B10001,
B00000};

void setup() {
  //associo la maschera di bit al carattere 0
  lcd.createChar(0, alieno);
  //inizializzo il display con 16 colonne e 2 righe
  lcd.begin(16, 2);
  //stampo il carattere 0 (dovrebbe apparire l'alieno)
  lcd.print(0);
}

void loop() {}
