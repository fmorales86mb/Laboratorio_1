#include <stdio.h>
#include <stdlib.h>

#include "Medicamentos.h"

int main()
{
    eMedicamento listaMedicamentos[3];
    int i;


    cargarMedicamentos(listaMedicamentos, 3);
    mostraTodosMedicamentos(listaMedicamentos, 3);

    return 0;
}

