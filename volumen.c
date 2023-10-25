
#include <stdio.h>
#include <math.h>
#include "volumen.h"
float datos(){
float dato ;
printf("ingrese el centro del cono, como coordenadas x,y,z\n");
   fflush(stdin);
    scanf("%f", &dato);
return dato;
 }
float volumenf(float cx, float cy, float cz, float rx, float ry, float rz, float altura)
{
    float vol, alturaf, radio, radiot;
    alturaf = altura * 1 / 4;
    radio = sqrt(pow(rx - cx, 2) + pow(ry - cy, 2) + pow(rz - cz, 2));
    radiot = (1 / 4) * radio;
    vol = ((pow(radio, 2) * altura * 3.14) / 3) - ((pow(radiot, 2) * alturaf * 3.14) / 3);

    return vol;
}
