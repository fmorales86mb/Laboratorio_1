#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Bibliotecas/biblioStr/validacionStr.h"
#include "../../Bibliotecas/Input/input.h"

#define LAB 3
#define MED 5
#define CLI 10

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idLaboratorio;//PK
    char razonSocial[25];
    char direccion[50];
    char telefono[20];
} eLaboratorio;

typedef struct
{
    int idMedicamento;//PK
    char descripcion[50];
    float precio;
    int idLaboratorio;//FK
    int stock;
    eFecha fechaElaboracion;
    eFecha fechaVencimiento;
} eMedicamento;

typedef struct
{
    int idCliente;//
    char nombre[50];
    int idMedicamento;//FK
} eCliente;

void inicializarLaboratorios(eLaboratorio[], int);
void inicializarMedicamentos(eMedicamento[], int);
void inicializarClientes(eCliente[], int);
void mostrarMedicamentos(eMedicamento[], int);
//void mostrarClientes(eCliente[], int);
eMedicamento traerMedicamentoPorId (eMedicamento lista[], int tam, int id);
eMedicamento traerMedicamentoPorDescripcion (eMedicamento listaMedicamentos[], int sizeMed, char descripcion []);
void mostrarClientes(eCliente clientes[], int sizeCli, eMedicamento medicamentos[], int sizeMed);
void MostrarClientesConMedicamento (eCliente listaClientes[], int sizeCli, eMedicamento listaMedicamentos[], int sizeMed, int idCli);
void mostrarClientesPorMedicamento (eCliente listaClientes[], int sizeCli, eMedicamento medicamento);
void mostrarClientesPorCadaMedicamento (eCliente listaClientes[], int sizeCli, eMedicamento listaMedicamentos[], int sizeMed);
void mostrarStockPorMedicamento(eMedicamento listaMedicamentos[], int sizeMed, eMedicamento medicamento);
float totalVentas (eCliente listaCliente[], int sizeCli, eMedicamento listaMedicamentos[], int sizeMed);

int main()
{
    eLaboratorio listaLaboratorios[LAB];
    eMedicamento listaMedicamentos[MED];
    eCliente listaClientes[CLI];

    inicializarLaboratorios(listaLaboratorios, LAB);
    inicializarMedicamentos(listaMedicamentos, MED);
    inicializarClientes(listaClientes, CLI);

    printf("\t Mostrar lista de medicamentos\n\n");
    mostrarMedicamentos(listaMedicamentos, MED);
    printf("\n\n***************************************************\n\n");
/*
    // Clientes con descripción del medicamento
    printf("\n \t Mostrar clientes con su medicamento \n\n");
    mostrarClientes(listaClientes, CLI, listaMedicamentos, MED);
    MostrarClientesConMedicamento(listaClientes, CLI, listaMedicamentos, MED, -1);
    printf("\n\n***************************************************\n\n");

    // Clientes que compraron ibuprofeno
    printf("\n \t Mostrar clientes por medicamento (ibu)\n\n");
    eMedicamento medicamento = traerMedicamentoPorDescripcion(listaMedicamentos, MED, "Ibuprofeno");
    mostrarClientesPorMedicamento(listaClientes, CLI, medicamento);
    printf("\n\n***************************************************\n\n");

    // Cada medicamento y los clientes que lo compraron
    printf("\n \t Cada medicamento y los clientes que lo compraron \n\n");
    mostrarClientesPorCadaMedicamento(listaClientes, CLI, listaMedicamentos, MED);
    printf("\n\n***************************************************\n\n");

    // stock disponible para el medicamento ingresado por el usuario
    printf("\n \t Stock disponible para el medicamento ingresado por el usuario \n\n");
    char descMed[50];
    eMedicamento medicamento;
    do
    {
        int flag = getString(descMed, "Ingrese medicamento: ", "Error en el ingreso.", 1, 50);
    } while(flag ==1)
    medicamento=traerMedicamentoPorDescripcion(listaMedicamentos, MED, descMed);

    if (medicamento.idMedicamento>=0)
    {
        mostrarStockPorMedicamento(listaMedicamentos, MED, medicamento);
    }
    */
    printf("\n\n***************************************************\n\n");

    // total de ventas en $
    printf("\n \t total de ventas en $ \n\n");
    float totVentas = totalVentas(listaClientes, CLI, listaMedicamentos, MED);
    printf("\n El total de ventas es %.2f \n", totVentas);
    printf("\n\n***************************************************\n\n");

    // el o los medicamentos mas vendidos.
    printf("\n \t Medicamentos con mayor venta \n\n");

    printf("\n\n***************************************************\n\n");

    return 0;
}


