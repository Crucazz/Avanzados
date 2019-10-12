/*
	Felipe Villalobos Padilla
	20.139.310-8
	Algoritmos Avanzados
	Laboratorio 1 Backtracking 
	Enunciado de la ciudad y las sucursales
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/backtracking.h"
#include "../inc/debug.h"
#include "../inc/colors.h"

/*
Funcion que imprime la matriz ingresada por argumento, junto con el tamañano de esta
Entrada: entero doble puntero, entero, entero
Salida: ----
O(n^2)	
*/

void printCurrent(int* ciudad[], int ejeX, int ejeY)
{
	#ifdef LINUX
		printf( VERDE_T"\n\nCiudad Novigrad \n"RESET_COLOR);
	#endif
	#ifdef WINDOWS
		printf( VERDE_T"\n\nCiudad Novigrad \n"RESET_COLOR);
	#endif
	printf("\n");
	for(int i=0; i<=ejeX; i++)
	{
		#ifdef LINUX
			printf(RESET_COLOR""CYAN_T"___"RESET_COLOR);
		#endif
		#ifdef WINDOWS
			printf(RESET_COLOR""CYAN_T"___"RESET_COLOR);
		#endif
	}
	printf("\n");
	for(int j=0; j<ejeY; j++)
	{
		printf(RESET_COLOR""CYAN_T"|"RESET_COLOR);
		for(int i=0; i<ejeX; i++)
		{
			#ifdef LINUX
				if(ciudad[i][j]!=0)
					printf(RESET_COLOR" "ROJO_T"X "RESET_COLOR);	
				else
					printf(RESET_COLOR" "VERDE_T"_ "RESET_COLOR);
			#endif

			#ifdef WINDOWS
				if(ciudad[i][j]!=0)

					printf(RESET_COLOR" "ROJO_T"X"RESET_COLOR);	
				else
					printf(RESET_COLOR" "VERDE_T"_"RESET_COLOR);
			#endif				
			
		}
		#ifdef LINUX
			printf(RESET_COLOR""CYAN_T"|\n"RESET_COLOR);
		#endif
		#ifdef WINDOWS
			printf(RESET_COLOR""CYAN_T"|\n"RESET_COLOR);
		#endif
	}
	for(int i=0; i<=ejeX; i++)
	{
		#ifdef LINUX
			printf(RESET_COLOR""CYAN_T"___"RESET_COLOR);
		#endif
		#ifdef WINDOWS
			printf(RESET_COLOR""CYAN_T"___"RESET_COLOR);
		#endif
	}
}