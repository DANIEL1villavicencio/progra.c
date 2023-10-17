#include <stdio.h>

char imprimirMenu();

float leerNumeroProducto(char producto[], float precio);

float preciof(float subtotal);

char select1;

int main(void)

{

    int resp, opcion, fact;

    float numa = 0, numb = 0, numc = 0, numd = 0, nume = 0, totala = 0, totalb = 0, totalc = 0, totald = 0, totale = 0;

    float precioa = 150, preciob = 55, precioc = 180, preciod = 70, precioe = 120;

    float subta = 0, subtb = 0, subtc = 0, subtd = 0, subte = 0, subtotal = 0, subtotaldes = 0, total = 0;

    char nombre[50], cedula[20];

    do

    {

        printf("presione 1 para ingresar a menu o 2 para salir del programa ");

        fflush(stdin);

        scanf("%i", &opcion);

        switch (opcion)

        {

        case 1:

            do

            {

                imprimirMenu();

                switch (select1)

                {

                case 'a':
                    subta = leerNumeroProducto("Llantas", precioa);
                    break;

                case 'b':
                    subtb = leerNumeroProducto("Pastillas", preciob);
                    break;

                case 'c':
                    subtc = leerNumeroProducto("Kit de embrague", precioc);
                    break;

                case 'd':

                    subtd = leerNumeroProducto("Faros", preciod);

                    break;

                case 'e':

                    subte = leerNumeroProducto("Radiadores", precioe);
                    break;
                }

                subtotal = subta + subtb + subtc + subtd + subte;
                total = preciof(subtotal);

                printf("desea regresar agregar otro articulo ? (presione 1 para regresar al menu o cualquier numero para proceder a la factura)\n");

                scanf("%i", &resp);

            } while (resp == 1);
            printf("desea imprimir la factura ? presione 1 )\n");

            scanf("%i", &fact);
            if (fact ==1){
            printf("Ingrese el nombre del cliente\n");

            fflush(stdin);

            scanf("%s", &nombre);

            printf("Ingrese el numero de cedula\n");

            fflush(stdin);

            scanf("%s", &cedula);

            printf("---------------Factura--------------\n");

            printf("Nombre del cliente: %s\n", nombre);

            printf("Cedula del cliente: %s\n", cedula);

            printf("Producto\t\tCantidad\t\tSubtotal\n");

            if (subta > 0)

                printf("Llantas\t\t%.2f.\t\t%.2f\n", totala, subta);

            if (subtb > 0)

                printf("Pastillas Freno\t\t%.2f\t\t%.2f\n", totalb, subtb);

            if (subtc > 0)

                printf("Embrague\t\t%.2f\t\t%.2f\n", totalc, subtc);

            if (subtd > 0)

                printf("Faro\t\t%.2f\t\t%.2f\n", totald, subtd);

            if (subte > 0)

                printf("Radiador\t\t%.2f\t\t%.2f\n", totale, subte);

            printf("Sub total\t%.2f\n", subtotal);

            printf("Sub total con descuento\t%.2f\n", subtotaldes);

            printf("Total\t%.2f\n", total);
            }

            break;

        case 2:

            printf("fin del programa\n");

            break;

        default:

            printf("opcion no valida\n");

            break;
        }

    } while (opcion != 2);

    return 0;
}

char imprimirMenu()

{

    printf("---------------BIENVENIDOS-------------------------\n");

    printf("Elija que producto desea facturar:\n");

    printf("a) Llantas (Precio: $150)\n");

    printf("b) Kit Pastillas de freno (Precio: $55)\n");

    printf("c) Kit de embrague (Precio: $180)\n");

    printf("d) Faro (Precio: $70)\n");

    printf("e) Radiador (Precio: $120)\n");

    fflush(stdin);

    scanf("%c", &select1);

    return select1;
}

float leerNumeroProducto(char producto[], float precio)

{
    int resp;
    float num, subtotal, totala;
    do
    {

        printf("Ingrese la cantidad de %s que desea comprar: ", producto);

        fflush(stdin);

        scanf("%f", &num);
        totala = totala + num;

        subtotal = totala * precio;
        printf("desea ingresar otro producto? (presione 1 para ingresar nuevos datos o cualquier numero para salir) ");

        fflush(stdin);

        scanf("%i", &resp);

    } while (resp == 1);

    return subtotal;
}

float preciof(float subtotal)
{
    float subtotaldes, totalf;
    if (subtotal > 100 && subtotal <= 500)

    {

        subtotaldes = subtotal * 0.95;
    }

    else if (subtotal > 500 && subtotal <= 1000)

    {

        subtotaldes = subtotal * 0.93;
    }

    else if (subtotal > 1000)

    {

        subtotaldes = subtotal * 0.90;
    }

    totalf = subtotaldes * 1.12;
    return totalf;
}