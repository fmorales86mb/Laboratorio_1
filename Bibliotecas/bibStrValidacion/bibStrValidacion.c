#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pedirInt (int* numero, char mje[], char emje[], int minimo, int maximo)
{
    int retorno=0;
    char strNro[2000];
    int nro;
    int i = 1;
    int iPrimero;

    // ver cantidad de caracteres maximos según los bytes del tipo int.

    printf("%s", mje);
    fflush( stdin );
    gets(strNro);

    while (strNro[i] == ' ')
    {
        i++;
    }

    iPrimero = i;

    while (strNro[i]!='\0')
    {
        if ( !(strNro[i]>= '0' && strNro[i]<= '9') && !(i==iPrimero && strNro[i] == '-') )
        {
            retorno= 0;
            break;
        }
        i++;
    }

    if (retorno != 0)
    {
        nro = atoi(strNro);
        if (nro>maximo || nro<minimo)
        {
            retorno = 0;
        }
        else
        {
            *numero = nro;
        }
    }

    if(retorno == 0)
    {
        printf("\n%s\n", emje);
    }

    return retorno;
}

int pedirFloat (float* numero, char mje[], char emje[], float minimo, float maximo)
{
    int retorno=1;
    char strNro[2000];
    float nro;
    int i = 0;
    int iPrimero;
    int pto = -1;

    // ver cantidad de caracteres maximos según los bytes del tipo int.

    printf("%s", mje);
    fflush( stdin );
    gets(strNro);

    while (strNro[i] == ' ')
    {
        i++;
    }

    iPrimero = i;

    while (strNro[i]!='\0')
    {
        if ( !(strNro[i]>= '0' && strNro[i]<= '9') && !(i==iPrimero && strNro[i] == '-') )
        {
            if(strNro[i] == '.' && pto == -1)
            {
                pto = 0;
            }
            else
            {
                retorno= 0;
                break;
            }
        }
        i++;
    }

    if (retorno != 0)
    {
        nro = atof(strNro);
        if (nro>maximo || nro<minimo)
        {
            retorno = 0;
        }
        else
        {
            *numero = nro;
        }
    }

    if(retorno == 0)
    {
        printf("\n%s\n", emje);
    }

    return retorno;
}

int pedirStrLetras (char cadena[], char mje[], char emje[], int minimo, int maximo)
{
    int retorno=1;
    char str[2000];
    int nro;
    int i = 0;

    printf("%s", mje);
    fflush( stdin );
    gets(str);

    while (str[i]!='\0')
    {
        if (!((str[i]>= 'A' && str[i]<= 'Z') || (str[i]>= 'a' && str[i]<= 'z') || (str[i] == ' ')))
        {
            retorno= 0;
            break;
        }
        i++;
    }

    if (retorno != 0)
    {
        nro = strlen(str);
        if (nro>maximo || nro<minimo)
        {
            retorno = 0;
        }
        else
        {
            strcpy(cadena, str);
        }
    }

    if(retorno == 0)
    {
        printf("\n%s\n", emje);
    }

    return retorno;
}
