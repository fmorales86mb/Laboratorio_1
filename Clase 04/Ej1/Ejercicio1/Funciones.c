#include <stdio.h>
#include <conio.h>

int PedirInt()
{
    int nro;

    printf("\nIngrese numero: ");
    scanf("%d", &nro);

    return nro;
}

float PedirFloat()
{
    float nro;

    printf("\nIngrese numero: ");
    scanf("%f", &nro);

    return nro;
}

char PedirChar()
{
    char caracter;

    printf("\nIngrese caracter: ");
    caracter = getche();

    return caracter;
}
