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
       returnAux->atendido = 0;
       returnAux->dni=0;
    }
    return returnAux;
}

int agregarTramite(ArrayList *lista, char* fileName)
{
    int retorno = 1;
    ETramite* tramite = NULL;
    tramite = newETramite();

    if (tramite!=NULL)
    {
        if (pedirTramite (tramite) != 0)
        {
            // Aca tenemos la pelicula cargada entonces la agregamos a la lista
            lista->add (lista, tramite);
            //guardarLista(lista, fileName, sizeof(EMovie));
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

int proximoCliente(ArrayList* listaU, ArrayList* listaR)
{
    int ret = 0;
    int i;
    int flag = 0;
    ETramite* tramiteAux = NULL;

    printf(" -- Proximo Cliente --\n\n");

    for(i=0; i<listaU->len(listaU); i++)
    {
        tramiteAux = (ETramite*)listaU->get(listaU, i);
        if(tramiteAux->atendido == 0)
        {
            printf(" DNI: %ld \n Tipo de Tramite: Urgente \n", tramiteAux->dni);
            tramiteAux->atendido =1;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        for(i=0; i<listaR->len(listaR); i++)
        {
            tramiteAux = (ETramite*)listaR->get(listaR, i);
            if(tramiteAux->atendido == 0)
            {
                printf(" DNI: %ld \n Tipo de Tramite: Regular \n", tramiteAux->dni);
                tramiteAux->atendido =1;
                flag = 1;
                break;
            }
        }
    }

    return ret;
}

int listarPendientes (ArrayList* listaU, ArrayList* listaR)
{
    ETramite *tramite;
    int i;

    printf("\n Nro   dni   atendido  Tramite\n\n");

    for(i=0; i<listaU->len(listaU); i++)
    {
        tramite = listaU->get(listaU, i);
        if(tramite->atendido == 0)
        {
            printf("   %d      %ld      %d   Urgente\n",i+1, tramite->dni, tramite->atendido);
        }
    }

    for(i=0; i<listaR->len(listaR); i++)
    {
        tramite = listaR->get(listaR, i);
        if(tramite->atendido == 0)
        {
            printf("   %d      %ld      %d   Regular\n",i+1, tramite->dni, tramite->atendido);
        }
    }

    printf("\n");

    return 1;
}

int informar (ArrayList* listaU, ArrayList* listaR)
{
    ETramite *tramite;
    int i;
    ArrayList* listaAux = NULL;

    listaAux = listaU->clone(listaU);

    if (listaAux != NULL)
    {
        listaAux->sort(listaAux, comparaElementos, 0);
    }

    printf("\n Nro   dni   atendido  Tramite\n\n");

    for(i=0; i<listaAux->len(listaAux); i++)
    {
        tramite = listaAux->get(listaAux, i);
        if(tramite->atendido == 1)
        {
            printf("   %d      %ld      %d   Urgente\n",i+1, tramite->dni, tramite->atendido);
        }
    }

    listaAux->clear(listaAux);
    listaAux = listaR->clone(listaR);

    if (listaAux != NULL)
    {
        listaAux->sort(listaAux, comparaElementos, 0);
    }

    for(i=0; i<listaAux->len(listaAux); i++)
    {
        tramite = listaAux->get(listaAux, i);
        if(tramite->atendido == 1)
        {
            printf("   %d      %ld      %d   Regular\n",i+1, tramite->dni, tramite->atendido);
        }
    }

    printf("\n");

    return 1;
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

int levantarLista(ArrayList* lista, char* nombre)
{
    /*
    int retorno;
    int i;
    int cant;
    int maximo = 0;
    EMovie *item;
    FILE * archivo;

    retorno = 1;
    // Intentamos abrir o crear un archivo.
    archivo = fopen(nombre, "rb");
    if (archivo == NULL)
    {
        archivo = fopen(nombre, "wb");
        if (archivo == NULL) {
            retorno = 0;
        }
    }

    // Si tenemos el archivo seguimos.
    if (retorno != 0) {
        // recorre el archivo del principioo hasta el final
        for (i=0; !feof(archivo); i++) {
            // Item apunta a una posicion de memoria donde entra un emovie
            item = (EMovie *) malloc (sizeof (EMovie));
            if (item == NULL) {
                retorno = 0;
                break;
            }

            // Leemos un registro del archivo y lo copiamos en la memoria apuntada por item
            cant = fread (item, sizeof(EMovie), 1, archivo);
            if (cant != 1){
                retorno = 0;
                break;
            }

            // Actualizamos el maximo
            if (item->id > maximo || i==0) {
                maximo = item->id;
            }

            // Si llegamos aca (por que no salio por ningun brake lo agreamos a la lista
            lista->add (lista, item);
        }

        // actualizamos proximo_id
        proximo_id = maximo + 1;

        fclose(archivo);
    }

    return retorno;
    */
    return 0;
}

int pisarArchivo(ArrayList *lista, char* nombre, int sizeOfStruct)
{
    int i;
    int cant;
    int retorno = 0;
    FILE *archivo;

    archivo = fopen(nombre, "wb");

    if (archivo == NULL)
    {
        printf("\n El archivo no puede ser abierto.\n");
        retorno = 0;

    }
    else
    {
        retorno = 1;

        //printf("\nstr: %d\nobj: %d", sizeof(EMovie), sizeOfStruct);

        for(i=0; i<lista->len (lista); i++)
        {
            cant = fwrite(lista->get(lista, i), sizeOfStruct, 1, archivo);

            if (cant != 1) {
                printf("\n No pudo escribir correctamente un registro.\n");
                retorno = 0;
                break;
            }
        }
    }

    fclose(archivo);

    return retorno;
}

void listarTramites(ArrayList *lista)
{
    ETramite *tramite;
    int i;

    printf("\n Nro   dni   atendido  \n\n");

    for(i=0; i<lista->len(lista); i++) {
        tramite = lista->get(lista, i);
    printf("   %d      %ld      %d \n",i+1, tramite->dni, tramite->atendido);
    }

    printf("\n");
}

int grabar (ArrayList* listaU, ArrayList* listaR)
{

}
/*
int clearList (ArrayList* lista, char* fileName)
{
    int ret = 0;

    if(lista->clear(lista)==0)
    {
        ret = 1;
        printf("\n Lista vaciada.\n");
        guardarLista(lista, fileName, sizeof(EMovie));
    }

    return ret;
}

int copiarLista (ArrayList* lista, char* fileName2, int sizeOfStruct)
{
    int ret = 0;

    ArrayList* cloneList = lista->clone(lista);

    if (cloneList != NULL)
    {
        if(guardarLista(cloneList, fileName2, sizeOfStruct))
        {
            ret =1;
        }
    }
    return ret;
}

int crearSublista (ArrayList* lista, char* fileName2, int sizeOfStruct)
{
    int ret = 0;
    int flag;
    int desde;
    int hasta;

    // entro si hay elementos en la lista
    if(lista->isEmpty(lista)==0)
    {
        listarPeliculas(lista);

        printf("\n -- Crear Sublista --\n\n");
        do
        {
            flag = pedirInt(&desde, " Desde indice: ", " Ingreso un valor incorrecto.",1 , lista->len(lista));
        } while(flag == -1);

        do
        {
            flag = pedirInt(&hasta, " Hasta indice: ", " Ingreso un valor incorrecto.",desde , lista->len(lista));
        } while(flag == -1);

        ArrayList* subList = lista->subList(lista, desde-1, hasta-1);

        if (subList != NULL)
        {
            if(guardarLista(subList, fileName2, sizeOfStruct))
            {
                ret =1;
            }
        }
    }

    return ret;
}

int ordenarLista (ArrayList* lista, char* fileName, int (*pFunc)(void* ,void*), int order )
{
    int ret = 0;

    if (lista->sort(lista, pFunc, order) == 0)
    {
        if (guardarLista(lista, fileName, sizeof(EMovie)))
        {
            ret = 1;
            listarPeliculas(lista);
        }
    }

    return ret;
}

int guardarLista (ArrayList* lista, char* fileName, int sizeOfStruct)
{
    int retorno = 1;

    if (pisarArchivo(lista, fileName, sizeOfStruct)==0)
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
*/
    // funcion de comparacion
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

