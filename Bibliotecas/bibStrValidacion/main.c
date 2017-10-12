#include <stdio.h>
#include <stdlib.h>
#include "bibStrValidacion.h"

int main()
{
    //int nro=-15;
    char str[10] = {"string"};

    pedirStrLetras(str, "ingrese una cadena: ", "cadena invalida.", 1, 9);
    printf("\n%s\n", str);

    //pedirInt(&nro, "ingrese nro: ", "nro invalido.", -10, 10);
    //printf("\n %d \n", nro);

    return 0;
}
