#ifndef ABMPRODUCTO_H_INCLUDED
#define ABMPRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

typedef struct{
    int codigo;
    char* descripcion;
    float precio;
}EProducto;

EProducto* newEProducto(void);

#endif // ABMPRODUCTO_H_INCLUDED
