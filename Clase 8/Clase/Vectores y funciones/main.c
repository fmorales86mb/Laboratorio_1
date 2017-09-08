#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#define TAM 5


int main()
{
    int edades[5]={10,17,6,9,14};
    int legajos[5]={1,2,3,4,5};
    char nombres_alumnos[5][LETRAS]={"Pepe","Moni","Coqui","Paola","Maria Enema"};

    mostrar(legajos, edades, nombres, TAM);

    return 0;
}

