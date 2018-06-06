#ifndef ABMCLIENTE_H_INCLUDED
#define ABMCLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abmFecha.h"
#include "ArrayList.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"

#define ACTIVO 1
#define INACTIVO 0

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    long int dni;
    EFecha* fechaNac;
    int estado;
}EPersona;

EPersona* newEPersona ();
int buscarPersona (ArrayList* lista, int id);
int generarIdPersona (ArrayList* lista);
int buscarPersonaPorDNI(ArrayList* lista, long int dni);
int pedirPersona (EPersona *persona);
int altaPersona(ArrayList *lista);
int pisarArchivoCSVPersona(ArrayList *lista, char* nombre, int sizeOfStruct);
void listarPersonas(ArrayList* lista);
int comparaElementos(void* elementoA, void* elementoB);
int pedirIdPersona ();
int bajaLogicaPersona (ArrayList* lista, int index);
void bajaPersona(ArrayList* lista);
void modificarPersona(ArrayList* lista);
void mostrarPersona(EPersona* elemento);
int levantarListaCSVPersonas (ArrayList* lista, char* fileName);


#endif // ABMCLIENTE_H_INCLUDED