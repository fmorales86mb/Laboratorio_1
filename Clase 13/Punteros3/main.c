#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* puntero1=NULL;
    int* puntero2=NULL;
    int val = 5;

    // Puntero dos apunta a puntero uno que apunta a val que es 5.
    puntero1=&val;
    puntero2=puntero1;

    printf("%d", *puntero2);



    return 0;
}
