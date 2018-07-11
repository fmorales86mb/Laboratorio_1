#ifndef ABMPRODUCTO_H_INCLUDED
#define ABMPRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

typedef struct{
    int id;
    char codigo[20];
    float precio;
}EProducto;

EProducto* newEProducto();
EProducto* newEProductoIni(int p_id, float p_precio, char* p_codigo);
void printProducto(EProducto* elemento);
void listarProductos(ArrayList* lista, int (*pFunc)(void* ,void*), int descendente);
int cargarCsvTxtProducto (ArrayList* lista, char* fileName, int encabezado);
int comparaIdProducto (void* elementoA, void* elementoB);
void levantarProd (ArrayList* lista);

#endif // ABMPRODUCTO_H_INCLUDED
