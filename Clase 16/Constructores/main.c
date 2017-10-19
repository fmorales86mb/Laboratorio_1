#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int edad;
    char nombre[15];
    char color[15];
} eCaballo;


eCaballo* newCaballo();//Constructor por defecto
void mostrarCaballo(eCaballo*);

int main()
{

    eCaballo* miCaballo;


    miCaballo = newCaballo();
    if(miCaballo!=NULL)
    {
        miCaballo->edad = 14;
        strcpy(miCaballo->color,"Azul");
        strcpy(miCaballo->nombre,"Twister");
        mostrarCaballo(miCaballo);
    }





    return 0;
}
eCaballo* newCaballo()
{
    eCaballo* miCaballo;
    miCaballo = (eCaballo*) malloc(sizeof(eCaballo));
    return miCaballo;
}
void mostrarCaballo(eCaballo* caballo)
{
    printf("%s--%d--%s\n", caballo->nombre, caballo->edad, caballo->color);
}
