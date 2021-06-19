#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Reserva espacio de memoria en heap
 *
 * \return Employee* puntero a empleado
 *
 */
Employee* employee_new(){
	Employee* newEmployee;

	newEmployee = (Employee*) calloc(sizeof(Employee), 1);

	return newEmployee;
}

/**\brief Setea datos dentro de un puntero Employee*
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return newEmployee Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* newEmployee;
	newEmployee = employee_new();

	if(newEmployee != NULL){
		employee_setId(newEmployee, atoi(idStr));
		employee_setSueldo(newEmployee, atoi(sueldoStr));
		employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
		employee_setNombre(newEmployee,nombreStr);

		}else{
			printf("\nError, los datos no se han podido cargar. Espacio insuficiente en memoria.");
		}

	return newEmployee;
}

/**\brief Obtiene datos del usuario y llama a la funcion que guardará los datos dentro de un puntero Employee*
 * \param pArrayListEmployee LinkedList*
 * \return newEmployee Employee*
 *
 */

Employee* employee_getData(LinkedList* pArrayListEmployee){
	Employee* newEmployee;
	int auxId;
	char id[5];
	char nombre[128];
	char salario[7];
	char horasTrabajadas[4];


	auxId = employee_calculateLastId(pArrayListEmployee);
	pedirCadena("Ingrese el nombre: ", "Error, ingrese un nombre valido" , nombre);
	pedirCadena("Ingrese el salario: ", "Error, ingrese un salario valido" , salario);
	pedirCadena("Ingrese la cantidad de horas trabajadas: ", "Error, ingrese una cantidad válida" , horasTrabajadas);
	auxId = auxId + 1;
	strcpy(id, itoa(auxId, id, 10));
	newEmployee = employee_newParametros(id, nombre, horasTrabajadas, salario);
	return newEmployee;
}


/**\brief Obtiene el último id existente en una LinkedList
 * \param pArrayListEmployee LinkedList*
 * \return lastId int
 */

int employee_calculateLastId(LinkedList* pArrayListEmployee){
	int lastId;
	lastId = 0;
	int len;
	int i;
	int flagId = 0;
	int auxId;
	Employee* auxEmployee;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len>0){
		for(i=0; i<len; i++){
			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &auxId);
			if(auxId>lastId || flagId == 0){
				lastId = auxId;
				flagId = 1;
			}
		}
	}
	return lastId;

}


/**\brief Llama a la función que se encargará de editar un empleado
 * \param pArrayListEmployee LinkedList*
 * \return result int
 */

int employee_editEmployees(LinkedList* pArrayListEmployee){
	int result = 0;
	int id;
	int index;
	int auxId;
	int auxSalario;
	int auxHoras;
	char auxNombre[128];
	Employee* auxEmployee;
	if(pArrayListEmployee != NULL){
		if(employee_listAll(pArrayListEmployee)){
			id = pedirIntRango("\nIngrese un ID: ",
					"\nError! Ingrese un ID entre 1 y 9999", 1, 9999, 2);
			if(id != -1){
				index = employee_searchById(pArrayListEmployee, id);
				if(index != -1){
					auxEmployee = ll_get(pArrayListEmployee, index);
					if(employees_editOneEmployee(auxEmployee) != 0){
						printf("\nEmpleado modificado con éxito: ");
						employee_getId(auxEmployee, &auxId);
						employee_getSueldo(auxEmployee, &auxSalario);
						employee_getNombre(auxEmployee, auxNombre);
						employee_getHorasTrabajadas(auxEmployee, &auxHoras);
						printf("\n%2d %8s %4d %4d", auxId, auxNombre, auxHoras, auxSalario);
						result = 1;
					}else{
						printf("\nNo se ha modificado al empleado.\n");
						};
					}

				}
			}
		}else{
			printf("\nNo hay empleados para modificar.\n");
		}
	return result;
	}


/**\brief Edita los campos de un empleado
 * \param this Employee*
 * \return result int
 */

int employees_editOneEmployee(Employee* this){
	int option;
	int result = 0;
	char nombre[128];
	int salario;
	int horasTrabajadas;

	if(this != NULL){
	mostrarMenuEditar("Nombre", "Sueldo", "Horas trabajadas");
	scanf("%d", &option);
	switch(option){
			case 1:
				pedirCadena("Ingrese el nombre: ", "Error, ingrese un nombre valido" , nombre);
				employee_setNombre(this, nombre);
				result = 1;
				break;
			case 2:
				salario = pedirIntRango("Ingrese el salario: ", "Error, ingrese un salario valido" , 1000, 400000, 2);
				employee_setSueldo(this, salario);
				result = 1;
				break;
			case 3:
				horasTrabajadas = pedirIntRango("Ingrese la cantidad de horas trabajadas: ", "Error, ingrese una cantidad válida", 1, 200, 2);
				employee_setHorasTrabajadas(this, horasTrabajadas);
				result = 1;
				break;
	}
}

	return result;
}

/**\brief Busca un empleado por id en una LinkedList, retornando la posicion en esa LL
 * \param pArrayListEmployee LinkedList*
 * \param idChosen int
 * \return result int
 */
