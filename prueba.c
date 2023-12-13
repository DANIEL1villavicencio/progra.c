#include <stdio.h>
#include <math.h>
void leerPuntos(float puntos[][3], int filas, int columnas);
void calcularDistancias(float puntos[][3], float distancias[]);
void calcularPerimetro(float *perimetro, float distancias[]);
void calcularArea(float *perimetro, float *area, float distancias[]);

int main(int argc, char *argv[])
{
    float puntos[5][3], distancias[9];
    float perimetro1, area2;
    float punto1,punto2;
    leerPuntos(puntos, 5, 3);
    calcularDistancias(puntos, distancias);
    printf("indique desde que 2 puntos se debe calcular la distancia \n");
    scanf("%f",punto1);
    scanf("%f",punto2);
    calcularPerimetro(&perimetro1, distancias);
    calcularArea(&perimetro1, &area2, distancias);



    printf("El perimetro del triangulo es: %f\n", perimetro1);
    printf("El area del triangulo es: %f\n", area2);
    return 0;
}
void leerPuntos(float puntos[][3], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        printf("Ingrese el la coordenadas (x, y,z) de punto %d :", i+1);
        scanf("%f,%f,%f", &puntos[i][0], &puntos[i][1], &puntos[i][2]);
    }
}
void calcularDistancias(float puntos[][3], float distancias[])
{
    // p1p2
    distancias[0] = sqrt(pow(puntos[0][0] - puntos[1][0], 2) + pow(puntos[0][1] - puntos[1][1], 2) + pow(puntos[0][2] - puntos[1][2], 2));
    // p1p3
    distancias[1] = sqrt(pow(puntos[0][0] - puntos[2][0], 2) + pow(puntos[0][1] - puntos[2][1], 2) + pow(puntos[0][2] - puntos[2][2], 2));
    // p1p4
    distancias[2] = sqrt(pow(puntos[0][0] - puntos[3][0], 2) + pow(puntos[0][1] - puntos[3][1], 2) + pow(puntos[0][2] - puntos[3][2], 2));
    // p1p5
    distancias[3] = sqrt(pow(puntos[0][0] - puntos[4][0], 2) + pow(puntos[0][1] - puntos[4][1], 2) + pow(puntos[0][2] - puntos[4][2], 2));
    // p2p3
    distancias[4] = sqrt(pow(puntos[1][0] - puntos[2][0], 2) + pow(puntos[1][1] - puntos[2][1], 2) + pow(puntos[1][2] - puntos[2][2], 2));
    // p2p4
    distancias[5] = sqrt(pow(puntos[1][0] - puntos[3][0], 2) + pow(puntos[1][1] - puntos[3][1], 2) + pow(puntos[1][2] - puntos[3][2], 2));
    // p2p5
    distancias[6] = sqrt(pow(puntos[1][0] - puntos[4][0], 2) + pow(puntos[1][1] - puntos[4][1], 2) + pow(puntos[1][2] - puntos[4][2], 2));
    // p3p4
    distancias[7] = sqrt(pow(puntos[2][0] - puntos[3][0], 2) + pow(puntos[2][1] - puntos[3][1], 2) + pow(puntos[2][2] - puntos[3][2], 2));
    // p3p5
    distancias[8] = sqrt(pow(puntos[2][0] - puntos[4][0], 2) + pow(puntos[2][1] - puntos[4][1], 2) + pow(puntos[2][2] - puntos[4][2], 2));
    // p4p5
    distancias[9] = sqrt(pow(puntos[3][0] - puntos[4][0], 2) + pow(puntos[3][1] - puntos[4][1], 2) + pow(puntos[3][2] - puntos[5][2], 2));
}
void calcularPerimetro(float *perimetro, float distancias[])
{
    *perimetro = distancias[0] + distancias[1] + distancias[2];
    float s = *perimetro / 2;
}

void calcularArea(float *perimetro, float *area, float distancias[])
{
    *perimetro = distancias[0] + distancias[1] + distancias[2];
    float s = *perimetro / 2;
    *area = sqrt(s * (s - distancias[0]) * (s - distancias[1]) * (s - distancias[2]));
}
