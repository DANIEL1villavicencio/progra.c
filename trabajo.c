#include <stdio.h>
#include <math.h>
#include "volumen.h"

int main(void)

{
    float rx = 0, ry = 0, rz = 0, cx = 0, cy = 0, cz = 0, altura = 0, numd = 0, volumen = 0, radio;
    cx = datos();
    cy = datos();
    cz = datos();
    rx = datos();
    ry = datos();
    rz = datos();
    altura= datos();
    volumen = volumenf(cx, cy, cz, rx, ry, rz, altura);
    printf("el volumen del cono truncado es %f\n", volumen);

    return 0;
}
