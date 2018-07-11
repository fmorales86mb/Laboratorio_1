#include "abmProducto.h"

EProducto* newEProducto()
{
    EProducto* returnAux = NULL;
    returnAux = (EProducto*)malloc(sizeof(EProducto));

    if(returnAux != NULL)
    {
        returnAux->id = 0;
        strcpy(returnAux->codigo, "");
        returnAux->precio = 0;
    }
    return returnAux;
}

EProducto* newEProductoIni(int p_id, float p_precio, char* p_codigo)
{
    EProducto* elemento = newEProducto();
    if (elemento != NULL)
    {
       elemento->id = p_id;
       elemento->precio = p_precio;
       strcpy(elemento->codigo, p_codigo);
    }

    return elemento;
}

void printProducto(EProducto* elemento)
{
    printf("   %d      %s        %.2f \n",
           elemento->id,
           elemento->codigo,
           elemento->precio);
}

void listarProductos(ArrayList* lista, int (*pFunc)(void* ,void*), int descendente)
{
    EProducto *elemento = NULL;
    int i;

    if (lista->sort(lista, pFunc, descendente) == 0)
    {
        printf("\n ID    Codigo     Precio  \n\n");
        for(i=0; i<lista->len(lista); i++) {
            elemento = lista->get(lista, i);
            printProducto(elemento);
        }
    }
    printf("\n");
}

int cargarCsvTxtProducto (ArrayList* lista, char* fileName, int encabezado)
{
    int ret = 1;
    char id[50], codigo[500], precio[500];
    EProducto* elemento = NULL;

    FILE * pFile;

    pFile = fopen (fileName, "r");
    if (pFile != NULL)
    {
        if (encabezado) fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, codigo, precio);
        while(!(feof(pFile)))
        {
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, codigo, precio);
            elemento = newEProductoIni(atoi(id), atof(precio), codigo);
            lista->add(lista, elemento);
        }
        printf("\n Se levantaron los datos correctamente\n");
    }
    else
    {
        ret = 0;
        printf("\n No se pudo abrir archivo \n.");
    }
    fclose(pFile);
    return ret;
}

int comparaIdProducto (void* elementoA, void* elementoB)
{
    if (elementoA != NULL && elementoB != NULL)
    {
        EProducto* a = (EProducto*) elementoA;
        EProducto* b = (EProducto*) elementoB;
        return a->id - b->id;
    }
    return 0;
}

int pedirIdProductoExistente (ArrayList* lista, int* id)
{
    *id = pedirIdProducto();
    int index = buscarProducto(lista, *id);
    if (index == -1)
    {
        printf("\n Id inexistente.\n");
    }
    return index;
}

int pedirIdProducto ()
{
    int id;
    int flag;

    do
    {
        flag = pedirInt(&id, " Ingrese ID: ", " ID invalido.", 1, 10000);
    }while (flag == -1);

    return id;
}

int buscarProducto (ArrayList* lista, int id)
{
    int i;
    int index = -1;
    EProducto* elemento;

    for(i=0; i<lista->len(lista); i++)
    {
        elemento = lista->get(lista, i);
        if(elemento->id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}
