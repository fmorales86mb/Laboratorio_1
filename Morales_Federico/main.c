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
#define FILE_NAME "File.dat"
#define FILE_NAME_BACKUP "File_copy.dat"

int main() {
    ArrayList* listaU;
    ArrayList* listaR;
    listaU = al_newArrayList();
    listaR = al_newArrayList();
    char seguir='s';
    int opcion=0;
    int flag;

    // aca inicializamos el proximo id para que sea cero por que la lista esta vacia.
    //proximo_id = 0;
    //levantarLista(lista, FILE_NAME);

    while(seguir=='s')
    {
        system("cls");
        printf("\n\t--MENU--\n");
        printf("\n 1- Tramite Urgente.\n"); //
        printf(" 2- Tramite Regular.\n"); //
        printf(" 3- Proximo Cliente.\n"); //
        printf(" 4- Listar.\n"); //
        printf(" 5- Informar.\n"); //
        printf(" 6- Grabar.\n"); //
        printf(" 7- Salir.\n"); //

        do
        {
            flag = pedirInt(&opcion, " Elija una opcion: ", " Ingreso un valor incorrecto.",1 , 7);
        } while(flag == -1);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarTramite(listaU, FILE_NAME);
                listarTramites(listaU);
                system("pause");
                break;
            case 2:
                system("cls");
                agregarTramite(listaR, FILE_NAME);
                listarTramites(listaR);
                break;
            case 3:
                system("cls");
                proximoCliente(listaU, listaR);
                system("pause");
                break;
            case 4:
                system("cls");
                listarPendientes(listaU, listaR);
                system("pause");
               break;
            case 5:
                system("cls");
                informar(listaU, listaR);
                system("pause");
                break;
            case 6:
                system("cls");
                //clearList(lista, FILE_NAME);
                system("pause");
                break;
            case 7:
                //guardarLista (lista, FILE_NAME);
                seguir = 'n';
                break;
        }
    }

    return 0;
}
