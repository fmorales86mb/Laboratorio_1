#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcABM.h"

void mostrarMedicamentos (eMedicamento medicamentos[], int size)
{
    int i;

    printf("\n\tMedicamentos\n\n");
    for (i=0; i<size; i++)
    {
        printf(" %s \t %.2f \n", medicamentos[i].descripcion, medicamentos[i].precio);
    }
}

void mostrarClientes (eCliente clientes[], int size)
{
    int i;

    printf("\n\tClientes\n\n");
    for(i=0; i<size; i++)
    {
        printf(" %s\n", clientes[i].nombre);
    }
}

void inicializarClienteMedicamento (eClienteMedicamento listaVentas[], int sizeVentas)
{
    int idCli []={111, 222, 333, 555, 222};
    int idMed []={100, 100, 104, 103, 104};
    int cant []={5,1,2,4,5};

    int i;
    for(i=0; i<sizeVentas; i++)
    {
        listaVentas[i].idCliente = idCli[i];
        listaVentas[i].idMedicamento = idMed[i];
        listaVentas[i].cantidad = cant[i];
    }
}

void inicializarMedicamentos(eMedicamento medicamentos[], int sizeMed)
{

    int id[]= {100,101,102,103,104};
    char descripcion[][30]= {"Ibuprofeno","Tafirol","Diclofenac","Bayaspirina", "Mejoralito"};
    float precio[]= {60,85,105,15,28};
    int laboratorio[]= {1,1,2,3,3,1};
    //int stock[]= {3,2,3,10,0};
    //eFecha elaboracion[]= {{22,9,2017},{15,2,2016},{10,6,2016},{22,9,2017},{5,10,2000}};
    //eFecha vencimiento[]= {{22,9,2030},{5,12,2017},{30,8,2019},{3,12,2020},{12,8,2005}};

    int i;
    for(i=0; i<sizeMed; i++)
    {
        medicamentos[i].idMedicamento=id[i];
        strcpy(medicamentos[i].descripcion, descripcion[i]);
        medicamentos[i].precio = precio[i];
        medicamentos[i].idLaboratorio=laboratorio[i];
        //medicamentos[i].stock = stock[i];
        //medicamentos[i].fechaElaboracion=elaboracion[i];
        //medicamentos[i].fechaVencimiento=vencimiento[i];
    }
}

void inicializarClientes(eCliente clientes[], int sizeCli)
{
    int id[]= {111,222,333,444,555,666,777,888,999,101010};
    char nombre[][30]= {"Geronimo","Adalberto","Inocencia","Felipe","Lucrecia","Ermenegildo","Efigenia","Dora","Anastacia","Armando"};
    //int medicamento[]= {104,100,101,101,101,102,103,101,101,100};

    int i;
    for(i=0; i<sizeCli; i++)
    {
        clientes[i].idCliente=id[i];
        strcpy(clientes[i].nombre, nombre[i]);
        //clientes[i].idMedicamento=medicamento[i];
    }
}

void inicializarLaboratorios(eLaboratorio laboratorios[], int sizeLab)
{
    int id[]= {1,2,3};
    char razon[][30]= {"Roemers","Bago","Bayer"};
    //char direccion[][30]= {"mitre 750","Belgrano 788","Sarmiento 1258"};
    //char telefono[][30]= {"12345","678910","1112131415"};

    int i;
    for(i=0; i<sizeLab; i++)
    {
        laboratorios[i].idLaboratorio=id[i];
        strcpy(laboratorios[i].razonSocial, razon);
        //strcpy(laboratorios[i].direccion, direccion);
        //strcpy(laboratorios[i].telefono, telefono);
    }
}

int clientePorNombre (eCliente clientes[], int size, char nombre[])
{
    int id;
    int i;

    for (i=0; i<size; i++)
    {
        if (strcmp(clientes[i].nombre, nombre) == 0)
        {
            id = clientes[i].idCliente;
            break;
        }
    }
    return id;
}

eCliente clientePorID (eCliente clientes[], int size, int id)
{
    eCliente cliente = {0};
    int i;

    for (i=0; i<size; i++)
    {
        if (clientes[i].idCliente == id)
        {
            strcpy(cliente.nombre, clientes[i].nombre);
            cliente.idCliente = id;
            break;
        }
    }

    return cliente;
}

int medicamentoPorNombre (eMedicamento medicamentos[], int size, char nombre[])
{
    int id;
    int i;

    for(i=0; i<size; i++)
    {
        if(strcmp(medicamentos[i].descripcion, nombre) == 0)
        {
            id=medicamentos[i].idMedicamento;
            break;
        }
    }

    return id;
}

eMedicamento medicamentoPorId (eMedicamento medicamentos[], int size, int id)
{
    eMedicamento medicamento = {0};
    int i;

    for(i=0; i<size; i++)
    {
        if(medicamentos[i].idMedicamento == id)
        {
            strcpy(medicamento.descripcion, medicamentos[i].descripcion);
            medicamento.idLaboratorio = medicamentos[i].idLaboratorio;
            medicamento.idMedicamento = id;
            medicamento.precio = medicamentos[i].precio;
            break;
        }
    }

    return medicamento;
}

void mostrarMedicamentosPorCliente (int idCli, eClienteMedicamento listaVentas [], int size)
{

}




