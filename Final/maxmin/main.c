#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#define CANT 5

typedef struct
{
    int dia, mes, anio;
} Fecha;

typedef struct
{
    long int dni;
    char nombre [50];
    Fecha fechaNac;
} Persona;

void ordenarPersonas (Persona* array, int tam);
void escribirBinario (Persona* array, char* name);
char* personaGetNombre (Persona* per);
int repeticiones(char* str, char letra);

int main()
{
    FILE* archivo;
    char* nombre = "arch.txt";
    char linea[10];
    char* rosa;

//    archivo = fopen(nombre, "w");
//    fclose(archivo);

    archivo = fopen(nombre, "r");

    if(archivo != NULL)
    {

        printf("%s", fgets(linea, 10, archivo));
        rosa = fgets(linea, 10, archivo);
        printf("\n %s", rosa);
        //printf("pepepe333ppe");
    }

fclose(archivo);
    return 0;
}

void ordenarPersonas (Persona* array, int tam)
{
    int i, j;
    Persona* aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp((array+i)->nombre, (array+j)->nombre)>0)
            {
                aux = array+i;
                *(array+i) = *(array+j);
                *(array+j) = *aux;
            }
            else if(strcmp((array+i)->nombre, (array+j)->nombre)==0)
            {
                if((array+i)->dni < (array+j)->dni)
                {
                    aux = (array+i);
                    *(array+i) = *(array+j);
                    *(array+j) = *aux;
                }
            }
        }
    }
}

void escribirBinario (Persona* array, char* name)
{
    FILE* pArch;
    int auxCant;

    pArch = fopen(name, "wb");

    auxCant = fwrite(array, sizeof(Persona), CANT, pArch);
    if(auxCant!=CANT)
        printf("error");
}

char* personaGetNombre (Persona* per)
{
    char* nom = per->nombre;
    return nom;
}

int repeticiones(char* str, char letra)
{
    int i;
    int len;
    int contador = 0;

    len = strlen(str);
    for(i=0; i<len; i++)
    {
        if (*(str+i) == letra)
        {
            contador++;
        }
    }

    return contador;
}
