#include <stdio.h>
#include <math.h>
#include <string.h>
char distancia[10];

int main(void)
{
    int matriz1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriz2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int resultado[3][3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; ++k)
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    printf("Matriz 1:\n");
    mostrarMatriz(matriz1);

    printf("\nMatriz 2:\n");
    mostrarMatriz(matriz2);

    printf("\nResultado de la multiplicación:\n");
    mostrarMatriz(resultado);
    return 0;
}

int mostrarMatriz(int matriz[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    return 
