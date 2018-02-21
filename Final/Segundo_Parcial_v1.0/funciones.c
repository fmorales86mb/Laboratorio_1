#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"
#include "ArrayList.h"

ETramite* newETramite (void)
{
    ETramite* returnAux;
    returnAux = (ETramite*)malloc(sizeof(ETramite));

    if(returnAux !=NULL)
    {
       //returnAux->atendido = 0;
       returnAux->dni=0;
    }
    return returnAux;
}

int agregarTramite(ArrayList *lista, char* fileName)
{
    int retorno = 1;
    ETramite* elemento = NULL;
    elemento = newETramite();

    if (elemento!=NULL)
    {
        if (pedirTramite (elemento) != 0)
        {
            lista->add (lista, elemento);
        }
        else
        {
            retorno = 0;
        }
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int proximoCliente(ArrayList* listaUP, ArrayList* listaRP, ArrayList* listaUA, ArrayList* listaRA)
{
    //int i;
    int flag = -1;
    ETramite* tramiteAux = NULL;

    printf(" -- Proximo Cliente --\n\n");

    // Si hay UP muestro el primero, lo quito de la lista y lo agrego a UA.
    if((listaUP->isEmpty(listaUP)) == 0)
    {
        tramiteAux = (ETramite*)listaUP->get(listaUP, 0);
        printf(" DNI: %ld \n Tipo de Tramite: Urgente \n", tramiteAux->dni);
        flag = listaUA->add(listaUA, listaUP->pop(listaUP, 0));
    }

    // Si hay RP muestro el primero, lo quito de la lista y lo agrego a RA.
    else if((listaRP->isEmpty(listaRP)) == 0)
    {
        tramiteAux = (ETramite*)listaRP->get(listaRP, 0);
        printf(" DNI: %ld \n Tipo de Tramite: Urgente \n", tramiteAux->dni);
        flag = listaRA->add(listaRA, listaRP->pop(listaRP, 0));
    }

    return flag;
}

int listarPendientes (ArrayList* listaUP, ArrayList* listaRP)
{
    ETramite *tramite = NULL;
    int i;

    printf("\n Nro   dni    Tramite\n\n");

    for(i=0; i<listaUP->len(listaUP); i++)
    {
        tramite = listaUP->get(listaUP, i);
        if (tramite!= NULL) printf("   %d      %ld     Urgente\n",i+1, tramite->dni);
        else printf("No Hay tramites urgentes.");
    }

    for(i=0; i<listaRP->len(listaRP); i++)
    {
        tramite = listaRP->get(listaRP, i);
        if (tramite!=NULL) printf("   %d      %ld     Regular\n",i+1, tramite->dni);
        else printf("No Hay tramites regulares.");
    }

    printf("\n");

    return 1;
}
/*
int informar_old (ArrayList* listaU, ArrayList* listaR)
{
    ETramite *tramite;
    int i;
    char tipo[20];
    ArrayList* listaAux = NULL;

    //Creo lista auxiliar con los elementos de las dos listas.
    listaAux = listaU->clone(listaU);
    for (i=0; i<listaR->len(listaR); i++)
    {
        listaAux->add(listaAux, listaR->get(listaR, i));
    }

    // ordeno
    if (listaAux != NULL)
    {
        listaAux->sort(listaAux, comparaElementos, 0);
    }

    printf("\n   dni   atendido  Tramite\n\n");

    // imprimo
    for(i=0; i<listaAux->len(listaAux); i++)
    {
        tramite = listaAux->get(listaAux, i);
        if(tramite->atendido == 1)
        {
            if(listaU->contains(listaU, tramite) == 1)
            {
                strcpy(tipo, "Urgente");
            }
            else
            {
                strcpy(tipo, "Regular");
            }
            printf("     %ld      %d   %s\n", tramite->dni, tramite->atendido, tipo);
        }
    }

    printf("\n");

    return 1;
}
*/
int informar (ArrayList* listaUA, ArrayList* listaRA)
{
    int i;
    ETramite* tramiteAux = NULL;

    printf("\n   dni    Tramite\n\n");

    // ordeno la lista en forma descendente e imprimo
    if(!(listaUA->sort(listaUA, comparaElementos, 0)))
    for(i=0; i<listaUA->len(listaUA);i++)
    {

        tramiteAux = listaUA->get(listaUA, i);
        printf(" %ld      Urgente\n", tramiteAux->dni);
    }

    // ordeno la lista en forma descendente e imprimo
    if(!(listaRA->sort(listaRA, comparaElementos, 0)))
    for(i=0; i<listaRA->len(listaRA);i++)
    {
        tramiteAux = listaRA->get(listaRA, i);
        printf(" %ld      Regular\n", tramiteAux->dni);
    }

    return 0;
}

int pedirTramite (ETramite *tramite)
{
    int flag;
    int chances = 0;
    int ret=0;

    //printf("\n Ingrese datos de la pelicula: \n\n");
    do
    {
        flag = pedirLong(&tramite->dni, " Ingrese su DNI: ", " DNI invalido.", 1, 100000000);
        chances++;
    }while (flag == -1 && chances<3);

    if(chances<3 && flag != -1)
    {
        ret =1;
    }

    /*
    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie->genero, " Genero: ", " Genero invalido.", 1, STR);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = pedirInt(&movie->duracion, " Duracion (minutos): ", " Duracion invalida.", 1, 800);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie->descripcion, " Descripcion: ", " Descripcion invalida.", 1, STRLONG);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = pedirInt(&movie->puntaje, " Puntaje (1 a 10): ", " Puntaje invalido.", 1, 10);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie->linkImagen, " Link a la imagen: ", " Link a la imagen invalido.", 1, STRLONG);
        }while (flag == -1 && chances<3);
    }
    */
    return ret;
}

int pisarArchivo(ArrayList *listaUP, ArrayList *listaRP, char* nombre, int sizeOfStruct)
{
    int i;
    //int cant;
    int retorno = 0;
    FILE *archivo;
    ETramite* tramiteAux= NULL;

    archivo = fopen(nombre, "wt");

    if (archivo == NULL)
    {
        printf("\n El archivo no puede ser abierto.\n");
        retorno = 0;
    }
    else
    {
        retorno = 1;

        //printf("\nstr: %d\nobj: %d", sizeof(EMovie), sizeOfStruct);

        for(i=0; i<listaUP->len (listaUP); i++)
        {
            tramiteAux = listaUP->get(listaUP, i);
            fprintf(archivo, "%ld; Urgente\n",tramiteAux->dni);
        }
        for(i=0; i<listaRP->len (listaRP); i++)
        {
            tramiteAux = listaRP->get(listaRP, i);
            fprintf(archivo, "%ld; Regular\n",tramiteAux->dni);
        }
    }

    fclose(archivo);

    return retorno;
}

void listarTramites(ArrayList *lista)
{
    ETramite *tramite;
    int i;

    printf("\n Nro   dni \n\n");

    for(i=0; i<lista->len(lista); i++) {
        tramite = lista->get(lista, i);
        printf("   %d      %ld \n", i+1, tramite->dni);
    }

    printf("\n");
}
/*
int grabar (ArrayList* listaU, ArrayList* listaR, char* fileName)
{
    ETramite *tramite;
    int i;
    ArrayList* listaAux = NULL;
    listaAux = al_newArrayList();

    ArrayList* listaAuxR = NULL;
    listaAuxR = al_newArrayList();

    for(i=0; i<listaU->len(listaU); i++)
    {
        tramite = listaU->get(listaU, i);
        if(tramite->atendido == 0)
        {
            listaAux->add(listaAux, tramite);
        }
    }

    for(i=0; i<listaR->len(listaR); i++)
    {
        tramite = listaR->get(listaR, i);
        if(tramite->atendido == 0)
        {
            listaAuxR->add(listaAuxR, tramite);
        }
    }

    guardarLista(listaAux, listaAuxR, fileName, sizeof(ETramite));
    printf("\n");

    return 1;
}
*/

int guardarLista (ArrayList* listaU, ArrayList* listaR, char* fileName, int sizeOfStruct)
{
    int retorno = 1;

    if (pisarArchivo(listaU, listaR, fileName, sizeOfStruct)==0)
    {
        retorno = 0;
        printf("\n El archivo no se pudo actualizar correctamente.\n\n");
    }
    else
    {
        printf("\n Archivo actualizado.\n\n");
    }
    return retorno;
}

// dniA > dniB = 1
// dniA < dniB = -1
// dniA = dniB = 0
int comparaElementos(void* elementoA, void* elementoB)
{
    if(((ETramite*)elementoA)->dni > ((ETramite*)elementoB)->dni)
    {
        return 1;
    }
    if(((ETramite*)elementoA)->dni < ((ETramite*)elementoB)->dni)
    {
        return -1;
    }
    return 0;
}

int levantarLista (ArrayList* lista, char* fileName)
{

}
