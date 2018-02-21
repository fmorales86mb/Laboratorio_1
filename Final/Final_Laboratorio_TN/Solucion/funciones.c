#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"
#include "ArrayList.h"

int idCiente = 0;

EProducto* newEProducto ()
{
    EProducto* returnAux;
    returnAux = (EProducto*)malloc(sizeof(EProducto));

    if(returnAux !=NULL)
    {
       returnAux->codigo = 0;
       returnAux->descripcion = "";
       returnAux->precio = 0;
    }
    return returnAux;
}

ECliente* newECliente ()
{
    ECliente* returnAux;
    returnAux = (ECliente*)malloc(sizeof(ECliente));

    if(returnAux !=NULL)
    {
       strcpy(returnAux->apellido, "");
       returnAux->dni = 0;
       returnAux->idCliente = 0;
       strcpy(returnAux->nombre, "");
    }
    return returnAux;
}

int altaClientes(ArrayList *lista, char* fileName)
{
    int retorno = 1;
    ECliente* elemento = NULL;
    elemento = newECliente();

    if (elemento!=NULL)
    {
        if (pedirCliente(elemento) != 0)
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
/*
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
*/
/*
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
*/
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
/*
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
}*/

int pedirCliente (ECliente *cliente)
{
    int flag;
    int chances = 0;
    int ret=0;

    if(chances<3)
    {
        chances = 0;
        do
        {
            flag = pedirLong(&cliente->dni, " Ingrese su DNI: ", " DNI invalido.", 1, 100000000);
            chances++;
        }while (flag == -1 && chances<3);
    }

    if(chances<3)
    {
        chances = 0;
        do
        {
            flag = pedirStrLetras(cliente->apellido, " Ingrese su Apellido: ", " Apellido invalido.", 1, 20);
            chances++;
        }while (flag == -1 && chances<3);
    }

    if(chances<3)
    {
        chances = 0;
        do
        {
            flag = pedirStrLetras(cliente->nombre, " Ingrese su nombre: ", " nombre invalido.", 1, 20);
            chances++;
        }while (flag == -1 && chances<3);
    }

    cliente->idCliente = idCiente+1;

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

int pisarArchivoCliente(ArrayList *lista, char* nombre, int sizeOfStruct)
{
    int i;
    //int cant;
    int retorno = 0;
    FILE *archivo;
    ECliente* elemento= NULL;

    archivo = fopen(nombre, "w");

    if (archivo == NULL)
    {
        printf("\n El archivo no puede ser abierto.\n");
        retorno = 0;
    }
    else
    {
        retorno = 1;

        for(i=0; i<lista->len (lista); i++)
        {
            elemento = lista->get(lista, i);
            fprintf(archivo, "%d,%s,%s,%ld\n",elemento->idCliente, elemento->nombre, elemento->apellido, elemento->dni);
        }
    }

    fclose(archivo);

    return retorno;
}

/*
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
*/
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

int guardarLista (ArrayList* lista, char* fileName, int sizeOfStruct)
{
    int retorno = 1;

    if (pisarArchivoCliente(lista, fileName, sizeOfStruct)==0)
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
/*
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
*/
int levantarListaClientes (ArrayList* lista, char* fileName)
{
    int ret = -1;
    int i;
    int posicion;
    int desde=0;
    FILE* archivo;
    char linea[100];
    char subStr[50];
    ECliente* cliente;

    if(archivo=fopen(fileName, "r") != NULL)
    {
        ret = 0;

        while((fgets(linea, 100, archivo)) != NULL)
        {
            cliente = newECliente();
            for(i=0; i<4; i++)
            {
                posicion = primerPosicionDe(linea, desde, ',');
                if (!(subString(linea, subStr,desde, posicion)))
                {
                    switch(i)
                    {
                        case 0:
                            if (!soloNumeros(subStr))
                            {
                                cliente->idCliente = atoi(subStr);
                            }
                            break;

                        case 1:
                            if (!soloLetras(subStr))
                            {
                                strcpy(cliente->nombre, subStr);
                            }
                            break;

                        case 2:
                            if (!soloLetras(subStr))
                            {
                                strcpy(cliente->apellido, subStr);
                            }
                            break;

                        case 3:
                            if (!soloNumeros(subStr))
                            {
                                cliente->idCliente = atol(subStr);
                            }
                            break;
                    }
                    desde = posicion + 1;

                }
            }
            lista->add(lista, cliente);
        }
    }
    return ret;
}

int cargarProductos(ArrayList* listaProductos)
{
    int ret = -1;

    EProducto* producto1;
    producto1 = newEProducto();
    producto1->codigo = 1000;
    producto1->descripcion = "TV_LG_32";
    producto1->precio = 8999.99;

    EProducto* producto2;
    producto2 = newEProducto();
    producto2->codigo = 1001;
    producto2->descripcion = "PS4";
    producto2->precio = 12999.99;

    EProducto* producto3;
    producto3 = newEProducto();
    producto3->codigo = 1002;
    producto3->descripcion = "IPHONE7";
    producto3->precio = 19480.99;

    if(listaProductos != NULL)
    {
        listaProductos->add(listaProductos, producto1);
        listaProductos->add(listaProductos, producto2);
        listaProductos->add(listaProductos, producto3);
        ret=0;
    }

    return ret;
}
