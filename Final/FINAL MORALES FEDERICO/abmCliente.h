#ifndef ABMCLIENTE_H_INCLUDED
#define ABMCLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abmFecha.h"
#include "ArrayList.h"

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    long int dni;
    EFecha* fechaNac;
}EPersona;

EPersona* newEPersona ();
EPersona* buscarPersona (ArrayList* lista, int id);
int generarIdPersona (ArrayList* lista);
EPersona* buscarPersonaPorDNI(ArrayList* lista, long int dni);
int pedirPersona (EPersona *persona);

#endif // ABMCLIENTE_H_INCLUDED
