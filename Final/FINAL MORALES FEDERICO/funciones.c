#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"
#include "ArrayList.h"

int idCiente = 0;



void realizarVenta (ArrayList* listaC, ArrayList* listaV)
{
    int flag;
    int id = pedirIdPersona();
    float precio;
    char strCodigo[17];
    int cantidad;
    EFecha* fecha = newEFecha();
    EVenta* venta = newEVenta();

    if (buscarPersona(listaC, id) != NULL)
    {
        do
        {
            flag = pedirStrAlfanumerico(strCodigo, "ingrese Codigo", "Codigo Erroneo", 1, 17);
        } while(flag == -1);

        do
        {
            flag = pedirFloat(&precio, "ingrese Precio", "Precio Erroneo", 0, 100000);
        } while(flag == -1);

        do
        {
            flag = pedirInt(&cantidad, "ingrese cantidad", "cantidad Erroneo", 1, 100000);
        } while(flag == -1);

        do
        {
            flag = pedirInt(&(fecha->dia), "ingrese dia", "dia Erroneo", 1, 32);
        } while(flag == -1);
        do
        {
            flag = pedirInt(&(fecha->mes), "ingrese mes", "mes Erroneo", 1, 12);
        } while(flag == -1);
        do
        {
            flag = pedirInt(&(fecha->anio), "ingrese anio", "anio Erroneo", 1, 100000);
        } while(flag == -1);


        venta->idCliente = id;
        strcpy(venta->codigoProducto, strCodigo);
        venta->precioUnitario = precio;
        venta->cantidad = cantidad;
        venta->fechaVenta = fecha;

    }
}

void crearCSV(char* fileName)
{
    FILE* archivo;
    archivo = fopen(fileName, "w");
    fclose(archivo);
}

void levantarCVS(ArrayList* lista)
{
    int flag;
    char fileName[50];
    do
    {
        flag = pedirStrLetras(fileName, "ingrese nombre del archivo: ", "nombre Erroneo", 1, 50);
    } while(flag == -1);

    levantarListaCSVPersonas(lista, fileName);
}

int guardarListaClientesCSV (ArrayList* lista, char* fileName, int sizeOfStruct)
{
    int retorno = 1;

    if (pisarArchivoCSVPersona(lista, fileName, sizeOfStruct)==0)
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

int opcionModificarCliente (ArrayList* lista)
{
    int id = pedirIdPersona();

    EPersona* elemento = NULL;
    EPersona* elementoAux;

    elemento = buscarPersona(lista, id);

    if(elemento != NULL)
    {
        if (pedirPersona(elementoAux))
        {
            strcpy(elemento->apellido, elementoAux->apellido);
            elemento->dni = elementoAux->dni;
            strcpy(elemento->nombre, elementoAux->nombre);
        }
    }
    else
    {
        printf("no existe ese cliente.");
    }

    return 0;
}



/////////////////////////////////////////////////////////////////////////////
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





/*

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



int levantarClientes (ArrayList* lista, char* fileName, int tam)
{
    int ret=-1;
    int i=0;

    FILE* archivo;
    archivo = fopen(fileName, "rb");
    if(archivo!=NULL)
    {
        ret=0;
        while(!feof(archivo))
        {
            fread(lista+i, 1, tam, archivo);
            i++;
        }
    }
    else
    {

        archivo = fopen(fileName, "wb");
        if(archivo != NULL)
        {
            ret=0;
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
