#include <stdio.h>
#include <stdlib.h>
#include "../inc/backtracking.h"
#include "../inc/debug.h"
#include "../inc/colors.h"

/*
Funcion que copia la matriz ingresada en el primer argumento, a la matriz del segundo argumento
Entrada: entero doble puntero, entero doble puntero, entero, entero
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
Entrada: entero doble puntero,entero, entero, entero, entero
Salida: entero
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

 ---------------------------
Parámetros:
	ciudad   - Fila de la reina que queremos colocar
	mejorCiudad - Vector con las posiciones de las reinas
	ejeX      - Número de reinas
	ejeY      - Número de reinas
	x      - Número de reinas
	y      - Número de reinas
	sucActaul      - Número de sucursales en actuales en la ciudad
	sucMaximas      - Número maximo de sucursales posibles en la ciudad

*/
void backtracking(int* ciudad[], int* mejorCiudad[], int ejeX, int ejeY, int x, int y, int sucActual, int sucMaximas, int* colocada)
{
	int ok = 0;
	if(sucActual != sucMaximas && colocada[0]==0)
	{
		for(int j=y; j<ejeY; j++)
		{
			for(int i=x; i<ejeX; i++)
			{
				//¿es posible colocar la sucursal?
				if(colocada[0]==0 && comprobar(ciudad,ejeX,ejeY,i,j)==1)
				{
					ciudad[i][j]=1;
					#ifdef DEBUG
						printCurrent(ciudad,ejeX ,ejeY);
					#endif

					if(sucActual+1>colocada[1])
					{
						guardar(ciudad,mejorCiudad,ejeX,ejeY);
						colocada[1]=sucActual+1;
					}
					backtracking(ciudad,mejorCiudad,ejeX,ejeY,0,j+1,sucActual+1,sucMaximas,colocada);
					//dado este punto se retorno, por lo tanto se eliminara la accion hecha
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
		return;
  }

  //return ok;
}