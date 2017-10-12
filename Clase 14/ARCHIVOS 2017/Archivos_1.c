#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* miArchivo;

    char palabra[50]="por defecto";
    int numero=123;
    int otro;

    miArchivo = fopen("prueba.txt","w");

    fprintf(miArchivo,"%d",numero);

    fclose(miArchivo);

    miArchivo = fopen("prueba.txt","r");
    if(miArchivo==NULL)
    {
        printf("Archivo no encontrado!!!");
    }
    else
    {
        fgets(palabra,50,miArchivo);
        fclose(miArchivo);
        puts(palabra);
        otro = atoi(palabra);

        otro++;
        printf("Incrementado %d", otro);
    }







}
