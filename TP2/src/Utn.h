/*
 * Utn.h
 *
 *  Created on: 13 may. 2021
 *      Author: agosb
 */

#ifndef UTN_H_
#define UTN_H_

/* \brief Muestra un menu
 * \param titulo char[] titulo del programa
 * \param opcion1 char[] opcion1
 * \param opcion2 char[] opcion1
 * \param opcion3 char[] opcion1
 * \param opcion4 char[] opcion1
 * \param opcion5 char[] opcion1
 * \return void
 */
void mostrarMenu(char [], char [], char [],
		char [], char [], char []);

/* \brief Valida si un número es entero
 * \param char[] recibe el dato a validar en formato string
 * \return si es un entero retorna 1, sino retorna 0
 */

int validarNumeroEntero(char []);

/* \brief Pide al usuario un numero entero
 * \param char[] recibe un string con el mensaje donde se solicita el ingreso de un numero entero
 * \param char[] recibe un string con el mensaje de error en el caso de que el usuario ingrese otra cosa que no sea un int
 * \return el numero entero
 */

int pedirInt(char [], char []);

/* \brief Pide al usuario un numero entero que debe responder a cierto rango minimo y maximo
 * \param char[] recibe un string con el mensaje donde se solicita el ingreso de un numero entero
 * \param char[] recibe un string con el mensaje de error en el caso de que el usuario ingrese otra cosa que no sea un int o que este fuera de rango
 * \param int numero minimo
 * \param int numero maximo
 * \return el numero entero
 */
int pedirIntRango(char [],char [],int, int);


int pedirIntSinRango(char []);

/* \brief Valida si un número es float
 * \param char[] recibe el dato a validar
 * \return si es un float retorna 1, sino retorna 0
 */

int validarNumeroFloat(char []);

/* \brief Pide al usuario un numero float
 * \param char[] recibe un string con el mensaje donde se solicita el ingreso de un numero float
 * \param char[] recibe un string con el mensaje de error en el caso de que el usuario ingrese otra cosa que no sea un float
 * \return el numero float
 */
float pedirFloat(char [], char[]);

/* \brief Pregunta al usuario si desea confirmar la operacion
 * \param mensaje char[] mensaje a mostrar
 * \param mensaje char[] mensaje de error a mostrar
 * \return int -1 si hay un error o no acepta, 0 si acepta
 */

int confirmarOperacion(char [], char []);

/* \brief Pide al usuario una cadena de caracteres
 * \param mensaje char[] mensaje a mostrar
 * \param mensaje char[] mensaje de error a mostrar
 * \param cadena char [] pasaje por referencia
 * \return void
 */

void pedirCadena(char [], char [], char[]);

/* \brief Suma del primer número ingresado y el segundo numero ingresado
 * \param primerNum recibe un primer numero a sumar
 * \param segundoNum recibe un segundo numero a sumar
 * \return la suma de los números ingresados por el usuario
 */

float sumar(float , float );

/* \brief Resta del primer número ingresado y el segundo numero ingresado
 * \param primerNum recibe un primer numero a restar
 * \param segundoNum recibe un segundo numero a restar
 * \return La resta de los números ingresados por el usuario
 */

float restar(float , float );

/* \brief Multiplica el primer número ingresado y el segundo numero ingresado
 * \param primerNum recibe un primer numero a multiplicar
 * \param segundoNum recibe un segundo numero a multiplicar
 * \return La multiplicación de los números ingresados por el usuario
 */

float multiplicar(float , float );

/* \brief Divide el primer número ingresado y el segundo numero ingresado.
 * 		  El segundo número ingresado NO puede ser 0.
 * \param primerNum recibe un primer numero a dividir.
 * \param segundoNum recibe un segundo numero a dividir (debe ser distinto de 0)
 * \return La división de esos números
 */

float dividir(float , float );

/* \brief Calcula el factorial del numero ingresado
 * \param num recibe un numero para realizar el factorial
 * \return El factorial del numero ingresado
 */

double factorial(double );


/* \brief Calcula un promedio segun un valor acumulado y una determinada cantidad
 * \param valorAcumulado float valor a calcular el promedio
 * \param cantidad int
 * \return El factorial del numero ingresado
 */
float calcularPromedio(float , int );

#endif /* UTN_H_ */
