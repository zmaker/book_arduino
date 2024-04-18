/*
Pilotagio di un servomotore RC 
*/

//aggiungiamo un riferimento alla libreria Servo
#include <Servo.h> 
 
//creo un oggetto Servo per interagire con l'hardware
Servo rcservo; 

void setup() { 
  //configuro il servo indicando il pin a cui è collegato
  rcservo.attach(9); 
} 
 
void loop(){
  //un ciclo for da 0 a 180 per spostare il servo gradualmente 
  for (int i = 0; i <= 180; i++){ 
    //imposto l'angolo
    rcservo.write(i); 
    //attendo un po'
    delay(20); 
  } 
  //un ciclo for da 180 a 0 per chiudere il servo gradualmente 
  for (int i = 180; i >= 0; i--){ 
    //imposto l'angolo
    rcservo.write(i); 
    //attendo
    delay(20); 
  } 
} 


