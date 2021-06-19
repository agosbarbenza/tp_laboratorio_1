#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int result = 0;
	FILE* pFile;
	pFile = fopen(path, "r");
	if(pFile != NULL){
		result = parser_EmployeeFromText(pFile, pArrayListEmployee);
	}
	fclose(pFile);
	return result;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int result = 0;
		FILE* pFile;
		pFile = fopen(path, "rb");
		if(pFile != NULL){
			result = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		}
		fclose(pFile);
		return result;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int result = 0;
	Employee* newEmployee;

	if(pArrayListEmployee != NULL){
		newEmployee = employee_getData();
		printf("\nSe agregó a: \n%2d %8s %4d %4d", newEmployee->id, newEmployee->nombre, newEmployee->sueldo, newEmployee->horasTrabajadas);
		ll_add(pArrayListEmployee, newEmployee);
		result = 1;
	}
    return result;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int result = 0;
	if(pArrayListEmployee != NULL){
		employee_editEmployees(pArrayListEmployee);
		result = 1;
		}

    return result;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int result = 0;
	if(pArrayListEmployee != NULL){
		if(employee_listAll(pArrayListEmployee)){
			result = 1;
		};
	}

    return result;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int result = 0;
	int index;
	int id;
	Employee* auxEmployee;
		if(pArrayListEmployee != NULL){
			if(controller_ListEmployee(pArrayListEmployee)){
				id = pedirIntRango("\nIngrese el ID del empleado a eliminar: ","\nError. Ingrese un empleado válido\n", 1, 8000, 2);
				index = employee_searchById(pArrayListEmployee, id);
				if(index != -1){
					auxEmployee = ll_get(pArrayListEmployee, index);
					printf("\nAtención! Usted está a punto de eliminar al siguiente empleado:\n");
					employee_listOne(auxEmployee);
					if(confirmarOperacion("", "") != -1){
						ll_remove(pArrayListEmployee, index);
						employee_delete(auxEmployee);
						result = 1;
					};
				}
			};

		}

	    return result;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int result = 0;
	if(pArrayListEmployee != NULL){
		if(employee_orderBy(pArrayListEmployee)){
			result = 1;
		};
	}
    return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int result = 0;
	FILE* pFile;
	pFile = fopen(path, "w");
	if(pFile != NULL){
		if(employee_saveAsText(pArrayListEmployee, pFile)){
			result = 1;
		};
	}
	fclose(pFile);
	return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int result = 0;
	FILE* pFile;
	pFile = fopen(path, "wb");
	if(pFile != NULL){
		if(employee_saveAsBinary(pArrayListEmployee, pFile)){
			result = 1;
		};
	}
	fclose(pFile);
	return result;
}

