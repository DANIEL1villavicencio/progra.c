#include <stdio.h>
#include <math.h>
#include <string.h>
char distancia[10];

int main(void)
{
    int edad[5], buscar;
    char nombre[5][10];
    char codigo[5][10];
    char id[10];
    for (int i = 0; i < 5; i++)
    {
        printf("ingrese el nombre de la persona %i\n", i + 1);
        scanf("%s", &nombre[i]);
        printf("ingrese el codigo de la persona %i\n", i + 1);
        scanf("%s", &codigo[i]);
        printf("ingrese la edad de la persona %i\n", i + 1);
        scanf("%i", &edad[i]);
    }
    do
    {
        printf("ingrese el codogio de la persona %i\n" );
        scanf("%i", &id);
    for (int j = 0; j < 4; j++)
    {

        if (strcmp(codigo[j], id) == 0)
        {
            printf(" la edad de la persona es %i\n",  edad[j] );
            printf("el codigo de la persona es %s\n",codigo[j] );
            printf("el nombre de la persona es %s\n",nombre[j] );
        } 
    }
            printf("presione 0 para salir o cualquier teclar para continuar \n" );
        scanf("%i", &buscar);
    } while (buscar=0);
    
    return 0;
}
