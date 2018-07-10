#include "ArrayList.h"
#include "abmPersona.h"
#include "abmFecha.h"
#include "abmProducto.h"
#include "abmVenta.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MO 50
#define STR 50
#define STRLONG 1000

void altaCliente (ArrayList* listaC); // 1
void modificacionCliente (ArrayList* listaC); // 2
void bajaCliente (ArrayList* listaC, ArrayList* listaV); // 3
void listarClientes (ArrayList* listaC); // 4
void opcionAltaVenta (ArrayList* listaC, ArrayList* listaV); // 6
void opcionListarVenta(ArrayList* listaV); // 7
void informarVentasPorProducto (ArrayList* listaV); // 8
void informarVentasPorCliente (ArrayList* listaC, ArrayList* listaV); // 10

void crearCSV(char* fileName);
void levantarCVS(ArrayList* lista);


#endif // FUNCIONES_H_INCLUDED
