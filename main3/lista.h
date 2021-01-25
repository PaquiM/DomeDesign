#ifndef LISTA_H
#define LISTA_H

#include "leds.h"
#include "colors.h"

class List{
    private:
      struct Nodo;
      typedef Nodo *PNodo;

      struct Nodo{
        int color;
        int pos;
        PNodo sig;
      };

      PNodo lista;
      //Tamaño de la lista
      unsigned sz;

      //Destruye la lista
      void destruir(PNodo &lista);
      //Inserta una pulsacion al final de la lista
      void insertar(PNodo &lista,int color, int pos);

    public:
      //Objeto cupula
      Leds l;
    
      //Constructor por defecto
      List();
      //Destrutor
      ~List();

      //Devuelve el tamaño de la lista
      unsigned tamanio();
      //Limpia la lista
      void limpiar();

};//Fin de la clase


#endif
