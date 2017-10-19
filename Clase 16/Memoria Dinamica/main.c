#include <stdio.h>
#include <stdlib.h>
#define T 4

int main()
{
    int* p;
    int* aux;
    int i;

    p = (int*) malloc(sizeof(int)*T);
    //p = (int*) calloc(T,sizeof(int));
    if(p!=NULL)
    {
        printf("CARGO LOS PRIMEROS 4\n");

        for(i=0; i<T; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", p+i);
        }
        for(i=0; i<T; i++)
        {
            printf("%d\n", *(p+i));
        }


        aux = (int*) realloc(p, sizeof(int) * (T+3));
        if(aux!=NULL)
        {
            p=aux;
            printf("CARGO LOS 3 RESTANTES\n");
            for(i=T; i<T+3; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", p+i);
            }
            for(i=0; i<T+3; i++)
            {
                printf("%d\n", *(p+i));
            }

            p = (int*) realloc(p, sizeof(int)*(T-1));
            printf("MUESTRO LO QUE ME QUEDA\n");
            for(i=0; i<3; i++)
            {
                printf("%d\n", *(p+i));
            }

            free(aux);

        }
        else
        {
            printf("No hay suficiente espacio en memoria!!!");
        }



        free(p);

    }
    else
    {
        printf("No hay espacio en memoria");
    }





    return 0;
}
