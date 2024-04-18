/*
8.14 - RTC DS1307

//libreria
RTCLib
*/

//libreria per I2C
#include <Wire.h>

//installare la RTCLib
#include "RTClib.h"

//l'oggetto per l'RTC
RTC_DS1307 rtc;

//array con i giorni della settimana
char settimana[7][4] = {"dom", "lun", "mar", "mer", "gio", "ven", "sab"};

void setup() {
  //imposto la seriale
  Serial.begin(9600);
  //inizializzo l'RTC
  if (!rtc.begin()) {
    Serial.println("Errore! Verifica le connesioni!");
    return;
  }

  //imposto l'ora se necessario
  if (!rtc.isrunning()) {
    Serial.println("Configuro l'ora");
    //Uso l'ora di compilazione dello sketch
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // per farlo a mano...
    // January 21, 2014 at 3am you would call
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

}

void loop() {
  //chiedo l'ora
  DateTime now = rtc.now();
  //stampo le informazioni
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(settimana[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  //attendo due secondi
  delay(2000);
}