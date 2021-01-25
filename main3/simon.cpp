#include "simon.h"

Simon::Simon(){
  l.OffCupula();
}
void Simon::tema_inicio(){
  // meloda que suena al inicio de las partidas
  int notas[] = {NOTA_B3, NOTA_B3,  NOTA_B3, NOTA_D4, NOTA_B3, NOTA_D4};
  int duracion[] = {T_NEGRA, T_NEGRA, T_NEGRA, T_BLANCA, T_NEGRA, T_REDONDA};
  //tempo = 150;
  // reproducimos la meloda
  reproduce_melodia (notas, duracion, 100, 6);
}

void Simon::reproduce_melodia(int notas[], int duracion[], int tempo, int nro_notas) {
  /* notas = array con las notas (frecuencias o notas pre-definidas)
     duracion = array con la duracin de cada nota del array notas[] son el factor multiplicador del tempo, es decir si queremos que dure un pulso de tempo, indicaremos 1 o T_NEGRA
     tempo = duracin de un pulso (una nota negra) en milisegundos
     nro_notas = numero de notas que compone el array notas[]
   */
  int x = 0;
  for (x = 0; x < nro_notas; x++) {
    tone(PIN_ZUMBADOR, notas[x], duracion[x] * tempo);
    delay(duracion[x] * tempo * 1.30);
  }
}
