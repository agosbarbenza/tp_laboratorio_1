#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	mostrarMenu("Cargar los datos de los empleados desde el archivo data.csv (modo texto).", "Cargar los datos de los empleados desde el archivo data.csv (modo binario).",
    			"Alta de empleado", "Modificar datos de empleado", "Baja de empleado",
    			"Listar empleados", "Ordenar empleados", "Guardar los datos de los empleados en el archivo data.csv (modo texto).","Guardar los datos de los empleados en el archivo data.csv (modo binario).", "Salir");

    	option = pedirIntRango("\nSeleccione una opcion:", "Error. Ingrese una opcion v�lida", 1, 10, 2);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)){
                	printf("\nLa carga de datos se realiz� correctamente\n");
                }else{
                	printf("\nError. La carga de datos no se realiz�\n");
                };
                break;
            case 2:
            	if(controller_loadFromBinary("data.bin",listaEmpleados)){
					printf("\nLa carga del archivo se realiz� correctamente\n");
				}else{
					printf("\nError. La carga del archivo no se realiz�\n");
				};
            	break;
            case 3:
            	if(controller_addEmployee(listaEmpleados)){
            		printf("\n");
            	}else{
            		printf("\nError. La carga del empleado no se realiz�\n");
            	};
                break;
            case 4:
            	if(controller_editEmployee(listaEmpleados)){
            		printf("\n");
            	}else{
            		printf("\nError. La modificacion del empleado no se realiz�\n");
            	};
            	break;
            case 5:
            	if(controller_removeEmployee(listaEmpleados)){
            		printf("\nEmpleado dado de baja correctamente.\n");
            	}else{
            		printf("\nError. No se ha podido dar de baja al empleado.\n");
            	};
            	break;
            case 6:
            	if(controller_ListEmployee(listaEmpleados)){
            		printf("\n");
            	}else{
            		printf("\nError, no se pueden mostrar los empleados\n");
            	}
            	break;
            case 7:
            	if(controller_sortEmployee(listaEmpleados)){
            		printf("\nEmpleados ordenados con �xito\n");
            	}else{
            		printf("\nError. No se ha podido ordenar a los empleados\n");
            	};
            	break;
            case 8:
            	if(controller_saveAsText("data.csv", listaEmpleados)){
            		printf("\nEl archivo se escribi� correctamente.\n");
            	}else{
            		printf("\nError. No se ha podido guardar el archivo de texto.\n");
            	};
            	break;
            case 9:
            	if(controller_saveAsBinary("data.bin" , listaEmpleados)){
            		printf("\nEl archivo se escribi� correctamente.\n");
            	}else{
            		printf("\nError. No se ha podido guardar el archivo binario.\n");
            	};
            	break;
            case 10:
            	printf("\nSaliendo con �xito del programa.");
            	break;
        }
    }while(option != 10);
    return 0;
}

