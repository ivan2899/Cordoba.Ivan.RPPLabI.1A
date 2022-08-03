#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bibliotecaGeneral.h"
#include "cliente.h"

int inicializarClientes(eCliente* clientes, int tam)
{
    int todoOk = 0;
    if(clientes != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            clientes[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarPosicionLibreCliente(eCliente* clientes, int tam, int* pIndex)
{
    int todoOk = 0;
    if(clientes && pIndex && tam>0 )
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].isEmpty)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int altaCliente(int indiceLibre, int* idCliente, eCliente* clientes, int tamClientes)
{
    int todoOk = 0;
    char auxNombre[31];
    char auxApellido[31];
    int auxCuil;

    if(indiceLibre >= 0 && idCliente && clientes && tamClientes>0 )
    {
        int i = indiceLibre;
        clientes[i].id = *idCliente;
        *idCliente = *idCliente + 1;

        printf("Ingrese el Nombre del cliente (maximo 30 caracteres): ");
        fflush(stdin);
        gets(auxNombre);

        while(!(validarGets(31,auxNombre)))
        {
            fflush(stdin);
            printf("Reingrese el Nombre del cliente de un maximo de 30 caracteres: ");
            gets(auxNombre);
        }
        strcpy(clientes[i].nombre, auxNombre);

        printf("Ingrese el Apellido del cliente (maximo 30 caracteres): ");
        fflush(stdin);
        gets(auxApellido);

        while(!(validarGets(31,auxApellido)))
        {
            fflush(stdin);
            printf("Reingrese el Apellido del cliente de un maximo de 30 caracteres: ");
            gets(auxApellido);
        }
        strcpy(clientes[i].apellido, auxApellido);

        printf("\nIngrese el cuil del cliente\n");
        fflush(stdin);
        scanf("%d", &auxCuil);
        clientes[i].cuil = auxCuil;

        clientes[i].isEmpty = 0;
        todoOk = 1;
    }
    return todoOk;
}

int modificarCliente(eCliente* clientes, int tam, int opcion, int i)
{
    int todoOk = 0;
    char auxNombre[30];
    char auxApellido[30];
    int auxCuil;

    if(clientes && (opcion == 1 || opcion == 2 || opcion == 3) && tam>0)
    {
        if(opcion == 1)
        {
            printf("Ingrese el nuevo Nombre del cliente (maximo 30 caracteres): ");
            fflush(stdin);
            gets(auxNombre);

            while(!(validarGets(21,auxNombre)))
            {
                fflush(stdin);
                printf("Reingrese el Nombre del cliente de un maximo de 30 caracteres: ");
                gets(auxNombre);
            }
            strcpy(clientes[i].nombre, auxNombre);
        }
        else if(opcion == 2)
        {
            printf("Ingrese el nuevo Apellido del cliente (maximo 30 caracteres): ");
            fflush(stdin);
            gets(auxApellido);

            while(!(validarGets(21,auxApellido)))
            {
                fflush(stdin);
                printf("Reingrese el Apellido del cliente de un maximo de 30 caracteres: ");
                gets(auxApellido);
            }
            strcpy(clientes[i].nombre, auxApellido);
        }
        else
        {
            printf("\nIngrese el nuevo cuil del cliente\n");
            fflush(stdin);
            scanf("%d", &auxCuil);
            clientes[i].cuil = auxCuil;
        }
    }

    todoOk = 1;
    return todoOk;
}

int buscarPosicionPorIdCliente(eCliente* clientes, int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(clientes && tam > 0 && pIndex && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].isEmpty == 0 && clientes[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarDescripcionCliente(eCliente* clientes, int tam, int num, char* nombreCliente)
{
    int todoOk = 0;

    if(clientes && tam>0 && num>0 && nombreCliente)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].id == num)
            {
                strcpy(nombreCliente, clientes[i].nombre);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarDescripcionClienteApellido(eCliente* clientes, int tam, int num, char* apellidoCliente)
{
    int todoOk = 0;

    if(clientes && tam>0 && num>0 && apellidoCliente)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].id == num)
            {
                strcpy(apellidoCliente, clientes[i].apellido);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
