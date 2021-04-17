/*
 * calculos.c
 *
 *Author: Agostina Barbenza
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



/*
 * Función Validar entero
 */
int validarNumeroEntero(char dato[]) {
	int numeroValidado = 1;

	if(strlen(dato)>0){
		for(int i = 0; i<strlen(dato); i++){
			if(isdigit(dato[i])== 0){
				numeroValidado = 0;
				break;
			}

		}
	}else{
		numeroValidado = 0;
	}
	return numeroValidado;
}


/*
 * Función Pedir INT
 */
int pedirInt(char mensaje[], char errorMsg[]) {
	int numeroInt;
	char dataIngresada[1000];
	printf(mensaje);
	scanf("%[^\n]", dataIngresada);
	while(validarNumeroEntero(dataIngresada) == 0){
		printf(errorMsg);
		scanf("%[^\n]", dataIngresada);
	}
	numeroInt = atoi(dataIngresada);
	return numeroInt;
}

/*
 * Función Pedir INT dentro de un Rango
 */
int pedirIntRango(char mensaje[], char errorMsg[], int min, int max) {
	int numeroIntRango;
	numeroIntRango = pedirInt(mensaje, errorMsg);
	while(numeroIntRango<min || numeroIntRango>max){
		printf("Error, el numero ingresado esta fuera del rango requerido. \n Ingrese un numero entre %d y %d", min, max);
		numeroIntRango = pedirInt(mensaje, errorMsg);
	}
	return numeroIntRango;
}
/*
 * Función Validar flotante
 */
int validarNumeroFloat(char dato[]) {
	int numeroValidado = 1;
	int contadorSigno = 0;

	if(strlen(dato)>0){
		for(int i=0; i<strlen(dato); i++){
			if(dato[0] == '-'){
				continue;
			}else{
				if(dato[i] == ',' || dato[i] =='.'){
					contadorSigno++;
				}else{
					if(isdigit(dato[i]) == 0){
						numeroValidado = 0;
						break;
					}
				}
			}
		}
		if(contadorSigno>1){
			numeroValidado = 0;
		}
	}else{
		numeroValidado = 0;
	}
	return numeroValidado;
}

/*
 * Función Pedir FLOAT
 */
float pedirFloat(char mensaje[], char errorMsg[]) {
	float numeroFloat;
	char dataIngresada[1000];
	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]", dataIngresada);
	while(validarNumeroFloat(dataIngresada) == 0){
			printf(errorMsg);
			fflush(stdin);
			scanf("%[^\n]", dataIngresada);
		}
	numeroFloat = atof(dataIngresada);
	return numeroFloat;
}

/*
 * Función SUMAR
 */
float sumar(float primerNum, float segundoNum) {
	float total;
	total = (float) primerNum + segundoNum;
	return total;
}

/*
 * Función RESTAR
 */
float restar(float primerNum, float segundoNum) {
	float total;
	total = (float) primerNum - segundoNum;
	return total;
}

/*
 * Función MULTIPLICAR
 */
float multiplicar(float primerNum, float segundoNum) {
	float total;
	total = (float)primerNum * segundoNum;
	return total;
}

/*
 * Función DIVIDIR
 */
float dividir(float primerNum, float segundoNum) {

	float error = 0;
	float total = 0;
	if (segundoNum == 0) {
		return error; //Si el segundo operador ingresado es  0, no se puede realizar la operación.
	} else {
		total = (float) primerNum / segundoNum;
		return total;
	}
}

/*
 * Función FACTORIAL
 */
double factorial(double num) {
	double fact = 1;
	double error = 0;
	if(num == 0){
		return fact;
	}else{
		if(((num - (int)num) == 0) && num >=1){ //Chequeo para saber si el usuario ingresó un numero decimal.
				for (int i = 1; i <= num; i++) {
					fact = fact * i;
				}
			return fact;
			}else { //si ingresó un numero decimal devuelve error ya que no se puede calcular el factorial de un decimal.
				return error;
			}
	}


}

/*
 * Función Mostrar menu cuando los flags valen 0 (inicio del programa)
 */
