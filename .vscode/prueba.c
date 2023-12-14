#include <stdio.h>
#include <math.h>
void leerPuntos(double puntos[][3], int filas);

#include <stdio.h>
#include <math.h>

double calcularDistancia(double punto1[3], double punto2[3]) {
    // Calcula la distancia euclidiana entre dos puntos en 3D
    return sqrt(pow(punto2[0] - punto1[0], 2) + pow(punto2[1] - punto1[1], 2) + pow(punto2[2] - punto1[2], 2));
}

void encontrarRutaMinima(double puntos[][3], int inicio, int fin, int numPuntos) {
    double distanciaMinima = INFINITY;
    int nodoIntermedio = -1;

    for (int intermedio = inicio + 1; intermedio < fin; ++intermedio) {
        double distanciaTotal = calcularDistancia(puntos[inicio], puntos[intermedio]) +
                                calcularDistancia(puntos[intermedio], puntos[fin]);

        if (distanciaTotal < distanciaMinima) {
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
void leerPuntos(double puntos[][3], int filas)
{
    for (int i = 0; i < filas; i++)
    {
        printf("Ingrese el la coordenadas (x, y,z) de punto %d :", i+1);
        scanf("%lf,%lf,%lf", &puntos[i][0], &puntos[i][1], &puntos[i][2]);
    }
}


int main() {
    int inicio;
    int fin ;
    double puntos[5][3] ;
    leerPuntos (puntos,5);
     for (int i = 0; i < 5; i++)
    {
        printf("%lf,%lf,%lf", puntos[i][0], puntos[i][1], puntos[i][2]);

    }
    printf("Ingrese el punto inicial y el punto final (0-4): ");
    scanf("%d %d", &inicio, &fin);

    
    int numPuntos = sizeof(puntos) / sizeof(puntos[0]);

    encontrarRutaMinima(puntos, inicio, fin, numPuntos);

    return 0;
}

