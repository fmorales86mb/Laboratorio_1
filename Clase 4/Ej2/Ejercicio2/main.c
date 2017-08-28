#include <stdio.h>
#include <stdlib.h>

#include "../../../Biblioteca/utn.h"

/*
2) Dise�ar un programa para jugar a adivinar un n�mero entre 0 y 100.
El juego tiene que dar pistas de si el n�mero introducido por el jugador est� por encima o por debajo.
El juego termina cuando se adivina el n�mero o se decide terminar de jugar ingresando un n�mero negativo.
Permitir jugar tantas veces como lo desee el jugador y al salir mostrar su mejor puntuaci�n.
Utilizar la biblioteca del punto 1.
*/

int main()
{
    int random;
    int nro;
    char continuar;
    int intentos;
    int mejorPuntuacion=0;
    int contador = 0;

    do
    {
        random = GenerarRandomInt(0,10);
        printf("\nAdivine el nro!(%d)", random);
        intentos = 1;

        do
        {
            nro = PedirInt();

            if (nro == random)
            {
                printf("\nAdivino!");
                nro = nro * (-1);
            }
            else if(nro<random && nro>=0)
            {
                printf("\nFalta.");
                intentos++;

            }
            else if(nro>random)
            {
                printf("\nSobra.");
                intentos++;
            }

        }while(nro>0);

        if (contador == 0)
        {
            mejorPuntuacion = intentos;
        }
        else
        {
            if (intentos<mejorPuntuacion)
            {
                mejorPuntuacion = intentos;
            }
        }

        contador++;

        continuar = ConsultaContinuar();

    }while(continuar == 's');

    printf("\nMejor puntuacion %d\n", mejorPuntuacion);

    return 0;
}
