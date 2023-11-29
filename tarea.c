int main()
{
    int productCount = 7;
    char id[100][50] = {"A0001", "A0002", "A0003", "A0004", "A0005", "A0006", "A0007"};
    char name[100][50] = {"Ibuprofeno", "Meloxicam", "Clonazepam", "Mebucaina ", "Lemonflu", "Aspirina", "Paracetamol"};
    float price[100] = {6.50, 4.40, 3.25, 4.00, 2.30, 1.75, 3.50};
    float quantity[100] = {60, 55, 40, 56, 30, 70, 80};
    int choice, casos;
    char removeId[50], Id2[50];
    float total, cantidad;
    do
    {
        printf("\n interfaz stock Fybeca granados:\n");
        printf("\n1. Agregar producto\n");
        printf("2. Quitar producto\n");
        printf("3. Mostrar inventario\n");
        printf("4. calcular precio del producto\n");
        printf("5.quitar o agregar stock\n");
        printf("6. editar item\n");
        printf("7. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (productCount < productos)
            {
                printf("Ingrese detalles del producto:\n");
                printf("ID:\n ");
                scanf("%s", &id[productCount]);
                printf("Nombre: \n");
                scanf("%s", &name[productCount]);
                printf("Precio:\n ");
                scanf("%f", &price[productCount]);
                printf("Cantidad: \n");
                scanf("%f", &quantity[productCount]);
                productCount++;
                printf("El producto %s ha sido ingresado exitosamente\n", id[productCount]);
            }
            else
            {
                printf("El inventario está lleno. No se pueden agregar más productos.\n");
            }
            break;
        case 2:
            if (productCount > 0)
            {
                getchar();
                printf("Ingrese el ID del producto a quitar:\n ");
                scanf("%s", &removeId);

                int found = 0;
                for (int i = 0; i < productCount; ++i)
                {
                    if ((strcmp(id[i], removeId) == 0))
                    {
                        found = 1;
                        // Mover los productos restantes hacia atrás en el array
                        for (int j = i; j < productCount - 1; ++j)
                        {
                            strcpy(id[j], id[j + 1]);
                            strcpy(name[j], name[j + 1]);
                            price[j] = price[j + 1];
                            quantity[j] = quantity[j + 1];
                        }
                        productCount--;
                        printf("Producto eliminado exitosamente.\n");
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else
            {
                printf("El inventario está vacío. No hay productos para quitar.\n");
            }
            break;
        case 3:

            printf(" id: \t");
            for (int i = 0; i < productCount; i++)
            {
                printf("\t %s \t\t", id[i]);
            }
            printf("\n medicamentos: ");
            for (int i = 0; i < productCount; i++)
            {
                printf("\t %s \t", name[i]);
            }
            printf("\n precios: \t");
            for (int i = 0; i < productCount; i++)
            {
                printf(" \t%.2f$ \t\t", price[i]);
            }
            printf(" \t");
            printf("\n cantidad: \t");
            for (int i = 0; i < productCount; i++)
            {
                printf(" \t%.2f \t\t", quantity[i]);
            }

            break;
        case 4:
            getchar();
            printf(" id \t medicamentos\n");
            for (int i = 0; i < productCount; i++)
            {
                printf(" %s \t %s\n", id[i], name[i]);
            }
            printf("Ingrese el ID del producto a comprar: \n");

            scanf("%s", &Id2);

            int found = 0;
            for (int i = 0; i < productCount; ++i)
            {
                if ((strcmp(id[i], Id2) == 0))
                {
                    found = 1;
                    printf("Ingrese la cantidad de %s que deseas adquirir (quedan %.2f disponibles) \n", name[i], quantity[i]);
                    scanf("%f", &cantidad);

                    quantity[i] = quantity[i] - cantidad;
                    if (quantity[i] < 0)
                    {
                        do
                        {
                            quantity[i] = quantity[i] + cantidad;
                            printf("No existen suficente stock");
                            printf("Ingrese la cantidad de %s que deseas adquirir (quedan %.2f disponibles)\n ", name[i], quantity[i]);
                            scanf("%f", &cantidad);
                            quantity[i] = quantity[i] - cantidad;
                        } while (quantity[i] < 0);
                    }
                    total = price[i] * cantidad;
                    printf(" debes pagar %.2f $ por  %.2f  de %s \n ", total, cantidad, name[i]);
                    printf("stock restante %.2f:\n ", quantity[i]);
                }
            }
            if (found == 0)
            {
                printf("Producto no encontrado.\n");
            }
            break;
        case 5:
            do
            {
                int found = 0;

                printf("presione 1 para renovar o 2 para quitar o 3 para salir \n");

                scanf("%d", &casos);

                switch (casos)
                {
                case 1:
                    getchar();
                    printf(" id \t medicamentos\n");
                    for (int i = 0; i < productCount; i++)
                    {
                        printf(" %s \t %s\n", id[i], name[i]);
                    }
                    printf("Ingrese el ID del producto a modificar stock: \n");

                    scanf("%s", &Id2);
                    for (int i = 0; i < productCount; ++i)
                    {
                        if ((strcmp(id[i], Id2) == 0))
                        {
                            found = 1;
                            printf("Ingrese la cantidad de %s que deseas renovar (quedan %.2f disponibles) \n", name[i], quantity[i]);
                            scanf("%f", &cantidad);

                            quantity[i] = quantity[i] + cantidad;

                            printf("stock renovado %.2f:\n ", quantity[i]);
                        }
                    }
                    if (found == 0)
                    {
                        printf("Producto no encontrado.\n");
                    }

                    break;
                case 2:
                    getchar();
                    printf(" id \t medicamentos\n");
                    for (int i = 0; i < productCount; i++)
                    {
                        printf(" %s \t %s\n", id[i], name[i]);
                    }
                    printf("Ingrese el ID del producto a modificar stock: \n");

                    scanf("%s", &Id2);
                    for (int i = 0; i < productCount; ++i)
                    {
                        if ((strcmp(id[i], Id2) == 0))
                        {
                            found = 1;
                            printf("Ingrese la cantidad de %s que deseas quitar (quedan %.2f disponibles) \n", name[i], quantity[i]);
                            scanf("%f", &cantidad);

                            quantity[i] = quantity[i] - cantidad;
                            if (quantity[i] < 0)
                            {
                                do
                                {
                                    quantity[i] = quantity[i] + cantidad;
                                    printf("No existen suficente stock");
                                    printf("Ingrese la cantidad de %s que deseas adquirir (quedan %.2f disponibles)\n ", name[i], quantity[i]);
                                    scanf("%f", &cantidad);
                                    quantity[i] = quantity[i] - cantidad;
                                } while (quantity[i] < 0);
                            }
                            printf("stock restante %.2f:\n ", quantity[i]);
                        }
                    }
                    if (found == 0)
                    {
                        printf("Producto no encontrado.\n");
                    }

                    break;
                case 3:
                    printf("salir.\n");
                    break;
                default:
                    printf("opcion invalida.\n");
                    break;
                }
            } while (casos != 3);
            break;
        case 6:
            if (productCount > 0)
            {
                getchar();
                printf("Ingrese el ID a editar:\n ");
                scanf("%s", &removeId);

                int found = 0;
                for (int i = 0; i < productCount; ++i)
                {
                    if ((strcmp(id[i], removeId) == 0))
                    {
                        found = 1;
                        printf("Ingrese detalles del producto:\n");
                        printf("nuevo ID (viejo id: %s) \n ", id[i]);
                        scanf("%s", &id[i]);
                        printf("nuevo nombre (viejo nombre: %s) \n ", name[i]);
                        scanf("%s", &name[i]);
                        printf("nuevo precio (viejo precio: %.2f) \n ", price[i]);
                        scanf("%f", &price[i]);
                        printf("nueva cantidad (vieja cantidad: %.2f) \n ", quantity[i]);
                        scanf("%f", &quantity[i]);
                        printf("El producto %s ha sido editadoo exitosamente\n", removeId);
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else
            {
                printf("El inventario está vacío. No hay productos para editar.\n");
            }
            break;

        case 7:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (choice != 7);

    return 0;
}
