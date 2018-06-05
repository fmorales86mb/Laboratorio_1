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
       returnAux->estado = ACTIVO;
    }
    return returnAux;
}

int buscarPersona (ArrayList* lista, int id)
{
    int i;
    int index = -1;
    EPersona* elemento;

    for(i=0; i<lista->len(lista); i++)
    {
        elemento = lista->get(lista, i);
        if(elemento->estado == ACTIVO && elemento->id == id)
        {
            index = i;
            break;
        }
    }

    return index;
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

int buscarPersonaPorDNI(ArrayList* lista, long int dni)
{
    int i;
    int index = -1;
    EPersona* elemento;

    for(i=0; i<lista->len(lista); i++)
    {
        elemento = lista->get(lista, i);
        if(elemento->estado == ACTIVO && elemento->dni == dni)
        {
            index = i;
            break;
        }
    }

    return index;
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
            printf("\nFecha de nacimiento:\n");
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

    personalist = lista->get(lista, buscarPersona(lista, id));

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

int altaPersona(ArrayList *lista)
{
    int retorno = 1;
    EPersona* elemento = NULL;
    elemento = newEPersona();

    if (elemento!=NULL)
    {
        if (pedirPersona(elemento) != 0)
        {
            elemento->id = generarIdPersona(lista);
            lista->add (lista, elemento);
        }
        else
        {
            retorno = 0;
        }
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int pisarArchivoCSVPersona(ArrayList *lista, char* nombre, int sizeOfStruct)
{
    int i;
    //int cant;
    int retorno = 0;
    FILE *archivo;
    EPersona* elemento= NULL;

    archivo = fopen(nombre, "w");

    if (archivo == NULL)
    {
        printf("\n El archivo no puede ser abierto.\n");
        retorno = 0;
    }
    else
    {
        retorno = 1;

        for(i=0; i<lista->len (lista); i++)
        {
            elemento = lista->get(lista, i);
            // con comas o pto y coma. El Excel separa las columnas con pto y coma.
            fprintf(archivo, "%d;%s;%s;%ld;%d/%d/%d\n",elemento->id, elemento->nombre, elemento->apellido, elemento->dni,
                    elemento->fechaNac->anio, elemento->fechaNac->mes, elemento->fechaNac->dia);
        }
    }

    fclose(archivo);

    return retorno;
}

void listarPersonas(ArrayList* lista)
{
    EPersona *elemento;
    int i;

    //lista->sort(lista, comparaElementos, 0);
    printf("\n ID   Apellido     Nombre     DNI        Fecha Nacimiento\n\n");

    for(i=0; i<lista->len(lista); i++) {
        elemento = lista->get(lista, i);
        if (elemento->estado == ACTIVO)
        {
            printf("   %d      %s        %s    %ld  %d/%d/%d \n", elemento->id, elemento->apellido, elemento->nombre, elemento->dni,
               elemento->fechaNac->anio, elemento->fechaNac->mes, elemento->fechaNac->dia);
        }

    }

    printf("\n");
}

int pedirIdPersona ()
{
    int id;
    int flag;

    do
    {
        flag = pedirInt(&id, " Ingrese ID: ", " ID invalido.", 1, 10000);
    }while (flag == -1);

    return id;
}

int bajaLogicaPersona (ArrayList* lista, int index)
{
    int ret = 0;
    EPersona* elemento;

    elemento = lista->get(lista, index);

    if (elemento != NULL)
    {
        elemento->estado = INACTIVO;
        ret = 1;
    }

    return ret;
}

void bajaPersona(ArrayList* lista)
{
    int id = 0;
    int index = -1;

    id = pedirIdPersona();
    index = buscarPersona(lista, id);

    if (bajaLogicaPersona(lista, index))
    {
        printf("\nEl elemento se dio de baja correctamente\n");
        system("pause");
    }
    else
    {
        printf("\nError: Elemento no encontrado o lista inexistente.\n");
        system("pause");
    }
}

void mostrarPersona(EPersona* elemento)
{
    if (elemento != NULL)
    {
        printf("\nNombre: %s", elemento->nombre);
        printf("\nApellido: %s", elemento->apellido);
        printf("\nDNI: %ld", elemento->dni);
        printf("\nFecha Nacimiento: %d/%d/%d", elemento->fechaNac->anio, elemento->fechaNac->mes, elemento->fechaNac->dia);
        printf("\nEstado: %d \n", elemento->estado);
    }
}

void modificarPersona(ArrayList* lista)
{
    int id = 0;
    int index = -1;

    id = pedirIdPersona();
    index = buscarPersona(lista, id);
    if (index>-1)
    {
        EPersona* elemento = newEPersona();
        mostrarPersona(lista->get(lista, index));

        if(elemento != NULL)
        {
            if (pedirPersona(elemento))
            {
                elemento->id = id;
                if(!(lista->set(lista, index, elemento)))
                {
                    printf("\nElemento modificado.\n");
                }
                else
                {
                    printf("\nError: Elemento no encontrado o lista inexistente.\n");
                }
            }
        }
    }
    else
    {
        printf("\nID no existe.\n");
    }
}
