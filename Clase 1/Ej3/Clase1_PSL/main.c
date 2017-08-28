#include <stdio.h>
#include <stdlib.h>
/*
3) Agregar al siguiente programa [DESCARGAR], la funcionalidad subrayada.

Limpie la pantalla
Solicite dos valores numéricos al usuario distintos de cero
Asigne a las variables numero1 y numero2 los valores obtenidos
Realice la resta de dichas variables
Muestre el resultado por pantalla
Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor
Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero
*/

int main(int argc, char *argv[]) {

	int a;
	int b;
	int resultado;

	system("cls");

	printf("\nIngrese 1 numero: ");
	scanf("%d",&a);

	while (a==0)
    {
        printf("Reingrese nro1 distinto a 0: ");
        scanf("%d", &a);
    }

	printf("\nIngrese 2 numero: ");
	scanf("%d",&b);

	while (b==0)
    {
        printf("Reingrese nro2 distinto a 0: ");
        scanf("%d", &b);
    }

	resultado=a-b;

	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n",resultado);
	if(resultado>0){
        printf("\nResultado positivo \n");
	}
	if(resultado<0){
        printf("\nResultado negativo \n");
	}
	printf("______________________________________\n\n\n\n");


	return 0;
}
