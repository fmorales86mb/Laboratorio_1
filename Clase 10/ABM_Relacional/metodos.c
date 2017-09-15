#include "metodos.h"

EMedicamento agregarMedicamento (int idMedicamento, int idLaboratorio, EFecha elaboracion)
{
    EMedicamento medicamento = {idMedicamento, idLaboratorio, elaboracion};
    return medicamento;
}

ELaboratorio agregarLaboratorio (int idLabo, char nombre [256])
{
    ELaboratorio labo = {idLabo, nombre};
    return labo;
}