void inicializarLaboratorios(eLaboratorio laboratorios[], int sizeLab)
{
    int id[]= {1,2,3};
    char razon[][30]= {"Roemers","Bago","Bayer"};
    char direccion[][30]= {"mitre 750","Belgrano 788","Sarmiento 1258"};
    char telefono[][30]= {"12345","678910","1112131415"};
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
    int id[]= {100,101,102,103,104};
    char descripcion[][30]= {"Ibuprofeno","Tafirol","Diclofenac","Bayaspirina", "Mejoralito"};
    float precio[]= {60,85,105,15,28};
    int laboratorio[]= {1,1,2,3,3,1};
    int stock[]= {3,2,3,10,0};
    eFecha elaboracion[]= {{22,9,2017},{15,2,2016},{10,6,2016},{22,9,2017},{5,10,2000}};
    eFecha vencimiento[]= {{22,9,2030},{5,12,2017},{30,8,2019},{3,12,2020},{12,8,2005}};
    int i;

    for(i=0; i<sizeMed; i++)
    {
        medicamentos[i].idMedicamento=id[i];
        strcpy(medicamentos[i].descripcion, descripcion[i]);
        medicamentos[i].precio = precio[i];
        medicamentos[i].idLaboratorio=laboratorio[i];
        medicamentos[i].stock = stock[i];
        medicamentos[i].fechaElaboracion=elaboracion[i];
        medicamentos[i].fechaVencimiento=vencimiento[i];

    }
}

void inicializarClientes(eCliente clientes[], int sizeCli)
{
    int id[]= {111,222,333,444,555,666,777,888,999,101010};
    char nombre[][30]= {"Geronimo","Adalberto","Inocencia","Felipe","Lucrecia","Ermenegildo","Efigenia","Dora","Anastacia","Armando"};
    int medicamento[]= {104,100,101,101,101,102,103,101,101,100};
    int i;

    for(i=0; i<sizeCli; i++)
    {
        clientes[i].idCliente=id[i];
        strcpy(clientes[i].nombre, nombre[i]);
        clientes[i].idMedicamento=medicamento[i];
    }
}

void mostrarMedicamentos(eMedicamento medicamentos[], int sizeMed)
{
    int i;
    printf("ID\t%10s\tPRECIO\tLAB\tSTOCK\tF. ELAB\t\tF.VTO\n", "DESCRIPCION");
    for(i=0; i<sizeMed; i++)
    {
        printf("%d\t%10s\t%.2f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\n", medicamentos[i].idMedicamento
               ,medicamentos[i].descripcion, medicamentos[i].precio, medicamentos[i].idLaboratorio
               ,medicamentos[i].stock, medicamentos[i].fechaElaboracion.dia, medicamentos[i].fechaElaboracion.mes
               ,medicamentos[i].fechaElaboracion.anio,medicamentos[i].fechaVencimiento.dia
               ,medicamentos[i].fechaVencimiento.mes,medicamentos[i].fechaVencimiento.anio);
    }

}

void mostrarClientes(eCliente clientes[], int sizeCli, eMedicamento medicamentos[], int sizeMed)
{
    int i;
    eMedicamento medicamento;
    int idMed;
    printf("ID\t%10s\tMEDICAMENTO\n", "NOMBRE");
    for(i=0; i<sizeCli; i++)
    {
        idMed =clientes[i].idMedicamento;
        medicamento = traerMedicamentoPorId(medicamentos, sizeMed, idMed);
        printf("%d\t%10s\t%s (%d)\n", clientes[i].idCliente, clientes[i].nombre, medicamento.descripcion,idMed);
    }
}

