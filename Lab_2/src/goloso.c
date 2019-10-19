/*
	Felipe Villalobos Padilla
	20.139.310-8
	Algoritmos Avanzados
	Laboratorio 1 Backtracking 
	Enunciado de la ciudad y las sucursales
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/goloso.h"
#include "../inc/debug.h"
#include "../inc/colors.h"	
#include "../inc/estructuras.h"	

/*
Funcion que copia la matriz ingresada en el primer argumento, a la matriz del segundo argumento
Entrada: 
	ciudad[entero doble puntero]: matriz que se quiere copiar
	mejorCiudad[entero doble puntero]: matriz donde se copiara la matriz anterior
	ejeX[entero]: Tamaño del eje X de la matriz
	ejeY[entero]: Tamaño del eje Y de la matriz
Salida: ----
O(n^2)	
*/
void guardar(int* ciudad[], int* mejorCiudad[] ,int ejeX,int ejeY)
{
	for(int j=0; j<ejeY; j++)
	{
		for(int i=0; i<ejeX; i++)
		{
			mejorCiudad[i][j]=ciudad[i][j];
		}
	}
}

/*
Funcion que comprueba si se puede colocar la sucursal, segun las reglan planteadas en el
enunciado, tales como la condicional de no estar en la misma vertical, horizontal y diagonal
Entrada:
	ciudad[entero doble puntero]: matriz que representa la ciudad
	ejeX[entero]: Tamaño del eje X de la matriz
	ejeY[entero]: Tamaño del eje Y de la matriz
	x[entero]: posicion en el eje X que se busca comparar
	y[entero]: posicion en el eje Y que se busca comparar
Salida: entero	-0: en caso de que se cumpla alguna de las restriccion
				-1: en caso de que no se cumpla ninguna restriccion
O(n^2)	
*/
int comprobar(int* ciudad[],int ejeX,int ejeY,int x,int y)
{

	for(int j=0; j<ejeY; j++)
	{
		if(ciudad[x][j]!=0)	
		{
			//No se puede colocar en vertical
			return (0);
		}
		for(int i=0; i<ejeX; i++)
		{
			if(ciudad[i][y]!=0)	
			{	
				//No se puede colocar en horizontal
				return (0);
			}
			if(y-x == j-i && ciudad[i][j] !=0)
			{
				//No se puede colocar en diagonal
				return (0);
			}
			if(abs(x+y) == abs(j+i) && ciudad[i][j] !=0)
			{
				//No se puede colocar en diagonal
				return (0);
			}

		}
	}
	return (1);

}


/*
recursion utilizando el metodo de backtracking para ir posicionando las sucursales en la ciudad,

Entrada:
	ciudad[entero doble puntero]: matriz que representa la ciudad
	mejorCiudad[entero doble puntero]: matriz que guardara la ciudad con mayor cantidad de sucursales
	ejeX[entero]: Tamaño del eje X de la matriz
	ejeY[entero]: Tamaño del eje Y de la matriz
	x[entero]: posicion actual en X que se esta revisando en el tablero, utilizado para recorrer la matriz de la ciudad
	y[entero]: posicion actual en Y que se esta revisando en el tablero, utilizado para recorrer la matriz de la ciudad
	sucActual[entero]: Número de sucursales en actuales en la ciudad
	sucMaximas[entero]: Número maximo de sucursales posibles en la ciudad
	colocada[entero puntero]: -en 0: guarda una bandera que se activa cuando se coloca la maxima cantidad posible de sucursales en la ciudad, permitiendo ir acabando con los llamados de la funcion 
							  -en 1: guarda el mayor numero de sucursales  puesta hasta el momento en la ciudad

Salida:-----
O(n^n)	
*/
void backtracking()
{
	int ok = 0;

	if(colocada[0]==1)
		return;

	if(sucActual != sucMaximas)
	{
		for(int j=y; j<ejeY; j++)
		{
			for(int i=x; i<ejeX; i++)
			{
				//¿es posible colocar la sucursal?
				if(colocada[0]==0 && comprobar(ciudad,ejeX,ejeY,i,j)==1)
				{
					ciudad[i][j]=1;
					
					// con la nueva sucursal
					// la ciudad actual, ¿tiene mas sucursales que la mejor ciudad hasta ahora?
					if(sucActual+1>colocada[1])
					{
						guardar(ciudad,mejorCiudad,ejeX,ejeY);
						colocada[1]=sucActual+1;
					}
					#ifdef DEBUG
						printCurrent(ciudad,ejeX ,ejeY,sucActual+1,colocada[1]);
					#endif
					backtracking(ciudad,mejorCiudad,ejeX,ejeY,0,j+1,sucActual+1,sucMaximas,colocada);
					//dado este punto se realizo el retorno, por lo tanto se eliminara la accion hecha
					ciudad[i][j]=0;

				}
				//en caso de que se encontrara la solucion
				//empezara a cortar las recursiones.
				if(colocada[0]==1)
					return;				
			}
		}

	} 
	else
	{
    	// Se colocan el maximo de sucursales en la ciudad
		//no hay mas opciones, por lo que se retornara desde este punto
		colocada[0]=1;
		guardar(ciudad,mejorCiudad,ejeX,ejeY);
		#ifdef DEBUG
			printCurrent(ciudad,ejeX ,ejeY,sucActual,colocada[1]);
		#endif
		return;
  	}
}