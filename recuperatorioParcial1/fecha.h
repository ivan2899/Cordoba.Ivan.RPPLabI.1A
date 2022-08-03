#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief Pide el dia mes y anio de un periodo de fecha
 *
 * \param dia int*  Puntero a donde se guardara el dia
 * \param mes int*  Puntero a donde se guardara el mes
 * \param anio int* Puntero a donde se guardara el anio
 * \param anioMin int   Anio minimo del periodo de fecha que valide
 * \param anioMax int   Anio maximo del periodo de fecha que valide
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarFecha(int* dia, int* mes, int* anio, int anioMin, int anioMax);


/** \brief Recibe la fecha y le dice al usuario si desea confirmarla
 *
 * \param dia int   Dia de la fecha a confirmar
 * \param mes int   Mes de la fecha a confirmar
 * \param anio int  Anio de la fecha a confirmar
 * \param eleccion char*    Eleccion del usuario, 'S' u otra letra
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int confirmarFecha(int dia, int mes, int anio, char* eleccion);
