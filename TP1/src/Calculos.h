/*
 * calculos.h
 *
 * Author: Agostina Barbenza
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

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
int pedirIntRango(char [], char [], int , int );

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

/* \brief Suma del primer número ingresado y el segundo numero ingresado
 * \param primerNum recibe un primer numero a sumar
 * \param segundoNum recibe un segundo numero a sumar
 * \return la suma de los números ingresados por el usuario
 */

float sumar(float primerNum, float segundoNum);

/* \brief Resta del primer número ingresado y el segundo numero ingresado
 * \param primerNum recibe un primer numero a restar
 * \param segundoNum recibe un segundo numero a restar
 * \return La resta de los números ingresados por el usuario
 */

float restar(float primerNum, float segundoNum);

/* \brief Multiplica el primer número ingresado y el segundo numero ingresado
 * \param primerNum recibe un primer numero a multiplicar
 * \param segundoNum recibe un segundo numero a multiplicar
 * \return La multiplicación de los números ingresados por el usuario
 */

float multiplicar(float primerNum, float segundoNum);

/* \brief Divide el primer número ingresado y el segundo numero ingresado.
 * 		  El segundo número ingresado NO puede ser 0.
 * \param primerNum recibe un primer numero a dividir.
 * \param segundoNum recibe un segundo numero a dividir (debe ser distinto de 0)
 * \return La división de esos números
 */

float dividir(float primerNum, float segundoNum);

/* \brief Calcula el factorial del numero ingresado
 * \param num recibe un numero para realizar el factorial
 * \return El factorial del numero ingresado
 */

double factorial(double num);

/* \brief Muestra el resultado de todas las operaciones
 * \param primerNum recibe el primer numero ingresado por el usuario
 * \param segundoNum recibe el segundo numero ingresado por el usuario
 * \param result1 recibe el resultado de la suma de los numeros
 * \param result2 recibe el resultado de la resta de los numeros
 * \param result3 recibe el resultado de la division de los numeros ingresados
 * \param result4 recibe el resultado de la multiplicacion de los numeros
 * \param result5 recibe el resultado del factorial del primer numero ingresado
 * \param result6 recibe el resultado del factorial del segundo numero ingresado
 * \return Muestra en pantalla los resultados de las operaciones
 */

float mostrarResultado(float primerNum, float segundoNum, float result1, float result2,
		float result3, float result4, double result5, double result6);

/* \brief Muestra el menú cuando los dos flags valen 0
 * \params: no recibe parametros
 * \return: No retorna ningun valor.
 */
void mostrarMenuFlagsCero(void);

/* \brief Muestra el menú cuando el primer flag vale 1 y el segundo vale 0
 * \param primerOp recibe el primer operador que ingresa el usuario
 * \return: no retorna ningun valor.
 */
void mostrarMenuFlagUnoYFlagCero(float primerOp);

/* \brief Muestra el menú cuando los dos flags valen 1
 * \param primerOp recibe el primer operador que ingresa el usuario
 * \param segundoOp recibe el segundo operador que ingresa el usuario
 * \return: no retorna ningun valor.
 */
void mostrarMenuFlagsUno(float primerOp, float segundoOp);

#endif /* CALCULOS_H_ */
