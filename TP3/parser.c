#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
		Employee* newEmployee;
		char id[20];
		char nombre[100];
		char horasTrabajadas[5];
		char sueldo[8];
		int i = 0;
		int result = 0;

		if(pFile != NULL){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
			while(!feof(pFile)){
					fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
					newEmployee = employee_newParametros(id,nombre,horasTrabajadas, sueldo);
					if(newEmployee != NULL){
						ll_add(pArrayListEmployee, newEmployee);
				}
				i++;
			}
			result = 1;
		}else{
			printf("Error, no se pudo cargar el archivo");
		}

    return result;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* newEmployee;
	int result = 0;

	if(pFile != NULL){
		while(!feof(pFile)){
			newEmployee = employee_new();
			fread(newEmployee, sizeof(Employee),1, pFile);
			ll_add(pArrayListEmployee, newEmployee);

		}
		result = 1;
	}else{
		printf("\nError, no se pudo cargar el archivo");
	}
    return result;
}
