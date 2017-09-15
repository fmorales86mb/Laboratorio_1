#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char descripcion[50];
    float precio;
    char laboratorio[30];
    int estado;//0:No esta cargado o 1:Si esta cargado
}eMedicamento;

/** \brief
 *
 * \param Array de medicamentos: Lista de medicamentos
 * \param
 * \return
 *
 */

void cargarMedicamentos(eMedicamento[], int);
void mostraTodosMedicamentos(eMedicamento[], int);
void mostrarMedicamento(eMedicamento);
void ordenarMedicamentos(eMedicamento[], int);
void inicializarMedicamentos(eMedicamento[], int);
void modificarMedicamento(eMedicamento[], int);
void eliminarMedicamento(eMedicamento[], int);
