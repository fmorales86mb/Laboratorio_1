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

typedef struct
{
    int idProducto;
    int idUsuario;
    int calificacion;
}eVenta;

void harcodearUsuario (eUsuario lista[]);
void mostrarUsuarios (eUsuario lista[], int size);
void iniListaUs (eUsuario lista[], int size);
int indiceUsLibre (eUsuario listaUs[], int size);
int buscarIdUsuariolibre (eUsuario lista[], int size);
int buscarUsuario1(char nombre[], char pass[], eUsuario lista[], int size );
eUsuario cargarUsuario (int id);
void altaUsuario (eUsuario listaUs[], int sizeUs);
eUsuario buscarUsuarioPorId (eUsuario lista[], int size, int id, int estado);
void modificarUsuario (eUsuario listaUs[], int sizeUs);

void harcodearProducto (eProducto lista[]);
void iniListaPR(eProducto lista[], int size);
int indicePrLibre (eProducto lista[], int size);
int buscarIdProductolibre (eProducto lista[], int size);
eProducto cargarProducto (int id, int idUs);
void altaProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs );
void listarPublicaciones (eProducto listaPr [], eUsuario listaUs [],int sizePr, int sizeUs);
void comprarProducto (eProducto listaPr[], int sizePr, eUsuario listaUs, int sizeUs, eVenta listaVe[], int sizeVe);

void iniVentas (eVenta lista[], int size);
int indiceLibreVenta (eVenta lista[], int size);


#endif // FUNCIONESEXAMEN_H_INCLUDED
