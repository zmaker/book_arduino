/*
8.17 - SD Card
*/

//aggiungo le librerie necessarie (non serve installarle)
#include <SPI.h>
#include <SD.h>

//riferimento al file che creeremo
File file;

void setup() {
  //inizializzo la seriale
  Serial.begin(9600);
  //inizializzo la scheda sd con CS sul pin 10 (verificare!)
  if (!SD.begin(10)) {
    //se ci sono errori mi fermo
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  //apro un file in scrittura
  file = SD.open("/test.txt", FILE_WRITE);
  //se il file è stato aperto...
  if (file) {
    //scrivo con delle print
    file.println("Hello!!!!");
    //chiudo il file
    file.close();
    Serial.println("file scritto.");
  } else {
    Serial.println("errore nell'aprire test.txt");
  }
  
  //Apro il file in lettura
  file = SD.open("/test.txt");
  if (file) {
    Serial.println("lettura file:");
    //leggo caratteri dal file fino a che ne trovo
    while(file.available()) {
      //stampo i caratetri sul serial monitor
      Serial.write(file.read());
    }
    //chiudo il file
    file.close();
  }

}

void loop() {}
