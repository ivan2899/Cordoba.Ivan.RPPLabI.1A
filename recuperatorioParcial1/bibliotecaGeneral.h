#ifndef BIBLIOTECAGENERAL_H_INCLUDED
#define BIBLIOTECAGENERAL_H_INCLUDED



#endif // BIBLIOTECAGENERAL_H_INCLUDED

/** \brief Muestra el menu principal
 *
 * \return int  Retorna la opcion elegida
 *
 */
int menu();

/** \brief Muestra un cartel al usuario y le pregunta si confirma la salida del programa
 *
 * \param eleccion char*    Devuelve la eleccion en letra, 'S' u otra letra
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int confirmaSalida(char* eleccion);
/** \brief Muestra un cartel al usuario y le pregunta si desea ingresar al lugar que se reciba por mensaje
 *
 * \param eleccion char*    Devuelve la eleccion en letra, 'S' u otra letra
 * \param mensaje char*     Mensaje de donde se va a ingresar
 * \param reintentos int    Reintentos posibles, sino da error
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int confirmaIngreso(char* eleccion, char* mensaje, int reintentos);
/** \brief Es una confirmacion generica para poner luego de un printf
 *
 * \param eleccion char*    Devuelve la eleccion en letra, 'S' u otra letra
 * \param reintentos int    Reintentos posibles, sino da error
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int confirma(char* eleccion, int reintentos);
/** \brief
 *
 * \param tam int
 * \param auxCad[100] char
 * \return int
 *
 */
int validarGets(int tam, char auxCad[100]);

/** \brief Pide y valida un Int con parametros recibidos
 *
 * \param resultado int* puntero a donde se va a guardar el resultado
 * \param mensaje[50] char	Mensaje que le pida al usuario el numero
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el numero
 * \param minimo int	Numero minimo a validar
 * \param maximo int	Numero maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarInt(int* resultado, char mensaje[50], char mensajeError[50], int minimo, int maximo);

/** \brief Pide y valida un Float con parametros recibidos
 *
 * \param resultado float* puntero a donde se va a guardar el resultado
 * \param mensaje[50] char	Mensaje que le pida al usuario el numero
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el numero
 * \param minimo float	Numero minimo a validar
 * \param maximo float	Numero maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarFloat(float* resultado, char mensaje[50], char mensajeError[50], float minimo, float maximo);

/** \brief Pide y valida un Char con parametros recibidos
 *
 * \param resultado char*	puntero a donde se va a guardar la letra
 * \param mensaje[50] char	Mensaje que le pida al usuario el caracter
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el caracter
 * \param minimo char	caracter minimo a validar
 * \param maximo char	caracter maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarChar(char* resultado, char mensaje[50], char mensajeError[50], char minimo, char maximo);

/** \brief Pide y valida un string con parametros recibidos
 *
 * \param maximo int	valor del maximo texto que puede recibir
 * \param cadena char*	puntero a donde se va a guardar el texto
 * \param mensaje[50] char	Mensaje que le pida al usuario el texto
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el texto
 * \param minimo char	largo de texto minimo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarString(int maximo, char* cadena,  char mensaje[50], char mensajeError[50], int minimo);