int employee_searchById(LinkedList* pArrayListEmployee, int idChosen){
	int result = -1;
	Employee* auxEmployee;
	int i;
	int len;
	int auxId;

	if(pArrayListEmployee != NULL && idChosen>0){
	len = ll_len(pArrayListEmployee);
		for(i=0; i<len; i++){
			auxEmployee = ll_get(pArrayListEmployee, i);
			if((employee_getId(auxEmployee, &auxId) != 0) && auxId == idChosen){
				result = i;
			}
		}
	}
	return result;
}



/* ============ SETTERS ============ */

/**\brief Setea el nombre de un puntero a Employee
 * \param this Employee*
 * \param nombre char*
 * \return result int
 */

int employee_setNombre(Employee* this,char* nombre){
	int result = 0;
	if(this !=NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		result = 1;
	}
	return result;
}

/**\brief Setea las horas trabajadas de un puntero a Employee
 * \param this Employee*
 * \param horasTrabajadas int
 * \return result int
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int result = 0;
		if(this !=NULL && horasTrabajadas>0){
			this->horasTrabajadas = horasTrabajadas;
			result = 1;
		}
		return result;
}

/**\brief Setea el sueldo de un puntero a Employee
 * \param this Employee*
 * \param sueldo int
 * \return result int
 */
int employee_setSueldo(Employee* this,int sueldo){
	int result = 0;
	if(this !=NULL && sueldo>0){
		this->sueldo = sueldo;
		result = 1;
	}
	return result;
}

/**\brief Setea el id de un puntero a Employee
 * \param this Employee*
 * \param id int
 * \return result int
 */
int employee_setId(Employee* this,int id){
	int result = 0;
		if(this !=NULL && id>0){
			this->id = id;
			result = 1;
		}
		return result;
}

/* ================================== */

/* ============ GETTERS ============ */

/**\brief Obtiene el id de un puntero a Employee
 * \param this Employee*
 * \param id int*
 * \return result int
 */
int employee_getId(Employee* this,int* id){
	int result = 0;
	if(this !=NULL && id>0){
		*id = this->id;
		result = 1;
	}
	return result;

}

/**\brief Obtiene las horas trabajadas de un puntero a Employee
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return result int
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int result = 0;
	if(this !=NULL && horasTrabajadas>0){
		*horasTrabajadas = this->horasTrabajadas;
		result = 1;
	}
	return result;
}

/**\brief Obtiene el sueldo de un puntero a Employee
 * \param this Employee*
 * \param sueldo int*
 * \return result int
 */
int employee_getSueldo(Employee* this,int* sueldo){
	int result = 0;
	if(this !=NULL && sueldo>0){
		*sueldo = this->sueldo;
	result = 1;
	}
		return result;

}

/**\brief Obtiene el nombre de un puntero a Employee
 * \param this Employee*
 * \param nombre char*
 * \return result int
 */
int employee_getNombre(Employee* this,char* nombre){
	int result = 0;
	if(this !=NULL){
		strcpy(nombre, this->nombre);
		result = 1;
	}
	return result;

}
/* ================================== */

/**\brief Muestra todos los empleados existentes en una LL
 * \param pArrayListEmployee LinkedList*
 * \return result int
 */
int employee_listAll(LinkedList* pArrayListEmployee){
	Employee* auxEmp;
	int result = 0;
	int i;
	int len;

	if(pArrayListEmployee != NULL){
		len = ll_len(pArrayListEmployee);
			if(len>0){
			for(i=0; i<len; i++){
				auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
				employee_listOne(auxEmp);
			}
			result = 1;
			}else{
				printf("\nNo hay empleados para mostrar.\n");
			}
	}

	return result;
}

/**\brief Muestra un empleado existente en una LL
 * \param this Employee*
 * \return result int
 */
int employee_listOne(Employee* this){
	int result = 0;
	int id;
	int sueldo;
	int horasTrabajadas;
	char nombre[128];
	if(this != NULL){
		employee_getId(this, &id);
		employee_getSueldo(this, &sueldo);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horasTrabajadas);
		printf("\n%4d %10s %6d %6d\n", id, nombre, horasTrabajadas, sueldo);
		result = 1;
	}else{
		printf("No hay empleado para mostrar.");
	}
	return result;
}


/**\brief Realiza un free de un puntero a empleado
 * \param this Employee*
 * \return void
 */
void employee_delete(Employee* this){
	free(this);
}


/**\brief Ordena empleados por nombre
 * \param firstEmployee void*
 * \param secondEmployee void*
 * \return result int
 */
int employee_orderByName(void* firstEmployee, void* secondEmployee){
	int result = 0;
	char firstName[128];
	char secondName[128];
	employee_getNombre(firstEmployee, firstName);
	employee_getNombre(secondEmployee, secondName);

	if(strcmp(firstName, secondName)>0){
		result = 1;
	}else{
		if(strcmp(firstName, secondName)<0){
			result = -1;
		}
	}
	return result;
}

/**\brief Ordena empleados por id
 * \param firstEmployee void*
 * \param secondEmployee void*
 * \return result int
 */
