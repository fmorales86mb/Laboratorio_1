#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void pedirChar (char* pletra);

int main()
{
    char vletra;

    pedirChar(&vletra);
    printf("\n%c", vletra);

    return 0;
}

void pedirChar (char* pletra)
{
    printf("Ingrese letra: ");
    fflush(stdin);
    *pletra = getche();
}
