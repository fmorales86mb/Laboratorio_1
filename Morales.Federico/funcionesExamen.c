#include <stdio.h>
#include <stdlib.h>
#include "funcionesExamen.h"
#include "input.h"
#include "bibStrValidacion.h"

#define US 10
#define STR 50
#define PR 20
#define VE 200


// USUARIOS
void harcodearUsuario (eUsuario lista[])
{
    int id[5]={1,2,3,4,5};
    int estado[5]={0,0,0,0,0};
    char nombre[][STR]={"noma", "nomb","nomc","nomd","nome"};
    char pass[][STR]={"pnom1", "pnom2","pnom3","pnom4","pnom5"};

    int i;
    for (i=0; i<5; i++)
    {
        lista[i].id=id[i];
        lista[i].estado = estado[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].pass, pass[i]);
    }
}

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
        strcpy(lista[i].nombre, " ");
        strcpy(lista[i].pass, " ");
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
    int i;
    int yaExiste = 0;

    indiceLibre = indiceUsLibre(listaUs, sizeUs);
    id = buscarIdUsuariolibre(listaUs, sizeUs);

    usuario = cargarUsuario(id);

    for(i=0; i<sizeUs; i++)
    {
        if(listaUs[i].estado==0 && strcmp(listaUs[i].nombre, usuario.nombre)==0 && strcmp(listaUs[i].pass, usuario.pass)==0)
        {
            printf("Este usuario ya existe.");
            yaExiste = 1;
            break;
        }
    }

    if (yaExiste == 0)
    {
        listaUs[indiceLibre] = usuario;
    }

}

