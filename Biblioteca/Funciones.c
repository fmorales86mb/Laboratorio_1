#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char ConsultaContinuar()
{
    char respuesta;

    printf("\nContinuar? (s/n): ");
    respuesta = tolower(getche());

    return respuesta;
}

int GenerarRandomInt(int inferior, int superior)
{
    int random;

    random = rand() % (superior+1)+inferior;

    return random;
}

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
