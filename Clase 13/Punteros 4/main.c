#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p = NULL;
    int var [5]={1,2,3,4,5};

    p=&var; //p=var; p=&var[0]

    printf("%p\t%d\n", p, *p);  //primer posicion de memoria
    printf("%p\t%d\n", p+0, *(p+0));
    printf("%p\t%d\n", p+1, *(p+1)); //suma 4 bytes, que es el tamaño de un entero. Serìa indice 1
    printf("%p\t%d\n", p+2, *(p+2));
    printf("%p\t%d\n", p++, *p); //
    printf("%p\t%d\n", p++, *p);
    printf("%p\t%d\n", p++, *p);




    return 0;
}
