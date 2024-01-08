#include <stdio.h>
#include <string.h>
#include "p2.h"
int main()
{
    int menu;
    char nombreProducto[10][50] = {"queso", "tomates", "yogurt", "papas", "carne", "pollo", "leche", "huevos", "aguacate", "pan"};
    int cantidadProducto[10] = {5, 6, 2, 7, 9, 1, 22, 45, 7, 69};

    do
    {
        printf("presione 1 para crear el archivo producto\n 2 para buscar un producto \n 3 para agregar un producto\n 4 para editar\n 5 para borrar\n 6 para salir\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            Mostrar(nombreProducto, cantidadProducto);
            break;
        case 2:
            Buscar();
            break;
        case 3:
            Agregar();
            break;
        case 4:
           Editar();
            break;
        case 5:
            Borrar();
            break;

        default:
            printf("no existe esa opcion\n");
            break;
        }
    } while (menu != 6);

    return 0;
}

void Mostrar(char nombreProducto[10][50], int cantidadProducto[10]);
void Buscar();
void Agregar();
void Editar();
void Borrar();




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
    return;
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
            printf("la cantidad de %s es %d \n", producto, cantidad);
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
    printf("producto ingresado con exito \n");
}
void Editar()
{
    FILE *archivo, *archivoSalida;

    char productoEditar[50];
    int editar = 0;
    int cantidad;
    char producto[50];
    char productoNuevo[50];
    int cantidadNuevo;
    archivo = fopen("archivo1", "r+");
    archivoSalida = fopen("Archivo", "w+");
    printf("Ingrese el producto a editar: ");
    scanf("%s", &productoEditar);
    while (feof(archivo) == 0)
    {
        fscanf(archivo, "%s %d \n", &producto, &cantidad);
        if (strcmp(producto, productoEditar) == 0)
        {
            printf("Ingrese el nuevo nombre y la nueva cantidad del producto: ");
            scanf("%s %d", &productoNuevo, &cantidadNuevo);
            fprintf(archivoSalida, "%s %d \n", productoNuevo, cantidadNuevo);
            editar = 1;
            continue;
        }
        if (!editar)
        {
            fprintf(archivoSalida, "%s %d\n", producto, cantidad);
        }
        editar = 0;
    }
    fclose(archivo);
    fclose(archivoSalida);
    remove("archivo1");
    rename("Archivo", "archivo1");
    printf("producto editado con éxito.\n");
}

void Borrar()
{
    FILE *archivo, *archivoSalida;
    char productoBorrar[50];
    int borrar = 0;
    int cantidad;
    char producto[50];
    archivo = fopen("archivo1", "r+");
    archivoSalida = fopen("Archivo", "w+");
    printf("Ingrese el producto a eliminar: ");
    scanf("%s", &productoBorrar);
    while (feof(archivo) == 0)
    {
        borrar = 0;
        fscanf(archivo, "%s %d \n", &producto, &cantidad);
        if (strcmp(producto, productoBorrar) == 0)
        {
            borrar = 1;
            continue;
        }
        if (!borrar)
        {
            fprintf(archivoSalida, "%s %d \n", producto, cantidad);
        }
    }
    fclose(archivo);
    fclose(archivoSalida);
    remove("archivo1");
    rename("Archivo", "archivo1");

    printf("producto eliminado con éxito.\n");
}

