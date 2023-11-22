    #include <stdio.h>
#include <math.h>
#include <string.h>
int main(void)
{
    int i1, i2, j1, j2,i3,j3;
    printf("ingrese la cantidad de columnas de la primera matriz:");
    scanf("%d", &i1);
    printf("ingrese la cantidad de columnas de la primera matriz:");
    scanf("%d", &j1);
    printf("ingrese la cantidad de columnas de la primera matriz:");
    scanf("%d", &i2);
    printf("ingrese la cantidad de columnas de la primera matriz:");
    scanf("%d", &j2);
    int matriz1[i1][j1];
    int matriz2[i2][j2];
    int resultado[i3][j3];
    if (j1==i2)
    {
    i3=i1;
    j3=j2;
    for (int i = 0; i < i1; i++)
    {
    for (int j = 0; i < j1; j++)
    {
    printf("ingrese el elemento %d %d de la matriz1",i+1,j+1);
    scanf("%d", &matriz1[i][j]);
    }
    }
    for (int i = 0; i < i2; i++)
    {
    for (int j = 0; i < j2; j++)
    {
    printf("ingrese el elemento %d %d de la matriz1",i+1,j+1);
    scanf("%d", &matriz2[i][j]);
    }
    
   
    }
    
    for (int i = 0; i < i1; ++i)
    {
        for (int j = 0; j < j2; ++j)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < j1; ++k)
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    printf("Matriz 1:\n");
    for (int i = 0; i < i1; ++i)
    {
        for (int j = 0; j < j1; ++j)
        {
            printf("%d\t", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz 2:\n");
    for (int i = 0; i < i2; ++i)
    {
        for (int j = 0; j < j2; ++j)
        {
            printf("%d\t", matriz2[i][j]);
        }
        printf("\n");
    }

    printf("\nResultado de la multiplicación:\n");
    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < j3; ++j)
        {
            printf("%d\t", resultado[i][j]);
        }
        printf("\n");
    }
    }
    else{
    printf("\nlas dos matrices no se pueden multiplicar\n");    
    }
    return 0;
}
