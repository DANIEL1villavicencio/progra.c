#include <stdio.h>
#include <math.h>

double calcularDistancia(double punto1[3], double punto2[3])
{
    // Calcula la distancia euclidiana entre dos puntos en 3D
    return sqrt(pow(punto2[0] - punto1[0], 2) + pow(punto2[1] - punto1[1], 2) + pow(punto2[2] - punto1[2], 2));
}

void encontrarRutaMinima(double puntos[][3], int inicio, int fin, int numPuntos)
{
    double distanciaMinima = INFINITY;// no tiene peso xd
    int nodoIntermedio = -1;

    for (int intermedio = inicio + 1; intermedio < fin; ++intermedio)
    {
        double distanciaTotal = calcularDistancia(puntos[inicio], puntos[intermedio]) +
                                calcularDistancia(puntos[intermedio], puntos[fin]);

        if (distanciaTotal < distanciaMinima)
        {
            distanciaMinima = distanciaTotal;
            nodoIntermedio = intermedio;
        }
    }

    printf("Ruta mínima:\n");
    printf("Punto de inicio: (%.1f, %.1f, %.1f)\n", puntos[inicio][0], puntos[inicio][1], puntos[inicio][2]);
    printf("Punto intermedio: (%.1f, %.1f, %.1f)\n", puntos[nodoIntermedio][0], puntos[nodoIntermedio][1], puntos[nodoIntermedio][2]);
    printf("Punto de fin: (%.1f, %.1f, %.1f)\n", puntos[fin][0], puntos[fin][1], puntos[fin][2]);
    printf("Distancia mínima: %.2f\n", distanciaMinima);
}

int main()
{
    double puntos[][3] = {
        {0.0, 0.0, 0.0},
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {10.0, 11.0, 12.0}};

    int inicio;
    int fin;
    printf("Ingrese el punto inicial y el punto final : ");
    scanf("%d %d", &inicio, &fin);
    int numPuntos = sizeof(puntos) / sizeof(puntos[0]);

    encontrarRutaMinima(puntos, inicio, fin, numPuntos);

    return 0;
}