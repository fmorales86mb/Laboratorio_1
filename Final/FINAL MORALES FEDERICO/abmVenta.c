#include "abmVenta.h"

EVenta* newEVenta()
{
    EVenta* returnAux;
    returnAux = (EVenta*)malloc(sizeof(EVenta));

    if(returnAux !=NULL)
    {
       returnAux->cantidad = 0;
       returnAux->idCliente = 0;
       returnAux->id = 0;
       returnAux->precioUnitario = 0;
       strcpy(returnAux->codigoProducto, "");
       returnAux->fechaVenta = newEFecha();
    }
    return returnAux;
}
