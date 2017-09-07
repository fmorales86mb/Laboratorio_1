#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector1 [5] = {3, 1, 4, 9, 5};
    int i;
    int j;
    int aux;

    for (i=0; i<5; i++)
    {
        printf("%d ", vector1[i]);
    }

    for (i=0; i<4; i++) //i<4 ya que i no llega al ùltimo elemento
    {
        for(j=i+1; j<5; j++) // j siempre empieza en el elemento siguiente a i
        {
            if(vector1[i] < vector1[j]) //comparo
            {
                // swap (intercambio)
                aux = vector1[j];
                vector1[j] = vector1[i];
                vector1[i] = aux;
            }
        }
    }

    printf("\n");
    for (i=0; i<5; i++)
    {
        printf("%d ", vector1[i]);
    }

    return 0;
}
