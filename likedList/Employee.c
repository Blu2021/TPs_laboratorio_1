#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* punteroEmpleado;

	punteroEmpleado=((Employee*)malloc(sizeof(Employee)));
	if(punteroEmpleado!=NULL)
	{
		employee_setId(punteroEmpleado,atoi(idStr));
		employee_setNombre(punteroEmpleado,nombreStr);
		employee_setHorasTrabajadas(punteroEmpleado,atoi(horasTrabajadasStr));
		employee_setSueldo(punteroEmpleado,atoi(sueldo));
	}

	return punteroEmpleado;
}

Employee* employee_new()
{
	Employee* punteroEmpleado;

	punteroEmpleado=((Employee*)malloc(sizeof(Employee)));

	return punteroEmpleado;
}

int employee_setId(Employee* this,int id)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		(*this).id=id;
	}
	return exito;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		strcpy((*this).nombre,nombre);
	}

	return exito;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		(*this).horasTrabajadas=horasTrabajadas;
	}

	return exito;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		(*this).sueldo=sueldo;
	}

	return exito;
}

int employee_getId(Employee* this,int* id)
{
	int exito=0;

	if(this!=NULL&&id!=NULL)
	{
		exito=1;
		*id=(*this).id;
	}

	return exito;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int exito=0;

	if(this!=NULL&&nombre!=NULL)
	{
		exito=1;
		strcpy(nombre,(*this).nombre);
	}

	return exito;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int exito=0;

	if(this!=NULL&&horasTrabajadas!=NULL)
	{
		exito=1;
		*horasTrabajadas=(*this).horasTrabajadas;
	}

	return exito;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int exito=0;

	if(this!=NULL&&sueldo!=NULL)
	{
		exito=1;
		*sueldo=(*this).sueldo;
	}

	return exito;
}

//AGREGADO TP4

int aumentaSueldo(void *empleadoRecibido)
{
	 int exito=0;
	 int auxSueldo;

	 if(empleadoRecibido!=NULL)
	 {
		 	 auxSueldo=(*(Employee*)(empleadoRecibido)).sueldo;

		 	 if(auxSueldo>20000)
		 	 {
		 		 auxSueldo=auxSueldo+(auxSueldo*15/100);

		 		 (*(Employee*)(empleadoRecibido)).sueldo=auxSueldo;
		 	 }

			 exito=1;
	 }

	 return exito;
}
