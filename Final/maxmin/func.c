#include <stdio.h>
#include <stdlib.h>

int sumar (int a, int b)
{
    int suma;
    suma = a + b;
    return suma;
}

void cargaSecuencial (int length)
{
    int vec[length];
    int i;

    for (i=0; i<length; i++)
    {
        printf("\n Ingrese un número: ");
        scanf("%d", &vec[i]);
    }

    printf("\n");

    for (i=0; i<length; i++)
    {
        printf("%d, ", vec[i]);
    }
}

void vectoresParalelos (int length)
{
    int vEdad[length];
    float vAltura[length];
    int i;
    float promedioEdad;
    float acumulador = 0;

    for(i=0; i<length; i++)
    {
        printf("\n\n Persona nro %d:", i);

        printf("\n Ingrese edad: ");
        scanf("%d", &vEdad[i]);
        acumulador += vEdad[i];

        printf("\n Ingrese altura: ");
        scanf("%f", &vAltura[i]);
    }

    promedioEdad = acumulador / length;

    printf("\n Promedio de edad: %.2f", promedioEdad);
}

void cargaAleatoria (int length)
{
    int i;
    int vEdad[length];
    int nro=0;
    float promedioEdad;
    float acumulador = 0;
    int indice;
    char seguir = 'n';

    for(i=0; i<length; i++)
    {
        vEdad[i]=0;
    }

    do
    {
        printf("\n\n Persona nro %d:\n", nro+1);

        printf("\n Ingrese Posicion: ");
        scanf("%d", &indice);

        printf("\n Ingrese edad: ");
        scanf("%d", &vEdad[indice]);
        acumulador += vEdad[indice];

        printf("\n Desea Seguir? s/n");
        scanf("%c", &seguir);

    }while(seguir == 's');

    promedioEdad = acumulador / nro;

    printf("\n Promedio de edad: %.2f", promedioEdad);
}

int buscarMayor(int v[], int length)
{
    int i;
    int mayor = v[0];

    for(i=1; i<length; i++)
    {
        if(v[i]>mayor)
        {
            mayor = v[i];
        }
    }

    return mayor;
}

void imprimirMatriz (int filas, int columnas)
{
    int i, j;

    for(i=1; i<=filas; i++)
    {
        printf("\n");
        for(j=1; j<=columnas; j++)
        {
            printf("[%d][%d], ", i, j);
        }
    }
}
