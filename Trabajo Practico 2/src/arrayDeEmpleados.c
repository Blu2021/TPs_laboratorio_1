#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayDeEmpleados.h"
#include "blu2021.h"
int inicializarArrayEmpleados(eEmpleados arrayRecibido[],int tamanioArrayRecibido)
{
	int exito=0;
	int i;
	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			arrayRecibido[i].estaVacio=1;
		}
		exito=1;
	}
	return exito;
}
int cargaDatosEmpleados(eEmpleados arrayRecibido[],int posicion)
{
	int exito=0;
	char auxNombre[51];
	char auxApellido[51];
	float auxSalario;
	int auxSector;

	inicializarCadenaCaracteres(auxNombre,51);
	inicializarCadenaCaracteres(auxApellido,51);

	if(arrayRecibido!=NULL)
	{
		utn_levantaCadenaCaracteres(auxNombre,"Ingrese nombre empleado","Error,Reingrese nombre sin numeros",51);
		utn_levantaCadenaCaracteres(auxApellido,"Ingrese apellido empleado","Error,Reingrese lugar sin numeros",51);
		utn_levantaDecimales(&auxSalario, "Ingrese salario", "ERROR,reingrese salario",0,200000);
		utn_levantaEnteros(&auxSector, "Ingrese sector del 1 al 5", "ERROR,Reingrese Sector", 1, 5);
		strcpy(arrayRecibido[posicion].nombre,auxNombre);
		strcpy(arrayRecibido[posicion].apellido,auxApellido);
		arrayRecibido[posicion].salario=auxSalario;
		arrayRecibido[posicion].sector=auxSector;
		arrayRecibido[posicion].estaVacio=0;
		exito=1;
	}
	return exito;
}
int buscarLibreEmpleados(eEmpleados arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int auxLibre=-1;

	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(arrayRecibido[i].estaVacio==1)
			{
				auxLibre=i;
				break;
			}
		}
	}
	return auxLibre;
}
void menuModificar(eEmpleados arrayRecibido[],int tamanioArrayRecibido)
{
	int idModificar;
	int idExistente=0;
	int campoModificar;
	int i;
	char auxNombre[51];
	char auxApellido[51];
	float auxSalario;
	int auxSector;

	printf("Bienvenido a Menu Modificar\n");
	printf("Ingrese id Empleado a modificar\n");
	scanf("%d",&idModificar);
	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(idModificar==arrayRecibido[i].idEmpleado&&arrayRecibido[i].estaVacio==0)
		{
			idExistente=1;
			break;
		}
	}
	if(idExistente)
	{
		printf("¿Que campo desea modificar?\n");
		printf("Nombre=1\nApellido=2\nSalario=3\nSector=4\n");
		scanf("%d",&campoModificar);
		while(campoModificar<1||campoModificar>4)
		{
			printf("ERROR,CAMPO INVALIDO ¿Que campo desea modificar?\n");
			printf("Nombre=1\nApellido=2\nSalario=3\nSector=4\n");
			scanf("%d",&campoModificar);
		}
		switch(campoModificar)
		{
			case 1:
				utn_levantaCadenaCaracteres(auxNombre,"Reingrese nombre empleado","Error,Reingrese nombre sin numeros",51);
				strcpy(arrayRecibido[i].nombre,auxNombre);
				printf("Nombre modificado con exito\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			break;
			case 2:
				utn_levantaCadenaCaracteres(auxApellido,"Reingrese apellido empleado","Error,Reingrese apellido sin numeros",51);
				strcpy(arrayRecibido[i].apellido,auxApellido);
				printf("Apellido modificado con exito\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			break;
			case 3:
				utn_levantaDecimales(&auxSalario,"Reingrese salario","Error,Reingrese salario",0,200000);
				arrayRecibido[i].salario=auxSalario;
				printf("Salario modificado con exito\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			break;
			case 4:
				utn_levantaEnteros(&auxSector,"Reingrese sector","Error,sector del 1 al 5",1,5);
				arrayRecibido[i].sector=auxSector;
				printf("Sector modificado con exito\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			break;
		}
	}
	else
	{
		printf("ERROR,usted no ha ingresado id valido, verifique y reingrese\n");
		printf("Pulse cualquiera tecla para volver\n");
		fflush(stdin);
		getchar();
	}
}
int bajaDatosEmpleados(eEmpleados arrayRecibido[],int tamanioArrayRecibido)
{
	int exito=0;
	int opcionBaja;
	int empleadoBaja;
	int empleadoExistente=0;
	int i;

	if(arrayRecibido!=NULL)
	{
		exito=2;
		printf("Ingrese Id empleado a dar de baja\n");
		fflush(stdin);
		scanf("%d",&empleadoBaja);
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(empleadoBaja==arrayRecibido[i].idEmpleado&&arrayRecibido[i].estaVacio==0)
			{
				empleadoExistente=1;
				break;
			}
		}

		if(empleadoExistente)
		{
				printf("Usted dara de baja el id %d, presione 1 para continuar o 2 para cancelar\n",empleadoBaja);
				scanf("%d",&opcionBaja);
				while(opcionBaja!=1&&opcionBaja!=2)
				{
					printf("ERROR,ingrese opcion valida\n");
					fflush(stdin);
					scanf("%d",&opcionBaja);
				}
				if(opcionBaja==1)
				{
					arrayRecibido[i].estaVacio=1;
					printf("Los datos se han dado de baja exitosamente\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
					exito=1;
				}
				else
				{
					printf("Usted ha cancelado la baja , los datos seguiran existiendo\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
		}
		else
		{
				printf("No hay datos cargados cuales dar de baja ó el id es invalido, verifique\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
		}
	}
	return exito;
}
void ordenarArrayApellido(eEmpleados arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int j;
	eEmpleados estructuraAuxiliar;

	for(i=0;i<tamanioArrayRecibido-1;i++)
	{
		for(j=i+1;j<tamanioArrayRecibido;j++)
		{
			if(arrayRecibido[i].estaVacio==0&&arrayRecibido[j].estaVacio==0)
			{
				strlwr(arrayRecibido[i].apellido);
				strlwr(arrayRecibido[j].apellido);
				if(strcmp(arrayRecibido[i].apellido,arrayRecibido[j].apellido)>0)
				{
					estructuraAuxiliar=arrayRecibido[i];
					arrayRecibido[i]=arrayRecibido[j];
					arrayRecibido[j]=estructuraAuxiliar;
				}
				else
				{
					if(strcmp(arrayRecibido[i].apellido,arrayRecibido[j].apellido)==0)
					{
						if(arrayRecibido[i].sector>arrayRecibido[j].sector)
						{
							estructuraAuxiliar=arrayRecibido[i];
							arrayRecibido[i]=arrayRecibido[j];
							arrayRecibido[j]=estructuraAuxiliar;
						}
					}
				}
			}
		}
	}
}

int muestraEmpleadosCargados(eEmpleados arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int exito=0;
	int sePuedeMostrar=1;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0)
		{
			if(sePuedeMostrar)
			{
				printf("------------------DATOS DE EMPLEADOS-------------------\n");
				printf("IdEmpleado    apellido      nombre     salario     sector\n");
				sePuedeMostrar=0;
			}
			muestraEmpleadoCargado(arrayRecibido[i]);
			exito=1;
		}
	}
	return exito;
}

void muestraEmpleadoCargado(eEmpleados estructuraRecibida)
{
	printf("%-14d%-14s%-11s%-12.2f%d\n",estructuraRecibida.idEmpleado,estructuraRecibida.apellido,estructuraRecibida.nombre,estructuraRecibida.salario,estructuraRecibida.sector);
}

int totalPromedioSalarios(eEmpleados arrayRecibido[],int tamanioArrayRecibido)
{
	int exito=0;
	int i;
	float acumuladorSalarios=0;
	int cantidadSalarios=0;
	float promedioSalarios;
	int contadorSuperanPromedio=0;

	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(arrayRecibido[i].estaVacio==0)
			{
				acumuladorSalarios=acumuladorSalarios+arrayRecibido[i].salario;
				cantidadSalarios++;
			}
		}
		promedioSalarios=acumuladorSalarios/cantidadSalarios;
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(arrayRecibido[i].salario>promedioSalarios&&arrayRecibido[i].estaVacio==0)
			{
				contadorSuperanPromedio++;
			}
		}
		printf("El total de los sueldos es %.2f y el promedio %.2f\n",acumuladorSalarios,promedioSalarios);
		printf("El total de empleados que superan el sueldo promedio es %d\n",contadorSuperanPromedio);
		exito=1;
	}
	return exito;
}
