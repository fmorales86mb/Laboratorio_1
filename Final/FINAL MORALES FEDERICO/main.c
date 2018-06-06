#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"
#include "ArrayList.h"
#include "abmPersona.h"

#define STR 50
#define STRLONG 1000
#define FILE_NAME "File.csv"
#define FILE_NAME_CLIENTES "clientes.csv"
#define FILE_NAME_CLIENTES_EXAMPLE "ClientesExample.csv"


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
        printf("\n\t--MENU--\n\n");
        printf(" 1- Alta de Cliente.\n"); // ok
        printf(" 2- Modificacion de Cliente.\n"); //ok
        printf(" 3- Baja de Cliente.\n"); // ok
        printf(" 4- Listar Clientes.\n"); // ok
        printf(" 6- Realizar una venta.\n"); //
        printf(" 7- Informar ventas.\n"); //
        printf(" 8- Informar ventas por producto.\n"); //
        printf(" 9- Generar informe de ventas.\n"); //
        printf(" 10- Informar cantidad de ventas por Cliente.\n"); //
        printf(" 11- Guardar Clientes en archivo TXT.\n"); //
        printf(" 12- Guardar Clientes en archivo binario.\n"); //
        printf(" 13- Guardar Clientes en archivo CSV.\n"); //ok
        printf(" 14- Levantar Clientes de archivo CSV.\n"); //ok
        printf(" 15- Levantar Clientes de archivo TXT.\n"); //
        printf(" 16- Levantar Clientes de archivo binario.\n"); //
        printf(" 20- Salir.\n"); //

        do
        {
            flag = pedirInt(&opcion, " Elija una opcion: ", " Ingreso un valor incorrecto.",1 , 20);
        } while(flag == -1);

        switch(opcion)
        {
            case 1:
                system("cls");
                altaPersona(listaClientes);
                system("pause");
                break;
            case 2:
                system("cls");
                listarPersonas(listaClientes);
                modificarPersona(listaClientes);
                system("pause");
                break;
            case 3:
                system("cls");
                listarPersonas(listaClientes);
                bajaPersona(listaClientes);
                break;
            case 4:
                system("cls");
                listarPersonas(listaClientes);
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
            case 13:
                system("cls");
                pisarArchivoCSVPersona(listaClientes, FILE_NAME_CLIENTES, sizeof(EPersona));
                system("pause");
                break;
            case 14:
                system("cls");
                levantarListaCSVPersonas(listaClientes, FILE_NAME_CLIENTES_EXAMPLE);
                system("pause");
                break;
            case 20:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
