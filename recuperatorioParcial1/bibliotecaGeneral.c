#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menu()
{
    int opcion;

    system("cls");
    printf("    Menu principal  \n"
            "1) Alta cliente\n"
            "2) Modificar datos de cliente\n"
            "3) Baja cliente\n"
            "4) Alta Prestamo\n"
            "5) Saldar prestamo\n"
            "6) Reanudar prestamo\n"
            "7) Imprimir clientes\n"
            "8) Imprimir prestamos\n"
            "9) Informar clientes\n"
            "10) Informar prestamos\n"
            "20) Salir\n");

    printf("\nIngrese opci%cn: ", 162);
    fflush(stdin); // Limpio el buff porque si en algun otro menu ingresan un numero seguido de enter o una letra, da como erroneo
    scanf("%d", &opcion);
    opcion = toupper(opcion);

    while(((opcion < 1 || opcion > 10) && opcion != 20))
    {
        fflush(stdin);      //Limpio el buff de entrada para que en el caso de que arriba ingresen una letra no se rompa el progama
        printf("Se ingreso una opci%cn erronea, ingrese la opci%cn nuevamente: ", 162, 162);
        scanf("%d", &opcion);
    }
    return opcion;
}

int confirmaSalida(char* eleccion)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        do
        {
            system("cls");
            printf(" ______________________________________ \n");
            printf("|   Ha ingresado a la opcion SALIR     |\n");
            printf("|______________________________________|\n\n");
            printf("Esta seguro que desea salir?\n");
            printf("Ingrese una letra, \"s\" para si: ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = toupper(auxSalida);

        }
        while(!isalpha(auxSalida));
        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int confirma(char* eleccion, int reintentos)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        printf("Ingrese una letra, \"s\" para si: ");
        fflush(stdin);
        scanf("%c", &auxSalida);
        auxSalida = toupper(auxSalida);


        do
        {
            if(isalpha(auxSalida))
            {
                break;
            }
            printf("Reingrese una letra, \"s\" para si: ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = toupper(auxSalida);
            reintentos--;
        }
        while(!isalpha(auxSalida) && reintentos > 0);

        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int confirmaIngreso(char* eleccion, char* mensaje, int reintentos)
{
    int todoOk = 0;

    if(eleccion && mensaje)
    {
        system("cls");
        printf("\nEsta seguro que desea ingresar a \"%s\" ?\n", mensaje);
        confirma(eleccion, reintentos);
        todoOk = 1;
    }
    return todoOk;
}

int validarGets(int tam, char auxCad[100])
{
    int validacion = 0;
    if(tam > 0 && auxCad)
    {
        if(strlen(auxCad) < tam)
        {
            validacion = 1;
        }
    }
    return validacion;
}

int pedirYValidarInt(int* resultado, char mensaje[50], char mensajeError[50], int minimo, int maximo)
{
    int todoOk = 0;
    char auxCad[50];
    int auxInt;


    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s ", mensaje);
        fflush(stdin);
        gets(auxCad);
        while(!(validarGets(50, auxCad)))
        {
            printf("Error, reingrese un numero menor a 50 cifras");
            fflush(stdin);
            gets(auxCad);
        }
        auxInt = atoi(auxCad);

        printf("\n");
        while(auxInt < minimo || auxInt > maximo)
        {
            printf ("%s ",mensajeError);
            fflush(stdin);
            gets(auxCad);
            while(!(validarGets(50, auxCad)))
            {
                printf("Error, reingrese un numero menor a 50 cifras");
                gets(auxCad);
            }
            auxInt = atoi(auxCad);
        }

        *resultado = auxInt;
        todoOk = 1;
    }
    return todoOk;
}

int pedirYValidarFloat(float* resultado, char mensaje[50], char mensajeError[50], float minimo, float maximo)
{
    int todoOk = 0;
    char auxCad[50];
    float auxFloat;


    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s ", mensaje);
        gets(auxCad);
        while(!(validarGets(50, auxCad)))
        {
            printf("Error, reingrese un numero menor a 50 cifras");
            fflush(stdin);
            gets(auxCad);
        }
        auxFloat = atof(auxCad);

       printf("\n");
        while(auxFloat < minimo || auxFloat > maximo)
        {
            printf ("%s ",mensajeError);
            fflush(stdin);
            gets(auxCad);
            while(!(validarGets(50, auxCad)))
            {
                printf("Error, reingrese un numero menor a 50 cifras");
                gets(auxCad);
            }
            auxFloat = atof(auxCad);
        }

        *resultado = auxFloat;
        todoOk = 1;
    }
    return todoOk;
}

int pedirYValidarChar(char* resultado, char mensaje[50], char mensajeError[50], char minimo, char maximo)
{
    int todoOk = 0;
    char buffer;

    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s ", mensaje);
        fflush(stdin);
        scanf("%c", &buffer);

        if(buffer >= minimo && buffer <= maximo)
        {
            *resultado = buffer;
            todoOk = 1;
        }
        else
        {
            do
            {
                printf("\n%s ", mensajeError);
                fflush(stdin);
                scanf("%c", &buffer);

                if(buffer >= minimo && buffer <= maximo)
                {
                    *resultado = buffer;
                    todoOk = 1;
                    break;
                }
            }
            while(1);
        }
    }
    return todoOk;
}

int pedirYValidarString(int maximo, char* cadena,  char mensaje[50], char mensajeError[50], int minimo)
{
    int todoOk = 0;
    char auxCad[maximo];

    if(cadena != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s ", mensaje);
        fflush(stdin);
        gets(auxCad);
        while(!validarGets(maximo, auxCad))
        {
            printf("Error, reingrese un texto menor a %d car%ccteres: ", maximo-1, 160);
            gets(auxCad);
        }

        if(strlen(auxCad) >= minimo && strlen(auxCad) < maximo)
        {
            strcpy(cadena, auxCad);
            todoOk = 1;
        }
        else
        {
            do
            {
                printf("\n%s", mensajeError);
                gets(auxCad);
                while(!validarGets(maximo, auxCad))
                {
                    printf("Error, reingrese un texto menor a %d y menor a %d car%ccteres: ", maximo-1, minimo, 160);
                    fflush(stdin);
                    gets(auxCad);
                }
                if(strlen(auxCad) >= minimo && strlen(auxCad) < maximo)
                {
                    strcpy(cadena, auxCad);
                    todoOk = 1;
                    break;
                }
            }
            while(1);
        }

    }


    return todoOk;
}
