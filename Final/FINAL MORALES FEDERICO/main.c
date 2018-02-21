#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"
#include "ArrayList.h"

#define STR 50
#define STRLONG 1000
#define FILE_NAME "File.csv"
#define FILE_NAME_CLIENTES "clientes.csv"


int main() {
    ArrayList* listaClientes;
    ArrayList* listaVentas;
    ArrayList* listaProductos;

    listaClientes = al_newArrayList();
    listaVentas = al_newArrayList();
    listaProductos = al_newArrayList();

    char seguir='s';
    int opcion=0;
    int flag;

    //crearCSV("clientes.csv");
    //cargarProductos(listaProductos);
    //levantarListaClientes(listaClientes, FILE_NAME_CLIENTES);
    //levantarClientes(listaClientes);

    while(seguir=='s')
    {
        system("cls");
        printf("\n\t--MENU--\n");
        printf("\n 1- Alta de Cliente.\n"); // ok
        printf(" 2- Modificacion de Cliente.\n"); //
        printf(" 3- Baja de Cliente.\n"); //
        printf(" 4- Listar Clientes.\n"); //
        printf(" 5- Importar clientes desde .CSV\n"); //
        printf(" 6- Realizar una venta.\n"); //
        printf(" 7- Informar ventas.\n"); //
        printf(" 8- Informar ventas por producto.\n"); //
        printf(" 9- Generar informe de ventas.\n"); //
        printf(" 10- Informar cantidad de ventas por Cliente.\n"); //

        do
        {
            flag = pedirInt(&opcion, " Elija una opcion: ", " Ingreso un valor incorrecto.",1 , 10);
        } while(flag == -1);

        switch(opcion)
        {
            case 1:
                system("cls");
                altaClientes(listaClientes, FILE_NAME_CLIENTES);
                guardarLista(listaClientes, FILE_NAME_CLIENTES, sizeof(ECliente));
                //listarTramites(listaUP);
                system("pause");
                break;
            case 2:
                system("cls");
                modificarCliente(listaClientes);
                system("pause");
                break;
            case 3:
                system("cls");
                //proximoCliente(listaUP, listaRP, listaUA, listaRA);
                system("pause");
                break;
            case 4:
                system("cls");
                listarClientes(listaClientes);
                system("pause");
               break;
            case 5:
                system("cls");
                levantarCVS(listaClientes);
                system("pause");
                break;
            case 6:
                system("cls");
                realizarVenta(listaClientes, listaVentas);
                system("pause");
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }

    return 0;
}