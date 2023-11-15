#include <stdio.h>
#include <math.h>
char distancia[10];
distanciaf(float x1, float x2, float y1, float y2);
datof(char coord, float centro);

int main(void)
{

    char x[5], y[5];
    for (int i = 0; i < 5; i++)
    {
       x[i]=datof("x",i+1);
        y[i]=datof("y",i+1);
    }
    

    for (int i = 1; i < 5; i++)
    {
        for (int j = i + 1; j < 6; i++)
        {
            distancia[10] = distanciaf(x[i], x[j], y[i], y[j]);
        }
    }

    printf("el volumen del cono truncado es %f\n");

    return 0;
}

distanciaf(x1, x2, y1, y2)
{

    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return dist;
}
datof(coord,centro){
float dato;
 printf("las componentes de %c del punto %f\n",coord, centro);
 scanf("%f",&dato);
 return dato;
} 
