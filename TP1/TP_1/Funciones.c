#include <stdio.h>
#include <stdlib.h>

// Sumar

float Sumar (float nro1, float nro2);

float Sumar (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 + nro2;

    return resultado;
}

// Restar

float Restar (float nro1, float nro2);

float Restar (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 - nro2;

    return resultado;
}

// Multiplicar

float Multiplicar (float nro1, float nro2);

float Multiplicar (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 * nro2;

    return resultado;
}

// Dividir

float Dividir (float nro1, float nro2);

float Dividir (float nro1, float nro2)
{
    float resultado;

    if (nro2 != 0)
    {
        resultado = nro1 / nro2;
    }

    return resultado;
}
