#ifndef SIMON_H
#define SIMON_H

  #include "leds.h"
  #include "colors.h"
  #include "lista.h"
  #include "sonidos.h"

  const byte PIN_ZUMBADOR=13;
  
  class Simon{
    private:
      const int VELOCIDAD_INICIAL = 1000; // velocidad inicial en milisegundos a la que se mostrar la secuencia
      byte ronda=0; //numero de ronda en la que vamos

      //Tiempo en milisegundos que permanecen encendidos los LEDs cuando muestra la secuencia a repetir
      int velocidad=VELOCIDAD_INICIAL; 
       //Duracion de un pulso en milisegundos. Se usa para la duracin de las notas
      int tempo=150;
      
      // variables para el controlde rebotes / bouncing de los pulsadores. Cada uno de los 4 pulsadores tiene las suyas
      long rebote_ultima_senal_verde = 0; //momento en el que se produjo la seal anterior del boton
      long rebote_ultima_senal_amarillo = 0; 
      long rebote_ultima_senal_azul = 0; 
      long rebote_ultima_senal_rojo = 0; 
      long rebote_retardo = 50; // tiempo en milisegundos transcurrido que si se supera entre dos seales del botn deja de considerarse un rebote
    
    public:
      Leds l;
      //Constructor
      Simon();

      //Inicia el juego      
      void InitGame();
      //Destruye la lista de celdas que tenia guardada y deja la cupula en blanco
      void EndGame();
      void tema_inicio();
      void reproduce_melodia(int notas[], int duracion[], int tempo, int nro_notas);
  
  };//Class

#endif