eMedicamento traerMedicamentoPorId (eMedicamento lista[], int tam, int id)
{
    eMedicamento medicamento = {-1, "", 0, 0,0,{},{}};
    int i;

    for (i=0; i<tam; i++)
    {
        if (lista[i].idMedicamento == id)
        {
            medicamento=lista[i];
        }
    }
    return medicamento;
}

eMedicamento traerMedicamentoPorDescripcion (eMedicamento listaMedicamentos[], int sizeMed, char descripcion []) // validar str descripcon
{
    eMedicamento medicamento = {-1, "", 0, 0,0,{},{}};

    int indiceMed;

    for (indiceMed = 0; indiceMed<sizeMed; indiceMed++)
    {
        if (strcmp(listaMedicamentos[indiceMed].descripcion, descripcion)==0)
        {
            medicamento = listaMedicamentos[indiceMed];
            break;
        }
    }

    return medicamento;
}

// idCli =-1 todos;
void MostrarClientesConMedicamento (eCliente listaClientes[], int sizeCli, eMedicamento listaMedicamentos[], int sizeMed, int idCli)
{
    int indiceCli;
    int indiceMed;

    for (indiceCli = 0; indiceCli <sizeCli; indiceCli++)
    {
        if(idCli==-1)// muestro todos
        {
            for(indiceMed = 0; indiceMed<sizeMed; indiceMed++)
            {
                if(listaClientes[indiceCli].idMedicamento == listaMedicamentos[indiceMed].idMedicamento)
                {
                    printf(" %s \t %s \n", listaClientes[indiceCli].nombre, listaMedicamentos[indiceMed].descripcion);
                }
            }
        }
    }
}

void mostrarClientesPorMedicamento (eCliente listaClientes[], int sizeCli, eMedicamento medicamento)
{
    int indiceCli;

    printf("\n \t Clientes que compraron el medicamento %s \n\n", medicamento.descripcion);

    for (indiceCli = 0; indiceCli<sizeCli; indiceCli++)
    {
        if (listaClientes[indiceCli].idMedicamento == medicamento.idMedicamento)
        {
            printf(" %s\n", listaClientes[indiceCli].nombre);
        }
    }
}

void mostrarClientesPorCadaMedicamento (eCliente listaClientes[], int sizeCli, eMedicamento listaMedicamentos[], int sizeMed)
{
    int indiceMed;

    for(indiceMed=0; indiceMed<sizeMed; indiceMed++)
    {
        mostrarClientesPorMedicamento(listaClientes, sizeCli, listaMedicamentos[indiceMed]);
    }
}

void mostrarStockPorMedicamento(eMedicamento listaMedicamentos[], int sizeMed, eMedicamento medicamento)
{
    int indiceMed;

    for(indiceMed = 0; indiceMed<sizeMed; indiceMed++)
    {
        if (listaMedicamentos[indiceMed].idMedicamento == medicamento.idMedicamento)
        {
            printf("Stock de %s: %d \n", listaMedicamentos[indiceMed].descripcion, listaMedicamentos[indiceMed].stock);
            break;
        }
    }
}

float totalVentas (eCliente listaCliente[], int sizeCli, eMedicamento listaMedicamentos[], int sizeMed)
{
    int indiceCli;
    float totalVentas=0;
    eMedicamento medicamento = {-1, "", 0, 0,0,{},{}};

    for(indiceCli = 0; indiceCli<sizeCli; indiceCli++)
    {
        medicamento = traerMedicamentoPorId(listaMedicamentos, sizeMed, listaCliente[indiceCli].idMedicamento);
        totalVentas += medicamento.precio;
    }

    return totalVentas;
}

void mostrarMedicamentosMasVendidos (eMedicamento listaMedicamentos[], eCliente listaClientes[], int sizeMed, int sizeCli)
{

}
