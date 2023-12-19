#include <stdio.h>
#include <math.h>

double calcularDistancia(double punto1[3], double punto2[3])
{
    // Calcula la distancia euclidiana entre dos puntos en 3D
    return sqrt(pow(punto2[0] - punto1[0], 2) + pow(punto2[1] - punto1[1], 2) + pow(punto2[2] - punto1[2], 2));
}

void encontrarRutaMinima(double puntos[][3], int inicio, int fin, int numPuntos)
{
    double distanciaMinima = INFINITY;
    int nodosIntermedios[3] = {-1, -1, -1};

    for (int intermedio1 = 0; intermedio1 < 5; ++intermedio1)
    {
        if (intermedio1 != inicio && intermedio1 != fin)
        {
            for (int intermedio2 = 0; intermedio2 < 5; ++intermedio2)
            {
                if (intermedio2 != inicio && intermedio2 != fin && intermedio2 != intermedio1)
                {
                    for (int intermedio3 = 0; intermedio3 < 5; ++intermedio3)
#include <stdio.h>
#include <math.h>

double calcularDistancia(double punto1[3], double punto2[3])
{
    // Calcula la distancia euclidiana entre dos puntos en 3D
    return sqrt(pow(punto2[0] - punto1[0], 2) + pow(punto2[1] - punto1[1], 2) + pow(punto2[2] - punto1[2], 2));
}

void encontrarRutaMinima(double puntos[][3], int inicio, int fin)
{
    double distanciaMinima = INFINITY;
    int nodosIntermedios[3] = {-1, -1, -1};

    for (int intermedio1 = 0; intermedio1 < 5; ++intermedio1)
    {
        if (intermedio1 != inicio && intermedio1 != fin)
        {
            for (int intermedio2 = 0; intermedio2 < 5; ++intermedio2)
            {
                if (intermedio2 != inicio && intermedio2 != fin && intermedio2 != intermedio1)
                {
                    for (int intermedio3 = 0; intermedio3 < 5; ++intermedio3)
                    {
                        if (intermedio3 != inicio && intermedio3 != fin && intermedio3 != intermedio1 && intermedio3 != intermedio2)
                        {
                            double distanciaTotal =
                                calcularDistancia(puntos[inicio], puntos[intermedio1]) +
                                calcularDistancia(puntos[intermedio1], puntos[intermedio2]) +
                                calcularDistancia(puntos[intermedio2], puntos[intermedio3]) +
                                calcularDistancia(puntos[intermedio3], puntos[fin]);
                            printf("distancia total %.1f,  inciando en %d pasando de %d a  %d a  %d y terminando en %d \n", distanciaTotal, inicio,intermedio1, intermedio2, intermedio3, fin);
                            if (distanciaTotal < distanciaMinima)
                            {
                                distanciaMinima = distanciaTotal;
                                nodosIntermedios[0] = intermedio1;
                                nodosIntermedios[1] = intermedio2;
                                nodosIntermedios[2] = intermedio3;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Ruta mínima:\n");
    printf("Punto de inicio: (%.1f, %.1f, %.1f)\n", puntos[inicio][0], puntos[inicio][1], puntos[inicio][2]);
    printf("Punto primer punto intermedio %d : (%.1f, %.1f, %.1f)\n", nodosIntermedios[0], puntos[nodosIntermedios[0]][0], puntos[nodosIntermedios[0]][1], puntos[nodosIntermedios[0]][2]);
    printf("Punto segundo punto intermedio %d: (%.1f, %.1f, %.1f)\n", nodosIntermedios[1], puntos[nodosIntermedios[1]][0], puntos[nodosIntermedios[1]][1], puntos[nodosIntermedios[1]][2]);
    printf("Punto tercer punto intermedio %d: (%.1f, %.1f, %.1f)\n", nodosIntermedios[2], puntos[nodosIntermedios[2]][0], puntos[nodosIntermedios[2]][1], puntos[nodosIntermedios[2]][2]);
    printf("Punto de fin: (%.1f, %.1f, %.1f)\n", puntos[fin][0], puntos[fin][1], puntos[fin][2]);
    printf("Distancia mínima: %.2f\n", distanciaMinima);
}

void leerPuntos(double puntos[][3], int filas) {
    for (int i = 0; i < filas; i++) {
        printf("Ingrese las coordenadas (x, y, z) del punto %d: ", i + 1);
        scanf("%lf, %lf, %lf", &puntos[i][0], &puntos[i][1], &puntos[i][2]);
    }
}

int main()
{
    int inicio, fin;
    double puntos[5][3];
    leerPuntos(puntos, 5);
  do
    {
        printf("Ingrese el punto inicial y el punto final (0-4): ");
        scanf("%d %d", &inicio, &fin);

        encontrarRutaMinima(puntos, inicio, fin);
    } while (inicio != 6);

    return 0;
}

