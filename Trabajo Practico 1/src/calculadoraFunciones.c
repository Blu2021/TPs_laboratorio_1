#include <stdio.h>
#include <stdlib.h>

int sumar(float numeroUno,float numeroDos,float* resultadoSumaMenu)
{
	float resultadoSumaFuncion;
	int exito=0;

	if(resultadoSumaMenu!=NULL)
	{
		resultadoSumaFuncion=numeroUno+numeroDos;
		*resultadoSumaMenu=resultadoSumaFuncion;
		exito=1;
	}
	return exito;
}

int restar(float numeroUno,float numeroDos,float* resultadoRestaMenu)
{
	float resultadoRestaFuncion;
	int exito=0;

	if(resultadoRestaMenu!=NULL)
	{
		resultadoRestaFuncion=numeroUno-numeroDos;
		*resultadoRestaMenu=resultadoRestaFuncion;
		exito=1;
	}
	return exito;
}

int division(float numeroUno,float numeroDos,float* resultadoDivisionMenu)
{
	 float resultadoDivisionFuncion;
	 int exito=0;

	 if(resultadoDivisionMenu!=NULL)
	 {
		 if(numeroDos!=0)
		 {
			resultadoDivisionFuncion=numeroUno/numeroDos;
			*resultadoDivisionMenu=resultadoDivisionFuncion;
		 }
		 exito=1;
	 }
	 return exito;
}

int multiplicar(float numeroUno,float numeroDos,float* resultadoMultiplicarMenu)
{
	float resultadoMultiplicarFuncion;
	int exito=0;

	if(resultadoMultiplicarMenu!=NULL)
	{
		resultadoMultiplicarFuncion=numeroUno*numeroDos;
		*resultadoMultiplicarMenu=resultadoMultiplicarFuncion;
		exito=1;
	}
	return exito;
}

int factorial(float numeroFactorial,long* resultadoFactorialMenu)
{
	int exito=0;
	int i;
	int numUno=numeroFactorial;
	int resFactorialFuncion=1;

	if(resultadoFactorialMenu!=NULL)
	{
		if(numeroFactorial-numUno==0&&numUno<34&&numUno>-1)
		{
			for(i=numUno;i>1;i--)
			{
				resFactorialFuncion=resFactorialFuncion*i;
			}
			*resultadoFactorialMenu=resFactorialFuncion;
		}
		exito=1;
	}
	return exito;
}


