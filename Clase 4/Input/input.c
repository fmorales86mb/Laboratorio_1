#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>o

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado (es una dirección de memoria).
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int salida = -1;

    printf("\n%s", message);
    scanf("%d", input); //input ya es dirección de memoria, no hace falta el '&'.

    while (*input<lowLimit || *input>hiLimit) //Como input es una dir de memoria, para tomar su valor se agrega el * delante.
    {
        printf("\n%s", eMessage);
        scanf("%d", input);
    }

    salida = 0;
    //*input = 44;
    return salida;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int salida = -1;

    printf("\n%s", message);
    scanf("%f", input); //input ya es dirección de memoria, no hace falta el '&'.

    while (*input<lowLimit || *input>hiLimit) //Como input es una dir de memoria, para tomar su valor se agrega el * delante.
    {
        printf("\n%s", eMessage);
        scanf("%f", input);
    }

    salida = 0;
    //*input = 44;
    return salida;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int salida = -1;

    printf("\n%s", message);
    *input = getche();

    while (*input!=lowLimit && *input!=hiLimit) //Como input es una dir de memoria, para tomar su valor se agrega el * delante.
    {
        printf("\n%s", eMessage);
        *input = getche();
    }

    salida = 0;
    //*input = 44;
    return salida;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{

    strcpy(input,"Sheldon");
    return 0;
}
