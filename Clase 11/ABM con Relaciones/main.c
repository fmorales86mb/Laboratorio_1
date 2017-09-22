#include <stdio.h>
#include <stdlib.h>

#define LAB 3
#define MED 5
#define CLI 10

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int idLaboratorio;//PK
    char razonSocial[25];
    char direccion[50];
    char telefono[20];
}eLaboratorio;

typedef struct{
    int idMedicamento;//PK
    char descripcion[50];
    float precio;
    int idLaboratorio;//FK
    int stock;
    eFecha fechaElaboracion;
    eFecha fechaVencimiento;
}eMedicamento;

typedef struct{
    int idCliente;
    char nombre[50];
    int idMedicamento;//FK
}eCliente;

void inicializarLaboratorios(eLaboratorio[], int);
void inicializarMedicamentos(eMedicamento[], int);
void inicializarClientes(eCliente[], int);
void mostrarLaboratorios (eLaboratorio lista[], int tam);

int main()
{
    eLaboratorio listaLaboratorios[LAB];
    eMedicamento listaMedicamentos[MED];
    //eCliente listaClientes[CLI];
    inicializarLaboratorios(listaLaboratorios, LAB);
    mostrarLaboratorios(listaLaboratorios, LAB);

    int i;
    for(i=0; i<LAB; i++)
    {
        printf("Razon social: %s\n", listaLaboratorios[i].razonSocial);
        printf("Direccion: %s\n", listaLaboratorios[i].direccion);
        printf("Telefono: %s\n", listaLaboratorios[i].telefono);
    }

    return 0;
}

void inicializarLaboratorios(eLaboratorio laboratorios[], int sizeLab)
{
    int id[]={1,2,3};
    char razon[][30]={"Roemers","Bago","Bayer"};
    char direccion[][30]={"mitre 750","Belgrano 788","Sarmiento 1258"};
    char telefono[][30]={"12345","678910","1112131415"};
    int i;

    for(i=0; i<sizeLab; i++)
    {
        laboratorios[i].idLaboratorio=id[i];
        strcpy(laboratorios[i].razonSocial, razon[i]);
        strcpy(laboratorios[i].direccion, direccion[i]);
        strcpy(laboratorios[i].telefono, telefono[i]);
    }
}

void inicializarMedicamentos(eMedicamento medicamentos[], int sizeMed)
{
     int id[]={1,2,3,4,5};
    char descripcion[][50]={"desc1","desc2","desc3","desc4","desc5"};
    float precio []={1.2,1.3,2.5,5.6,6.4};
    int labo[]={1,2,3,3,2};
    int stock[]={12,35,54,61,12};
    eFecha elaboracion ={02,05,2017};
    eFecha vencimiento ={12,07,2019};
    int i;

    for(i=0; i<sizeMed; i++)
    {
        medicamentos[i].idMedicamento=id[i];
        strcpy(medicamentos[i].descripcion, descripcion[i]);
        medicamentos[i].precio=precio[i];
        medicamentos[i].idLaboratorio = labo[i];
        medicamentos[i].stock = stock[i];
        medicamentos[i].fechaElaboracion = elaboracion;
        medicamentos[i].fechaVencimiento = vencimiento;
        //medicamentos[i].fechaElaboracion.dia = elaboracion.dia;
        //medicamentos[i].fechaElaboracion.mes = elaboracion.mes;
       // medicamentos[i].fechaElaboracion.anio = elaboracion.anio;
       // medicamentos[i].fechaVencimiento.dia = vencimiento.dia;
       // medicamentos[i].fechaVencimiento.mes = vencimiento.mes;
        //medicamentos[i].fechaVencimiento.anio = vencimiento.anio;
    }
}
/*
void inicializarClientes(eCliente clientes[], int sizeCli)
{
     int id[]={1,2,3};
    char razon[][30]={"Roemers","Bago","Bayer"};
    char direccion[][30]={"mitre 750","Belgrano 788","Sarmiento 1258"};
    char telefono[][30]={"12345","678910","1112131415"};
    int i;

    for(i=0; i<sizeCli; i++)
    {
        laboratorios[i].idLaboratorio=id[i];
        strcpy(laboratorios[i].razonSocial, razon);
        strcpy(laboratorios[i].direccion, direccion);
        strcpy(laboratorios[i].telefono, telefono);
    }
}
*/

void mostrarLaboratorios (eLaboratorio lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Razon social: %s\n", lista[i].razonSocial);
        printf("Direccion: %s\n", lista[i].direccion);
        printf("Telefono: %s\n", lista[i].telefono);
    }
}
