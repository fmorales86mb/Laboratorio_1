#include "abmPersona.h"

EPersona* newEPersona ()
{
    EPersona* returnAux;
    returnAux = (EPersona*)malloc(sizeof(EPersona));

    if(returnAux !=NULL)
    {
       strcpy(returnAux->apellido, "");
       returnAux->dni = 0;
       returnAux->id = 0;
       strcpy(returnAux->nombre, "");
       returnAux->fechaNac = newEFecha();
    }
    return returnAux;
}

EPersona* buscarPersona (ArrayList* lista, int id)
{
    int i;
    EPersona* elemento;
    EPersona* elementoRet = NULL;

    for(i=0; i<lista->len(lista); i++)
    {
        elemento = lista->get(lista, i);
        if(elemento->id == id)
        {
            elementoRet = elemento;
            break;
        }
    }

    return elementoRet;
}

int generarIdPersona (ArrayList* lista)
{
    int i;
    int max;
    EPersona* elemento;

    for (i=0; i<lista->len(lista); i++)
    {
        elemento = lista->get(lista, i);
        if(i==0 || max < elemento->id)
        {
            max = elemento->id;
        }
    }

    return max+1;
}

EPersona* buscarPersonaPorDNI(ArrayList* lista, long int dni)
{
    int i;
    EPersona* elemento;
    EPersona* elementoRet = NULL;

    for(i=0; i<lista->len(lista); i++)
    {
        elemento = lista->get(lista, i);
        if(elemento->dni == dni)
        {
            elementoRet = elemento;
            break;
        }
    }

    return elementoRet;
}

int pedirPersona (EPersona *persona)
{
    int flag;
    int chances = 0;
    int ret=0;

    if(chances<3)
    {
        do
        {
            flag = pedirLong(&(persona->dni), " Ingrese su DNI: ", " DNI invalido.", 1, 100000000);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        do
        {
            flag = pedirStrLetras(persona->apellido, " Ingrese su Apellido: ", " Apellido invalido.", 1, 20);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        do
        {
            flag = pedirStrLetras(persona->nombre, " Ingrese su nombre: ", " nombre invalido.", 1, 20);
            chances++;
        }while (flag == -1 && chances<3);
        chances = 0;
    }

    if(chances<3 && flag != -1)
    {
        do
        {
            flag = pedirFecha(persona->fechaNac);
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

int reemplazarPersona(ArrayList* lista ,int id, EPersona *personaNueva)
{
    int ret = -1;
    int index = -1;
    EPersona* personalist = NULL;

    personalist = buscarPersona(lista, id);

    if(personalist != NULL)
    {
        index = lista->indexOf(lista, personalist);
        if (index > -1)
        {
            ret = lista->set(lista, index, personaNueva);
        }
    }

    return ret;
}
