#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesEstructura.h"



int main()
{
    eMedicamento med1; //esctructura con basura
    eMedicamento med2 = {2, "med2", 10.6, "lab2"}; // estcuctura con datos

    // copio datos de uno en otro en forma manual
    /*
    med1.codigo = med2.codigo;
    med1.precio = med2.precio;
    strcpy(med1.laboratorio, med2.laboratorio);
    strcpy(med1.nombre, med2.nombre);
    */

    // copio datos de uno en otro usando propiedad de estructuras.
    med1 = med2;

    // if (med1 == med2){} No se puede comparar estructuras con ==
    // se debe hacer en forma manual.

    if (strcmp(med1.nombre, med2.nombre) == 0)
    {
        printf("nombres iguales.\n");
    }

    //los muestro
    printf("%d\t%.2f\t%s\t%s\n",
           med1.codigo,
           med1.precio,
           med1.nombre,
           med1.laboratorio);

    printf("%d\t%.2f\t%s\t%s\n",
           med2.codigo,
           med2.precio,
           med2.nombre,
           med2.laboratorio);
    system("pause");
    system("cls");

    // VECTOR DE ESTRUCTURA

    eMedicamento listaMedicamentos [3]; //vector de medicamentos.
    int i;

    // carga de vectores de struct
    for(i=0;i<3;i++)
    {
        printf("\nCodigo: ");
        scanf("%d", &listaMedicamentos[i].codigo);
        printf("\nPrecio: ");
        scanf("%f", &listaMedicamentos[i].precio);
        printf("\nNombre: ");
        fflush( stdin );
        gets(listaMedicamentos[i].nombre);
        fflush( stdin );
        printf("\nLaboratorio: ");
        gets(listaMedicamentos[i].laboratorio);
    }

    // muestro datos.
    for (i=0;i<3;i++)
    {
        printf("%d\t%f\t%s\t%s\n",
               listaMedicamentos[i].codigo,
               listaMedicamentos[i].precio,
               listaMedicamentos[i].nombre,
               listaMedicamentos[i].laboratorio);
    }

    return 0;
}
