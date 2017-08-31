#include <stdio.h>
#include <stdlib.h>
int incrementar(int);



int ingresarNumero(int*);
int main()
{
    int numero;
    int retorno;

    retorno = ingresarNumero(&numero);


    printf("%d", numero);

    if(retorno==1)
    {
        printf("\nEsta en rango");
    }
    else
    {
        printf("\nNo esta en rango");
    }

    return 0;
}
int incrementar(int valor)
{
    valor++;
    return valor;
}

int ingresarNumero(int* dato)
{
    int flag = 0;
    int valor;

    printf("Ingrese un numero: ");
    scanf("%d", &valor);

    if(valor>=1 && valor<=10)
    {
        flag = 1;
    }

    *dato = valor;

    return flag;

}

