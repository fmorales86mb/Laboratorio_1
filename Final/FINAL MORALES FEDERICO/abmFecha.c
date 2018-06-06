#include "abmFecha.h"

EFecha* newEFecha ()
{
    EFecha* returnAux;
    returnAux = (EFecha*)malloc(sizeof(EFecha));

    if(returnAux != NULL)
    {
       returnAux->dia = 0;
       returnAux->mes = 0;
       returnAux->anio = 0;
    }
    return returnAux;
}

EFecha* newEFechaIni (int d, int m, int y)
{
    EFecha* fecha = newEFecha();
    if (fecha != NULL)
    {
        fecha->dia = d;
        fecha->mes = m;
        fecha->anio = y;
    }
}

int pedirFecha (EFecha *fecha)
{
    int flag;
    int chances = 0;
    int ret=0;

    if(chances<3)
    {
        do
        {
            flag = pedirInt(&(fecha->anio), " Anio: ", " Anio invalido.", 1, 3000);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        do
        {
            flag = pedirInt(&(fecha->mes), " Mes: ", " Mes invalido.", 1, 12);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        do
        {
            flag = pedirInt(&(fecha->dia), " Dia: ", " Dia invalido.", 1, 31);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        ret =1;
    }

    return ret;
}

EFecha* aToDate (char* date)
{
    int barra1;
    int barra2;
    int y, m, d;
    char anio [10];
    char mes [10];
    char dia [10];

    barra1 = primerPosicionDe(date, 0, '/');
    subString(date, dia, 0, barra1);

    barra2 = primerPosicionDe(date, barra1+1, '/');
    subString(date, mes, barra1+1, barra2);

    subString(date, anio, barra2+1, strlen(date));

    y = atoi(anio);
    m = atoi(mes);
    d = atoi(dia);

    return newEFechaIni(d, m, y);
}
