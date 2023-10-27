#include <stdio.h>
#include <math.h>
#include "volumen.h"

int main(void)

{

    float rx = 0, ry = 0, rz = 0, cx = 0, cy = 0, cz = 0, a1 = 0, a2 = 0, a3 = 0, volumen = 0, r2x = 0, r2y = 0, r2z = 0;
    cx = datos("centro", "x");
    cy = datos("centro", "y");
    cz = datos("centro", "z");
    rx = datos("radio inferior", "x");
    ry = datos("radio inferior", "y");
    rz = datos("radio inferior", "z");
    a1 = datos("altura", "x");
    a2 = datos("altura", "y");
    a3 = datos("altura", "z");
    r2x = datos("radio superior", "x");
    r2y = datos("radio  superior", "y");
    r2z = datos("radio  superior", "z");
    volumen = volumenf(cx, cy, cz, rx, ry, rz, a1, a2, a3, r2x, r2y, r2z);
    printf("el volumen del cono truncado es %f\n", volumen);

    return 0;
}
