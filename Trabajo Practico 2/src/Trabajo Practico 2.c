//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include "arrayDeEmpleados.h"
#include "blu2021.h"
#define CANTIDADEMPLEADOS 5

int main(void)
{
	setbuf(stdout,NULL);
	int opcionMenu;
	int posLibre;
	int idEmpleado=0;
	int controlActivos=0;
	int devolucionBajaDatos;
	eEmpleados empleados[CANTIDADEMPLEADOS];

	inicializarArrayEmpleados(empleados, CANTIDADEMPLEADOS);
	do
	{
		printf("Bienvenido al Menu Empleados\n"
				"1: ALTA EMPLEADO\n"
				"2: MODIFICAR EMPLEADO\n"
				"3: BAJA EMPLEADO\n"
				"4: INFORMES\n"
				"5: SALIR\n");
		utn_levantaEnteros(&opcionMenu,"Ingrese opcion de menu","ERROR,opcion invalida",1,5);
		switch(opcionMenu)
		{
			case 1:
				posLibre=buscarLibreEmpleados(empleados,CANTIDADEMPLEADOS);
				if(posLibre!=-1)
				{
					if(cargaDatosEmpleados(empleados,posLibre))
					{
						empleados[posLibre].idEmpleado=idEmpleado;
						printf("Empleado dado de alta con exito bajo id %d\n",idEmpleado);
						idEmpleado++;
						controlActivos++;
						printf("Pulse cualquiera tecla para volver\n");
						fflush(stdin);
						getchar();
					}
					else
					{
						printf("Algo fallo en la carga de datos\n");
						printf("Pulse cualquiera tecla para volver\n");
						fflush(stdin);
						getchar();
					}
				}
				else
				{
					printf("No hay espacio disponible para la carga,elimine al menos uno\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
			break;
			case 2:
				if(controlActivos>0)
				{
					menuModificar(empleados,CANTIDADEMPLEADOS);
				}
				else
				{
					printf("No hay empleado cargado cual modificar\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
			break;
			case 3:
				if(controlActivos>0)
				{
					devolucionBajaDatos=bajaDatosEmpleados(empleados,CANTIDADEMPLEADOS);
					if(devolucionBajaDatos==1)
					{
						controlActivos--;
					}
					else
					{
						if(devolucionBajaDatos==0)
						{
							printf("Algo fallo en la baja de datos\n");
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
					}
				}
				else
				{
					printf("No hay empleado cargado cual dar de baja\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
			break;
			case 4:
				if(controlActivos>0)
				{
					ordenarArrayApellido(empleados,CANTIDADEMPLEADOS);
					muestraEmpleadosCargados(empleados,CANTIDADEMPLEADOS);
					totalPromedioSalarios(empleados,CANTIDADEMPLEADOS);
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
				else
				{
					printf("No hay empleados cargados cuales imprimir\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
			break;
			case 5:
				printf("Gracias por utilizar nuestros servicios\n");
			break;
		}
	}while(opcionMenu!=5);
	return EXIT_SUCCESS;
}