void mostrarMenuFlagsCero() {
	printf("\nIngrese una opcion: ");
	printf("\n 1. Ingresar 1er operando (A = X)");
	printf("\n 2. Ingresar 2do operando (B = Y)");
	printf("\n 3. Calcular todas las operaciones: ");
	printf("\n 	a) Calcular la suma (A+B)");
	printf("\n 	b) Calcular la resta (A-B)");
	printf("\n	c) Calcular la division (A/B)");
	printf("\n	d) Calcular la multiplicacion (A*B)");
	printf("\n	e) Calcular el factorial (A! y B!)");
	printf("\n 4. Informar resultados:");
	printf("\n 5. Salir \n");
}

/*
 * Función Mostrar menu cuando el primer flag == 1 y segundo flag == 0
 */
void mostrarMenuFlagUnoYFlagCero(float primerOp) {
	printf("\nIngrese una opcion: ");
	printf("\n 1. Ingresar 1er operando (A = %.2f)", primerOp);
	printf("\n 2. Ingresar 2do operando (B = y)");
	printf("\n 3. Calcular todas las operaciones: ");
	printf("\n 	a) Calcular la suma (%.2f+B)", primerOp);
	printf("\n 	b) Calcular la resta (%.2f-B)", primerOp);
	printf("\n	c) Calcular la division (%.2f/B)", primerOp);
	printf("\n	d) Calcular la multiplicacion (%.2f*B)", primerOp);
	printf("\n	e) Calcular el factorial (%.2f! y B!)", primerOp);
	printf("\n 4. Informar resultados:");
	printf("\n 5. Salir \n");
}

/*
 * Función Mostrar menu cuando el primer flag y el segundo flag == 1 (todos los operadores fuerno ingresados)
 */
void mostrarMenuFlagsUno(float primerOp, float segundoOp) {
	printf("\nIngrese una opcion: ");
	printf("\n 1. Ingresar 1er operando (A = %.2f)", primerOp);
	printf("\n 2. Ingresar 2do operando (B = %.2f)", segundoOp);
	printf("\n 3. Calcular todas las operaciones: ");
	printf("\n 	a) Calcular la suma (%.2f+%.2f)", primerOp, segundoOp);
	printf("\n 	b) Calcular la resta (%.2f-%.2f)", primerOp, segundoOp);
	printf("\n	c) Calcular la division (%.2f/%.2f)", primerOp, segundoOp);
	printf("\n 	d) Calcular la multiplicacion (%.2f*%.2f)", primerOp, segundoOp);
	printf("\n 	e) Calcular el factorial (%.2f! y %.2f!)", primerOp, segundoOp);
	printf("\n 4. Informar resultados:");
	printf("\n 5. Salir \n");
}

/*
 * Función Mostrar resultados por pantalla
 */
float mostrarResultado(float primerNum, float segundoNum, float result1, float result2,
		float result3, float result4, double result5, double result6) {
	printf("\n 4. Informar resultados: ");
	printf("\n   a) El resultado de %.2f+%.2f es: %.2f", primerNum, segundoNum,
			result1);
	printf("\n   b) El resultado de %.2f-%.2f es: %.2f", primerNum, segundoNum,
			result2);
	if (result3 == 0) {
		printf("\n   c) ERROR! No es posible dividir un numero por 0");
	} else {
		printf("\n   c) El resultado de %.2f/%.2f es: %.2f ", primerNum, segundoNum,
				result3);
	}
	printf("\n   d) El resultado de %.2f*%.2f es: %.2f", primerNum, segundoNum,
			result4);

	if (result5 == 0 && result6 == 0) {
		printf("\n   e) No se puede calcular factorial de %.0f y %.0f por ser ambos < 0 o decimales ",
				primerNum, segundoNum);
	} else if (result5 >= 1 && result6 == 0) {
		printf("\n   e) El factorial de %.2f es: %.2lf y El factorial de %.2f no se puede calcular por ser < 0 o decimal \n",
				primerNum, result5, segundoNum);
	} else if (result5 == 0 && result6 >= 1) {
		printf("\n   e) El factorial de %.2f no se puede calcular por ser < 0 o decimal y El factorial de %.2f es: %.2lf \n",
				primerNum, segundoNum, result6);
	} else if (result5 >= 1 && result6 >= 1) {
		printf("\n   e) El factorial de %.2f es: %.2lf y El factorial de %.2f es: %.2lf \n",
				primerNum, result5, segundoNum, result6);
	}
	return 0;
}

