#include <stdio.h>
#include <stdlib.h>

#include "utn.h"

int main()
{
    // Prueba de las funciones de la biblioteca.
    int sumaInt;
    sumaInt = sumarInt(3,6);
    printf("\nsuma int = %d", sumaInt);

    float sumaFloat;
    sumaFloat = sumarFloat(2.3, 2.65);
    printf("\nsuma float = %f", sumaFloat);

    char continuar;
    continuar = ConsultaContinuar();
    printf("\ncontinuar = %c", continuar);

    int random;
    random = GenerarRandomInt(-5, 109);
    printf("\nRandom = %d", random);

    return 0;
}
