#include "ArrayList.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MO 50
#define STR 50
#define STRLONG 1000

typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct{
    int codigo;
    char* descripcion;
    float precio;
}EProducto;

typedef struct{
    int id;
    int idCliente;
    char codigoProducto[17];
    float precioUnitario;
    int cantidad;
    EFecha* fechaVenta;
}EVenta;

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    long int dni;
}ECliente;

EFecha* newEFecha ();
EProducto* newEProducto(void);
EVenta* newEVenta(void);
ECliente* newECliente(void);

int altaClientes(ArrayList *lista, char* fileName);
int pedirCliente (ECliente *cliente);
int generarIdCliente (ArrayList* lista);
int modificarCliente (ArrayList* lista);
ECliente* buscarCliente (ArrayList* lista, int id);
int pedirId ();
void listarClientes(ArrayList* lista);
int comparaElementos(void* elementoA, void* elementoB);
int levantarListaClientes (ArrayList* lista, char* fileName);
void realizarVenta (ArrayList* listaC, ArrayList* listaV);
void crearCSV(char* fileName);
void levantarCVS(ArrayList* lista);
ECliente* buscarClientePorDNI(ArrayList* lista, long int dni);

int pisarArchivoCliente(ArrayList *lista, char* nombre, int sizeOfStruct);
int guardarLista (ArrayList* lista, char* fileName, int sizeOfStruct);

int levantarClientes (ArrayList* lista, char* fileName, int tam);
int cargarProductos(ArrayList* listaProductos);

#endif // FUNCIONES_H_INCLUDED
