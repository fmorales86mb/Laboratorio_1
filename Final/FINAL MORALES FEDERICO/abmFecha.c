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
