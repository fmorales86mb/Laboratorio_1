#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* pVariable;

    pVariable = (int*)malloc(sizeof(int));
    if(pVariable!=NULL)
    {
        *pVariable=88;


        printf("El entero es %d", *pVariable);
    }
    else
    {
        printf("No hay memoria");
    }





    return 0;
}
