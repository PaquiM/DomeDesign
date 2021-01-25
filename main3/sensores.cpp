#include "sensores.h"

void Sensores::ConfigPines(){
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT); 
  pinMode(y0, INPUT);
  pinMode(y1, INPUT);
  pinMode(y2, INPUT);
  pinMode(y3, INPUT);
  pinMode(y4, INPUT);
}

void Sensores::LeerSensores(int &r0, int &r1,int &r2, int &r3, int &r4){

  PORTB = B00000000;  
  //for para leer cada una de las entradas del mux
  for(int i = 0; i < numEntradas; i++){
      r0 = digitalRead(y0);
      r1 = digitalRead(y1);
      r2 = digitalRead(y2);
      r3 = digitalRead(y3);
      r4 = digitalRead(y4);
      
//      if(r0 == 1){
//          Serial.print("Sensor ");
//          Serial.print(i);
//          Serial.println(" MUX0 activo");
//          tira.setPixelColor(i,255,0,0); // Rojo
//          tira.show();
//         } /*else if(r0 == 0){
//           tira.setPixelColor(i,0,0,0); // Rosa
//           tira.show();
//        }*/
//
//       if(r1 == 1){
//          Serial.print("Sensor ");
//          Serial.print(i);
//          Serial.println(" MUX1 activo");
//          tira.setPixelColor(i+1,255,0,0); // Rojo
//          tira.show();
//         }/* else if(r3 == 0) {
//           tira.setPixelColor(i+1,0,0,0); // Rosa
//           tira.show();
//        }*/
//
//       if(r2 == 1){
//          Serial.print("Sensor ");
//          Serial.print(i);
//          Serial.println(" MUX2 activo");
//          tira.setPixelColor(i+2,255,0,0); // Rojo
//          tira.show();
//         } else if(r3 == 0) {
//           tira.setPixelColor(i+2,0,0,0); // Rosa
//           tira.show();
//        }
//
//
//        if(r3 == 1){
//          Serial.print("Sensor ");
//          Serial.print(i);
//          Serial.println(" MUX3 activo");
//          tira.setPixelColor(i+3,255,0,0); // Rojo
//          tira.show();
//         }/* else if(r3 == 0) {
//           tira.setPixelColor(i+3,0,0,0); // Rosa
//           tira.show();
//        }
//*/
//       if(r4 == 1){
//          Serial.print("Sensor ");
//          Serial.print(i);
//          Serial.println(" MUX4 activo");
//          tira.setPixelColor(i+4,255,0,0); // Rojo
//          tira.show();
//         } /*else if(r3 == 0) {
//           tira.setPixelColor(i+4,0,0,0); // Rosa
//           tira.show();
//        }*/
 
      PORTB ++; 
  }
}  
