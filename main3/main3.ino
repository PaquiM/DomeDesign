#include "sensores.h"
#include "leds.h"
#include "simon.h"

//Declaracion del objeto cupula
Leds l; 
Simon s;

//Adafruit_NeoPixel tira = Adafruit_NeoPixel(nc,11, NEO_GRB + NEO_KHZ800);

//Botones
const int buttonPin = 2;     // the number of the pushbutton pin

#define ESTADO_INICIAL 0
#define ESTADO_COLOR   1
#define ESTADO_ESPIRAL 2

int estado=ESTADO_INICIAL;
int cont=0;
//Variables para contar el tiempo con millis() dentro de la interrupción
const int Banda = 150;

//Variable volatil para la interrupción
volatile int ISR_Cont = 0;
long Time = 0;

 
void setup(){
  //Configura las entradas y salidas
  // inicializacion de la tira de leds
  tira.begin();       
  tira.show();
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  //Configura la interrupción en el PIN del pulsador en modo FALLING
  attachInterrupt(digitalPinToInterrupt(buttonPin), InterContador, FALLING);
}
 
void loop(){
 
   //Esta etapa  incrementa el contador cuando ISR_Cont
   //es modificado dentro de la interrupción
   if(cont!=ISR_Cont){
      cont=ISR_Cont;
      Serial.print("Contador: ");
      Serial.println(estado);
   }

   switch(estado){
      case ESTADO_INICIAL:
        l.OnCupula();
      break;

      case ESTADO_COLOR:
        l.FxOn(1,ROSA);
        l.FxOn(2,AZUL);
        l.FxOn(3,NARANJA);
      break;

      case ESTADO_ESPIRAL:
        s.tema_inicio();
        delay(50);
        while(estado==2){
        for(int i=0;i<nc;i++)
          l.OnLedn(i,colores[random(0,9)]);
        }

      break;
    }
}

//Función que se ejecuta cuando se ACTIVA la INTERRUPCIÓN
void InterContador(){
  int n=random(0,9);
  //Incrementa el contador
  ISR_Cont++;
  // Debounce o Antirebote por código
  if (millis() - Time > Banda){
      ISR_Cont++;
      Time=millis()+100;
  }
  estado++;
  if(estado==3)
    estado=0;
}
