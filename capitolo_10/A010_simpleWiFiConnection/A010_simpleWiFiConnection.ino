/* 
Listato 10.10 – Semplice connessione WiFi con Arduino UNO WiFi
*/

//includo le librerie per il wifi
#include <WiFi.h>

void setup() {
  //preparo la seriale
  Serial.begin(115200);
  delay(1000);
  //stampo un messaggio
  Serial.println("Simple WiFi Connection");

  //avvio al connessione alla rete esistente
  WiFi.begin("ssid delal rete", "password");
  Serial.println("mi connetto...");
  //attendo la connessione
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nconnesso");
  
  //se connesso stampo l'IP e la potenza del segnale
  Serial.print("IP: "); Serial.println(WiFi.localIP());
  Serial.print("Segnale (RRSI): "); Serial.println(WiFi.RSSI());
  
  delay(5000);

  //mi scollego
  WiFi.disconnect();
  Serial.println("disconnesso");
}

void loop() {}
