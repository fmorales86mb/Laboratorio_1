#ifndef FUNCPARCIAL_H_INCLUDED
#define FUNCPARCIAL_H_INCLUDED

#define STR 50

typedef struct
{
    int horas;
    int minutos;
    int segundos;
}eTiempo;

typedef struct
{
    int idLlamada; //
    char motivo[STR];
    int idAbonado; //fk
    int estado;
    eTiempo tiempo;
}eLlamada;

typedef struct
{
    int idAbonado;
    int numero;
    char nombre[STR];
    char apellido[STR];
}eAbonado;

int altaAbonado (eAbonado listaAbonado[], int sizeAbo);
eAbonado cargarAbonado ();
int traerUltimoIdAbonado (eAbonado listaAbonado[], int sizeAbo);
void inicializarIdAbonados (eAbonado listaAbonados[], int sizeAbo, int id);
void modificarAbonado (eAbonado listaAbonado[], int sizeAbo);



#endif // FUNCPARCIAL_H_INCLUDED
