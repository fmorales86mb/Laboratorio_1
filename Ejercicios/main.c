#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../Bibliotecas/Funciones/utn.h"
#include "../Bibliotecas/Input/input.h"


int main()
{

//EJERCICIO 32
//En una empresa se carga por teclado los siguientes datos:
//nombre del empleado, nacionalidad (A argentino, E -extranjero),
//estudios cursados (1- primaria, 2 - secundario, 3 - universitario) y antigüedad.
//Se pide emitir un listado con aquellos empleados que sean extranjeros, tengan estudios universitarios
//y tengan una antigüedad igual o mayor a 20 años y por último indicar cuantos son y qué porcentaje son respecto del total de empleados de la empresa
    #define TAM 50

    char empleado[TAM][2][2][3];
    char nombre[TAM];
    char nacionalidad;
    int estudios;
    int antiguedad;
    char listadoEmpleados[3][TAM];
    int cantidad = 0;
    int porcentaje;
    int flag;
    char seguir = 's';

    do
    {
        //Nombre empleado
        do
        {
            flag = getString(nombre, "Ingrese nombre del empleado: ", "Nombre invalido.", 2, TAM);
        }while (flag!=0);

        // Nacionalidad
        do
        {
            flag = getChar(&nacionalidad, "Nacionalidad (A argentino, E extranjero): ", "Nacionalidad invalida.", 'a', 'e');
        } while (flag!=0);

        //Estudios
    }





/*
33. En un restaurante hay 2 mozos; al final del día su dueño entrega un plus al mozo que más clientes haya atendido, ese plus es de 1/3 de lo que facturó cada mozo. El proceso termina cuando se ingresa un número de mozo 0
34. Introducir una letra por teclado. Imprimirla cinco veces en filas consecutivas, pero en cada impresión ir desplazándola 4 columnas a la derecha
35. Hacer un que imprima los números de 0 al 100, controlando las filas y las columnas de forma tal que se visualicen en pantalla todos a la vez
36. Realizar la tabla de multiplicar de un número entre 0 y 10 de forma que se visualice de la siguiente forma: 4x1= 4 4x2= 8
37. Hacer un programa que simule el funcionamiento de un reloj digital y que permita ponerlo en hora
38. Se registran de los empleados de una empresa Número de legajo, sueldo y sexo (1 femenino y 2 masculino). Diseñar en un programa que permita informar cuantas mujeres ganan más de á 500 y cuantos hombres ganan menos de $ 400
*/


    return 0;
}
