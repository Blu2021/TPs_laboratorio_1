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
	int exito=0;
	char buffer[4][128];

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));

	while(!feof(pFile))
	{
		Employee* punteroEmpleado=NULL;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));

		punteroEmpleado=employee_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));
		if(punteroEmpleado!=NULL)
		{
			ll_add(pArrayListEmployee,(Employee*)punteroEmpleado);
			exito=1;
		}
	}
    return exito;
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
	int exito=0;
	Employee empleadoLeidoBin;
	int dimensionLinkedList;
	int dimensionLevantada=0;

	while(!feof(pFile))
	{
		Employee* punteroEmpleado=NULL;

		if(fread(&empleadoLeidoBin,sizeof(Employee),1,pFile))
		{
			dimensionLevantada++;
			punteroEmpleado=employee_new();
			if(punteroEmpleado!=NULL)
			{
				employee_setId(punteroEmpleado,empleadoLeidoBin.id);
				employee_setHorasTrabajadas(punteroEmpleado,empleadoLeidoBin.horasTrabajadas);
				employee_setSueldo(punteroEmpleado,empleadoLeidoBin.sueldo);
				employee_setNombre(punteroEmpleado,empleadoLeidoBin.nombre);
				ll_add(pArrayListEmployee,(Employee*)punteroEmpleado);
				exito=1;
			}
		}
	}
	dimensionLinkedList=ll_len(pArrayListEmployee);
	if(dimensionLevantada!=dimensionLinkedList)
	{
		exito=0;
	}
    return exito;
}
