#ifndef ABMVENTA_H_INCLUDED
#define ABMVENTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "abmFecha.h"
#include "abmPersona.h"

typedef struct{
    int id;
    int idCliente;
    int idProducto;
    int cantidad;
}EVenta;

EVenta* newEVenta();
EVenta* newEventaIni(int p_idCliente, int p_id, int p_cant, int p_idProducto);
int generarIdVenta (ArrayList* lista);
int agregarVenta(ArrayList *listaV, EVenta* elemento);
void printVenta (EVenta* elemento);
void listarVentas(ArrayList* lista, int (*pFunc)(void* ,void*), int descendente);
int comparaIdVenta (void* elementoA, void* elementoB);
int buscarVentaId (ArrayList* lista, int id);
ArrayList* listaVentasIdCliente (ArrayList* lista, int p_idCliente);
ArrayList* listaVentasProducto (ArrayList* lista, int p_idProd);

#endif // ABMVENTA_H_INCLUDED
