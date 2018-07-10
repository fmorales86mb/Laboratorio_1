#include "funciones.h"

void altaCliente (ArrayList* listaC)
{
    system("cls");
    altaPersona(listaC);
    system("pause");
}

void modificacionCliente (ArrayList* listaC)
{
    system("cls");
    listarPersonas(listaC, comparaIdPersona, 1);
    modificarPersona(listaC);
    system("pause");
}

void bajaCliente (ArrayList* listaC, ArrayList* listaV)
{
    system("cls");
    listarPersonas(listaC, comparaIdPersona, 1);
    bajaPersonaV(listaC, listaV);
}

void listarClientes (ArrayList* listaC)
{
    system("cls");
    listarPersonas(listaC, comparaPorApellido, 1);
    system("pause");
}

void opcionAltaVenta (ArrayList* listaC, ArrayList* listaV)
{
    system("cls");
    listarPersonas(listaC, comparaIdPersona, 1);
    altaVenta(listaV, listaC);
    system("pause");
}

void opcionListarVenta(ArrayList* listaV)
{
    system("cls");
    listarVenta(listaV, comparaIdVenta, 1);
    system("pause");
}

void informarVentasPorCliente (ArrayList* listaC, ArrayList* listaV)
{
    system("cls");

    int index, id;
    ArrayList* listaVdeC = NULL;
    listarPersonas(listaC, comparaIdPersona, 1);
    index = pedirIdPersonaExistente(listaC, &id);
    if (index > -1)
    {
        listaVdeC = listaVentasIdCliente(listaV, id);
        if (listaVdeC->isEmpty(listaVdeC) == 1)
        {
            printf("\n Lista Vacia. \n");
        }
        else
        {
            listarVenta(listaVdeC, comparaIdVenta, 1);
            printf("\n Cantidad de ventas del cliente: %d \n", listaVdeC->len(listaVdeC));
        }
    }
    system("pause");
}

void informarVentasPorProducto (ArrayList* listaV)
{
    system("cls");

    int chances = 0;
    int flag;
    ArrayList* listaVdeP = NULL;
    char* cod;

    do
    {
        flag = pedirStrAlfanumerico(cod, " Ingrese codigo del producto: ", " Codigo invalido.", 1, 17); //ver
        chances++;
    }while (flag == -1 && chances<3);

    if (flag == 0)
    {
        listaVdeP = listaVentasProducto(listaV, cod);
        if (listaVdeP->isEmpty(listaVdeP) == 1)
        {
            printf("\n Lista Vacia. \n");
        }
        else
        {
            listarVenta(listaVdeP, comparaIdVenta, 1);
            //printf("\n Cantidad de ventas del cliente: %d \n", listaVdeP->len(listaVdeP));
        }
    }
    system("pause");
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

    cargarCsvTxtPersonas(lista, fileName, 1);
}





