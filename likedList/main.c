//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "blu2021.h"

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
	setbuf(stdout,NULL);

    int option = 0;
    int entroAlcasoUno=0;
    int entroAlcasoDos=0;
    int entroTresSinUnoDos=0;
    int opcionSalvaDatos;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL)
    {
			do{
				 printf("Bienvenido al Menu Empleados\n"
						"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
						"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
						"3. Alta de empleado\n"
						"4. Modificar datos de empleado\n"
						"5. Baja de empleado\n"
						"6. Listar empleados\n"
						"7. Ordenar empleados\n"
						"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
						"9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
						"10.Aumentar sueldo empleados ingreso mayor a 20.000 , en 15%\n"
						"11.Salir\n");
				utn_levantaEnteros(&option,"Ingrese opcion de menu","ERROR,opcion invalida",1,10);
				switch(option)
				{
					case 1:
						if(entroTresSinUnoDos)
						{
							utn_levantaEnteros(&opcionSalvaDatos,"ALERTA, usted ha cargado datos con anterioridad,ingrese :\n"
									   "1: salvar los datos en un nuevo archivo(salvado.txt)\n"
									   "2: continuar sin guardar(se perderan los datos anteriores)","ERROR opcion entre1/2",1,2);
							switch(opcionSalvaDatos)
							{
									case 1:
										if(!controller_saveAsText("salvado.txt",listaEmpleados))
										{
											printf("Algo fallo en el salvado de datos,lo lamentamos\n");
										}
										else
										{
											printf("Salvado de datos exitoso\n");
										}
										system("pause");
									break;
							}
						}
						if(!controller_loadFromText("data.csv",listaEmpleados))
						{
							printf("Algo fallo en la creacion de memoria u otros\n");
						}
						else
						{
							entroAlcasoUno=1;
						}
						system("pause");
					break;
					case 2:
						if(!controller_loadFromBinary("dataCopia.bin",listaEmpleados))
						{
							printf("Algo fallo en la creacion de memoria u otros\n");
						}
						else
						{
							entroAlcasoDos=1;
						}
						system("pause");
					break;
					case 3:
						controller_addEmployee(listaEmpleados);
						if(!entroAlcasoUno&&!entroAlcasoDos)
						{
							entroTresSinUnoDos=1;
						}
						system("pause");
					break;
					case 4:
						if(!controller_editEmployee(listaEmpleados))
						{
							printf("El id ingresado no existe\n");
						}
						system("pause");
					break;
					case 5:
						if(!controller_removeEmployee(listaEmpleados))
						{
							printf("El id ingresado no existe\n");
						}
						system("pause");
					break;
					case 6:
						if(!controller_ListEmployee(listaEmpleados))
						{
							printf("No existen empleados cuales listar\n");
						}
						system("pause");
					break;
					case 7:
						if(!controller_sortEmployee(listaEmpleados))
						{
							printf("No hay datos cargados cuales ordenar o solamente hay un empleado cargado\n");
						}
						system("pause");
					break;
					case 8:
						controller_saveAsText("data.csv",listaEmpleados);
						system("pause");
					break;
					case 9:
						controller_saveAsBinary("dataCopia.bin",listaEmpleados);
						system("pause");
					break;
					case 10:
						controller_aumentarSueldo(listaEmpleados);
						system("pause");
					break;
					case 11:
						ll_deleteLinkedList(listaEmpleados);
						printf("Finalizando Menu...\n");
					break;
				}
			}while(option != 11);
    }
    return 0;
}

