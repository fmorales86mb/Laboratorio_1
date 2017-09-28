#ifndef FUNCABM_H_INCLUDED
#define FUNCABM_H_INCLUDED

typedef struct
{
    int idMedicamento;//PK
    char descripcion[50];
    float precio;
    int idLaboratorio;//FK
    //int stock;
    //eFecha fechaElaboracion;
    //eFecha fechaVencimiento;
} eMedicamento;

typedef struct
{
    int idCliente;//
    char nombre[50];
    //int idMedicamento;//FK
} eCliente;

typedef struct
{
    int idLaboratorio;//PK
    char razonSocial[25];
} eLaboratorio;

typedef struct
{
    int idCliente;
    int idMedicamento;
    int cantidad;
}eClienteMedicamento;

void inicializarMedicamentos(eMedicamento[], int);
void inicializarClientes(eCliente[], int);
void inicializarClienteMedicamento (eClienteMedicamento listaVentas[], int sizeVentas);
void inicializarLaboratorios(eLaboratorio laboratorios[], int sizeLab);
void mostrarMedicamentos (eMedicamento medicamentos[], int size);
void mostrarClientes (eCliente clientes[], int size);
int clientePorNombre (eCliente clientes[], int size, char nombre[]);
eCliente clientePorID (eCliente clientes[], int size, int id);
int medicamentoPorNombre (eMedicamento medicamentos[], int size, char nombre[]);
eMedicamento medicamentoPorId (eMedicamento medicamentos[], int size, int id);


#endif // FUNCABM_H_INCLUDED
