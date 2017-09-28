#include "Biblioteca.h"
#include <stdio.h>
void mostrar(int legajos[], int edades[], char nombres[][LETRAS], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d--%d--%s\n",legajos[i] ,edades[i], nombres[i]);
    }
}
