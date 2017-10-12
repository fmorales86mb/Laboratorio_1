#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int entero;
    char caracter;
}eDato;


void cargarDatos(eDato*, int);
void mostrarDatos(eDato*, int);
void newDato(eDato*, int, char);//Constructor parametrizado


int main()
{
    eDato miDato[3];
    int i;

    cargarDatos(miDato, 3);
    printf("\n");
    mostrarDatos(miDato, 3);





    //printf("%d--%c", (*(pDato+1)).entero,(*(pDato+1)).caracter);

    return 0;
}
void cargarDatos(eDato* pDato, int t)
{
    int i;
    int entero;
    char caracter;

    for(i=0; i<t; i++)
    {
        printf("Ingrese un entero: ");
        scanf("%d", &entero);
        printf("Ingrese un caracter: ");
        caracter = getche();

        newDato(pDato+i, entero, caracter);

    }

}
void mostrarDatos(eDato* pDato, int t)
{
    int i;
    for(i=0; i<t; i++)
    {
         printf("%d--%c\n", (pDato+i)->entero,(pDato+i)->caracter);
    }
}
void newDato(eDato* pDato, int ent, char car)
{
    pDato->entero=ent;
    pDato->caracter = car;
}
/* eDato miDato={1,'A'};

    eDato* pDato;

    pDato = &miDato;

  printf("%d--%c", pDato->entero, pDato->caracter);*/
