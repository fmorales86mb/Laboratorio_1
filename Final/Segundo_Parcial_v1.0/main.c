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


int main() {
    ArrayList* listaUP;
    ArrayList* listaRP;
    ArrayList* listaUA;
    ArrayList* listaRA;
    listaUP = al_newArrayList();
    listaRP = al_newArrayList();
    listaUA = al_newArrayList();
    listaRA = al_newArrayList();
    char seguir='s';
    int opcion=0;
    int flag;

    //levantarLista(lista, FILE_NAME);

    while(seguir=='s')
    {
        system("cls");
        printf("\n\t--MENU--\n");
        printf("\n 1- Tramite Urgente.\n"); //
        printf(" 2- Tramite Regular.\n"); //
        printf(" 3- Proximo Cliente.\n"); //
        printf(" 4- Listar.\n"); //
        printf(" 5- Informar.\n"); // atendidos ordenados por dni
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
                agregarTramite(listaUP, FILE_NAME);
                listarTramites(listaUP);
                system("pause");
                break;
            case 2:
                system("cls");
                agregarTramite(listaRP, FILE_NAME);
                listarTramites(listaRP);
                system("pause");
                break;
            case 3:
                system("cls");
                proximoCliente(listaUP, listaRP, listaUA, listaRA);
                system("pause");
                break;
            case 4:
                system("cls");
                listarPendientes(listaUP, listaRP);
                system("pause");
               break;
            case 5:
                system("cls");
                informar(listaUA, listaRA);
                system("pause");
                break;
            case 6:
                system("cls");
                //grabar(listaU, listaR, FILE_NAME);
                guardarLista(listaUP, listaRP, FILE_NAME, sizeof(ETramite));
                system("pause");
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
