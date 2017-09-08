#include "Medicamentos.h"

void cargarMedicamentos(eMedicamento lista[], int t)
{
    int i;
     for(i=0; i<t; i++)
    {
        printf("Ingrese codigo: ");
        scanf("%d", &lista[i].codigo);
        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(lista[i].descripcion);
        printf("Ingrese precio: ");
        scanf("%f", &lista[i].precio);
        printf("Ingrese laboratorio: ");
        fflush(stdin);
        gets(lista[i].laboratorio);
    }
}
void mostraTodosMedicamentos(eMedicamento lista[], int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        mostrarMedicamento(lista[i]);
    }
}
void mostrarMedicamento(eMedicamento med)
{
    printf("%d--%s--%f--%s\n", med.codigo, med.descripcion, med.precio, med.laboratorio);
}

