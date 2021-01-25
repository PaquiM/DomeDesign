#ifndef SENSORES_H
#define SENSORES_H

#include "colors.h"
#include "leds.h"
//Libreria para el manejo del neopixel
#include <Adafruit_NeoPixel.h>

#define numEntradas 8
#define LEDAPAGADO 0
#define LEDENCENDIDO 1

class Sensores{
  private:
    // salidas, señales control del mux
    int A = 8;
    int B = 9;
    int C = 10;
    // entradas
    int y0 = 3; // salida del mux0
    int y1 = 4; // salida del mux1
    int y2 = 5; // salida del mux2
    int y3 = 6; // salida del mux3
    int y4 = 7; // salida del mux4
    
    // variable para guardar lecturas
    int r0; // lectura del mux0
    int r1; // lectura del mux1
    int r2; // lectura del mux2
    int r3; // lectura del mux3
    int r4; // lectura del mux4

    // contador colores leds
    int cont = 0;
    int ESTADO = LEDAPAGADO;

    void ConfigPines();

   public:
    void LeerSensores(int &r0, int &r1,int &r2, int &r3, int &r4);

    
};//clase







#endif
