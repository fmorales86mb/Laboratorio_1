#include <stdio.h>
#include <stdlib.h>

//1) Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.

int main()
{
    int max;
    int min;
    int acumulador=0;
    float media;
    int nro;

    for (int i=0; i<5; i++)
    {
        printf("(%d)Ingrese nro: ", i+1);
        scanf("%d", &nro);

        if (i==0)
        {
            max=nro;
            min=nro;
        }
        else
        {
            if (nro<min)
            {
                min=nro;
            }
            else if (nro>max)
            {
                max=nro;
            }
        }

        acumulador+=nro;
    }

    media=(float)acumulador/5;

    printf("Maximo = %d\nMinimo = %d\nMedia = %.2f\n", max, min, media);

    return 0;
}
