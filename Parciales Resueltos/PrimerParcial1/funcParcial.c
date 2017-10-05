#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Laboratorio_1/Bibliotecas/Input/input.h"
#include "../../Laboratorio_1/Bibliotecas/biblioStr/validacionStr.h"
#include "funcParcial.h"


int altaAbonado (eAbonado listaAbonado[], int sizeAbo)
{
    int indiceAbo;
    eAbonado abonado=cargarAbonado();
    int id;

    for (indiceAbo=0; indiceAbo<sizeAbo; indiceAbo++)
    {
        if (listaAbonado[indiceAbo].idAbonado<0)
        {
            id = (traerUltimoIdAbonado(listaAbonado, sizeAbo))+1;
            abonado.idAbonado = id;
            listaAbonado[indiceAbo] = abonado;
            break;
        }
    }

    return indiceAbo;
}

eAbonado cargarAbonado ()
{
    eAbonado abonado = {-1, 0, "", ""};
    int flag;
    int numero;
    char nombre[STR];
    char apellido[STR];

    do
    {
        flag=getInt(&numero, "Ingrese numero de abonado: ", "Valor erroneo.", 1, 500);
    }while(flag == -1);
    do
    {
        flag=getString(nombre, "Ingrese nombre del abonado: ", "Nombre incorrecto.", 1, STR);
    }while (flag == -1);
    do
    {
        flag=getString(apellido, "Ingrese apellido del abonado: ", "Apellido incorrecto.", 1, STR);
    }while (flag == -1);

    abonado.numero = numero;
    strcpy(abonado.nombre, nombre);
    strcpy(abonado.apellido, apellido);

    return abonado;
}

int traerUltimoIdAbonado (eAbonado listaAbonado[], int sizeAbo)
{
    int i;
    int maxId;

    for(i=0; i<sizeAbo; i++)
    {
        if (i==0 || listaAbonado[i].idAbonado>maxId)
        {
            maxId = listaAbonado[i].idAbonado;
        }
    }

    return maxId;
}

void inicializarIdAbonados (eAbonado listaAbonados[], int sizeAbo, int id)
{
    int i;

    for(i=0; i<sizeAbo; i++)
    {
        listaAbonados[i].idAbonado = id;
    }
}

void modificarAbonado (eAbonado listaAbonado[], int sizeAbo)
{
    int i;
    int flag;
    int id;
    char nombre[STR];
    char apellido[STR];
    int maxId = traerUltimoIdAbonado(listaAbonado, sizeAbo);

    do
    {
        flag = getInt(&id, "Ingrese el ID del abonado: ", "ID invalido.", 0, maxId);
    }while(flag<0);

    for (i=0; i<sizeAbo; i++)
    {
        if (listaAbonado[i].idAbonado == id)
        {
           do
            {
                flag = getString(nombre, "Ingrese el nuevo nombre: ", "Nombre invalido.", 1, STR);
            }while(flag<0);

            do
            {
                flag = getString(apellido, "Ingrese el nuevo apellido: ", "Apellido invalido.", 1, STR);
            }while(flag<0);
        }
    }




}




