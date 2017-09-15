#include <stdio.h>
#include <stdlib.h>
#include "Medicamentos.h"
#define TAM 3
int menu(char[]);


int main()
{
    eMedicamento listaMedicamentos[TAM];
    int i;
    int opcion;
    for(i=0; i<TAM; i++)
    {
        listaMedicamentos[i].estado = 0;
    }

    do
    {
        opcion=menu("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Modificacion\n5.Baja\n6.Salir\n Elija una opcion: ");
        switch(opcion)
        {
            case 1:
                //cargarMedicamentos(listaMedicamentos, TAM);
                inicializarMedicamentos(listaMedicamentos, TAM);
            break;
            case 2:
                mostraTodosMedicamentos(listaMedicamentos, TAM);
            break;
            case 3:
                ordenarMedicamentos(listaMedicamentos, TAM);
            break;
            case 4:
                modificarMedicamento(listaMedicamentos, TAM);
            break;
            case 5:
                eliminarMedicamento(listaMedicamentos, TAM);
            break;
        }

    }while(opcion!=6);


    return 0;
}

int menu(char texto[])
{
    int opcion;
    printf("%s", texto);
    scanf("%d", &opcion);

    return opcion;
}

