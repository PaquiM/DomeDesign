#include "lista.h"

//Constructor por defecto
//Inicializa la lista a tamaño cero 
List::List():lista(NULL),sz(0){
  l.OffCupula();  
}

//Destrutor
List::~List(){
  destruir(lista);
}
  
void List::destruir(PNodo &lista){
  while(lista!=NULL){
    PNodo aux=lista;
    lista=lista->sig;
    delete aux;
  }
}//Como manipula los elementos de la clase
//este metodo auxiliar se define en la parte privada

unsigned List::tamanio(){
  return sz;
}

//Dejar la lista limpia?
void List::limpiar(){
  destruir(lista);
  sz=0;
}

void List::insertar(PNodo &lista, int _color,int _pos){
  PNodo nue=new Nodo;
  nue->color=_color;
  //Posicion de la celda que se encendio
  nue->pos=_pos;
  //Significa que el juego acaba de empezar por tanto 
  //no hay ningun dato guardado y la lista esta vacia
  if(lista==NULL){
    lista=nue;
    sz++;
  }else{
  //La lista ya esta inicializada
    PNodo aux;
    aux=lista;
    while(aux->sig!=NULL)
      aux=aux->sig;

    aux->sig=nue;
    nue->sig=NULL;
    sz++;
  }
}
