#include "ArrayList.h"
#include "abmPersona.h"
#include "abmFecha.h"
#include "abmProducto.h"
#include "abmVenta.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MO 50
#define STR 50
#define STRLONG 1000

int modificarCliente (ArrayList* lista);
int comparaElementos(void* elementoA, void* elementoB);
void realizarVenta (ArrayList* listaC, ArrayList* listaV);
void crearCSV(char* fileName);
void levantarCVS(ArrayList* lista);
int levantarClientes (ArrayList* lista, char* fileName, int tam);
int cargarProductos(ArrayList* listaProductos);
int guardarListaPersona (ArrayList* lista, char* fileName, int sizeOfStruct);




#endif // FUNCIONES_H_INCLUDED
