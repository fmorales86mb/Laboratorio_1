#ifndef ABMVENTA_H_INCLUDED
#define ABMVENTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "abmFecha.h"

typedef struct{
    int id;
    int idCliente;
    char codigoProducto[17];
    float precioUnitario;
    int cantidad;
    EFecha* fechaVenta;
}EVenta;

EVenta* newEVenta(void);

#endif // ABMVENTA_H_INCLUDED
