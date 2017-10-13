#include <stdio.h>
#include <stdlib.h>
#include "funcionesExamen.h"
#include "input.h"
#include "bibStrValidacion.h"

#define US 10
#define STR 50
#define PR 20
#define VE 200

int main()
{
    int opcion;
    int seguirMenu = 0;
    int flag;

    eUsuario listaUsuario[US];
    iniListaUs(listaUsuario, US);
    harcodearUsuario(listaUsuario);

    eProducto listaProducto[PR];
    iniListaPR(listaProducto, PR);
    harcodearProducto(listaProducto);

    eVenta listaVenta[VE];
    iniVentas(listaVenta, VE);
    harcodearVenta(listaVenta);

    do
    {
        system("cls");
        printf("\n1) ALTA DE USUARIO.\n");
        printf("\n2) MODIFICAR DATOS DEL USUARIO.\n");
        printf("\n3) BAJA DEL USUARIO.\n");
        printf("\n4) PUBLICAR PRODUCTO.\n");
        printf("\n5) MODIFICAR PUBLICACION.\n");
        printf("\n6) BAJA PUBLICACION.\n");
        printf("\n7) COMPRAR PRODUCTO.\n");
        printf("\n8) LISTAR PUBLICACIONES DE USUARIO.\n");
        printf("\n9) LISTAR PUBLICACIONES.\n");
        printf("\n10) LISTAR USUARIOS.\n");

        do
        {
            flag = getInt(&opcion, "Elija una opcion: ", "Opcion erronea.", 1, 10);
        }while (flag ==-1);

        switch(opcion)
        {
            case 1:
                system("cls");
                altaUsuario(listaUsuario, US);
                mostrarUsuarios(listaUsuario, US);
                system("pause");
                break;
            case 2:
                system("cls");
                mostrarUsuarios(listaUsuario, US);
                modificarUsuario(listaUsuario, US);
                system("pause");
                break;
            case 3:
                system("cls");
                mostrarUsuarios(listaUsuario, US);
                bajaUsuario(listaUsuario, US, listaProducto, PR);
                system("pause");
                break;
            case 4:
                system("cls");
                altaProducto(listaProducto, PR,listaUsuario, US);
                mostrarProductos(listaProducto, PR);
                system("pause");
                break;
            case 5:
                system("cls");
                modificarProducto(listaProducto, PR, listaUsuario, US);
                mostrarProductos(listaProducto, PR);
                system("pause");
                break;
            case 6:
                system("cls");
                bajaProducto(listaProducto, PR, listaUsuario, US);
                mostrarProductos(listaProducto, PR);
                system("pause");
                break;
            case 7:
                system("cls");
                mostrarProductos(listaProducto, PR);
                comprarProducto(listaProducto, PR, listaUsuario, US, listaVenta, VE);
                mostrarVentas(listaVenta, VE);
                system("pause");
                break;
            case 8:
                system("cls");
                listarPublicacionesPorUsuario(listaProducto, PR, listaUsuario, US);
                system("pause");
                break;
            case 9:
                system("cls");
                listarPublicaciones(listaProducto, listaUsuario, PR, US);
                system("pause");
                break;
            case 10:
                system("cls");
                listarUsuarios(listaUsuario, US, listaVenta, VE);
                system("pause");
                break;
        }

    } while(seguirMenu == 0);


    return 0;
}
