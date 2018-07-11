#include "funciones.h"
#include <stdlib.h>

void altaCliente (ArrayList* listaC, char* nameFile)
{
    system("cls");
    altaPersona(listaC);
    guardarCsvTxtPersona(listaC, nameFile, sizeof(EPersona), 0);
    system("pause");
}

void modificacionCliente (ArrayList* listaC, char* nameFile)
{
    system("cls");
    listarPersonas(listaC, comparaIdPersona, 1);
    modificarPersona(listaC);
    guardarCsvTxtPersona(listaC, nameFile, sizeof(EPersona), 0);
    system("pause");
}

void bajaCliente (ArrayList* listaC, ArrayList* listaV, char* nameFile)
{
    system("cls");
    listarPersonas(listaC, comparaIdPersona, 1);
    guardarCsvTxtPersona(listaC, nameFile, sizeof(EPersona), 0);
    bajaPersonaV(listaC, listaV);
}

void listarClientes (ArrayList* listaC)
{
    system("cls");
    listarPersonas(listaC, comparaPorApellido, 1);
    system("pause");
}

void opcionAltaVenta (ArrayList* listaC, ArrayList* listaV, ArrayList* listaP, char* nameFile) // replantear
{
    system("cls");

    int idCliente, indexC, indexP, idProducto;
    int flag = 0;

    listarPersonas(listaC, comparaIdPersona, 1);
    indexC = pedirIdPersonaExistente(listaC, &idCliente);
    if (indexC>-1) flag = 1;

    if (flag)
    {
        system("cls");
        listarProductos(listaP, comparaIdProducto, 1);
        indexP = pedirIdProductoExistente(listaP, &idProducto);
        if (indexP<0) flag = 0;
    }
    if (flag)
    {
        system("cls");
        int cant = pedirCantidadVenta();
        EVenta * venta = NULL;
        int idVenta = generarIdVenta(listaV);
        venta = newEventaIni(idCliente, idVenta, cant, idProducto);
        agregarVenta(listaV, venta);
        guardarCsvTxtVentas(listaV, nameFile, sizeof(EVenta), 0);
    }

    system("pause");
}

void opcionListarVenta(ArrayList* listaV)
{
    system("cls");
    listarVentas(listaV, comparaIdVenta, 1);
    system("pause");
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