eUsuario cargarUsuario (int id)
{
    int flag;
    char nombre[STR];
    char pas[STR];
    eUsuario usuario;

    do
    {
        flag = pedirStrLetras(nombre, "Ingrese Nombre: ", "Nombre invalido.", 1, STR);
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

eUsuario buscarUsuarioPorId (eUsuario lista[], int size, int id, int estado)
{
    eUsuario usuario ={0,-1,"",""};
    int i;

    for (i=0;i<size;i++)
    {
        if(lista[i].estado==estado && lista[i].id==id)
        {
            usuario=lista[i];
            break;
        }
    }

    return usuario;
}

void mostrarUsuarios (eUsuario lista[], int size)
{
    int i;
    int contador = 1;

    printf("\nLista de usuarios: \n");

    for(i=0; i<size; i++)
    {
        if (lista[i].estado!=-1)
        {
            printf(" %d) %s \n", contador, lista[i].nombre);
            contador++;
        }

    }
    printf("\n");
}

int pedirIdUsuario (eUsuario lista[], int size)
{
    int flag;
    char nombre[STR];
    char pas[STR];
    int idUs=-1;

    do
    {
        flag = pedirStrLetras(nombre, "Ingrese Nombre usuario: ", "Nombre invalido.", 1, STR);
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

void modificarUsuario (eUsuario listaUs[], int sizeUs)
{
    int idUs;
    char nombre[STR];
    char pas[STR];
    int flag;
    int i;

    do
    {
        idUs = pedirIdUsuario(listaUs, sizeUs);
    }while(idUs == -1);

    do
    {
        do
        {
            flag = pedirStrLetras(nombre, "\nIngrese nuevo Nombre del usuario: ", "Nombre invalido.", 1, STR);
        }while(flag==-1);

        do
        {
            flag = getString(pas, "Ingrese nuevo Password: ", "Password invalido.", 1, STR);
        }while(flag==-1);

        flag=buscarUsuario1(nombre, pas, listaUs, sizeUs);
        if (flag!=-1)
        {
            printf("\n Los datos ya existen en otro usuario.\n");
        }

    } while(flag!=-1);

    for(i=0;i<sizeUs;i++)
    {
        if (listaUs[i].estado == 0 && listaUs[i].id==idUs)
        {
            strcpy(listaUs[i].nombre, nombre);
            strcpy(listaUs[i].pass, pas);
        }
    }

}

void bajaUsuario (eUsuario listaUs[], int sizeUs, eProducto listaPr[], int sizePr)
{
    int idUs;
    int i;
    int usEncontrado = -1;

    do
    {
        idUs = pedirIdUsuario(listaUs, sizeUs);
    } while(idUs==-1);

    for(i=0; i<sizeUs; i++)
    {
        if(listaUs[i].id == idUs && listaUs[i].estado==0)
        {
            usEncontrado=0;
            listaUs[i].estado=-1;
            printf("Usuario Borrado\n");
            break;
        }
    }
    if (usEncontrado==-1)
    {
        printf("Usuario no Encontrado.\n");
    }
    else
    {
        for(i=0; i<sizePr;i++)
        {
            if(listaPr[i].idUsuario==idUs)
            {
                listaPr[i].estado=-1;
            }
        }
    }
}

void listarUsuarios (eUsuario listaUs[], int sizeUs, eVenta listaVe[], int sizeVe)
{
    int indU;
    int indV;
    float media;
    int acumulador;
    int contador;

    printf("NombreUs\t Promedio Calificacion\n");

    for(indU=0; indU<sizeUs; indU++)
    {
        media=0;
        acumulador=0;
        contador=0;

        if (listaUs[indU].estado == 0)
        {
            for(indV=0; indV<sizeVe; indV++)
            {
                if(listaVe[indV].idUsuario == listaUs[indU].id)
                {
                    acumulador += listaVe[indV].calificacion;
                    contador++;
                }
            }

            if (contador>0)
            {
                media = (float)acumulador/contador;
            }

            printf(" %s \t %.2f\n", listaUs[indU].nombre, media);
        }
    }
}

void listarUsConMasPublicaciones (eUsuario listaUs[], int sizeUs, eProducto listaPr[], int sizePr)
{
    int i;
    int j;
    int acumulador;
    int idUs [sizeUs];
    int cantPublic [sizeUs];
    int max;
    eUsuario usuario;


    // cargo arrays
    for (i=0; i< sizeUs; i++) //us
    {
        acumulador=-1; // caso us borrado
        idUs[i]=listaUs[i].id;

        if (listaUs[i].estado != -1)
        {
            acumulador=0;
            for(j=0; j<sizePr; j++) //pr
            {
                if (listaPr[j].estado != -1)
                {
                    if(listaPr[j].idUsuario == listaUs[i].id)
                    {
                        acumulador++;
                    }
                }
            }
        }

        cantPublic[i] = acumulador;
    }

    // busco la max cant de publicaciones
    max = maximo(cantPublic, sizeUs);

    // imprimo lista


    if (max == -1) // si no hay usuarios
    {
        printf("\n No hay usuarios.\n");
    }
    else
    {
        printf("\n Usuario \t Id \t Cant. Publicaciones \n\n");

        for(j=0; j<sizeUs; j++)
        {
            if(cantPublic[j] == max)
            {
                usuario = buscarUsuarioPorId(listaUs, sizeUs, idUs[j], 0);

                printf(" %s \t %d \t %d \n", usuario.nombre, usuario.id, max);
            }
        }
    }
}

int maximo (int listaInt[], int sizeArray)
{
    int max;
    int i;

    for(i=0; i<sizeArray; i++)
    {
        if (i==0 || listaInt[i] > max)
        {
            max = listaInt[i];
        }
    }

    return max;
}


//PRODUCTOS
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
    float precio;
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
        flag = pedirFloat(&precio, "Ingrese precio: ", "precio invalido.", 0, 1000);
        //flag = getFloat(&precio, "Ingrese precio: ", "precio invalido.", 1.0, 1000.0 );
    }while (flag==-1);

    do
    {
        flag = pedirInt(&stock, "Ingrese stock: ", "stock invalido.", 1, 1000);
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

void harcodearProducto (eProducto lista[])
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
    for (i=0; i<5; i++)
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

    printf("\n id\t nombre\t precio\t ventas\t stock\t usuario \n");

    for(indP=0; indP<sizePr; indP++)
    {
        if (listaPr[indP].estado==0)
        {
            for(i=0; i<sizeUs; i++)
            {
                if(listaUs[i].id == listaPr[indP].idUsuario)
                {
                    strcpy(nomUs,listaUs[i].nombre);
                    break;
                }
            }

            printf("\n %d \t %s \t %.2f \t %d \t %d \t %s \n",
                   listaPr[indP].id,
                   listaPr[indP].nombre,
                   listaPr[indP].precio,
                   listaPr[indP].ventas,
                   listaPr[indP].stock,
                   nomUs);
        }
    }
}

void mostrarProductos(eProducto lista[], int size)
{
    int i;

    printf("IdPr\t idUS\t Nombre\t precio\t ventas\t stock\t estado\n\n");

    for(i=0; i<size; i++)
    {
        if (lista[i].estado!=-1)
        {
                printf("%d \t %d \t %s \t %.2f \t %d \t %d \t %d\n",
                       lista[i].id, lista[i].idUsuario, lista[i].nombre,
                       lista[i].precio, lista[i].ventas, lista[i].stock, lista[i].estado);
        }

    }

}

void comprarProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs, eVenta listaVe[], int sizeVe)
{
    int flag;
    int id;
    int i;
    int calificacion;
    int idmax= buscarIdProductolibre(listaPr, sizeUs);
    int indVenta;
    int idUs;

    do
    {
        flag=pedirInt(&id, "Ingrese Id del producto a comprar: ", "Id invalido.", 1, idmax);
    }while(flag==-1);

    for(i=0; i<sizePr; i++)
    {
        if(listaPr[i].estado==0 && listaPr[i].id==id)
        {
            if(listaPr[i].stock>0)
            {
                idUs=listaPr[i].idUsuario;
                listaPr[i].stock--;
                listaPr[i].ventas++;
                flag=-1;
                break;
            }
        }
    }

    if(flag==-1)
    {
        printf("Compra realizada.\n");
        do
        {
            flag=pedirInt(&calificacion, "Ingrese calificacion (de 0 a 10): ", "Calificacion invalida.", 0, 10);
        }while(flag==-1);

        indVenta=indiceLibreVenta(listaVe, sizeVe);
        if (indVenta >-1)
        {
            listaVe[indVenta].calificacion=calificacion;
            listaVe[indVenta].idProducto=id;
            listaVe[indVenta].idUsuario=idUs;
        }
    }
}

void modificarProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs)
{
    int idUs;
    int idPr;
    char nombre[STR];
    float precio;
    int stock;
    int flag;
    int idCheck=-1;
    int i;

    do
    {
        idUs = pedirIdUsuario(listaUs, sizeUs);
    }while(idUs == -1);

    printf(" Id\t NombrePr\t Precio\t Ventas\t Stock\n\n");
    for(i=0;i<sizePr;i++)
    {
        if(listaPr[i].idUsuario==idUs)
        {
            printf("%d\t %s\t %.2f\t %d\t %d\n", listaPr[i].id,
                   listaPr[i].nombre, listaPr[i].precio, listaPr[i].ventas, listaPr[i].stock);
        }
    }

    do
    {
        flag=pedirInt(&idPr, "Ingrese id del producto a modificar: ", "Id invalido.", 0, 1000);

        if(flag!=-1)
        {
            for(i=0; i<sizePr; i++)
            {
                if(listaPr[i].id==idPr && listaPr[i].estado==0 && listaPr[i].idUsuario==idUs)
                {
                    idCheck=0;
                    break;
                }
            }

        }

    }while(flag==-1 || idCheck!=0);



    do
    {
        flag=getString(nombre, "Ingrese nuevo nombre del producto: ", "Nombre invalido", 1, STR);
    }while(flag==-1);

    do
    {
        flag=pedirFloat(&precio, "Ingrese nuevo precio del producto: ", "Precio invalido.", 0, 1000);
    }while(flag==-1);

    do
    {
        flag=pedirInt(&stock, "Ingrese nuevo stock del producto: ", "stock invalido.", 0, 1000);
    }while(flag==-1);

    for(i=0; i<sizePr; i++)
    {
        if(listaPr[i].id==idPr && listaPr[i].estado==0)
        {
            listaPr[i].precio=precio;
            listaPr[i].stock = stock;
            strcpy(listaPr[i].nombre, nombre);
        }
    }
}

void bajaProducto (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs)
{
    int idUs;
    int idPr;
    int flag;
    int idCheck=-1;
    int i;

    do
    {
        idUs = pedirIdUsuario(listaUs, sizeUs);
    }while(idUs == -1);

    printf(" Id\t NombrePr\t Precio\t Ventas\t Stock\n\n");
    for(i=0;i<sizePr;i++)
    {
        if(listaPr[i].idUsuario==idUs && listaPr[i].estado==0)
        {
            printf("%d\t %s\t %.2f\t %d\t %d\n", listaPr[i].id,
                   listaPr[i].nombre, listaPr[i].precio, listaPr[i].ventas, listaPr[i].stock);
        }
    }

    do
    {
        flag=pedirInt(&idPr, "Ingrese id del producto a dar de baja: ", "Id invalido.", 0, 1000);

        if(flag!=-1)
        {
            for(i=0; i<sizePr; i++)
            {
                if(listaPr[i].id==idPr && listaPr[i].estado==0 && listaPr[i].idUsuario==idUs)
                {
                    idCheck=0;
                    listaPr[i].estado=-1;
                    printf("El Producto %s  fue cancelado.\n", listaPr[i].nombre);
                    break;
                }
            }

        }

    }while(flag==-1);

    if (idCheck==-1)
    {
        printf("Producto no encontrado.\n");
    }
}

void productosPorUsuario (eProducto lista[], int size, int idUs)
{
    int i;

    printf("idPr\t NombrePr\t Precio\t Ventas\t Stock\n");
    for (i=0; i<size; i++)
    {
        if(lista[i].idUsuario == idUs && lista[i].estado == 0)
        {
            printf(" %d\t %s\t %.2f\t %d\t %d\n", lista[i].id, lista[i].nombre,
                   lista[i].precio, lista[i].ventas, lista[i].stock);
        }
    }
}

void listarPublicacionesPorUsuario (eProducto listaPr[], int sizePr, eUsuario listaUs[], int sizeUs)
{
    int idUs;
    //int i;
    //int existeUs=-1;

    do
    {
        idUs = pedirIdUsuario(listaUs, sizeUs);
    }while(idUs == -1);

    productosPorUsuario(listaPr, sizePr, idUs);

}



// VETNAS
void iniVentas (eVenta lista[], int size)
{
    int i;
    for(i=0; i<size;i++)
    {
        lista[i].calificacion=-1;
        lista[i].idProducto=-1;
        lista[i].idUsuario=-1;
    }
}

void harcodearVenta (eVenta lista[])
{
    int idP[10]={1,1,3,5,5,2,1,4,3,1};
    int idU[10]={5,1,2,5,3,5,4,1,2,5};
    int cal[10]={2,2,1,4,3,0,10,9,8,7};

    int i;
    for (i=0; i<10; i++)
    {
        lista[i].idProducto=idP[i];
        lista[i].idUsuario = idU[i];
        lista[i].calificacion = cal[i];
    }
}

int indiceLibreVenta (eVenta lista[], int size)
{
    int i;
    int indice = -1;
    for(i=0;i<size;i++)
    {
        if(lista[i].calificacion==-1)
        {
            indice = i;
            break;
        }
    }

    return  indice;
}

void mostrarVentas(eVenta lista[], int size)
{
    int i;

    printf(" idUs\t idPr\t calif\n\n");
    for (i=0; i<size; i++)
    {
        if(lista[i].calificacion>-1)
        {
            printf(" %d\t %d\t %d\n",lista[i].idUsuario, lista[i].idProducto, lista[i].calificacion);
        }

    }
}



