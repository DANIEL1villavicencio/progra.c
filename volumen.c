
#include <stdio.h>
#include <math.h>
#include "volumen.h"
float datos(char centro[20], char coordenada[20]){
float dato ;
printf("ingrese  %s del cono como componente en %s\n", centro, coordenada);
   fflush(stdin);
    scanf("%f", &dato);
return dato;
 }
float volumenf(float cx, float cy, float cz, float rx, float ry, float rz, float a1,float a2, float a3,float r2x, float r2y, float r2z)
{
    float vol, altura,alturat1 ,alturat2 , radio1,radio2, radiot;
    altura =sqrt(pow(a1 - cx, 2) + pow(a2 - cy, 2) + pow(a3 - cz, 2)); 
    alturat1= altura *2/3;
    alturat2= altura*1/3;
    radio1 = sqrt(pow(rx - cx, 2) + pow(ry - cy, 2) + pow(rz - cz, 2));
    radiot = (2 / 3) * radio1;
    radio2= sqrt(pow(a1 - r2x, 2) + pow(a2 - r2y, 2) + pow(a3 - r2z, 2));
    vol = (((pow(radio1, 2)+pow(radiot, 2) + radio1*radiot)* alturat1 * 3.14) / 3) + ((pow(radio2, 2) +(pow(radiot, 2)+ radio2*radiot) *alturat2 * 3.14) / 3) ;
 
    return vol;
}
