#ifndef ARRAYDEEMPLEADOS_H_
#define ARRAYDEEMPLEADOS_H_
typedef struct
{
	int idEmpleado;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int estaVacio;
}eEmpleados;
/*
 * @Brief inicializarArrayEmpleados asigna un "1" a cada posicion de "estaVacio" de cada estructura del array,para asi
 * indicar la disponibilidad de la misma.
 * @param recibe un array de estructuras tipo eEmpleados y el tamanio de la misma.
 * @return retorna 1 en caso de que valide se haya recibido la cadena de estructuras correctamente
 *         retorna 0 en caso contrario.
 */
int inicializarArrayEmpleados(eEmpleados arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief cargaDatosEmpleados mediante funciones que levantan distintos tipos de variables, se asegura de cargar
 * todos los distintos tipos de datos del array de estructura recibido , siempre contemplando hacerlo en la posicion
 * libre que se le envio como parametro segundo , suponiendo que la posicion que recibe esta verificada como disponible.
 * @param recibe un array de estructuras tipo eEmpleados y una "supuesta" posicion libre en la cual cargar datos sin
 * pisar algo que esta en uso.
 * @return retorna 1 en caso de que valide se haya recibido la cadena de estructuras correctamente
 *         retorna 0 en caso contrario.
 */
int cargaDatosEmpleados(eEmpleados arrayRecibido[],int posicion);
/*
 * @Brief buscarLibreEmpleados verifica el "estaVacio" de una cadena de estructuras recibida, para asi enviar la
 * posicion libre que encuentre primero con su retorno.
 * @param recibe un array de estructuras tipo eEmpleados y el tamanio de la misma.
 * @return retorna la posicion libre que encuentre.
 *         retorna -1 en caso de que no haya encontrado una posicion libre.
 */
int buscarLibreEmpleados(eEmpleados arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief bajaDatosEmpleados pide que se ingrese un id para dar de baja , luego verifica que este id exista es una
 * estructura de empleados activa , en dicho caso modifica el valor del "estaVacio" a 1, para volver a indicar
 * la disponibilidad de la estructura y a su vez se la considere como vacia(sin datos a considerar por cualquier
 * otra funcion que verifique el "estaVacio").
 * @param recibe un array de estructuras tipo eEmpleados y el tamanio de la misma.
 * @return retorna 2 en caso de que haya recibido la cadena de estructuras correctamente y paralelamente en caso de
 * que el usuario se haya arrepentido de la baja.
 *         retorna 1 en caso de que haya recibido la cadena de estructuras correctamente y paralelamente en caso de
 * que el usuario haya efectivizado la baja.
 * 		   retorna 0 en caso de que haya habido error en la cadena de estructuras Recibida.
 */
int bajaDatosEmpleados(eEmpleados arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief muestraEmpleadosCargados muestra los empleados cargados, trabaja en conjunto con muestraEmpleadoCargado.
 * @param recibe un array de estructuras tipo eEmpleados y el tamanio de la misma.
 * @return retorna 1 en caso de que confirme que exista alguna estructura la cual mostrar.
 *         retorna 0 en caso contrario.
 */
int muestraEmpleadosCargados(eEmpleados arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief muestraEmpleadoCargado muestra los empleados cargados, trabaja en conjunto con muestraEmpleadosCargados.
 * @param recibe una estructura de tipo eEmpleados la cual le envia muestraEmpleadosCargados
 * @return no tiene retorno.
 */
void muestraEmpleadoCargado(eEmpleados estructuraRecibida);
/*
 * @Brief ordenarArrayApellido ordena cadena de estructuras de tipo eEmpleados segun su apellido de la "a" a la "z"
 * ademas si los apellidos coinciden ordena los empleados segun su sector de menor a mayor.
 * @param recibe una cadena de estructuras eEmpleados y el tamanio de la misma.
 * @return no tiene retorno.
 */
void ordenarArrayApellido(eEmpleados arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief menuModificar permite al usuario modificar cualquier campo de una estructura tipo eEmpleados segun el Id
 * ingresado, ademas verifica que este Id exista y este vigente en una estructura actualmente activa.
 * @param recibe una cadena de estructuras eEmpleados y el tamanio de la misma.
 * @return no tiene retorno.
 */
void menuModificar(eEmpleados arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief totalPromedioSalarios acumula todos los salarios de empleados activos , cuenta cuantos son estos empleados
 * activos y consigue el promedio de los salarios. Luego compara si cada empleado supera o no el promedio y en caso
 * de existir empleados que lo superen los cuenta. Informa los datos obtenidos.
 * @param recibe una cadena de estructuras eEmpleados y el tamanio de la misma.
 * @return retorna 1 en caso de que haya recibido la cadena de estructuras correctamente.
 *         retorna 0 en caso contrario.
 */
int totalPromedioSalarios(eEmpleados arrayRecibido[],int tamanioArrayRecibido);

#endif /* ARRAYDEEMPLEADOS_H_ */
