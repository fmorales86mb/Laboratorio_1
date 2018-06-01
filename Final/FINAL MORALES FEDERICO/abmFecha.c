#include "abmFecha.h"

EFecha* newEFecha ()
{
    EFecha* returnAux;
    returnAux = (EFecha*)malloc(sizeof(EFecha));

    if(returnAux != NULL)
    {
       returnAux->dia = 0;
       returnAux->mes = 0;
       returnAux->anio = 0;
    }
    return returnAux;
}
