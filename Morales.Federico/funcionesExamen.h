#ifndef FUNCIONESEXAMEN_H_INCLUDED
#define FUNCIONESEXAMEN_H_INCLUDED

#include <string.h>
#define STR 50

typedef struct
{
    int id;
    int estado;
    char nombre[50];
    char pass [50];
}eUsuario;

typedef struct
{
    int id;
    int idUsuario;
    int estado;
    char nombre[50];
    //float precio;
    int precio;
    int stock;
    int ventas;
}eProducto;

void harcodearUsuario (eUsuario lista[], int size);
void harcodearProducto (eProducto lista[], int size);


void iniListaUs (eUsuario lista[], int size);
void iniListaPR(eProducto lista[], int size);

int indiceUsLibre (eUsuario listaUs[], int size);
int indicePrLibre (eProducto lista[], int size);

int buscarIdUsuariolibre (eUsuario lista[], int size);
int buscarIdProductolibre (eProducto lista[], int size);
int buscarUsuario1(char nombre[], char pass[], eUsuario lista[], int size );

eUsuario cargarUsuario (int id);
eProducto cargarProducto (int id, int idUs);

void altaUsuario (eUsuario listaUs[], int sizeUs);
void altaProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs );

void listarPublicaciones (eProducto listaPr [], eUsuario listaUs [],int sizePr, int sizeUs);


#endif // FUNCIONESEXAMEN_H_INCLUDED
