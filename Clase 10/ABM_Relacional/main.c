#include <stdio.h>
#include <stdlib.h>
#include "metodos.h"

int main()
{
    // listas
    EMedicamento listaMedicamentos [5];
    ELaboratorio listaLaboratorios [3];
    ECliente listaClientes [2];

    //harcodeo
    EFecha elaboracion1 = {15, 2, 1960};
    EFecha elaboracion2 = {16, 3, 1960};
    EFecha elaboracion3 = {17, 4, 1963};
    listaMedicamentos[0]=agregarMedicamento(2,1, elaboracion1);
    listaMedicamentos[1]=agregarMedicamento(3,2, elaboracion2);
    listaMedicamentos[2]=agregarMedicamento(4,3, elaboracion3);
    listaMedicamentos[3]=agregarMedicamento(5,1, elaboracion1);
    listaMedicamentos[4]=agregarMedicamento(6,2, elaboracion2);

    listaLaboratorios[0]=agregarLaboratorio(1, "labo1");
    listaLaboratorios[1]=agregarLaboratorio(2, "labo2");
    listaLaboratorios[2]=agregarLaboratorio(3, "labo3");

    printf("%d\t%s", listaMedicamentos[0].idMedic, listaLaboratorios[2].nombre);

    return 0;
}

