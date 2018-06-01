#include "ArrayList.h"
#include "abmCliente.h"
#include "abmFecha.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MO 50
#define STR 50
#define STRLONG 1000

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


EProducto* newEProducto(void);
EVenta* newEVenta(void);

int altaClientes(ArrayList *lista, char* fileName);
int generarIdCliente (ArrayList* lista);
int modificarCliente (ArrayList* lista);
int pedirId ();
void listarClientes(ArrayList* lista);
int comparaElementos(void* elementoA, void* elementoB);
int levantarListaClientes (ArrayList* lista, char* fileName);
void realizarVenta (ArrayList* listaC, ArrayList* listaV);
void crearCSV(char* fileName);
void levantarCVS(ArrayList* lista);
int pisarArchivoCliente(ArrayList *lista, char* nombre, int sizeOfStruct);
int guardarLista (ArrayList* lista, char* fileName, int sizeOfStruct);

int levantarClientes (ArrayList* lista, char* fileName, int tam);
int cargarProductos(ArrayList* listaProductos);

#endif // FUNCIONES_H_INCLUDED
