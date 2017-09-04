#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../Bibliotecas/Funciones/utn.h"
#include "../Bibliotecas/Input/input.h"


int main()
{

//EJERCICIO 31
//Por teclado se ingresa el valor hora de un empleado.
//Posteriormente se ingresa el nombre del empleado, la antigüedad y la cantidad de horas trabajadas en el mes.
//Se pide calcular el importe a cobrar teniendo en cuenta que el total resulta de multiplicar el valor hora por la cantidad de horas trabajadas,
//hay que sumarle la cantidad de años trabajados multiplicados por $30, y al total de todas esas operaciones restarle el 13% en concepto de descuentos.
//Imprimir el recibo correspondiente con el nombre, la antigüedad, el valor hora, el total a cobrar en bruto,
//el total de descuentos y el valor neto a cobrar

    float valorHora;
    char nombre[];
    int antiguedad;
    int horasMes;
    float salarioBruto;
    float salarioNeto;

    printf("Ingrese valor hora: ");
    scanf("%f", &valorHora);

    printf("Ingrese nombre: ");


    printf("Ingrese antiguedad: ");
    scanf("%d", &antiguedad);

    printf("Ingrese horas trabajadas: ");
    scanf("%d", &horasMes);







/*
32. En una empresa se carga por teclado los siguientes datos: nombre del empleado, nacionalidad (A argentino, E -extranjero), estudios cursados (1- primaria, 2 - secundario, 3 - universitario) y antigüedad. Se pide emitir un listado con aquellos empleados que sean extranjeros, tengan estudios universitarios y tengan una antigüedad igual o mayor a 20 años y por último indicar cuantos son y qué porcentaje son respecto del total de empleados de la empresa
33. En un restaurante hay 2 mozos; al final del día su dueño entrega un plus al mozo que más clientes haya atendido, ese plus es de 1/3 de lo que facturó cada mozo. El proceso termina cuando se ingresa un número de mozo 0
34. Introducir una letra por teclado. Imprimirla cinco veces en filas consecutivas, pero en cada impresión ir desplazándola 4 columnas a la derecha
35. Hacer un que imprima los números de 0 al 100, controlando las filas y las columnas de forma tal que se visualicen en pantalla todos a la vez
36. Realizar la tabla de multiplicar de un número entre 0 y 10 de forma que se visualice de la siguiente forma: 4x1= 4 4x2= 8
37. Hacer un programa que simule el funcionamiento de un reloj digital y que permita ponerlo en hora
38. Se registran de los empleados de una empresa Número de legajo, sueldo y sexo (1 femenino y 2 masculino). Diseñar en un programa que permita informar cuantas mujeres ganan más de á 500 y cuantos hombres ganan menos de $ 400
*/


    return 0;
}
