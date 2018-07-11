#ifndef ABMFECHA_H_INCLUDED
#define ABMFECHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionStr.h"

typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

EFecha* newEFecha ();
EFecha* newEFechaIni (int d, int m, int y);
int pedirFecha (EFecha *fecha);
EFecha* aToDate (char* date);

#endif // ABMFECHA_H_INCLUDED