int employee_orderById(void* firstEmployee, void* secondEmployee){
	int result = 0;
	int firstId;
	int secondId;
	employee_getId(firstEmployee, &firstId);
	employee_getId(secondEmployee, &secondId);

	if(firstId > secondId){
		result = 1;
	}else{
		if(firstId < secondId){
			result = -1;
		}
	}
	return result;
}

/**\brief Ordena empleados por salario
 * \param firstEmployee void*
 * \param secondEmployee void*
 * \return result int
 */
int employee_orderBySalary(void* firstEmployee, void* secondEmployee){
	int result = 0;
	int firstSueldo;
	int secondSueldo;
	employee_getSueldo(firstEmployee, &firstSueldo);
	employee_getSueldo(secondEmployee, &secondSueldo);

	if(firstSueldo > secondSueldo){
		result = 1;
	}else{
		if(firstSueldo < secondSueldo){
			result = -1;
		}
	}
	return result;
}

/**\brief Ordena empleados por horas trabajadas
 * \param firstEmployee void*
 * \param secondEmployee void*
 * \return result int
 */
int employee_orderByWorkedHrs(void* firstEmployee, void* secondEmployee){
	int result = 0;
	int firstHoras;
	int secondHoras;
	employee_getHorasTrabajadas(firstEmployee, &firstHoras);
	employee_getHorasTrabajadas(secondEmployee, &secondHoras);

	if(firstHoras > secondHoras){
		result = 1;
	}else{
		if(firstHoras < secondHoras){
			result = -1;
		}
	}
	return result;
}

/**\brief Llama a las funciones que realizaran un ordenamiento de la lista de empleados segun un criterio particular
 * \param pArrayListEmployee LinkedList*
 * \return result int
 */
int employee_orderBy(LinkedList* pArrayListEmployee){
	int result = 0;
	int criteria;
	int subCriteria;

	mostrarMenuOrdenar("Nombre", "Id", "Salario", "Horas trabajadas");
	criteria = pedirIntRango("\nOpcion elegida: ", "Error, ingrese una opcion válida", 1, 5, 2);
	switch(criteria){
		case 1:
			subCriteria = pedirIntRango("\nIndique el subcriterio: \n1 para Ascendente \n0 para Descendente\n", "Error, ingrese una opcion válida \n1 para Ascendente \n0 para Descendente\n", 0, 1, 2);
			printf("\nOrdenando empleados, aguarde un momento...");
			ll_sort(pArrayListEmployee,employee_orderByName,subCriteria);
			result = 1;
		break;
		case 2:
			subCriteria = pedirIntRango("Indique el criterio: \n1 para Ascendente \n0 para Descendente\n", "Error, ingrese una opcion válida \n1 para Ascendente \n0 para Descendente\n", 0, 1, 2);
			printf("\nOrdenando empleados, aguarde un momento...");
			ll_sort(pArrayListEmployee,employee_orderById,subCriteria);
			result = 1;
		break;
		case 3:
			subCriteria = pedirIntRango("\nIndique el subcriterio: \n1 para Ascendente \n0 para Descendente\n", "Error, ingrese una opcion válida \n1 para Ascendente \n0 para Descendente\n", 0, 1, 2);
			printf("\nOrdenando empleados, aguarde un momento...");
			ll_sort(pArrayListEmployee,employee_orderBySalary,subCriteria);
			result = 1;

		break;
		case 4:
			subCriteria = pedirIntRango("\nIndique el subcriterio: \n1 para Ascendente \n0 para Descendente\n", "Error, ingrese una opcion válida \n1 para Ascendente \n0 para Descendente\n", 0, 1, 2);
			printf("\nOrdenando empleados, aguarde un momento...");
			ll_sort(pArrayListEmployee,employee_orderByWorkedHrs,subCriteria);
			result = 1;
		break;
		default:
			printf("\nNo se encontró el criterio de ordenamiento\n");
		break;

	}
	return result;
}


/**\brief Guarda un archivo como texto
 * \param pArrayListEmployee LinkedList*
 * \param pFile FILE*
 * \return result int
 */
int employee_saveAsText(LinkedList* pArrayListEmployee, FILE* pFile){
	int result = 0;
	int len;
	int i;
	int id;
	int salario;
	int horasTrabajadas;
	char nombre[128];
	Employee* auxEmployee;
	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL){
	for(i=0; i<len; i++){
		auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
		employee_getId(auxEmployee, &id);
		employee_getSueldo(auxEmployee, &salario);
		employee_getNombre(auxEmployee, nombre);
		employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
			fprintf(pFile, "%d, %s, %d, %d\n", id, nombre, horasTrabajadas, salario);
		}
	result = 1;
	}

	return result;

}

/**\brief Guarda un archivo como binario
 * \param pArrayListEmployee LinkedList*
 * \param pFile FILE*
 * \return result int
 */
int employee_saveAsBinary(LinkedList* pArrayListEmployee, FILE* pFile){
	int result = 0;
	int len;
	int i;

	Employee* auxEmployee;
	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL){
	for(i=0; i<len; i++){
		auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(&auxEmployee, sizeof(Employee), 1, pFile);
		}
	result = 1;
	}

	return result;

}
