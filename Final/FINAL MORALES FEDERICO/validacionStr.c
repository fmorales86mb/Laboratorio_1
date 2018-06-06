#include <string.h>


int soloLetras(char str[])
{
    int retorno = 0;
    int i=0;
    char caracter;

    while (str[i]!='\0')
    {
        caracter = str[i];
        if (!((caracter>= 'A' && caracter<= 'Z') || (caracter>= 'a' && caracter<= 'z') || (caracter == ' ')))
        {
            retorno= -1;
            break;
        }
        i++;
    }

    return retorno;
}

int soloNumeros(char str[])
{
    int retorno = 0;
    int i=0;
    char caracter;

    while (str[i]!='\0')
    {
        caracter = str[i];
        if (!(caracter>= '0' && caracter<= '9'))
        {
            retorno= -1;
            break;
        }
        i++;
    }

    return retorno;
}

int soloAlfanumerico(char str[])
{
    int retorno = 0;
    int i=0;
    char caracter;

    while (str[i]!='\0')
    {
        caracter = str[i];
        if (!(caracter>= '0' && caracter<= '9')||
            (caracter>= 'A' && caracter<= 'Z') ||
            (caracter>= 'a' && caracter<= 'z') ||
            (caracter == ' '))
        {
            retorno= -1;
            break;
        }
        i++;
    }

    return retorno;
}

int soloTelefono(char str[])
{
    int retorno = 0;
    int i=0;
    char caracter;

    while (str[i]!='\0')
    {
        caracter = str[i];
        if (!(caracter>= '0' && caracter<= '9') || (caracter =='-'))
        {
            retorno= -1;
            break;
        }
        i++;
    }

    return retorno;
}

//inclusive posicion, agrega \0
int subString (char* str, char* subStr, int desde, int posicion)
{
    int ret = -1;
    int i;
    int isub = 0;

    if (strlen(str)>=posicion)
    {
        for(i=desde; i<posicion; i++)
        {
            ret = 0;
            *(subStr+isub) = *(str+i);
            isub++;
        }
        *(subStr+isub) = '\0';
    }

    return ret;
}

int primerPosicionDe (char* str, int desde, char caracter)
{
    int ret = 0;
    int i;

    for (i=desde; i<strlen(str); i++)
    {
        if (*(str+i) == caracter)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

