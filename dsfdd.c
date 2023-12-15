#include <stdio.h>
#include <string.h>
#include "volumen.h"
int main(void)
{
    char cedula[10][50], nombre[10][50];
    int edad[10], i = 1, choice;
    do
    {
        display(&choice);
       
        switch (choice)
        {
        case 1:
            datos(cedula, nombre, edad, &i);
            i++;
            break;
        case 2:
            eliminar(cedula, nombre, edad);
            break;
        case 3:
            buscar(cedula, nombre, edad);
            break;
        case 4:
            editar(cedula, nombre, edad);
            break;
        case 5:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (choice != 5);

    return 0;
}
void display ( int *choice);
void datos(char cedula[10][50], char nombre[10][50], int edad[10], int *i);
void eliminar(char cedula[10][50], char nombre[10][50], int edad[10]);
void buscar(char cedula[10][50], char nombre[10][50], int edad[10]);
void editar(char cedula[10][50], char nombre[10][50], int edad[10]);

#include <stdio.h>
#include <string.h>
#include "volumen.h"
void display( int *choice)
{
          printf("\n1. registrar contacto\n");
        printf("2. borrar contacto\n");
        printf("3. buscar contactos\n");
        printf("4. editar contacto\n");
        printf("5. salir \n ");
        printf("Ingrese su eleccion: ");
        scanf("%d", choice);
}
void datos(char cedula[][50], char nombre[][50], int edad[10], int *i)
{

    printf("Ingrese datos del contacto %d:\n", *i);
    printf("nombre: ");
    fflush(stdin);
    scanf("%s", &nombre[*i - 1]);
    printf("cedula: ");
    fflush(stdin);
    scanf("%s", &cedula[*i - 1]);
    printf("edad: ");
    fflush(stdin);
    scanf("%d", &edad[*i - 1]);

    printf("contacto ingresado con exito ");
}
void eliminar(char cedula[][50], char nombre[][50], int edad[10])
{
    char vacio[50] = "vacio";
    char cedula2[50];
    float mins, total, pagar;
    getchar();

    printf("ingrese la cedula de la persona a eliminar ");
    fflush(stdin);
    scanf("%s", cedula2);

    int found = 0;
    for (int i = 0; i < 10; ++i)
    {

        if ((strcmp(cedula[i], cedula2) == 0))
        {
            found = 1;
            strcpy(nombre[i], vacio);
            strcpy(cedula[i], vacio);
            edad[i] = 0;
            printf("contacto eliminado correctamente.\n");
        }
    }
    if (found == 0)
    {
        printf("contacto no encontrado.\n");
    }
}
void buscar(char cedula[][50], char nombre[][50], int edad[10])
{
    char cedula2[50];
    float mins, total, pagar;
    getchar();

    printf("ingrese la cedula de la persona a buscar ");
    fflush(stdin);
    scanf("%s", cedula2);

    int found = 0;
    for (int i = 0; i < 10; ++i)
    {

        if ((strcmp(cedula[i], cedula2) == 0))
        {
            found = 1;
            printf("contacto %d:\n", i + 1);
            printf(" nombre: \t");
            printf(" %s \t", nombre[i]);
            printf("\n cedula: ");
            printf("%s \t", cedula[i]);
            printf("\n edad: \t");
            printf(" %d \t", edad[i]);
        }
        if (found == 0)
        {
            printf("contacto no encontrado.\n");
        }
    }
}
void editar(char cedula[][50], char nombre[][50], int edad[10])
{

    char vacio[50] = "vacio";
    char cedula2[50];
    float mins, total, pagar;
    getchar();

    printf("ingrese la cedula de la persona a editar ");
    fflush(stdin);
    scanf("%s", cedula2);

    int found = 0;
    for (int i = 0; i < 10; ++i)
    {

        if ((strcmp(cedula[i], cedula2) == 0))
        {
            found = 1;
            printf("Ingrese datos del contacto %d:\n", i);
            printf("nombre: ");
            fflush(stdin);
            scanf("%s", &nombre[i]);
            printf("cedula: ");
            fflush(stdin);
            scanf("%s", &cedula[i]);
            printf("edad: ");
            fflush(stdin);
            scanf("%d", &edad[i]);
            printf("contacto editado correctamente.\n");
        }
    }
    if (found == 0)
    {
        printf("contacto no encontrado.\n");
    }
}
