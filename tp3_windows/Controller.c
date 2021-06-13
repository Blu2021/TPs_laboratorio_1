#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "blu2021.h"
#include <string.h>

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito=0;
	FILE* punteroArchivo;

	punteroArchivo=fopen(path,"r");

	ll_clear(pArrayListEmployee);

	if(punteroArchivo!=NULL)
	{
		if(parser_EmployeeFromText(punteroArchivo,pArrayListEmployee))
		{
			exito=1;
			printf("Datos cargados desde texto con exito\n");
		}
	}
	fclose(punteroArchivo);

    return exito;
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
	int exito=0;
	FILE* punteroArchivo;

	punteroArchivo=fopen(path,"rb");

	ll_clear(pArrayListEmployee);

	if(punteroArchivo!=NULL)
	{
		if(parser_EmployeeFromBinary(punteroArchivo, pArrayListEmployee))
		{
			exito=1;
			printf("Datos cargados desde binario con exito\n");
		}
	}
	fclose(punteroArchivo);

  return exito;
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
	Employee* punteroEmpleado;
	int exito=0;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	int dimensionLinkedList;
	int i;
	Employee* auxDirMemEmpleado;
	int maximoId=0;
	int auxMaximo;

	if(pArrayListEmployee!=NULL)
	{
		exito=1;
		punteroEmpleado=employee_new();
		dimensionLinkedList=ll_len(pArrayListEmployee);
		for(i=0;i<dimensionLinkedList;i++)
		{
			auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
			auxMaximo=(*auxDirMemEmpleado).id;
			if(i==0||auxMaximo>maximoId)
			{
				maximoId=(*auxDirMemEmpleado).id;
			}
		}
		maximoId++;
		employee_setId(punteroEmpleado,maximoId);
		utn_levantaCadenaCaracteres(auxNombre,"Ingrese Nombre Empleado","ERROR",128);
		employee_setNombre(punteroEmpleado,auxNombre);
		utn_levantaEnteros(&auxSueldo,"Ingrese Sueldo","ERROR entre 100000/200000",100000,200000);
		employee_setSueldo(punteroEmpleado,auxSueldo);
		utn_levantaEnteros(&auxHorasTrabajadas,"Ingrese horas trabajadas","ERROR entre 60/325",60,325);
		employee_setHorasTrabajadas(punteroEmpleado,auxHorasTrabajadas);

		ll_add(pArrayListEmployee,punteroEmpleado);
	}
    return exito;
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
	int exito=0;
	Employee* auxDirMemEmpleado;
	int auxId;
	int dimensionLinkedList;
	int i;
	int opcionModificar;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;

	if(pArrayListEmployee!=NULL)
	{
		printf("Ingrese id de empleado a modificar\n");
		fflush(stdin);
		scanf("%d",&auxId);
		dimensionLinkedList=ll_len(pArrayListEmployee);
		for(i=0;i<dimensionLinkedList;i++)
		{
			auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
			if(auxId==(*auxDirMemEmpleado).id)
			{
				exito=1;
				break;
			}
		}

		if(exito)
		{
			printf("Modificacion de empleado id %d\n",auxId);
			utn_levantaEnteros(&opcionModificar,"Ingrese 1: modifica nombre\n"
					                                "Ingrese 2: modifica sueldo\n"
                                          "Ingrese 3: modifica horas\n ","ERROR ,ENTRE 1/3",1,3);
			switch(opcionModificar)
			{
				case 1:
					utn_levantaCadenaCaracteres(auxNombre,"Reingrese nombre","ERROR",128);
					employee_setNombre(auxDirMemEmpleado,auxNombre);
				break;
				case 2:
					utn_levantaEnteros(&auxSueldo,"Reingrese Sueldo entre 100000/200000","ERROR entre 100000/200000",100000,200000);
					employee_setSueldo(auxDirMemEmpleado,auxSueldo);
				break;
				case 3:
					utn_levantaEnteros(&auxHorasTrabajadas,"Reingrese Horas entre 60/325","ERROR entre 60/325",60,325);
					employee_setHorasTrabajadas(auxDirMemEmpleado,auxHorasTrabajadas);
				break;
			}
		}
	}
    return exito;
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
	int exito=0;
	int auxId;
	int dimensionLinkedList;
	int i;
	int auxHorasTrabajadas;
	char auxNombre[128];
	int auxSueldo;
	int opcionEliminar;
	Employee* auxDirMemEmpleado;

	if(pArrayListEmployee!=NULL)
	{
		dimensionLinkedList=ll_len(pArrayListEmployee);
		printf("Ingrese id de empleado a eliminar\n");
		fflush(stdin);
		scanf("%d",&auxId);
		for(i=0;i<dimensionLinkedList;i++)
		{
			auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
			if(auxId==(*auxDirMemEmpleado).id)
			{
				exito=1;
				employee_getHorasTrabajadas(auxDirMemEmpleado,&auxHorasTrabajadas);
				employee_getNombre(auxDirMemEmpleado,auxNombre);
				employee_getSueldo(auxDirMemEmpleado,&auxSueldo);
				printf("--------------SE ELIMINARA A--------------\n");
				printf("IdEmpleado    nombre      horas     sueldo\n");
				printf("%-14d%-12s%-9d%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
				utn_levantaEnteros(&opcionEliminar,"confirmar:1\ncancelar:2","ERROR entre 1/2",1,2);
				if(opcionEliminar==1)
				{
					ll_remove(pArrayListEmployee,i);
					free(auxDirMemEmpleado);
					printf("Eliminacion exitosa\n");
					break;
				}
				else
				{
					printf("Eliminacion cancelada\n");
					break;
				}
			}
		}
	}
    return exito;
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
	int exito=0;
	int i;
	int dimensionLinkedList;
	Employee* auxDirMemEmpleado;

	dimensionLinkedList=ll_len(pArrayListEmployee);

	if(pArrayListEmployee!=NULL&&dimensionLinkedList>0)
	{
		exito=1;

		for(i=0;i<dimensionLinkedList;i++)
		{
			auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
			if(i==0)
			{
				printf("------------DATOS DE EMPLEADOS------------\n");
				printf("IdEmpleado    nombre      horas     sueldo\n");
			}
			printf("%-14d%-12s%-9d%d\n",(*auxDirMemEmpleado).id,(*auxDirMemEmpleado).nombre,(*auxDirMemEmpleado).horasTrabajadas,(*auxDirMemEmpleado).sueldo);
		}
	}
    return exito;
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
	int exito=0;
	int opcionOrdenar;
	int dimensionLinkedList;
	int i;
	int j;
	Employee* auxDirMemEmpleado;
	Employee* auxDirMemEmpleadoDos;

	dimensionLinkedList=ll_len(pArrayListEmployee);

	if(dimensionLinkedList>1&&pArrayListEmployee!=NULL)
	{
		exito=1;
		utn_levantaEnteros(&opcionOrdenar,"Ingrese opcion de ordenamiento\n"
										  "ordenar por id     : 1\n"
										  "ordenar por nombre : 2\n"
										  "ordenar por horas  : 3\n"
										  "ordenar por sueldo : 4","ERROR opcion entre 1/4",1,4);
		switch(opcionOrdenar)
		{
			case 1:
				for(i=0;i<dimensionLinkedList-1;i++)
				{
					for(j=i+1;j<dimensionLinkedList;j++)
					{
						auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
						auxDirMemEmpleadoDos=ll_get(pArrayListEmployee,j);
						if((*auxDirMemEmpleado).id>(*auxDirMemEmpleadoDos).id)
						{
							ll_set(pArrayListEmployee,i,auxDirMemEmpleadoDos);
							ll_set(pArrayListEmployee,j,auxDirMemEmpleado);
						}
					}
				}
				printf("Empleados ordenados por id de - a +\n");
			break;
			case 2:
				for(i=0;i<dimensionLinkedList;i++)
				{
					for(j=i+1;j<dimensionLinkedList;j++)
					{
						auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
						auxDirMemEmpleadoDos=ll_get(pArrayListEmployee,j);
						strlwr((*auxDirMemEmpleado).nombre);
						strlwr((*auxDirMemEmpleadoDos).nombre);
						if(strcmp((*auxDirMemEmpleado).nombre,(*auxDirMemEmpleadoDos).nombre)>0)
						{
							ll_set(pArrayListEmployee,j,auxDirMemEmpleado);
							ll_set(pArrayListEmployee,i,auxDirMemEmpleadoDos);
						}
					}
				}
				printf("Empleados ordenados por nombre de 'a' hasta 'z'\n");
			break;
			case 3:
				for(i=0;i<dimensionLinkedList;i++)
				{
					for(j=i+1;j<dimensionLinkedList;j++)
					{
						auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
						auxDirMemEmpleadoDos=ll_get(pArrayListEmployee,j);
						if((*auxDirMemEmpleado).horasTrabajadas>(*auxDirMemEmpleadoDos).horasTrabajadas)
						{
							ll_set(pArrayListEmployee,j,auxDirMemEmpleado);
							ll_set(pArrayListEmployee,i,auxDirMemEmpleadoDos);
						}
					}
				}
				printf("Empleados ordenados por horas de - a +\n");
			break;
			case 4:
				for(i=0;i<dimensionLinkedList;i++)
				{
					for(j=i+1;j<dimensionLinkedList;j++)
					{
						auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
						auxDirMemEmpleadoDos=ll_get(pArrayListEmployee,j);
						if((*auxDirMemEmpleado).sueldo>(*auxDirMemEmpleadoDos).sueldo)
						{
							ll_set(pArrayListEmployee,j,auxDirMemEmpleado);
							ll_set(pArrayListEmployee,i,auxDirMemEmpleadoDos);
						}
					}
				}
				printf("Empleados ordenados por sueldo de - a +\n");
			break;
		}
	}
	else
	{
		 exito=0;
	}

    return exito;
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
	int exito=0;
	FILE* punteroArchivo;
	int dimensionLinkedList;
	int i;
	Employee* auxDirMemEmpleado;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	punteroArchivo=fopen(path,"w");
	dimensionLinkedList=ll_len(pArrayListEmployee);

	if(path!=NULL&&pArrayListEmployee!=NULL&&punteroArchivo!=NULL&&dimensionLinkedList>0)
	{
		exito=1;
		fprintf(punteroArchivo,"idEmpleado,nombre,horas,sueldo\n");
		for(i=0;i<dimensionLinkedList;i++)
		{
			auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
			employee_getId(auxDirMemEmpleado,&auxId);
			employee_getNombre(auxDirMemEmpleado,auxNombre);
			employee_getHorasTrabajadas(auxDirMemEmpleado,&auxHoras);
			employee_getSueldo(auxDirMemEmpleado,&auxSueldo);
			fprintf(punteroArchivo,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
		}
		fclose(punteroArchivo);
		printf("Datos guardados con exito(modo texto)\n");
	}
	return exito;
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
	int exito=0;
	FILE* punteroArchivo;
	int dimensionLinkedList;
	Employee* auxDirMemEmpleado=NULL;
	Employee auxEmpleado;
	int i;

	dimensionLinkedList=ll_len(pArrayListEmployee);
	punteroArchivo=fopen(path,"wb");
	if(path!=NULL&&punteroArchivo!=NULL&&pArrayListEmployee!=NULL&&dimensionLinkedList>0)
	{
		exito=1;
		for(i=0;i<dimensionLinkedList;i++)
		{
			auxDirMemEmpleado=ll_get(pArrayListEmployee,i);
			if(auxDirMemEmpleado!=NULL)
			{
					auxEmpleado=*(auxDirMemEmpleado);
					fwrite(&auxEmpleado,sizeof(Employee),1,punteroArchivo);
			}
		}
	}
	fclose(punteroArchivo);
	printf("Datos guardados con exito(modo binario)\n");

	return exito;
}

