#include <stdio.h>
#include <stdlib.h>

/*
4) Escribir un programa que realice las siguientes acciones:

Solicite al usuario 10 números
Calcule cuántos son negativos y cuantos son positivos
Muestre por pantalla la cantidad de negativos y la cantidad de positivos
*/

int main()
{
    int nro;
    int negativos=0;
    int positivos=0;

    for (int i=0; i<10; i++)
    {
        printf("Ingrese %d° numero:", i+1);
        scanf ("%d", &nro);

        if (nro<0)
        {
            negativos++;
        }
        else if(nro>0)
        {
            positivos++;
        }
    }

    printf("\nSe ingresaron %d numeros negativos y %d positivos.\n", negativos, positivos);

    return 0;
}
