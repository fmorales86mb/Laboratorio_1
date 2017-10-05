#include <stdio.h>
#include <stdlib.h>
#include "../../Laboratorio_1/Bibliotecas/Input/input.h"
#include "../../Laboratorio_1/Bibliotecas/biblioStr/validacionStr.h"
#include "funcParcial.h"

#define STR 50
#define ABO 5
#define LLA 10

int main()
{
    int opcion = 0;
    int seguir = 0;
    int flag1 = 0;

    eAbonado listaAbonados [ABO];
    eLlamada listaLlamadas [LLA];

    inicializarIdAbonados(listaAbonados, ABO, -1);

    do
    {
        system("cls");
        printf("\n \t MENU \n\n");
        printf("\n 1) Alta del Abondado.\n ");
        printf("\n 2) Modificar datos del Abondado.\n ");
        printf("\n 3) Baja del Abondado.\n ");
        printf("\n 4) Nueva Llamada.\n ");
        printf("\n 5) Fin Llamada.\n ");
        printf("\n 6) Informar.\n ");

        do
        {
            flag1 = getInt(&opcion, "Elija una opcion del menu: ","Opcion erronea.", 1, 6);
        }while (flag1<0);

        switch(opcion)
        {
            case 1:
                system("cls");
                int indice = altaAbonado(listaAbonados, ABO);
                printf("\n indice = %d", indice);
                system("pause");
                break;

            case 2:
                system("cls");

                system("pause");
                break;

            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }

    }while (seguir == 0);



    return 0;
}
