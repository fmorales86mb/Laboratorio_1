#include "funciones.h"
#include <stdlib.h>

void altaCliente (ArrayList* listaC, char* nameFile)
{
    system("cls");
    altaPersona(listaC);
    guardarCsvTxtPersona(listaC, nameFile, sizeof(EPersona), 0);
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

    int idCliente, index;
    int flag = 0;

    listarPersonas(listaC, comparaIdPersona, 1);
    index = pedirIdPersonaExistente(listaC, &idCliente);
    if (index>-1) flag = 1;

    if (!flag)
    {

    }
    system("pause");
}

void opcionListarVenta(ArrayList* listaV)
{
    system("cls");
    //listarVenta(listaV, comparaIdVenta, 1);
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





