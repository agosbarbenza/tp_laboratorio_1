/*
 ============================================================================
 Name        : Tp_laboratorio_2.c
 Author      : Agostina Barbenza 1 "F" Turno noche
 Version     :
 Copyright   : 
 Description : 2° Tp de Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Utn.h"

#define EMPTY 0
#define TAKEN 1
#define Q_EMPLOYEES 1000
#define Q_HARDCODE 10

int main(void) {
	setbuf(stdout, NULL);
	eEmployee arrayEmployees[Q_EMPLOYEES];
	initEmployees(arrayEmployees, Q_EMPLOYEES);
	hardCodeEmployees(arrayEmployees, Q_HARDCODE);
	int option;
	int incrementalId = 999;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int idToRemove;
	int idToModify;
	int informOption;
	int orderCriteria;

	do {
		mostrarMenu("Sistema Empleados", "ALTAS", "BAJAS", "MODIFICAR",
				"INFORMAR", "SALIR");
		option = pedirIntSinRango(" ");
		switch (option) {
		case 1:
			if (getEmployeeData(arrayEmployees, Q_EMPLOYEES, &incrementalId,
					name, lastName, &salary, &sector) == 0
					&& addEmployee(arrayEmployees, Q_EMPLOYEES, incrementalId,
							name, lastName, salary, sector) == 0) {

				printf("\nEmpleado cargado correctamente.");
			} else {
				printf(
						"\nEl empleado no ha sido cargado. Vuelva a intentarlo.");
			}
			break;
		case 2:
			if (printEmployees(arrayEmployees, Q_EMPLOYEES) == 0) {
				idToRemove = pedirIntRango(
						"\n\nIngrese el ID del empleado a remover: ",
						"Error! Ingrese un ID entre 1000 y 3000", 1000, 3000);
				if (removeEmployee(arrayEmployees, Q_EMPLOYEES, idToRemove)
						== 0) {
					printf(
							"\nEmpleado removido de la base de datos correctamente.");
				} else {
					printf(
							"\nEl empleado no ha sido removido de la base de datos. Vuelva a intentarlo.");
				};
			} else {
				printf(
						"\n\nError! No hay empleados disponibles para remover de la base de datos.");
			}
			;
			break;
		case 3:
			if (printEmployees(arrayEmployees, Q_EMPLOYEES) == 0) {
				idToModify = pedirIntRango(
						"\n\nIngrese el ID del empleado a modificar: ",
						"Error! Ingrese un ID entre 1000 y 3000", 1000, 3000);
				if (modifyEmployee(arrayEmployees, Q_EMPLOYEES, idToModify)
						== 0) {
					printf("\nEmpleado modificado con éxito.");
				} else {
					printf("\nError, no se modificó el empleado.");
				};
			} else {
				printf("\nNo hay empleados disponibles para modificar");
			}
			break;
		case 4:
			if (checkAtLeastOneRegister(arrayEmployees, Q_EMPLOYEES) == 0) {
				subMenuInform();
				informOption = pedirIntRango("\n",
						"Error! Ingrese una opcion correcta", 1, 2);
				switch (informOption) {
				case 1:
					subMenuOrderCriteria();
					orderCriteria = pedirIntRango("\n",
							"Error! Ingrese una opcion correcta", 0, 1);
					if (sortEmployees(arrayEmployees, Q_EMPLOYEES,
							orderCriteria) == 0) {
						printf("\n\nEmpleados ordenados con éxito");
					} else {
						printf("\n\nNo se ha podido ordenar a los empleados.");
					}
					;
					break;
				case 2:
					if (checkAtLeastOneRegister(arrayEmployees, Q_EMPLOYEES)
							== 0) {
						if (printEmployees(arrayEmployees, Q_EMPLOYEES) == 0) {
							if (calculateAverageSalary(arrayEmployees,
									Q_EMPLOYEES) == 0) {
								printf("\n");
							} else {
								printf("\nNo hay salarios para mostrar.");
							}
						} else {
							printf("\nNo hay empleados para mostrar.");
						}
					} else {
						printf("\nNo hay información para mostrar");
					}
					break;
				}
			}else{
				printf("\nError, no hay información para mostrar.");
			}

			break;
		case 5:
			printf("\n\nSistema cerrado con éxito.");
			break;
		}
	} while (option != 5);
	return EXIT_SUCCESS;
}
