/*
 * Utn.c
 *
 */

#ifndef UTN_C_
#define UTN_C_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Utn.h"



void mostrarMenu(char titulo[], char opcionUno[], char opcionDos[],
		char opcionTres[], char opcionCuatro[], char opcionCinco[]) {
	printf(
			"\n========================\n    %s\n          Menu \n========================\nIngrese una opcion: ",
			titulo);
	printf(
			"\n1) %s\n2) %s \n3) %s \n4) %s\n5) %s\n=======================",
			opcionUno, opcionDos, opcionTres, opcionCuatro, opcionCinco);
}


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
	printf(mensaje);
	scanf("%d", &numeroIntRango);
	while(numeroIntRango<min || numeroIntRango>max){
		printf(errorMsg);
		scanf("%d", &numeroIntRango);
	}
	return numeroIntRango;
}
/*
 * Función Pedir INT sin Rango
 */
int pedirIntSinRango(char mensaje[]) {
	int numeroIntRango;
	printf(mensaje);
	scanf("%d", &numeroIntRango);
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
 * Función Pedir Cadena de caracteres
 */
void pedirCadena(char mensaje[], char errorMsg[], char cadena[]) {
	//char dataIngresada[1000];
	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadena);
	while(strlen(cadena)<1){
		printf(errorMsg);
		fflush(stdin);
		scanf("%[^\n]", cadena);
	}
}


/*
 * Funcion para confirmar la operacion
 */

int confirmarOperacion(char mensaje[], char errorMensaje[]){
	int resultadoOperacion = -1;
	int confirmar;
	confirmar = pedirIntRango("\nDesea confirmar la operacion? 1 para si - 0 para no ", "\nError. Desea confirmar la operacion? si - no ", 0, 1);

	if(confirmar == 1){
		resultadoOperacion = 0;
	}
	return resultadoOperacion;
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
 * Función PROMEDIO
 */
float calcularPromedio(float valorAcumulado, int cantidad) {
	float resultadoPromedio;
	resultadoPromedio = valorAcumulado/cantidad;

return resultadoPromedio;
}

#endif /* UTN_C_ */
