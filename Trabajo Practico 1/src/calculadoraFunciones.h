#ifndef CALCULADORAFUNCIONES_H_
#define CALCULADORAFUNCIONES_H_
/*
 * @Brief sumar realiza la suma de dos numeros.
 * @param recibe dos numeros para sumar y un puntero al cual cargarle el resultado.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente.
 *         retorna 0 en caso contrario.
 */
int sumar(float numeroUno,float numeroDos,float* resultadoSumaMenu);
/*
 * @brief restar realiza la resta de dos numeros.
 * @param recibe dos numeros para estar y un puntero al cual cargarle el resultado.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente.
 * 		   retorna 0 en caso contrario.
 */
int restar(float numeroUno,float numeroDos,float* resultadoRestaMenu);
/*
 * @brief division realiza la division de dos numeros.
 * @param recibe dos numeros para dividir y un puntero al cual cargarle el resultado.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente y que el segundo
 * numero sea distinto de 0.
 * 		   retorna 2 en caso de que SOLO el puntero se recibio correctamente.
 * 		   retorna 0 en caso contrario al 2.
 */
int division(float numeroUno,float numeroDos,float* resultadoDivisionMenu);
/*
 * @brief multiplicar realiza la multiplicacion de dos numeros.
 * @param recibe dos numeros para multiplicar y un puntero al cual cargarle el resultado.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente.
 * 		   retorna 0 en caso contrario.
 */
int multiplicar(float numeroUno,float numeroDos,float* resultadoMultiplicarMenu);
/*
 * @brief factorial realiza el factorial de un numero.
 * @param recibe un numero por parametro y un puntero al cual cargarle el resultado.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente y que el numero recibido
 * es entero , es positivo y no es mayor a 12(este ultimo debido a limitaciones de memoria).
 *         retorna 2 en caso de que SOLO el puntero se recibio correctamente.
 *         retorna 0 en caso contrario al 2.
 */
int factorial(float numeroFactorial,unsigned long* resultadoFactorialMenu);

#endif /* CALCULADORAFUNCIONES_H_ */
