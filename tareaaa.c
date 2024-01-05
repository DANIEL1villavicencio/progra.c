#include <stdio.h>
#include <string.h>
#include "p2.h"
int main()
{
    int menu;
    char nombreProducto[10][50] = {"queso", "tomates", "yogurt", "papas", "carne", "pollo", "leche", "huevos", "aguacate", "pan"};
    int cantidadProducto[10] = {5, 6, 2, 7, 9, 1, 22, 45, 7, 9};

    Mostrar(nombreProducto, cantidadProducto);
    printf("presione 1 para buscar un producto \n 2 para agregar un producto\n 3 para borrar\n, 4 para salir\n");
    scanf("%d", &menu);
    do
    {
        switch (menu)
        {

        case 1:
            Buscar();
            break;
        case 2:
            Agregar();
            break;
        case 3:
            Borrar(nombreProducto, cantidadProducto);
            break;

        default:
            printf("no existe esa opcion\n");
            break;
        }
    } while (menu == 4);

    return 0;
}

void Mostrar(char nombreProducto[10][50], int cantidadProducto[10]);
void Buscar();
void Agregar();
void Borrar(char nombreProducto[10][50], int cantidadProducto[10]);



#include <stdio.h>
#include <string.h>
#include "p2.h"
void Mostrar(char nombreProducto[10][50], int cantidadProducto[10])
{
    FILE *archivo;

    archivo = fopen("archivo1", "w+");
    if (archivo == NULL)
    {
        printf("no hay archivo\n");
    }
    for (int i = 0; i < 10; i++)
    {
        fprintf(archivo, "%s %d \n", nombreProducto[i], cantidadProducto[i]);
    }
    fclose(archivo);
}

void Buscar()
{
    FILE *archivo;

    char productoBuscar[50];
    printf("ingrese el nombre del producto\n");
    scanf("%s", &productoBuscar);
    archivo = fopen("archivo1", "r+");
    if (archivo == NULL)
    {
        printf("no se puede abrir\n");
    }
    int cantidad;
    char producto[50];
    while (feof(archivo) == 0)
    {
        fscanf(archivo, "%s %d", &producto, &cantidad);
        if (strcmp(producto, productoBuscar) == 0)
        {
            printf("la cantidad de papas es %d", cantidad);
        }
    }
    fclose(archivo);
}

void Agregar()
{
    FILE *archivo;
    char nuevoProd[50];
    int nuevoCant;
    archivo = fopen("archivo1", "a+");
    printf("ingrese un nuevo producto y la cantidad de este \n");
    scanf("%s %d", &nuevoProd, &nuevoCant);
    fprintf(archivo, "%s %d ", nuevoProd, nuevoCant);
    fclose(archivo);
}
void Borrar(char nombreProducto[10][50], int cantidadProducto[10])
{
    FILE *archivo;

    archivo = fopen("archivo1", "w+");
    char productoBuscar[50];
    printf("ingrese el nombre del producto a borrar\n");
    scanf("%s", &productoBuscar);
    if (archivo == NULL)
    {
        printf("no se puede abrir\n");
    }
    char producto[50];
    while (feof(archivo) == 0)
    {
        fscanf(archivo, "%s", &producto);

        for (int i = 0; i < 10; i++)
        {
            if (strcmp(producto, productoBuscar) == 0)
            {
                fprintf(archivo, "%s %d \n", nombreProducto[i], cantidadProducto[i]);
            }
        }
    }
    fclose(archivo);
}
