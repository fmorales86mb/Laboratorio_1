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
    char codigoProducto[17];
    float precioUnitario;
    int cantidad;
    EFecha* fechaVenta;
}EVenta;

EVenta* newEVenta(void);
EVenta* newEventaIni(int p_idCliente, int p_id, int p_cant, float p_precioUnit, EFecha* p_fechaVenta, char* p_codigo);
int generarIdVenta (ArrayList* lista);
int pedirVenta (EVenta *venta);
int altaVenta(ArrayList *listaV, ArrayList* listaP);
void listarVenta(ArrayList* lista, int (*pFunc)(void* ,void*), int descendente);
int comparaIdVenta (void* elementoA, void* elementoB);
int comparaImporteVenta (void* elementoA, void* elementoB);
ArrayList* listaVentasIdCliente (ArrayList* lista, int p_idCliente);
ArrayList* listaVentasProducto (ArrayList* lista, char* p_prod);

#endif // ABMVENTA_H_INCLUDED
