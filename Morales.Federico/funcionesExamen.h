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
    float precio;
    //int precio;
    int stock;
    int ventas;
}eProducto;

typedef struct
{
    int idProducto;
    int idUsuario;
    int calificacion;
}eVenta;

/**
* \brief Lista los usuarios con más publicaciones.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño de listaUs.
* \param listaPr. Array de eProducto
* \param sizePr. Tamaño de listaPr.
*/
void listarUsConMasPublicaciones (eUsuario listaUs[], int sizeUs, eProducto listaPr[], int sizePr);

/**
* \brief Calcula el màximo valor del array de int.
* \param listaInt. Array de int.
* \param sizeArray. Tamaño del array.
* \return màximo valor del array.
*/
int maximo (int listaInt[], int sizeArray);

/**
* \brief Harcodea lista de usuarios.
* \param lista. Array de eUsuario
*/
void harcodearUsuario (eUsuario lista[]);

/**
* \brief Muestra por consola la lista de usuarios activos.
* \param lista. Array de eUsuario.
* \param size. Tamaño del array.
*/
void mostrarUsuarios (eUsuario lista[], int size);

/**
* \brief Inicializa lista de usuarios.
* \param lista. Array de eUsuario.
* \param size. Tamaño del array.
*/
void iniListaUs (eUsuario lista[], int size);

/**
* \brief Busca el índice del primer elemento del array con estado inactivo.
* \param listaUs. Array de eUsuario.
* \param size. Tamaño del array.
* \return Indice libre.
*
*/
int indiceUsLibre (eUsuario listaUs[], int size);

/**
* \brief Busca el ID del primer elemento del array estado inactivo.
* \param lista. Array de eUsuario.
* \param size. Tamaño del array.
* \return Id de usuario.
*
*/
int buscarIdUsuariolibre (eUsuario lista[], int size);

/**
* \brief Busca el elemento del array con los parámetros dados.
* \param nombre. nombre del usuario.
* \param pass. Password del usuario.
* \param lista. Array de eUsuario.
* \param size. Tamaño del array.
* \return Id de usuario.
*
*/
int buscarUsuario1(char nombre[], char pass[], eUsuario lista[], int size );

/**
* \brief Pide datos de eUsuario.
* \param id. Id del eUsuario
* \return eUsuario con los datos ingresados.
*/
eUsuario cargarUsuario (int id);

/**
* \brief Pide datos de eUsuario y lo da de alta en la lista.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array.
*/
void altaUsuario (eUsuario listaUs[], int sizeUs);

/**
* \brief Buscar usuario por id.
* \param lista. Array de eUsuario.
* \param size. Tamaño del array.
* \param id. id del usuario a buscar.
* \param estado. Estado del usuario a buscar.
* \return eUsuario del id pasado.
*/
eUsuario buscarUsuarioPorId (eUsuario lista[], int size, int id, int estado);

/**
* \brief Pide datos de eUsuario y los carga en uno ya existente.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array.
*/
void modificarUsuario (eUsuario listaUs[], int sizeUs);

/**
* \brief Pide datos de eUsuario y lo da de baja en la lista.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array de usuarios.
* \param listaPr. Array de eProducto.
* \param sizePr. Tamaño del array de productos.
*/
void bajaUsuario (eUsuario listaUs[], int sizeUs, eProducto listaPr[], int sizePr);

/**
* \brief Lista Usuarios con promedio de calificaciones.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array de usuarios.
* \param listaVe. Array de eVentas.
* \param sizeVe. Tamaño del array de eVentas.
*/
void listarUsuarios (eUsuario listaUs[], int sizeUs, eVenta listaVe[], int sizeVe);



/**
* \brief Harcodea lista de productos.
* \param lista. Array de eProducto
*/
void harcodearProducto (eProducto lista[]);

/**
* \brief Inicializa lista de productos.
* \param lista. Array de eProductos.
* \param size. Tamaño del array.
*/
void iniListaPR(eProducto lista[], int size);

/**
* \brief Busca el índice del primer elemento del array con estado inactivo.
* \param lista. Array de eProducto.
* \param size. Tamaño del array.
* \return Indice libre.
*
*/
int indicePrLibre (eProducto lista[], int size);

/**
* \brief Busca el ID del primer elemento del array estado inactivo.
* \param lista. Array de eProducto.
* \param size. Tamaño del array.
* \return Id de producto.
*
*/
int buscarIdProductolibre (eProducto lista[], int size);

/**
* \brief Pide datos de eProducto.
* \param id. Id del eProducto
* \param idUs. IdUsuario del eProducto.
* \return eProducto con los datos ingresados.
*/
eProducto cargarProducto (int id, int idUs);

/**
* \brief Pide datos de eProducto y lo da de alta en la lista.
* \param listaPr. Array de eProducto.
* \param sizePr. Tamaño del array eProducto.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array eUsuario.
*/
void altaProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs );

/**
* \brief Lista Productos con nombres de usuarios.
* \param listaPr. Array de eProducto.
* \param sizePr. Tamaño del array de eProducto.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array de usuarios.
*/
void listarPublicaciones (eProducto listaPr [], eUsuario listaUs [],int sizePr, int sizeUs);

/**
* \brief Implementa la compra de un producto.
* \param listaPr. Array de eProducto.
* \param sizePr. Tamaño del array de eProducto.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array de usuarios.
* \param listaVe. Array de eVentas.
* \param sizeVe. Tamaño del array de eVentas.
*/
void comprarProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs, eVenta listaVe[], int sizeVe);

/**
* \brief Muestra por consola la lista de productos activos.
* \param lista. Array de eProducto.
* \param size. Tamaño del array de eProducto.
*/
void mostrarProductos(eProducto lista[], int size);

/**
* \brief Pide datos de eProducto y los carga en uno ya existente.
* \param listaPr. Array de eProducto.
* \param sizePr. Tamaño del array de eProducto.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array de usuarios.
*/
void modificarProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs);

/**
* \brief Pide id de eProducto y lo da de baja en la lista.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array de usuarios.
* \param listaPr. Array de eProducto.
* \param sizePr. Tamaño del array de productos.
*/
void bajaProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs);

/**
* \brief Pide id de eUsuario y lista sus productos activos.
* \param lista. Array de eProducto.
* \param size. Tamaño del array de eProducto.
* \param idUs. id del usuario.
*/
void productosPorUsuario (eProducto lista[], int size, int idUs);

/**
* \brief Lista las publicaciones por usuario.
* \param listaPr. Array de eProducto.
* \param sizePr. Tamaño del array de productos.
* \param listaUs. Array de eUsuario.
* \param sizeUs. Tamaño del array de usuarios.
*/
void listarPublicacionesPorUsuario (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs);



/**
* \brief Inicializa lista de eVenta.
* \param lista. Array de eVenta.
* \param size. Tamaño del array.
*/
void iniVentas (eVenta lista[], int size);

/**
* \brief Busca el primer indice en la lista con elemento inactivo.
* \param lista. Array de eVentas.
* \param size. Tamaño del array de eVentas.
* \return eProducto con los datos ingresados.
*/
int indiceLibreVenta (eVenta lista[], int size);

/**
* \brief Harcodea lista de eVenta.
* \param lista. Array de eVenta
*/
void harcodearVenta (eVenta lista[]);

/**
* \brief Muestra lista de ventas activas.
* \param lista. Array de eVenta.
* \param size. Tamaño del array.
*/
void mostrarVentas(eVenta lista[], int size);


#endif // FUNCIONESEXAMEN_H_INCLUDED
