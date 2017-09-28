#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcABM.h"

/*
1- Cargar hardcodeando datos:
	a. Medicamentos
	b. Laboratorios
	c. Clientes
	d. Clientes - Medicamentos
2- Mostrar:
    a. Medicamentos
    b. Clientes
    c. Cada cliente con los medicamentos que compro.

    for en clientes
        printf nom cli
        for en clixmed
            if idcliente == id cliente de lista clixmed
                for en medi
                    if medicamento == a med en lista med
                    print f med
                    break

    d. Por cada medicamento: los clientes que lo compraron.
    e. Por cada medicamento: Total de las ventas.
    f. El medicamento mas vendido.
    g. Todos los clientes que compraron medicamentos del laboratorio Roemers.
*/

#define LAB 3
#define MED 5
#define CLI 10
#define VEN 5

int main()
{
    eLaboratorio listaLaboratorios[LAB];
    eMedicamento listaMedicamentos[MED];
    eCliente listaClientes[CLI];
    eClienteMedicamento listaVentas[VEN];

    inicializarClienteMedicamento(listaVentas, VEN);
    inicializarClientes(listaClientes, CLI);
    inicializarLaboratorios(listaLaboratorios, LAB);
    inicializarMedicamentos(listaMedicamentos, MED);

    mostrarMedicamentos(listaMedicamentos, MED);
    mostrarClientes(listaClientes, CLI);

    eCliente cli = clientePorID(listaClientes, CLI, 444);
    printf("\n%s %d", cli.nombre, cli.idCliente);

    //char nombre[50];
    //int enco = medicamentoPorId(listaMedicamentos, MED, 102, nombre);
    //printf("\n %s \t %d", nombre, enco);

    //int id = medicamentoPorNombre(listaMedicamentos, MED, "Tafirol");
    //printf("\n%d", id);

    //char nombre[50];
    //int enco = clientePorID(listaClientes, CLI, 444, nombre);
    //printf("\n %s \t %d", nombre, enco);

    //int id = clientePorNombre(listaClientes, CLI, "Felipe");
    //printf("\n%d", id);

    return 0;
}
