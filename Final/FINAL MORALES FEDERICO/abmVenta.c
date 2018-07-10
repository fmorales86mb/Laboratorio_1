#include "abmVenta.h"

EVenta* newEVenta()
{
    EVenta* returnAux;
    returnAux = (EVenta*)malloc(sizeof(EVenta));

    if(returnAux !=NULL)
    {
       returnAux->cantidad = 0;
       returnAux->idCliente = 0;
       returnAux->id = 0;
       returnAux->precioUnitario = 0;
       strcpy(returnAux->codigoProducto, "");
       returnAux->fechaVenta = newEFecha();
    }
    return returnAux;
}

EVenta* newEventaIni(int p_idCliente, int p_id, int p_cant, float p_precioUnit, EFecha* p_fechaVenta, char* p_codigo)
{
    EVenta* elemento = newEVenta();
    if (elemento != NULL)
    {
       elemento->cantidad = p_cant;
       elemento->idCliente = p_idCliente;
       elemento->id = p_id;
       elemento->precioUnitario = p_precioUnit;
       strcpy(elemento->codigoProducto, p_codigo);
       elemento->fechaVenta = p_fechaVenta;
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

int pedirVenta (EVenta *venta)
{
    int flag;
    int chances = 0;
    int ret=0;

    if(chances<3)
    {
        do
        {
            flag = pedirFloat(&(venta->precioUnitario), " Ingrese el precio unitario: ", " Precio invalido.", 0, 100000);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        do
        {
            flag = pedirInt(&(venta->cantidad), " Ingrese cantidad: ", " Cantidad invalida.", 1, 200);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        do
        {
            flag = pedirStrAlfanumerico(venta->codigoProducto, " Ingrese codigo del producto: ", " Codigo invalido.", 1, 17);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        do
        {
            printf("\nFecha de la venta:\n");
            flag = pedirFecha(venta->fechaVenta);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        ret =1;
    }

    return ret;
}

int altaVenta(ArrayList *listaV, ArrayList* listaP)
{
    int retorno = 1;
    int idPersona;
    EVenta* elemento = NULL;
    elemento = newEVenta();

    if (elemento!=NULL)
    {
        // pido y verifico id cliente
        if (pedirIdPersonaExistente(listaP, &idPersona) > -1)
        {
            elemento->idCliente = idPersona;

            //existe id cliente, pido venta y genero id de la venta
            if (pedirVenta(elemento) != 0)
            {
                elemento->id = generarIdVenta(listaV);
                listaV->add (listaV, elemento);
            }
            else
            {
                retorno = 0;
            }
        }
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

void listarVenta(ArrayList* lista, int (*pFunc)(void* ,void*), int descendente)
{
    EVenta *elemento;
    int i;

    if (lista->sort(lista, pFunc, descendente) == 0)
    {
        printf("\n ID   Codigo     Precio U.     Cantidad        Fecha de Venta  IdCliente\n\n");
        for(i=0; i<lista->len(lista); i++) {
            elemento = lista->get(lista, i);
            printf("   %d      %s        %.2f    %d  %d/%d/%d    %d \n", elemento->id, elemento->codigoProducto, elemento->precioUnitario, elemento->cantidad,
             elemento->fechaVenta->anio, elemento->fechaVenta->mes, elemento->fechaVenta->dia, elemento->idCliente);
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

int comparaImporteVenta (void* elementoA, void* elementoB)
{
    if (elementoA != NULL && elementoB != NULL)
    {
        EVenta* a = (EVenta*) elementoA;
        EVenta* b = (EVenta*) elementoB;
        float importeA = a->precioUnitario * a->cantidad;
        float importeB = b->precioUnitario * b->cantidad;
        return importeA - importeB;
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

ArrayList* listaVentasProducto (ArrayList* lista, char* p_prod)
{
    ArrayList* ventasCliente = NULL;
    ventasCliente = al_newArrayList();
    int i;

    for(i=0; i<lista->len(lista); i++)
    {
        if (strcmp(((EVenta*)(lista->get(lista, i)))->codigoProducto, p_prod) == 0)
        {
            ventasCliente->add(ventasCliente, ((EVenta*)(lista->get(lista, i))));
        }
    }

    return ventasCliente;
}


