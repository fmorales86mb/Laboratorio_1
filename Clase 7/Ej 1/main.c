#include <stdio.h>
#include <stdlib.h>
#include "../../Bibliotecas/Input/input.h"

#define TAM 50
#define CANT 200

/*
1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos:

Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido
*/

int main()
{
    char nombre[CANT][TAM];
    char apellido[CANT][TAM];
    int legajo[CANT];
    char seguir = 's';
    int opcion;
    int flag;
    int flagLegajo = 0;
    int cantidad=0;
    int indice;
    int i;
    int legajoSeleccionado;

    do
    {
        system("cls");
        printf("\n--- MENU INICIO---\n");

        printf("\n1-Alta.");
        printf("\n2-Baja.");
        printf("\n3-Modificar.");
        printf("\n4-Mostrar listado.");
        printf("\n5-Salir.\n");

        do
        {
            flag=getInt(&opcion, "Elija una opcion: ", "Opcion invalida.", 1, 5);
        } while(flag!=0);

        switch(opcion)
        {
            case 1:// alta
                system("cls");

                do
                {
                    flag = getString(&nombre[cantidad], "Ingrese nombre: ", "Nombre invalido.", 1, TAM);
                } while(flag!=0);
                do
                {
                    flag = getString(&apellido[cantidad], "Ingrese apellido: ", "Apellido invalido.", 1, TAM);
                } while(flag!=0);
                do
                {
                    flag = getInt(&legajo[cantidad], "Ingrese legajo: ", "Legajo invalido.", 1, 1000);
                    // chequeo que el legajo no esté repetido.
                    if (flag==0)
                    {
                        for (i=0; i<cantidad; i++)
                        {
                            if (legajo[cantidad]== legajo[i])
                            {
                                flag=-1;
                                printf("\tLegajo repetido.");
                                break;
                            }
                        }
                    }
                } while(flag!=0);

                cantidad++;

                break;

            case 2: // baja
                system("cls");

                do
                {
                    flag = getInt(&legajoSeleccionado, "Ingrese legajo que desea borrar: ", "Nro de legajo invalido.", 0, 1000);
                    if (flag == 0)
                    {
                        for (i=0; i<cantidad; i++)
                        {
                            if (legajoSeleccionado == legajo[i])
                            {
                                indice = i;
                                flagLegajo = 1;
                                break;
                            }
                        }
                        if (flagLegajo == 1)
                        {
                            legajo[indice] = -1;
                            printf("\nLegajo borrado.\n");
                            flagLegajo=0;
                            system("pause");
                        }
                        else
                        {
                            printf("\nLegajo no encontrado.\n");
                            system("pause");
                        }
                    }

                }while(flag != 0);

                break;

            case 3: //modificacion
                system("cls");

                do
                {
                    flag = getInt(&legajoSeleccionado, "Ingrese legajo que desea modificar: ", "Nro de legajo invalido.", 0, 1000);
                    if (flag == 0)
                    {
                        for (i=0; i<cantidad; i++)
                        {
                            if (legajoSeleccionado == legajo[i])
                            {
                                indice = i;
                                flagLegajo = 1;
                                break;
                            }
                        }
                        if (flagLegajo == 1)
                        {
                            printf("\nNombre: %s\nApellido: %s\nLegajo: %d\n", nombre[indice], apellido[indice], legajo[indice]);

                            do
                            {
                                printf("\n--- MENU Modificar---\n");

                                printf("\n1-Nombre.");
                                printf("\n2-Apellido.");
                                printf("\n3-Legajo.");
                                printf("\n4-Salir.\n");

                                do
                                {
                                    flag=getInt(&opcion, "Elija una opcion: ", "Opcion invalida.", 1, 4);
                                } while(flag!=0);

                                switch(opcion)
                                {
                                    case 1:
                                        break;
                                    case 2:
                                        break;
                                    case 3:
                                        break;
                                    case 4:
                                        break;
                                }
                            }while(seguir=='s');
                        }
                        else
                        {
                            printf("\nLegajo no encontrado.\n");
                            system("pause");
                        }
                    }

                }while(flag != 0);

                break;
            case 4:
                system("cls");

                for(i=0; i<cantidad; i++)
                {
                    printf("\nNombre: %s\nApellido %s\nLegajo %d\n\n", nombre[i], apellido[i], legajo[i]);
                }

                system("pause");
                break;
            case 5:

                break;
        }


    }while(seguir=='s');

    return 0;
}
