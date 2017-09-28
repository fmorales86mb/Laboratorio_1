#ifndef FUNCIONESESTRUCTURA_H_INCLUDED
#define FUNCIONESESTRUCTURA_H_INCLUDED
// Las esctructuras se definen fuera de las funciones, incluida el main
typedef struct
{
    int codigo;
    char nombre[50];
    float precio;
    char laboratorio[30];
}eMedicamento; // ahora lo puedo usar como tipo de dato

void cargaMedicamentos (eMedicamento listaMed[], int tam);
void mostrarMedicamentos (eMedicamento listaMed[], int tam);
void mostrarMedicamento (eMedicamento med);

#endif // FUNCIONESESTRUCTURA_H_INCLUDED
