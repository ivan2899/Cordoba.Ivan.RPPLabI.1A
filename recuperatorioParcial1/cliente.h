#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[31];
    char apellido[31];
    int cuil;
    int isEmpty;

}eCliente;

#endif // CLIENTE_H_INCLUDED

int inicializarClientes(eCliente* clientes, int tam);

int buscarPosicionPorIdCliente(eCliente* clientes, int tam,int id, int* pIndex);
int buscarPosicionLibreCliente(eCliente* clientes, int tam, int* pIndex);
int buscarDescripcionCliente(eCliente* clientes, int tam, int num, char* nombreCliente);
int buscarDescripcionClienteApellido(eCliente* clientes, int tam, int num, char* apellidoCliente);

int altaCliente(int indiceLibre, int* idCliente, eCliente* clientes, int tamClientes);
int modificarCliente(eCliente* clientes, int tam, int opcion, int i);
