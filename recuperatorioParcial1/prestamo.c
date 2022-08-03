#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bibliotecaGeneral.h"
#include "prestamo.h"
#include "cliente.h"
#include "informes.h"

int inicializarPrestamos(ePrestamo* prestamos, int tam)
{
    int todoOk = 0;
    if(prestamos != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            prestamos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarPosicionLibrePrestamo(ePrestamo* prestamos, int tam, int* pIndex)
{
    int todoOk = 0;
    if(prestamos && pIndex && tam>0 )
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(prestamos[i].isEmpty)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int altaPrestamo(ePrestamo* prestamos, int tamPres, eCliente* clientes, int tamCliente, int* pId, int i)
{
    int todoOk = 0;
    int idCli;
    int indice;
    float auxPrecio;
    int auxCuotas;

    if(prestamos && pId && tamPres>0 && clientes && tamCliente>0 && i>=0)
    {
        prestamos[i].id = *pId;
        *pId = *pId + 1;

        printf("\nSi desea salir ingrese el n%cmero \"1\" \n", 163);
        listarClientes(clientes, tamCliente);
        printf("\nIngrese id del cliente : ");
        scanf("%d", &idCli);
        if(idCli == 1)
        {
            return todoOk;
        }

        if(buscarPosicionPorIdCliente(clientes, tamCliente, idCli, &indice))
        {
            while(indice == -1)
            {
                fflush(stdin);
                printf("No hay clientes con ese id\n");
                printf("Reingrese el id del cliente v%clido (los que aparecen en la lista) o ingrese 1 para salir: ", 160);
                scanf("%d", &idCli);
                if(idCli == 1)
                {
                    return todoOk;
                }
                buscarPosicionPorIdCliente(clientes, tamCliente, idCli, &indice);
            }
        }
        prestamos[i].idCliente = idCli;

        printf("Ingrese el precio del prestamo: ");
        fflush(stdin);
        scanf("%f", &auxPrecio);

        while(auxPrecio < 0 || auxPrecio > 150000000)
        {
         printf("Reingrese el precio del prestamo: ");
        fflush(stdin);
        scanf("%f", &auxPrecio);
        }
        prestamos[i].importe = auxPrecio;


        pedirYValidarInt(&auxCuotas, "Ingrese las cuotas en las que se va a pagar(1 - 48)", "Reingrese las cuotas(1 - 48)", 1, 48);
        prestamos[i].cantidadCuotas = auxCuotas;

        prestamos[i].estado = 1;
        prestamos[i].isEmpty = 0;

        printf("Se dio de alta el prestamo correctamente, su ID es: %d", prestamos[i].id);
    }
    return todoOk;
}

int buscarPosicionPorIdPrestamo(ePrestamo* prestamos, int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(prestamos && tam > 0 && pIndex && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(prestamos[i].isEmpty == 0 && prestamos[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
