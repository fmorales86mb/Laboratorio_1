#include "abmVenta.h"

EVenta* newEVenta()
{
    EVenta* returnAux;
    returnAux = (EVenta*)malloc(sizeof(EVenta));

    if(returnAux !=NULL)
    {
        returnAux->id = 0;
        returnAux->idCliente = 0;
        returnAux->idProducto = 0;
        returnAux->cantidad = 0;
    }
    return returnAux;
}

EVenta* newEventaIni(int p_idCliente, int p_id, int p_cant, int p_idProducto)
{
    EVenta* elemento = newEVenta();
    if (elemento != NULL)
    {
       elemento->cantidad = p_cant;
       elemento->idCliente = p_idCliente;
       elemento->id = p_id;
       elemento->idProducto = p_idProducto;
    }

    return elemento;
}

int generarIdVenta (ArrayList* lista)
{
    int i;
    int max;
    EVenta* elemento;

    for (i=0; i<lista->len(lista); i++)
    {
        elemento = lista->get(lista, i);
        if(i==0 || max < elemento->id)
        {
            max = elemento->id;
        }
    }

    return max+1;
}

int agregarVenta(ArrayList *listaV, EVenta* elemento)
{
    listaV->add(listaV, elemento);
    return 0;
}

void printVenta (EVenta* elemento)
{
    printf("   %d      %d        %d      %d \n",
           elemento->id,
           elemento->idProducto,
           elemento->idCliente,
           elemento->cantidad);
}

void listarVentas(ArrayList* lista, int (*pFunc)(void* ,void*), int descendente)
{
    EVenta *elemento;
    int i;

    if (lista->sort(lista, pFunc, descendente) == 0)
    {
        printf("\n ID    IdProducto     IdCliente     Cantidad  \n\n");
        for(i=0; i<lista->len(lista); i++) {
            elemento = lista->get(lista, i);
            printVenta(elemento);
        }
    }
    printf("\n");
}

int comparaIdVenta (void* elementoA, void* elementoB)
{
    if (elementoA != NULL && elementoB != NULL)
    {
        EVenta* a = (EVenta*) elementoA;
        EVenta* b = (EVenta*) elementoB;
        return a->id - b->id;
    }
    return 0;
}

int buscarVentaId (ArrayList* lista, int id)
{
    int i;
    int index = -1;
    EVenta* elemento;

    for(i=0; i<lista->len(lista); i++)
    {
        elemento = lista->get(lista, i);
        if(/*elemento->estado == ACTIVO &&*/ elemento->id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

ArrayList* listaVentasIdCliente (ArrayList* lista, int p_idCliente)
{
    ArrayList* ventasCliente = NULL;
    ventasCliente = al_newArrayList();
    int i;

    for(i=0; i<lista->len(lista); i++)
    {
        if (((EVenta*)(lista->get(lista, i)))->idCliente == p_idCliente)
        {
            ventasCliente->add(ventasCliente, ((EVenta*)(lista->get(lista, i))));
        }
    }

    return ventasCliente;
}

ArrayList* listaVentasProducto (ArrayList* lista, int p_idProd)
{
    ArrayList* ventasCliente = NULL;
    ventasCliente = al_newArrayList();
    int i;

    for(i=0; i<lista->len(lista); i++)
    {
         if (((EVenta*)(lista->get(lista, i)))->idProducto == p_idProd)
        {
            ventasCliente->add(ventasCliente, ((EVenta*)(lista->get(lista, i))));
        }
    }

    return ventasCliente;
}


