#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesEstructura.h"

int i;
void cargaMedicamentos (eMedicamento listaMed[], int tam)
{
    // carga de vectores de struct
    for(i=0;i<tam;i++)
    {
        printf("\nCodigo: ");
        scanf("%d", &listaMed[i].codigo);
        printf("\nPrecio: ");
        scanf("%f", &listaMed[i].precio);
        printf("\nNombre: ");
        fflush( stdin );
        gets(listaMed[i].nombre);
        fflush( stdin );
        printf("\nLaboratorio: ");
        gets(listaMed[i].laboratorio);
    }
}

void mostrarMedicamentos (eMedicamento listaMed[], int tam)
{
    // muestro datos.
    for (i=0;i<tam;i++)
    {
        printf("%d\t%f\t%s\t%s\n",
               listaMed[i].codigo,
               listaMed[i].precio,
               listaMed[i].nombre,
               listaMed[i].laboratorio);
    }
}

// carga un solo medicamento.
void mostrarMedicamento (eMedicamento med)
{
    printf("%d\t%f\t%s\t%s\n",
               med.codigo,
               med.precio,
               med.nombre,
               med.laboratorio);
}
