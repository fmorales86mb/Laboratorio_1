#ifndef ABMFECHA_H_INCLUDED
#define ABMFECHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

EFecha* newEFecha ();

#endif // ABMFECHA_H_INCLUDED
