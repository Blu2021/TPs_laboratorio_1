#ifndef BLU2021_H_
#define BLU2021_H_
/*
 * @Brief levantaEnteros como su nombre lo indica...consigue un dato de tipo entero.
 * @param recibe por puntero un lugar para almacenar el resultado ,un mensaje para imprimirle al usuario,un mensaje
 * de error,un minimo y un maximo estipulado. Si el entero levantado no cumple con estar entre el rango min y max se
 * imprime el mensaje de error , invitando al usuario a ingresar nuevamente el dato.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente y a su vez que logro
 * conseguir el dato en cuestion.
 *         retorna 0 en caso contrario.
 */
int utn_levantaEnteros(int* resultado,char* mensaje,char* mensajeError,int min,int max);
/*
 * @Brief levantaDecimales como su nombre lo indica...consigue un dato de tipo decimal.
 * @param recibe por puntero un lugar para almacenar el resultado ,un mensaje para imprimirle al usuario,un mensaje
 * de error,un minimo y un maximo estipulado. Si el decimal levantado no cumple con estar entre el rango min y max se
 * imprime el mensaje de error , invitando al usuario a ingresar nuevamente el dato.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente y a su vez que logro
 * conseguir el dato en cuestion.
 *         retorna 0 en caso contrario.
 */
int utn_levantaDecimales(float* resultado,char* mensaje,char* mensajeError,float min,float max);
/*
 * @Brief inicializarCadenaCaracteres como su nombre lo indica... inicializa todos los indices(espacios) de una
 * cadena de caracteres imprimendoles un ' '(espacio), para asi esten vacias.
 * @param recibe una cadena de caracteres por parametro junto con el largo de esta.
 * @return retorna 1 en caso de que valide se haya recibido el puntero a cadena correctamente.
 *         retorna 0 en caso contrario.
 */
int inicializarCadenaCaracteres(char cadenaRecibida[],int largoCadena);
/*
 * @Brief levantaCadenaCaracteres como su nombre lo indica... consigue un dato de tipo "string".
 * @param recibe una cadena de caracteres por parametro junto con el largo de esta y ademas un mensaje el cual
 * mostrarle al usuario y un mensaje de error. El aspecto mas importante a destacar es que verifica que el
 * string que esta levantando no contenga numeros.
 * @return retorna 1 en caso de que valide se haya recibido el puntero a cadena y los mensajes correctamente, y
 * a su vez en caso de que haya podido validar que no hay numeros en la cadena, mientras que no consiga el exito
 * levantaCadenaCaracteres mantiene al usuario en un bucle.
 *         retorna 0 en caso contrario.
 */
int utn_levantaCadenaCaracteres(char cadena[],char* mensaje,char* mensajeError,int largoCadena);

#endif /* BLU2021_H_ */
