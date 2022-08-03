#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bibliotecaGeneral.h"
#include "cliente.h"
#include "informes.h"
#include "prestamo.h"

#define TAM_CLIENTES 50
#define TAM_PRESTAMOS 50

#define REINTENTOS 5

int main()
{
    char eleccion = 'n';
    char confIngreso = 'n';
    char mensaje[50];
    int indiceLibre;
    int indice;
    int opcion;
    int idRequerido;
    eCliente clientes[TAM_CLIENTES];
    ePrestamo prestamos[TAM_PRESTAMOS];

    //IDs
    int idCliente = 10;
    int idPrestamo = 1000;

    inicializarClientes(clientes, TAM_CLIENTES);
    inicializarPrestamos(prestamos, TAM_PRESTAMOS);
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            strcpy(mensaje, "Alta Cliente");
            confirmaIngreso(&confIngreso, mensaje, REINTENTOS);

            if(confIngreso == 'S')
            {
                buscarPosicionLibreCliente(clientes, TAM_CLIENTES, &indiceLibre);
                altaCliente(indiceLibre,&idCliente, clientes, TAM_CLIENTES);
            }
            break;
        case 2:
            listarClientes(clientes, TAM_CLIENTES);
            printf("Ingrese el id de cliente a modificar");
            scanf("%d", &idRequerido);

            if(buscarPosicionPorIdCliente(clientes, TAM_CLIENTES, idRequerido, &indice))
            {
                if(indice == -1)
                {
                    printf("No hay clientes con ese id");
                }
                else
                {

                printf("\nQue desea modificar ?\n"
                   "1) Nombre\n"
                   "2) Apellido\n"
                   "3) Cuil\n");
                pedirYValidarInt(&opcion, "Ingrese la opcion que desea modificar", "Error, reingrese la opcion", 1, 3);
                modificarCliente(clientes, TAM_CLIENTES, opcion, indice);
               }
            }
            break;
        case 3:
            listarClientes(clientes, TAM_CLIENTES);
            printf("\nIngrese el id de cliente");
            scanf("%d", &idRequerido);

            if(buscarPosicionPorIdCliente(clientes, TAM_CLIENTES, idRequerido, &indice))
            {
                if(indice == -1)
                {
                    printf("No hay clientes con ese id");
                }
                else
                {

               }
            }
            break;
        case 4:
            buscarPosicionLibrePrestamo(prestamos, TAM_PRESTAMOS, &indiceLibre);
            altaPrestamo(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES, &idPrestamo, indiceLibre);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            listarClientes(clientes, TAM_CLIENTES);
            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;

        case 20:
            confirmaSalida(&eleccion);
            break;
        }
        printf("\n\n");
        system("pause");

    }
    while(eleccion != 'S');

    return 0;
}
