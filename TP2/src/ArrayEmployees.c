/*
 * eArrayEmployees.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Utn.h"

#define EMPTY 0
#define TAKEN 1


void showSectors(void) {
	printf(
			"\nListado de sectores:\n1 para RRHH\n2 para SISTEMAS\n3 para CONTABILIDAD\n4 para ADMINISTRACION\n");
}
void subMenuModify(void) {
	printf(
			"\nIngrese el dato a modificar: \n1)Nombre \n2)Apellido \n3)Salario \n4)Sector\n");
}
void subMenuInform(void) {
	printf(
			"\nSeleccione el informe: \n1)Empleados ordenados por apellido y sector\n2)Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n");
}

void subMenuOrderCriteria(void) {
	printf(
			"\nIngrese el criterio de ordenamiento: \n0 para Menor a Mayor \n1 para Mayor a Menor \n");
}

int initEmployees(eEmployee list[], int len) {
	int resultInit = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
		}
		resultInit = 0;
	}
	return resultInit;
}

int addEmployee(eEmployee list[], int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int resultAdd = -1;
	int indexEmpty;

	if (list != NULL && len > 0) {

		indexEmpty = findEmptyIndex(list, len);
		if (indexEmpty != -1) {
			if (confirmarOperacion("\nDesea confirmar la operacion? si-no",
					"\nError, desea confirmar la operación? si - no") == 0) {
				list[indexEmpty].id = id;
				strcpy(list[indexEmpty].name, name);
				strcpy(list[indexEmpty].lastName, lastName);
				list[indexEmpty].salary = salary;
				list[indexEmpty].sector = sector;
				list[indexEmpty].isEmpty = TAKEN;
				resultAdd = 0;
			}
		}
	}

	return resultAdd;
}

int getEmployeeData(eEmployee list[], int len, int *incrementalId, char name[],
		char lastName[], float *salary, int *sector) {
	int resultGetData = -1;
	int auxId = *incrementalId + 1;

	if (list != NULL) {

		pedirCadena("\nIngrese el nombre del empleado: ",
				"\nError! Ingrese un nombre válido: ", name);
		pedirCadena("\nIngrese el apellido del empleado: ",
				"\nError! Ingrese un apellido válido: ", lastName);
		*salary = pedirFloat("\nIngrese el salario: ",
				"\nError! Ingrese un salario válido: ");
		showSectors();
		*sector = pedirIntRango("\nElija un sector: ",
				"Error, el sector elegido no es válido ", 1, 4);
		printf(
				"\n=======================================================================");
		printf(
				"\nLos datos ingresados son los siguientes:\n\nNombre: %s | Apellido: %s | Salario: %.2f  | Sector: %d",
				name, lastName, *salary, *sector);
		printf(
				"\n=======================================================================\n");
		*incrementalId = auxId;
		resultGetData = 0;

	}
	return resultGetData;
}

int findEmployeeById(eEmployee list[], int len, int id) {
	int resultFind = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				resultFind = i;
				break;
			}
		}
	}

	return resultFind;
}

int findEmptyIndex(eEmployee list[], int len) {
	int index = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == EMPTY) {
				index = i;
				break;
			}
		}
	}

	return index;
}

int removeEmployee(eEmployee list[], int len, int id) {
	int resultRemove = -1;
	int index;
	int atLeastOneRegister = -1;

	if (list != NULL && len > 0) {
		atLeastOneRegister = checkAtLeastOneRegister(list, len);

		if (atLeastOneRegister == 0) {
			index = findEmployeeById(list, len, id);
		}
		if (index != -1) {
			printf(
					"\nEstá a punto de remover al empleado ID N°%d, cuyo nombre es %s %s",
					list[index].id, list[index].name, list[index].lastName);
			if (confirmarOperacion("Desea confirmar la operacion? si - no",
					"Error. Desea confirmar la operacion? si - no") == 0) {
				list[index].isEmpty = EMPTY;
				resultRemove = 0;
			}
		}
	}

	return resultRemove;
}

int printEmployees(eEmployee list[], int len) {
	int resultPrint = -1;
	int i;
	int qty_Employees = 0;

	if (list != NULL && len > 0) {
		printf(
				"\n==================================================\nListado de Empleados: \n==================================================");
		printf("\nID      NOMBRE     APELLIDO    SECTOR      SALARIO");
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TAKEN) {
				printEmployee(list[i]);
				qty_Employees++;
			}
		}
		if (qty_Employees > 0) {
			resultPrint = 0;
		}
	}
	return resultPrint;
}

void printEmployee(eEmployee employee) {

	printf("\n%3d %9s %12s %9d %12.2f", employee.id, employee.name,
			employee.lastName, employee.sector, employee.salary);

}

void hardCodeEmployees(eEmployee list[], int len) {
	int idEmployee[] = { 1500, 1501, 1502, 1503, 1504, 1505, 1506, 1507, 1508,
			1509 };
	char nameEmployee[][51] = { "Avril", "Amy", "James", "Chris", "Eddie",
			"Bruno", "Alicia", "Anthony", "Alanis", "Bruce" };
	char lastNameEmployee[][51] = { "Lavigne", "Lee", "Hetfield", "Cornell",
			"Vedder", "Mars", "Keys", "Dickinson", "Morissette", "Dickinson" };
	int salary[] = { 120000, 125500, 78000, 80120, 169000, 82150, 100005,
			147800, 200000, 99000 };
	int sector[] = { 1, 2, 3, 4, 2, 3, 1, 3, 2, 1 };

	int i;

	for (i = 0; i < len; i++) {
		list[i].id = idEmployee[i];
		strcpy(list[i].name, nameEmployee[i]);
		strcpy(list[i].lastName, lastNameEmployee[i]);
		list[i].salary = salary[i];
		list[i].sector = sector[i];
		list[i].isEmpty = TAKEN;
	}

}

int modifyEmployee(eEmployee list[], int len, int id) {
	int resultModify = -1;
	int atLeastOneRegister = -1;
	int optionToModify;
	int index;
	char name[51];
	char lastName[51];

	if (list != NULL && len > 0) {
		atLeastOneRegister = checkAtLeastOneRegister(list, len);

		if (atLeastOneRegister == 0) {
			index = findEmployeeById(list, len, id);
		}
		if (index != -1) {
			subMenuModify();
			optionToModify = pedirIntRango("\n",
					"Error, ingrese una opcion valida", 1, 4);
			switch (optionToModify) {
			case 1:
				pedirCadena("\nIngrese el nombre del empleado: ",
						"\nError! Ingrese un nombre válido: ", name);
				strcpy(list[index].name, name);
				break;
			case 2:
				pedirCadena("\nIngrese el apellido del empleado: ",
						"\nError! Ingrese un apellido válido: ", lastName);
				strcpy(list[index].lastName, lastName);
				break;
			case 3:
				list[index].salary = pedirFloat("\nIngrese el salario: ",
						"\nError! Ingrese un salario válido: ");
				break;
			case 4:
				showSectors();
				list[index].sector = pedirIntRango("\nElija un sector: ",
						"Error, el sector elegido no es válido ", 1, 4);
				break;
			}
			resultModify = 0;
		}
	}

	return resultModify;
}

int sortEmployees(eEmployee list[], int len, int order) {
	int resultSort = -1;
	int i;
	if (list != NULL && len > 0) {
		switch (order) {
		case 0:
			for (i = 0; i < len; i++) {
				sortLowerToHigher(list, len, i);
			}
			break;
		case 1:
			for (i = 0; i < len; i++) {
				sortHigherToLower(list, len, i);
			}
			break;
		}
		printEmployees(list, len);
		resultSort = 0;
	}
	return resultSort;
}

void sortLowerToHigher(eEmployee list[], int len, int i) {
	int j;
	eEmployee auxiliar;
	if (list != NULL && len > 0) {
		for (j = i + 1; j < len; j++) {
			if (list[i].isEmpty == TAKEN && list[j].isEmpty == TAKEN) {
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {
					if (list[i].sector > list[j].sector) {
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
				} else {
					if (strcmp(list[i].lastName, list[j].lastName) > 0) {
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
				}

			}
		}
	}

}

void sortHigherToLower(eEmployee list[], int len, int i) {
	int j;
	eEmployee auxiliar;

	if (list != NULL && len > 0) {
		for (j = i + 1; j < len; j++) {
			if (list[i].isEmpty == TAKEN && list[j].isEmpty == TAKEN) {
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {
					if (list[i].sector < list[j].sector) {
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}

				} else {
					if (strcmp(list[i].lastName, list[j].lastName) < 0) {
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
				}

			}
		}
	}

}

int calculateAverageSalary(eEmployee list[], int len) {
	int resultCalculate = -1;
	int atLeastOneRegister = -1;
	float accruedWages = 0;
	float averageSalaries = 0;
	int sumEmployees = 0;
	int sumEmployeesUpAverageSalary = 0;
	int i;

	if (list != NULL && len > 0) {

		atLeastOneRegister = checkAtLeastOneRegister(list, len);

		if (atLeastOneRegister == 0) {
			for (i = 0; i < len; i++) {
				if (list[i].isEmpty == TAKEN) {
					accruedWages += list[i].salary;
					sumEmployees++;
				}

			}
			averageSalaries = calcularPromedio(accruedWages, sumEmployees);

			for (i = 0; i < len; i++) {
				if (list[i].isEmpty == TAKEN
						&& list[i].salary > averageSalaries) {
					sumEmployeesUpAverageSalary++;
				}

			}
			printf("\n==================================================");
			printf(
					"\nTotal salarios: $%.2f\n\nPromedio salarios: $%.2f\n\nCantidad de empleados que superan el salario promedio: %d",
					accruedWages, averageSalaries, sumEmployeesUpAverageSalary);
			printf("\n==================================================");
			resultCalculate = 0;
		}

	}

	return resultCalculate;
}

int checkAtLeastOneRegister(eEmployee list[], int len) {
	int resultAtLeastOne = -1;
	int i;
	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TAKEN) {
				resultAtLeastOne = 0;
				break;
			}
		}
	}
	return resultAtLeastOne;
}
