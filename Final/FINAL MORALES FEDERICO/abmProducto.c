#include "abmProducto.h"

EProducto* newEProducto ()
{
    EProducto* returnAux;
    returnAux = (EProducto*)malloc(sizeof(EProducto));

    if(returnAux != NULL)
    {
       returnAux->codigo = 0;
       returnAux->descripcion = "";
       returnAux->precio = 0;
    }
    return returnAux;
}
