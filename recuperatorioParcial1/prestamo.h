#include "cliente.h"

#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED

typedef struct
{
    int id;
    int  idCliente;
    float importe;
    int cantidadCuotas;
    int estado;
    int isEmpty;

}ePrestamo;

#endif // PRESTAMO_H_INCLUDED

int inicializarPrestamos(ePrestamo* prestamos, int tam);

int buscarPosicionLibrePrestamo(ePrestamo* prestamos, int tam, int* pIndex);
int buscarPosicionPorIdPrestamo(ePrestamo* prestamos, int tam,int id, int* pIndex);

int altaPrestamo(ePrestamo* prestamos, int tamPres, eCliente* clientes, int tamCliente, int* pId, int i);
