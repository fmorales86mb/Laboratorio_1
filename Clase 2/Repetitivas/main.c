#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
Se ingresan numeros enteros (positivos), no se sabe cuantos.
Determinar:
 - cantidad de numeros comprendidos entre 10 y 100 (inclusive) (X)
 - cantidad de numeros primos ()
 - cantidad de numeros pares (X)
 - cantidad de numeros impares (X)
 - promedio (X)
 - maximo (X)
 - minimo (X)

*/



int main()
{
    int numero;
    int cont10a100 = 0;
    int contPares = 0;
    int contImpares = 0;
    int contador = 0;
    int acumulador = 0;
    float promedio;
    int maximo;
    int minimo;
    int flag = 0;
    int i;
    int esPrimo = 0;
    int contPrimos = 0;
    char seguir;

    do
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numero);
        while(!(numero>0))
        {
            printf("\nError!!! Ingrese un numero positivo: ");
            scanf("%d", &numero);
        }

        if(numero>=10 && numero<=100)
        {
            cont10a100++;
        }
        if(numero%2==0)
        {
            contPares++;
        }
        else
        {
            contImpares++;
        }

        acumulador += numero;//acumulador = acumulador + numero;
        contador++;

        if(flag==0 || numero>maximo)
        {
            maximo = numero;
        }
        if(flag==0 || numero<minimo)
        {
            minimo = numero;
            flag = 1;
        }

        /*
        if(flag==0)
        {
            maximo = numero;
            minimo = numero;
            flag = 1;
        }
        else
        {
            if(numero>maximo)
            {
                maximo = numero;
            }
            if(numero<minimo)
            {
                minimo = numero;
            }
        }*/

        esPrimo = 0;
        for(i=1; i<=numero; i++)
        {
            if(numero%i==0)
            {
               esPrimo++;
            }
        }
        if(esPrimo==2)
        {
            contPrimos++;
        }



        printf("Desea ingresar otro numero? (s/n) ");
        seguir = getche();



    }while(seguir=='s');

    promedio = (float)acumulador / contador;

    printf("\nLa cantidad de numeros entre 10 y 100 (inclusive) es: %d\n", cont10a100);
    printf("La cantidad de pares es: %10d", contPares);
    printf("La cantidad de impares es: %d\n", contImpares);
    printf("El promedio es: %10.2f", promedio);
    printf("El maximo es %d, y el minimo es %d", maximo, minimo);
    printf("\nCont primos: %d", contPrimos);


    return 0;
}




 /*while(cont<10)
    {
        cont++;
        printf("%d\n", cont);
    }

   do
    {
        cont++;
        printf("%d\n", cont);
    }while(cont<10);*/

    /*for(inicializacion de la variable de control; condicion de continuidad de bucle; incremento de la variable de control)*/

    /*for(cont=0; cont<10; cont++)
    {
        printf("%d\n", cont+1);
    }*/
