#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

// Las esctructuras se definen fuera de las funciones, incluida el main
typedef struct
{
    int codigo;
    char nombre[50];
    float precio;
    char laboratorio[30];
}eMedicamento; // ahora lo puedo usar como tipo de dato

int main()
{
    // ESTRUCTURAS

    // defino variable medic1
    eMedicamento medicamento1;// uso eMedicamento como tipo de dato.
    eMedicamento medicamento2;
    eMedicamento medicamento3 = {206, "ibuprofeno", 120.50, "labo3"}; // cargar por EXTENCION o HARCODEAR

    // asigno valores
    medicamento1.codigo = 701; // asigno valor al codigo de la variable med1.
    medicamento1.precio = 105.4;
    strcpy(medicamento1.nombre, "aspirina"); //para asignar una cadena de car se usa strcpy
    strcpy(medicamento1.laboratorio, "Bahgo");


    medicamento2.codigo = 601;
    medicamento2.precio = 10.4;
    strcpy(medicamento2.nombre, "penicilina");
    strcpy(medicamento2.laboratorio, "Bayer");

    //muestro por pantalla
    printf("%d\t%.2f\t%s\t%s\n",
           medicamento1.codigo,
           medicamento1.precio,
           medicamento1.nombre,
           medicamento1.laboratorio);

    printf("%d\t%.2f\t%s\t%s\n",
           medicamento2.codigo,
           medicamento2.precio,
           medicamento2.nombre,
           medicamento2.laboratorio);

    printf("%d\t%.2f\t%s\t%s\n",
           medicamento3.codigo,
           medicamento3.precio,
           medicamento3.nombre,
           medicamento3.laboratorio);

    return 0;
}
