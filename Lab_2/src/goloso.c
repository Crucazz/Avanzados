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


Salida:-----
O(n)	
*/
float goloso()
{


}