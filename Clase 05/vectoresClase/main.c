#include <stdio.h>
#include <stdlib.h>
#define TAM 10


int main()
{


    int vector[TAM];
    int acum = 0;
    int i;
    int flag =0;
    int maximo;
    int minimo;
    char opcion;

    do
    {
        system("cls");
        printf("1. Cargar\n2.Mostrar\n3.Inversa\n4.Suma\n5.Minimo\n6.Maximo\n7.Pares\n8.Salir\nElija una opcion: ");
        opcion = getche();
        switch(opcion)
        {
        case '1':
            for(i=0; i<TAM; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", &vector[i]);
            }
            break;
        case '2':
            printf("\nIngresados\n");
            for(i=0; i<TAM; i++)
            {
                printf("%d\n", vector[i]);
            }
            system("pause");
            break;
        case '3':
            printf("\nInversa\n");
            for(i=TAM-1; i>=0; i--)
            {
                printf("%d\n", vector[i]);
            }
            system("pause");
            break;
        case '4':
            acum = 0;
            for(i=0; i<TAM; i++)
            {
                acum += vector[i];
            }
            printf("El acumulado es: %d", acum);

            system("pause");
            break;
        case '5':
            flag = 0;
            for(i=0; i<TAM; i++)
            {
                if(flag==0 || vector[i]<minimo)
                {
                    minimo = vector[i];
                    flag=1;
                }
            }
            printf("\nLos minimos\n");
            for(i=0; i<TAM; i++)
            {
                if(vector[i]==minimo)
                {
                    printf("%d\n", vector[i]);
                }
            }

            system("pause");
            break;
        case '6':
            flag = 0;
            for(i=0; i<TAM; i++)
            {
                if(flag==0 || vector[i]>maximo)
                {
                    maximo = vector[i];
                    flag = 1;
                }
            }

            printf("\nLos maximos\n");
            for(i=0; i<TAM; i++)
            {
                if(vector[i]==maximo)
                {
                    printf("%d\n", vector[i]);
                }
            }
            system("pause");
            break;
        case '7':
            printf("\nLos pares\n");
            for(i=0; i<TAM; i++)
            {
                if(vector[i]%2 == 0)
                {
                    printf("%d\n", vector[i]);
                }
            }
            system("pause");
            break;
        }

    }
    while(opcion!='8');

















    return 0;
}
