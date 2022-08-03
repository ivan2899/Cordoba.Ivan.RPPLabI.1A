#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "informes.h"
#include "cliente.h"
#include "prestamo.h"

int listarUnCliente(eCliente* clientes, int tam, int i)
{
    int todoOk = 0;

    if(clientes && tam>0)
    {
        if(!(clientes[i].isEmpty))
        {

            printf("\n|  %4d      %20s    %20s              %15d |", clientes[i].id, clientes[i].nombre, clientes[i].apellido, clientes[i].cuil);
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarClientes(eCliente* clientes, int tam)
{
    int todoOk = 0;

    if(clientes && tam>0 )
    {

        printf("|                                                               **LISTADO DE CLIENTES**                                                              |\n");
        printf("|      ID      |            NOMBRE         |         APELLIDO          |           CUIL               ");
        for(int i=0; i<tam; i++)
        {
            listarUnCliente(clientes, tam, i);
        }

        todoOk = 1;
    }
    return todoOk;
}

int listarUnPrestamo(ePrestamo* prestamos, int tamPres, eCliente* clientes, int tamCli, int i)
{
    int todoOk = 0;
    char descNombre[30];
    char descApellido[30];
    char auxEstado[15];

    if(prestamos && tamPres>0 && clientes && tamCli>0 && i >=0)
    {
        if(!(prestamos[i].isEmpty))
        {
            if((prestamos[i].estado) == 1)
            {
                strcpy(descNombre, "Activo");
            }
            else if((prestamos[i].estado) == 2)
            {
                strcpy(descNombre, "Pausado");
            }
            else
            {
                strcpy(descNombre, "Saldado");
            }


            buscarDescripcionCliente(clientes, tamCli, prestamos[i].idCliente, descNombre);
            buscarDescripcionClienteApellido(clientes, tamCli, prestamos[i].idCliente, descApellido);

            printf("\n| %7d        %20s            %20f         %3d             %15s    |", prestamos[i].id, descNombre, prestamos[i].importe, prestamos[i].cantidadCuotas, auxEstado);
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarTrabajos(ePrestamo* prestamos, int tamPres, eCliente* clientes, int tamCli)
{
    int todoOk = 0;

    if(prestamos && tamPres>0 && clientes && tamCli>0)
    {
        printf("|                    **LISTADO DE PRESTAMOS**                             |\n");
        printf("|  ID          |   NOMBRE        |         IMPORTE       |      CUOTAS    |     ESTADO ACTUAL");
        for(int i=0; i<tamPres; i++)
        {
            listarUnPrestamo(prestamos, tamPres, clientes, tamCli, i);
        }

        todoOk = 1;
    }
    return todoOk;
}
