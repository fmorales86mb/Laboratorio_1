#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"
#include "ArrayList.h"
#include "abmPersona.h"
#include "abmFecha.h"
#include "abmVenta.h"

#define STR 50
#define STRLONG 1000
#define FILE_NAME "File.csv"
#define FILE_NAME_CLIENTES "clientes.csv"
#define FILE_NAME_CLIENTES_EXAMPLE "ClientesExample.csv"
#define FILE_NAME_CLIENTES_TXT "Clientes.txt"
#define FILE_NAME_CLIENTES_BIN "Clientes.bin"


int main() {
    ArrayList* listaClientes;
    ArrayList* listaVentas;

    listaClientes = al_newArrayList();
    listaVentas = al_newArrayList();

    char seguir='s';
    int opcion=0;
    int flag;

    while(seguir=='s')
    {
        system("cls");
        printf("\n\t--MENU--\n\n");
        printf(" 1- Alta de Cliente.\n"); // ok
        printf(" 2- Modificacion de Cliente.\n"); //ok
        printf(" 3- Baja de Cliente.\n"); // ok
        printf(" 4- Listar Clientes.\n"); // ok

        printf(" 6- Realizar una venta.\n"); // ok
        printf(" 7- Informar ventas.\n"); // ok
        printf(" 8- Informar ventas por producto.\n"); //
        printf(" 9- Generar informe de ventas.\n"); //
        printf(" 10- Informar cantidad de ventas por Cliente.\n"); // ok

        printf(" 11- Guardar Clientes en archivo TXT.\n"); //ok
        printf(" 12- Guardar Clientes en archivo binario.\n"); // ok
        printf(" 13- Guardar Clientes en archivo CSV.\n"); //ok
        printf(" 14- Levantar Clientes de archivo CSV.\n"); //ok
        printf(" 15- Levantar Clientes de archivo TXT.\n"); //ok
        printf(" 16- Levantar Clientes de archivo binario.\n"); // ok
        printf(" 17- Levantar Ventas de archivo TXT.\n"); //

        printf(" 20- Salir.\n"); //

        do
        {
            flag = pedirInt(&opcion, " Elija una opcion: ", " Ingreso un valor incorrecto.",1 , 20);
        } while(flag == -1);

        switch(opcion)
        {
            case 1:
                altaCliente(listaClientes);
                break;
            case 2:
                modificacionCliente(listaClientes);
                break;
            case 3:
                bajaCliente(listaClientes, listaVentas);
                break;
            case 4:
                listarClientes(listaClientes);
                break;
            case 6:
                opcionAltaVenta(listaClientes, listaVentas);
                break;
            case 7:
                opcionListarVenta(listaVentas);
                break;
            case 8:
                informarVentasPorProducto(listaVentas);
                break;
            case 10:
                informarVentasPorCliente(listaClientes, listaVentas);
                break;
            case 11:
                system("cls");
                guardarCsvTxtPersona(listaClientes, FILE_NAME_CLIENTES_TXT, sizeof(EPersona), 1);
                system("pause");
                break;
            case 12:
                system("cls");
                guardarBinPersona(listaClientes, FILE_NAME_CLIENTES_BIN, sizeof(EPersona));
                system("pause");
                break;
            case 13:
                system("cls");
                guardarCsvTxtPersona(listaClientes, FILE_NAME_CLIENTES, sizeof(EPersona), 1);
                system("pause");
                break;
            case 14:
                system("cls");
                cargarCsvTxtPersonas(listaClientes, FILE_NAME_CLIENTES_EXAMPLE, 1);
                system("pause");
                break;
            case 15:
                system("cls");
                cargarCsvTxtPersonas(listaClientes, FILE_NAME_CLIENTES_TXT, 1);
                system("pause");
                break;
            case 16:
                system("cls");
                cargarBinPersonas(listaClientes, FILE_NAME_CLIENTES_BIN, sizeof(EPersona));
                system("pause");
                break;
            case 20:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
