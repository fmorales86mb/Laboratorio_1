#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED

typedef struct //Estructura anidada en otras. Se declara primero.
{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct
{
    int idMedic; //PK (primary key)
    int idLaboratorio; //FK (foreign key)
    EFecha elaboracion; // Estructura anidada
}EMedicamento;

typedef struct
{
    int idLabo; //PK
    char nombre [256];
}ELaboratorio;

typedef struct
{
    int idCliente; //PK
    char nombre [256];
    int medicamento; //FK
    EFecha nacimiento; //Estructura anidada.
}ECliente;

EMedicamento agregarMedicamento (int idMedicamento, int idLaboratorio, EFecha elaboracion);

ELaboratorio agregarLaboratorio (int idLabo, char nombre [256]);

void agregarCliente ();

#endif // METODOS_H_INCLUDED
