#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Creo el vector.
    int numeros [5];
    int suma = 0;
    int i; //Hay que declararlo afuera.

    // Pido al usuario que ingrese datos.

    // Acceso aleatorio.
    //numeros[3]=45;
    //numeros[2]=55;

    // Carga secuencial: cargo en orden los elementos hasta el final.
    // Utilizamos un for ya que conozco la cantidad de elementos y por lo tanto las iteraciones.

    for(i=0; i<5; i++)
    {
        // i es la variable de control, nos indica el indice.
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]); // La mascara del vector es la del tipo de dato.
        // &numeros[i] me pasa la direccion de memoria de ese elemento del vector.

    }

    for (i=0; i<5; i++)
    {
        suma += numeros[i];
    }

    printf("\nSuma = %d", suma);

    // Estructura repetitiva para mostrar.
    for (i=0; i<5; i++)
    {
        printf("\nIndice %d, ", i);
        printf("valor %d, ", numeros[i]);
        printf(" %d", &numeros[i]);
    }

    printf("\n\n%d", &numeros);
    // numeros es un puntero que apunta al primer elemento del vector.
    // Para avanzar hace 4 (bytes) multiplicado por el nro de indice.

    return 0;
}
