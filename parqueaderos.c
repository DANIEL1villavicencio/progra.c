#include <stdio.h>
#include <string.h>
#include <math.h>
#define parqueadero 10
void caso1(int *lote, char placa[][50], char modelo[][50], char color[][50], float ingresoh[10], float ingresom[10], char estado[][50], char parqueado[50]);
void caso2(char placa1[50], float *salidah, float *minutos, char placa[][50], char modelo[][50], char color[10][50], float ingresoh[10], float ingresom[10], char estado[][50], char parqueado[50], char vacio[50]);
void caso3(int espacio[10], char placa[][50], char estado[][50]);
int main()
{
    int choice, lote;
    int espacio[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char color[10][50] = {"vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio"};
    char placa[10][50] = {"vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio"};
    char modelo[10][50] = {"vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio"};
    char estado[10][50] = {"vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio", "vacio"};
    char placa1[50];
    char parqueado[50] = "parqueado";
    char vacio[50] = "vacio";
    float ingresoh[10];
    float ingresom[10];
    float salidah, minutos, mins, pagar, total;
    do
    {
        printf("\n1. registrar vehiculo\n");
        printf("2. salida y pago del vehiculo\n");
        printf("3. Mostrar parqueadero\n");
        printf("4. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            caso1(&lote, placa, modelo, color, ingresoh, ingresom, estado, parqueado);
            break;
        case 2:

            caso2(placa1, &salidah, &minutos, placa, modelo, color, ingresoh, ingresom, estado, parqueado, vacio);

            break;

        case 3:
            caso3(espacio, placa, estado);
            break;
        case 4:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (choice != 4);

    return 0;
}
void caso1(int *lote, char placa[][50], char modelo[][50], char color[10][50], float ingresoh[10], float ingresom[10], char estado[][50], char parqueado[50])
{

    printf("Ingrese datos del vehiculo:\n");
    printf("espacio (del 1 al 10): ");
    fflush(stdin);
    scanf("%d", lote);
    printf("placa: ");
    fflush(stdin);
    scanf("%s", &placa[*lote - 1]);
    printf("modelo: ");
    fflush(stdin);
    scanf("%s", &modelo[*lote - 1]);
    printf("color: ");
    fflush(stdin);
    scanf("%s", &color[*lote - 1]);
    printf("ingreso (hora): ");
    fflush(stdin);
    scanf("%f", &ingresoh[*lote - 1]);
    printf("ingreso (minuto): ");
    fflush(stdin);
    scanf("%f", &ingresom[*lote - 1]);
    strcpy(estado[*lote - 1], parqueado);

    printf("vehiculo ingresado con exito ");
}
void caso2(char placa1[50], float *salidah, float *minutos, char placa[][50], char modelo[][50], char color[10][50], float ingresoh[10], float ingresom[10], char estado[][50], char parqueado[50], char vacio[50])
{
    float mins, total, pagar;
    getchar();

    printf("la placa de su vehiculo ");
    fflush(stdin);
    scanf("%s", placa1);

    int found = 0;
    for (int i = 0; i < parqueadero; ++i)
    {

        if ((strcmp(placa[i], placa1) == 0))
        {
            found = 1;
            printf("Ingrese la hora de salida ");
            fflush(stdin);
            scanf("%f", salidah);
            printf("Ingrese los minutos de salida ");
            fflush(stdin);
            scanf("%f", minutos);

            mins = ((*salidah * 60) + *minutos);
            total = ceil((mins - (((ingresoh[i] * 60) + ingresom[i]))) / 60);
            pagar = total * (1.50);
            printf("debe pagar %f \n", pagar);
            printf("gracias por su visita \n");
            strcpy(placa[i], vacio);
            strcpy(modelo[i], vacio);
            strcpy(color[i], vacio);
            strcpy(estado[i], vacio);
            ingresoh[i] = 0;
            ingresom[i] = 0;
        }
    }
    if (found == 0)
    {
        printf("vehiculo no encontrado.\n");
    }
}
void caso3(int espacio[10], char placa[][50], char estado[][50])
{
    printf(" espacios: \t");
    for (int i = 0; i < parqueadero; i++)
    {
        printf(" %d \t", espacio[i]);
    }
    printf("\n vehiculos: ");
    for (int i = 0; i < parqueadero; i++)
    {
        printf("%s \t", placa[i]);
    }
    printf("\n estado: \t");
    for (int i = 0; i < parqueadero; i++)
    {
        printf(" %s \t", estado[i]);
    }
    printf(" \t");
}