#include <stdio.h>
#include <stdlib.h>

int validarEntero ()


int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int salida = -1;
	int nro;

    printf("\n%s", message);
    scanf("%d", &nro);

    if (nro>hiLimit || nro<lowLimit)
    {
        printf("\n%s\n", eMessage);
        //system("pause");
    }
    else
    {
        *input = nro;
        salida = 0;
    }

    return salida;
}
