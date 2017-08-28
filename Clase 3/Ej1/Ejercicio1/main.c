#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
1) Crear una funci�n que permita ingresar un numero al usuario y lo retorne.
Crear una funci�n que reciba el radio de un c�rculo y retorne su �rea.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule el �rea de un c�rculo cuyo radio es ingresado por el usuario.
Documentar las funciones al estilo Doxygen.
*/

float IngresarNro ();
float AreaCirculo (float radio);

int main()
{
    float radio;
    float area;

    radio = IngresarNro();
    area = AreaCirculo(radio);

    printf("\nEl area del circulo es %.2f", area);

    return 0;
}

float IngresarNro ()
{
    float nro;

    printf("\nIngrese un numero: ");
    scanf("%f", &nro);

    return nro;
}

float AreaCirculo (float radio)
{
    float area;

    area = M_PI * (radio*radio);

    return area;
}
