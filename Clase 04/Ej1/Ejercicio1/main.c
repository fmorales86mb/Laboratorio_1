#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/*
1) Desarrollar una biblioteca "utn.h" que posea funciones para pedirle al usuario el ingreso de datos

getInt()
getFloat()
getChar()
*/

int main()
{
    int nroInt;
    float nroFloat;
    char caracter;

    nroInt=PedirInt();
    nroFloat=PedirFloat();
    caracter=PedirChar();

    printf("\nint %d\nfloat=%f\nchar=%c",nroInt,nroFloat,caracter);

    return 0;
}
