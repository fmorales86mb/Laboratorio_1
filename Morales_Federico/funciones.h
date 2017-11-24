#include "ArrayList.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MO 50
#define STR 50
#define STRLONG 1000

typedef struct{
    int atendido; // 0 no, 1 si
    long int dni;
}ETramite;

ETramite* newETramite (void);

/**
 *  Agrega una pelicula al archivo binario y a la lista
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param fileName, nombre del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarTramite(ArrayList *lista, char* fileName);


/**
 *  Genera un elemento EMovie con los datos ingresados por el usuario.
 *  @return retorna EMovie con id = 0 si pudo generar la pelicula o con id = -1 si no pudo.
 */
int pedirTramite (ETramite *tramite);

/**
 *  Carga el array de peliculas con los datos del archivo binario
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param nombre, nombre del archivo binario.
 *  @return retorna 1 si carga correctamente la lista, o 0 si no pudo
 */
int levantarLista(ArrayList* lista, char* nombre);

/**
 *  Guarda en el archivo binario la lista de Emovie
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param nombre, nombre del archivo binario.
 *  @return retorna 1 si guardó correctamente la lista, o 0 si no pudo
 */
int pisarArchivo(ArrayList *listaU, ArrayList *listaR, char* nombre, int sizeOfStruct);


/**
 *  Muestra por consola el listado de peliculas.
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 */
void listarTramites(ArrayList *lista);

int guardarLista (ArrayList* listaU, ArrayList* listaR, char* fileName, int sizeOfStruct);

int comparaElementos(void* elementoA, void* elementoB);

int proximoCliente(ArrayList* listaU, ArrayList* listaR);

int listarPendientes (ArrayList* listaU, ArrayList* listaR);

int informar (ArrayList* listaU, ArrayList* listaR);

int grabar (ArrayList* listaU, ArrayList* listaR, char* fileName);

#endif // FUNCIONES_H_INCLUDED
