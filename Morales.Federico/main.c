#include <stdio.h>
#include <stdlib.h>
#include "funcionesExamen.h"
#include "input.h"

#define US 100
#define STR 50
#define PR 100

int main()
{
    int opcion;
    int seguirMenu = 0;
    int flag;

    eUsuario listaUsuario[US];
    iniListaUs(listaUsuario, US);
    harcodearUsuario(listaUsuario, US);

    eProducto listaProducto[PR];
    iniListaPR(listaProducto, PR);
    harcodearProducto(listaProducto, PR);

    do
    {
        system("cls");
        printf("\n1) ALTA DE USUARIO.\n");
        printf("\n2) PUBLICAR PRODUCTO.\n");
        printf("\n3) LISTAR PUBLICACIONES.\n");

        do
        {
            flag = getInt(&opcion, "Elija una opcion: ", "Opcion erronea.", 1, 3);
        }while (flag ==-1);

        switch(opcion)
        {
            case 1:
                system("cls");
                altaUsuario(listaUsuario, US);
                //printf("\n %d, %d, %s, %s ", listaUsuario[0].id, listaUsuario[0].estado, listaUsuario[0].nombre, listaUsuario[0].pass);
                system("pause");
                break;
            case 2:
                system("cls");
                altaProducto(listaProducto, PR,listaUsuario, US);
                break;
            case 3:
                system("cls");
                listarPublicaciones(listaProducto, listaUsuario, PR, US);
                system("pause");
                break;
        }

    } while(seguirMenu == 0);


    return 0;
}
