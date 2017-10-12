#include <stdio.h>
#include <stdlib.h>
#include "bibStrValidacion.h"

int main()
{
    float nro =2.6;
    int resu;
    resu = pedirFloat(&nro, "ingrese nro: ", "nro invalido.", -10.5, 10.5);
    printf("\n %f\t %d \n", nro, resu);

    char str[10] = {"string"};
    resu = pedirStrLetras(str, "ingrese una cadena: ", "cadena invalida.", 1, 9);
    printf("\n%s\t %d \n", str, resu);

    int nroInt=-15;
    resu = pedirInt(&nroInt, "ingrese nro: ", "nro invalido.", -10, 10);
    printf("\n %d\t %d \n", nroInt, resu);

    return 0;
}
