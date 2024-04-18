/*
10.9 - Web Server con Ehternet e modulo W5500
LED collegato sul pin 9
*/

//includo le librerie necessarie
#include <SPI.h>  
#include <Ethernet.h>  
      
//definizione degli indirizzi
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xD5, 0xB1};   
byte ip[] = { 192, 168, 0, 41 }; // indirizzo IP della shield  
byte gateway[] = { 192, 168, 0, 1 }; // indirizzo ip del router  
byte subnet[] = { 255, 255, 255, 0 }; //subnet mask  

//creo un oggetto serer sulla porta 80
EthernetServer server(80);   

//stringa per la lettura dei dati 
String readString;   

void setup(){  
  //configuro la seriale
  Serial.begin(9600);  
  //configuro la scheda di rete
  Ethernet.begin(mac, ip, gateway, subnet);  
  //imposto il pin per il lED
  pinMode(9, OUTPUT);  
}  

void loop(){  
  //il server attende un client
  EthernetClient client = server.available();  
  //se arriva un client lo serve...
  if (client) {      
    boolean currentLineIsBlank = true;  
    //fino a a che il client è connesso...
    while (client.connected()) {  
      //se ci sono dati provenienti dal client
      if (client.available()) {  
        //li leggo char per char
        char c = client.read(); 
        //li accodo nella stringa  
        readString.concat(c);   
        if (c == '\n' && currentLineIsBlank) {  
          //se ricevo un "a capo" e la linea è vuota
          //stampo la riga 
          Serial.print(readString);  
          //cerco la substring con led=1
          if (readString.indexOf("led=1") > 0) {  
            //se la trovo accendo il led
            digitalWrite(9, HIGH);                       
          } else {   
            //altriment lo spengo
            digitalWrite(9, LOW);                       
          }  

          //mando la risposta al client
          client.println("HTTP/1.1 200 OK");  
          client.println("Content-Type: text/html");  
          client.println();  
          client.print("<html><body><h1>WebLed</h1>");  
          client.print("<a href='/?led=1'>ON</a> | <a href='/?led=0'>OFF</a>");  
          client.println("</body></html>");  
          //ripulisco la stringa per la lettura dei dati
          readString="";  
          //chiudo la comunicazione
          client.stop();  
        }   
      }
    }   
  }    
}



