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

void levantarProd (ArrayList* lista)
{
    EProducto* prod = NULL;
    char b [12] = "as";
    prod = newEProductoIni(2, 2.3, b);
}

