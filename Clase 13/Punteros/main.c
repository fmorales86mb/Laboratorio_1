#include <stdio.h>
#include <stdlib.h>
/*
 El asterisco (*) se denomina operador de inacceso
 Se usa en dos ocaciones.
     -para declarar que una variable es un puntero. (int* puntero)
     -para ir al valor de la dir de memoria que guarda el puntero. (*puntero =3)
*/
int main()
{
    int* pInt; //puntero
    int var = 7; // variable

    pInt = &var; //le paso al puntero la dir de memoria de Var.

    printf(" %d \n", var); // Muestro valor de Var a través de la variable.
    printf(" %d \n\n", *pInt); // Muestro valor de Var a través del puntero.

    printf(" %p \n", &var); // Dir de memoria de var.
    printf(" %p \n", pInt); // Dir de memoria que guarda PInt.
    printf(" %p \n", &pInt); // Dir de memoria de pInt.

    return 0;
}
