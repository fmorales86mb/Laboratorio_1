#include <stdio.h>
#include <stdlib.h>
#include "../../Bibliotecas/Input/input.h"
#include "../../Bibliotecas/Arreglos/arreglo.h"

//1) Solicitar al usuario 5 números, permitir listarlos por pantalla indicando el máximo, el mínimo y el promedio.
//Permitir Modificar el valor de cualquiera de los números cargados indicando el índice del mismo y su nuevo valor.

int main()
{
    int arreglo[5];
    int max;
    int min;
    float promedio;
    int indice;
    int i;
    char continuar = 's';
    int opcion;
    int flagIngresoDatos = 0;

    do
    {
        system("cls");
        printf("---- Menu ----\n");
        printf("\n1-Ingresar datos.\n");
        printf("2-Mostrar datos cargados.\n");
        printf("3-Maximo.\n");
        printf("4-Minimo.\n");
        printf("5-Promedio.\n");
        printf("6-Modificar dato.\n");
        printf("7-Salir.\n");

        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1: // Pido datos
            system("cls");
            for (i=0; i<5; i++)
            {
                printf("\nIngrese un numero: ");
                scanf("%d", &arreglo[i]);
            }
            flagIngresoDatos = 1;
            break;

        case 2: // Listo por pantalla.
            system("cls");
            if (flagIngresoDatos == 1)
            {
                for (i=0; i<5; i++)
                {
                    printf("\nIndice %d - ", i);
                    printf("Valor %d", arreglo[i]);
                }
            }
            else
            {
                printf("No ingreso datos.");
            }
            printf("\n\n");
            system("pause");
            break;

        case 3: //Maximo
            system("cls");
            if (flagIngresoDatos == 1)
            {
                max = maximo(arreglo, 5);
                printf("Maximo = %d", max);
            }
            else
            {
                printf("No ingreso datos.");
            }
            printf("\n\n");
            system("pause");
            break;

        case 4://Minimo
            system("cls");
            if (flagIngresoDatos == 1)
            {
                min = minimo(arreglo, 5);
                printf("Minimo = %d", min);
            }
            else
            {
                printf("No ingreso datos.");
            }
            printf("\n\n");
            system("pause");
            break;

        case 5://media
            system("cls");
            if (flagIngresoDatos == 1)
            {
                promedio = media(arreglo, 5);
                printf("Promedio = %.2f", promedio);
            }
            else
            {
                printf("No ingreso datos.");
            }
            printf("\n\n");
            system("pause");
            break;

        case 6://modificar
            system("cls");
            if (flagIngresoDatos == 1)
            {
                printf("Ingrese indice: ");
                scanf("%d", &indice);
                printf("\ningrese valor: ");
                scanf("%d", &arreglo[indice]);
            }
            else
            {
                printf("No ingreso datos.");
            }

            break;
        case 7:
            continuar = 'n';
            break;

        }

    } while (continuar == 's');







    return 0;
}
