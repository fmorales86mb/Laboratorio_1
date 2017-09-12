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
    char nombreAux[TAM];
    char apellidoAux[TAM];
    int legajoAux;
    int repetido = 0;
    int i;
    int e;
    int legajoSeleccionado;
    int legajoOrdenado[CANT];
    int min;

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
                    // utilizo una variable aux porque sino no garantizo que no haya legajos repetidos.
                    flag = getInt(&legajoAux, "Ingrese legajo: ", "Legajo invalido.", 1, 1000);
                    // chequeo que el legajo no esté repetido.
                    if (flag==0)
                    {
                        repetido = 0;
                        for (i=0; i<cantidad; i++)
                        {
                            if (legajoAux == legajo[i])
                            {
                                flag=-1;
                                printf("\tLegajo repetido.");
                                repetido =1;
                                break;
                            }
                        }
                        if (repetido == 0)
                        {
                            legajo[cantidad] = legajoAux;
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

                //valido legajo ingresado.
                do
                {
                    flag = getInt(&legajoSeleccionado, "Ingrese legajo que desea modificar: ", "Nro de legajo invalido.", 0, 1000);
                }while(flag != 0);

                // tareas con el legajo
                if (flag == 0)
                {
                    for (i=0; i<cantidad; i++)
                    {
                        // busco el indice del legajo seleccionado.
                        if (legajoSeleccionado == legajo[i])
                        {
                            indice = i;
                            flagLegajo = 1;
                            break;
                        }
                    }

                    // tareas si encontré el legajo
                    if (flagLegajo == 1)
                    {

                        // muestro los datos encontrados + menú
                        do
                        {
                            system("cls");
                            printf("\nNombre: %s\nApellido: %s\nLegajo: %d\n", nombre[indice], apellido[indice], legajo[indice]);

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
                                case 1: //nombre
                                    system("cls");
                                    printf("\nNombre: %s\nApellido: %s\nLegajo: %d\n", nombre[indice], apellido[indice], legajo[indice]);
                                    do
                                    {
                                        flag = getString(&nombre[indice], "Ingrese nuevo nombre: ", "Nombre invalido.", 1, TAM);
                                    } while(flag!=0);
                                    break;

                                case 2: //apellido
                                    system("cls");
                                    printf("\nNombre: %s\nApellido: %s\nLegajo: %d\n", nombre[indice], apellido[indice], legajo[indice]);
                                    do
                                    {
                                        flag = getString(&apellido[indice], "Ingrese nuevo apellido: ", "Apellido invalido.", 1, TAM);
                                    } while(flag!=0);
                                    break;

                                case 3: //legajo
                                    system("cls");
                                    printf("\nNombre: %s\nApellido: %s\nLegajo: %d\n", nombre[indice], apellido[indice], legajo[indice]);
                                    do
                                    {
                                        flag = getInt(&legajoAux, "Ingrese nuevo legajo: ", "legajo invalido.", 0, 1000);
                                        if (flag==0)
                                        {
                                            repetido =0;
                                            for (i=0; i<cantidad; i++)
                                            {
                                                if (legajoAux == legajo[i])
                                                {
                                                    flag=-1;
                                                    printf("\tLegajo repetido.");
                                                    repetido =1;
                                                    break;
                                                }
                                            }
                                            if (repetido == 0)
                                            {
                                                legajo[indice] = legajoAux;
                                            }
                                        }
                                    } while(flag!=0);

                                    break;

                                case 4:
                                    seguir = 'n';
                                    break;
                            }
                        }while(seguir=='s');
                        seguir = 's';
                    }
                    else
                    {
                        printf("\nLegajo no encontrado.\n");
                        system("pause");
                    }
                }

                break;
            case 4:
                system("cls");

                for(i=0; i<cantidad; i++)
                {
                    // legajos activos
                    if (legajo[i] >=0)
                    {
                        // Ordeno alfabeticamente

                        for (i=0; i<cantidad; i++)
                        {
                            for (e = i;e<cantidad;e++)
                            {
                                // obtengo min
                                if (e==i || stricmp(apellido[e], menor)<0)
                                {
                                    strcpy(menor, apellido[e]);
                                    min = e;
                                }
                                //pongo cada min en orden.
                            }

                        }
                        printf("\nNombre: %s\nApellido %s\nLegajo %d\n\n", nombre[min], apellido[min], legajo[min]);
                    }
                }

                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }


    }while(seguir=='s');

    return 0;
}
