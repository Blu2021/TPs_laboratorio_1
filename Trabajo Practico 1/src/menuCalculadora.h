#ifndef MENUCALCULADORA_H_
#define MENUCALCULADORA_H_
/*
 * @brief menu pide el ingreso de una opcion validando que sea del 1 al 5 ,
 * si la opcion es 1 solicita el ingreso de un numero,
 * si opcion es 2 solicita el ingreso de otro numero,
 * si es 3 realiza operaciones de suma,resta,multiplicacion,division y factorial de ambos numeros solicitados
 * y lo realiza invocando funciones de calculo.(no permite ingresar a la opcion 3 si no se cargaron los numeros en
 * la opcion 1 y en la 2)
 * si es 4 muestra los resultados al usuario , y en el resultado de division y en el de factorial informa
 * errores dependiendo del valor de retorno que se obtenga en las funciones mencionadas.(no permite mostrar resultados
 * si no se ha ingresado a la opcion 3)
 * si es 5 menu concluye su funcion.
 */
int menu();

#endif /* MENUCALCULADORA_H_ */
