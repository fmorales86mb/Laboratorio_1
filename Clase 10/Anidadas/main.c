#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    char calle[50];
    int numero;
    char localidad[50];
    char provincia[50];

}eLocacion;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int dni;
    char nombre[50];
    int edad;
    char estadoCivil;

    eLocacion direccion;
    eFecha fechaNacimiento;
    eFecha fechaInicioActividades;


}ePersona;

typedef struct
{
    int dni;
    char nombre[50];
    int edad;

    eLocacion direccion;
    eFecha fechaNacimiento;
    eFecha fechaIngreso;


}eAlumno;

eFecha cargarFecha(int dia, int mes, int anio);

int main()
{
    ePersona miPersona;

    eFecha miFecha;



    miPersona.dni = 30333333;

    strcpy(miPersona.direccion.calle,"Av. Mitre");



    miPersona.fechaNacimiento=cargarFecha(20,10,1987);



    printf("%d--%s--%d/%d/%d", miPersona.dni,miPersona.direccion.calle,miPersona.fechaNacimiento.dia,miPersona.fechaNacimiento.mes,miPersona.fechaNacimiento.anio);


    return 0;
}

eFecha cargarFecha(int dia, int mes, int anio)
{
    eFecha miFecha;
     miFecha.dia=dia;
    miFecha.mes=mes;
    miFecha.anio=anio;

    return miFecha;
}
