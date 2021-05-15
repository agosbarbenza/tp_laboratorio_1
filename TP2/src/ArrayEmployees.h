/*
 * eArrayEmployees.h
 *
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;



/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee [], int );


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(eEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Get employee data from user and add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int getEmployeeData(eEmployee list[], int len, int* id, char name[],
		char lastName[], float *salary, int *sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee list[], int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */

int removeEmployee(eEmployee list[], int len,int id);

/** \brief print the content of one employee
 *
 * \param struct one Employee
 * \return int
 *
 */
void printEmployee(eEmployee employee);



/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int (-1) if Error, 0 if OK
 *
 */
int printEmployees(eEmployee list[], int len);

/** \brief Finds an index where isEmpty equals EMPTY
 *
 * \param list Employee*
 * \param length int
 * \return int (-1) if Error, 0 if OK
 *
 */
int findEmptyIndex(eEmployee list[], int len);

/** \brief Hardcodes an eEmployee array with 10 employees
 *
 * \param list Employee*
 * \param length int
 * \return void
 *
 */
void hardCodeEmployees(eEmployee list[], int len);

/** \brief Shows a menu and gives the chance to user to pick a field to modify
 *
 * \param void
 * \return void
 *
 */
void subMenuModify(void);


/** \brief Modifies a field from an employee
 *
 * \param list Employee*
 * \param length int
 * \param id int
 * \return int (-1) if Error, 0 if OK
 *
 */
int modifyEmployee(eEmployee list[], int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee list[], int len, int order);

/** \brief Sort the elements in the array of employees from down to up
 *
 * \param list Employee*
 * \param len int
 * \param i index
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void sortLowerToHigher(eEmployee list[], int len, int i);

/** \brief Sort the elements in the array of employees from up to down
 *
 * \param list Employee*
 * \param len int
 * \param i index
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void sortHigherToLower(eEmployee list[], int len, int i);


/** \brief Shows submenu giving the user inform options
 *
 * \param void
 * \return no
 *
 */

void subMenuInform(void);

/** \brief Shows a list of sectors
 *
 * \param void
 * \return void
 *
 */

void showSectors(void);

/** \brief Shows submenu giving the user the chance to pick order criteria
 *
 * \param void
 * \return no
 *
 */
void subMenuOrderCriteria(void);

/** \brief Calculates average salary for an array of employees
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int calculateAverageSalary(eEmployee list[], int len);

/** \brief Checks if there is at least one employee on the database
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int checkAtLeastOneRegister(eEmployee list[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
