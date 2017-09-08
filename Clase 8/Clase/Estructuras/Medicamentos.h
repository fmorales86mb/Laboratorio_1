
typedef struct
{
    int codigo;
    char descripcion[50];
    float precio;
    char laboratorio[30];
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

