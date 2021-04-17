/*
 ============================================================================
 Nombre      : TP_Laboratorio_1 - Calculadora
 Autor       : Agostina Barbenza
 Division    : 1 "F"
 Materia     : Laboratorio 1
 Descripción : Calculadora que realiza las operaciones de suma, resta,
 división, multiplicación y factorial, y muestra los resultados.
 ============================================================================
 */

/*------------------------------------------------ACLARACIONES----------------------------------------------:
 * 1) Cursé la materia el segundo cuatrimestre del 2020 (1 "E"), ya había entregado y aprobado el tp 1.
 * Estoy usando el mismo código con algunas modificaciones, si necesitan pueden ver mi tp del año pasado acá:
 * https://github.com/agosbarbenza/tp_laboratorio_1_2020
 *
 * 2) Este programa utiliza las funciones system("CLS") y system("PAUSE"), por esto sería conveniente
 * correrlo desde la terminal para una mejor visualización.
 *
 *3) A las palabras dentro de los printf no les puse tilde porque al ejecutarse el programa por terminal cmd
 *	las mismas figuran con caracteres extraños.
 ------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calculos.h" //Librería de funciones que realizan los calculos matemáticos

int main(void) {
	setbuf(stdout, NULL);

	int opcion = 0;
	int flagOper1 = 0;
	int flagOper2 = 0;
	int flagOperacionesOk = 0;
	float primerOp = 0;
	float segundoOp = 0;
	float resultSuma = 0;
	float resultResta = 0;
	float resultDiv = 0;
	float resultMult = 0;
	double resultFactPrimerOp = 0;
	double resultFactSegundoOp = 0;

	printf("\n*******************\n****CALCULADORA****\n*******************");
	do {
		system("CLS");
		if (flagOper1 == 0 && flagOper2 == 0) {
			mostrarMenuFlagsCero();
		} else if (flagOper1 == 1 && flagOper2 == 0) {
			mostrarMenuFlagUnoYFlagCero(primerOp);
		} else if (flagOper1 == 1 && flagOper2 == 1) {
			mostrarMenuFlagsUno(primerOp, segundoOp);
		}
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			if (flagOper1 == 0) {
				system("CLS");
				primerOp = pedirFloat("\n 1. Ingresar 1er operando (A=x) ", "Error, ingrese un numero valido: ");
				flagOper1 = 1;
			} else {
				printf("\n Atencion! Usted ya ingreso el numero %.2f como 1er operando, ahora debe ingresar el 2do.\n",
						primerOp);
				system("PAUSE");
			}
			break;

		case 2:
			if (flagOper1 == 0) {
				printf("\n Atencion! Para continuar debe ingresar el 1er operando\n");
				system("PAUSE");
			} else if(flagOper2 == 1){
				printf("\n Atencion! Usted ya ingreso el numero %.2f como 2do operando, ahora debe realizar los calculos\n", segundoOp);
				system("PAUSE");
			}else{
				system("CLS");
				segundoOp = pedirFloat("\n 2.Ingresar 2do operando (B=y) ","Error, ingrese un numero valido: " );
				flagOper2 = 1;
			}
			break;

		case 3:
			if (flagOper1 == 1 && flagOper2 == 1) {
				system("CLS");
				resultSuma = sumar(primerOp, segundoOp);
				resultResta = restar(primerOp, segundoOp);
				resultDiv = dividir(primerOp, segundoOp);
				resultMult = multiplicar(primerOp, segundoOp);
				resultFactPrimerOp = factorial(primerOp);
				resultFactSegundoOp = factorial(segundoOp);
				printf("\n3.Calcular todas las operaciones: ");
				printf("\nLos calculos se realizaron correctamente\n");
				flagOperacionesOk = 1;
				system("PAUSE");
			} else {
				printf("\n Atencion! Para continuar debe ingresar primero los operandos\n");
				system("PAUSE");
			}
			break;

		case 4:
			if(flagOperacionesOk == 0){
				printf("\n Atencion! No se pueden mostrar los resultados ya que aún no realizó los cálculos!\n");
				system("PAUSE");
			}else if (flagOper1 == 1 && flagOper2 == 1) {
				system("CLS");
				mostrarResultado(primerOp, segundoOp, resultSuma, resultResta,
						resultDiv, resultMult, resultFactPrimerOp,
						resultFactSegundoOp);
				system("PAUSE");
			} else {
				printf("\n Atencion! Para continuar debe ingresar primero los operandos...\n");
				system("PAUSE");
			}
			break;

		case 5:
			system("CLS");
			flagOper1 = 0;
			flagOper2 = 0;
			printf("Saliendo con exito...");
			system("PAUSE");
			break;

		default:
			system("CLS");
			printf("La opcion ingresada no es correcta, elija entre 1,2,3,4 o 5\n");
			system("PAUSE");
			system("CLS");
			break;
		}

	} while (!(opcion == 5));

	return 0;
}
