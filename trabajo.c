#include <stdio.h>
#include <math.h>

float volumenf(float cx, float cy, float cz, float rx, float ry, float rz, float altura);

int main(void)

{
    float rx = 0, ry = 0, rz = 0, cx = 0, cy = 0, cz = 0, altura = 0, numd = 0, volumen = 0, radio;

    printf("ingrese el centro del cono, como coordenadas x,y,z\n");
    scanf("%f %f %f", &cx, &cy, &cz);
    printf("ingrese el radio del cono,como coordenadas xyz\n");
    scanf("%f %f %f", &rx, &ry, &rz);
    printf("ingrese la altura del cono\n");
    scanf("%f", &altura);
    volumen = volumenf(cx, cy, cz, rx, ry, rz, altura);
    printf("el volumen del cono truncado es %f\n", &volumen);

    return 0;
}

float volumenf(float cx, float cy, float cz, float rx, float ry, float rz, float altura)
{
    float vol, alturaf, radio, radiot;
    alturaf = altura * 1 / 4;
    radio = sqrt(pow(rx - cx, 2) + pow(ry - cy, 2) + pow(rz - cz, 2));
    radiot = (1/4) * radio;
    vol = ((pow(radio, 2) * altura * 3.14) / 3) - ((pow(radiot, 2) * alturaf * 3.14) / 3);

    return vol;
}
