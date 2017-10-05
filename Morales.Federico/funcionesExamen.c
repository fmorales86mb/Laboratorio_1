#include "funcionesExamen.h"
#define STR 50

int indiceUsLibre (eUsuario listaUs[], int size)
{
    int i;
    int indice = -1;
    for(i=0; i<size;i++)
    {
        if (listaUs[i].estado == -1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void iniListaUs (eUsuario lista[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        lista[i].estado = -1;
        lista[i].id=0;
    }
}

int buscarIdUsuariolibre (eUsuario lista[], int size)
{
    int max;
    int i;
    int id =-1;

    for(i=0; i<size; i++)
    {
        if (i==0 || lista[i].id>max)
        {
            max = lista[i].id;
        }
    }

    id=max+1;

    return id;
}

void altaUsuario (eUsuario listaUs[], int sizeUs)
{
    int indiceLibre;
    eUsuario usuario;
    int id;

    indiceLibre = indiceUsLibre(listaUs, sizeUs);
    id = buscarIdUsuariolibre(listaUs, sizeUs);

    usuario = cargarUsuario(id);
    listaUs[indiceLibre] = usuario;
}

eUsuario cargarUsuario (int id)
{
    int flag;
    char nombre[STR];
    char pas[STR];
    eUsuario usuario;

    do
    {
        flag = getString(nombre, "Ingrese Nombre: ", "Nombre invalido.", 1, STR);
    }while(flag==-1);

    do
    {
        flag = getString(pas, "Ingrese Password: ", "Password invalido", 1, STR);
    }while (flag==-1);

    usuario.estado = 0;
    usuario.id = id;
    strcpy(usuario.nombre, nombre);
    strcpy(usuario.pass, pas);

    return usuario;
}

void iniListaPR(eProducto lista[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        lista[i].estado=-1;
        lista[i].id = 0;
        lista[i].idUsuario = 0;
        strcpy(lista[i].nombre, "");
        lista[i].precio = -1;
        lista[i].stock = 0;
        lista[i].ventas =0;
    }
}

int indicePrLibre (eProducto lista[], int size)
{
    int i;
    int indice = -1;
    for(i=0; i<size;i++)
    {
        if (lista[i].estado == -1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarIdProductolibre (eProducto lista[], int size)
{
    int max;
    int i;
    int id =-1;

    for(i=0; i<size; i++)
    {
        if (i==0 || lista[i].id>max)
        {
            max = lista[i].id;
        }
    }

    id=max+1;

    return id;
}

eProducto cargarProducto (int id, int idUs)
{
    int flag;
    char nombre[STR];
    //float precio =0;
    int precio;
    int estado=0;
    int stock;
    int ventas = 0;
    eProducto producto;

    do
    {
        flag = getString(nombre, "Ingrese Nombre del producto: ", "Nombre invalido.", 1, STR);
    }while(flag==-1);

    do
    {
        flag = getInt(&precio, "Ingrese precio: ", "precio invalido.", 0, 1000);
        //flag = getFloat(&precio, "Ingrese precio: ", "precio invalido.", 1.0, 1000.0 );
    }while (flag==-1);

    do
    {
        flag = getInt(&stock, "Ingrese stock: ", "stock invalido.", 1, 1000);
    }while (flag==-1);

    producto.estado = estado;
    producto.id = id;
    producto.idUsuario = idUs;
    strcpy(producto.nombre, nombre);
    producto.precio = precio;
    producto.stock = stock;
    producto.ventas = ventas;

    return producto;
}

void altaProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs )
{
    int indiceLibre;
    eProducto producto;
    int id;
    int flag;
    int idUs;

    do
    {
        idUs = pedirIdUsuario(listaUs, sizeUs);
    }while(idUs == -1);

    indiceLibre = indicePrLibre(listaPr, sizePr);
    id = buscarIdProductolibre(listaPr, sizePr);

    producto = cargarProducto(id, idUs);
    listaPr[indiceLibre] = producto;
}

int pedirIdUsuario (eUsuario lista[], int size)
{
    int flag;
    char nombre[STR];
    char pas[STR];
    int idUs=-1;

    do
    {
        flag = getString(nombre, "Ingrese Nombre usuario: ", "Nombre invalido.", 1, STR);
    }while(flag==-1);

    do
    {
        flag = getString(pas, "Ingrese Password: ", "Password invalido.", 1, STR);
    }while(flag==-1);

    idUs = buscarUsuario1(nombre, pas, lista, size);

    return idUs;
}

int buscarUsuario1(char nombre[], char pass[], eUsuario lista[], int size )
{
    int i;
    int id=-1;

    for (i=0; i<size; i++)
    {
        if (strcmp(lista[i].nombre, nombre)==0)
        {
            if (strcmp(lista[i].pass, pass)==0)
            {
                id=lista[i].id;
                break;
            }
        }
    }

    return id;
}

void harcodearUsuario (eUsuario lista[], int size)
{
    int id[5]={1,2,3,4,5};
    int estado[5]={0,0,0,0,0};
    char nombre[][STR]={"nom1", "nom2","nom3","nom4","nom5"};
    char pass[][STR]={"pnom1", "pnom2","pnom3","pnom4","pnom5"};

    int i;
    for (i=0; i<size; i++)
    {
        lista[i].id=id[i];
        lista[i].estado = estado[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].pass, pass[i]);
    }
}

void harcodearProducto (eProducto lista[], int size)
{
    int id[5]={1,2,3,4,5};
    int estado[5]={0,0,0,0,0};
    char nombre[][STR]={"prnom1", "prnom2","prnom3","prnom4","prnom5"};
    int idUsuario [5]={2,2,1,4,3};
    //float precio;
    int precio [5]={3,2,6,4,12};
    int stock[5]={2,3,5,6,45};
    int ventas[5]={1,2,3,4,6};

    int i;
    for (i=0; i<size; i++)
    {
        lista[i].id=id[i];
        lista[i].estado = estado[i];
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].idUsuario = idUsuario[i];
        lista[i].precio = precio[i];
        lista[i].stock = stock[i];
        lista[i].ventas = ventas[i];
    }
}

void listarPublicaciones (eProducto listaPr [], eUsuario listaUs [],int sizePr, int sizeUs)
{
    int i;
    int indP;
    char nomUs[STR];

    for(indP=0; indP<sizePr; indP++)
    {
        if (listaPr[i].estado==0)
        {
            for(i=0; i<sizeUs; i++)
            {
                if(listaUs[i].id == listaPr[indP].idUsuario)
                {
                    strcpy(nomUs,listaUs[i].nombre);
                    break;
                }
            }

            printf("\n %d \t %s \t %d \t %d \t %d \t %s \n",
                   listaPr[indP].id,
                   listaPr[indP].nombre,
                   listaPr[indP].precio,
                   listaPr[indP].ventas,
                   listaPr[indP].stock,
                   nomUs);
        }
    }
}





/*
void strToInt (char mje[], char emje[])
{
    int salida = -1;
	char dato[2000];
    int soloNum;
    int entreVal;
    int numero;

    printf("\n%s", message);
    fflush( stdin );
    gets(dato);
    soloNum = soloNumeros(dato)

    if (soloNum==0)
    {
        numero = aito(dato;)

    {
}
*/

