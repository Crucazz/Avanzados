/*
	Felipe Villalobos Padilla
	20.139.310-8
	Algoritmos Avanzados
	Laboratorio 2 Goloso
	Enunciado 1:la empresa de limpieza Clover Sanity
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/backtracking.h"
#include "../inc/debug.h"
#include "../inc/colors.h"


/*
Funcion que imprime la matriz ingresada por argumento, junto con el tamañano de esta
Entrada:
	ciudad[entero doble puntero]: matriz que representa la ciudad	
	ejeX[entero]: Tamaño del eje X de la matriz
	ejeY[entero]: Tamaño del eje Y de la matriz
	sucActual[entero]: Número de sucursales en actuales en la ciudad
	sucMax[entero]: Número maximo de sucursales puestas en la ciudad de forma global
Salida:-----
O(n^2)	
*/
void printCurrent(int* ciudad[], int ejeX, int ejeY, int sucActual, int sucMax)
{

    #ifdef LINUX // preguntamos si estamos trabajando en linux
    printf( VERDE_T"\t╔═══════════════════════════════════════════════════════════════════════╗\n"RESET_COLOR);
    printf( VERDE_T"\t║     "AMARILLO_T"Ciudad Novigrad                                                   "VERDE_T"║\n"RESET_COLOR);
    printf( VERDE_T"\t╠═══════════════════════════════════════════════════════════════════════╣\n"RESET_COLOR);
    printf( VERDE_T"\t║                                                                       ║\n"RESET_COLOR);
    printBoard(ciudad,ejeX ,ejeY);
    printf( VERDE_T"\t║                                                                       ║\n"RESET_COLOR);
    printf( VERDE_T"\t╠═══════════════════════════════════════════════════════════════════════╣\n"RESET_COLOR);
    printf( VERDE_T"\t║    "AMARILLO_T"Sucursales en la ciudad "ROJO_T"→ %d \t "AMARILLO_T"Mejor : "RESET_COLOR "%d\t   \t        "VERDE_T"║\n"RESET_COLOR,sucActual,sucMax);
    printf( VERDE_T"\t╚═══════════════════════════════════════════════════════════════════════╝\n"RESET_COLOR);
    #endif

    #ifdef WINDOWS // preguntamos si estamos trabajando en windows
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    printf( VERDE_T"\t|     "AMARILLO_T"Ciudad Novigrad                                                   "VERDE_T"|\n"RESET_COLOR);
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    printf( VERDE_T"\t|                                                                       |\n"RESET_COLOR);
    printBoard(ciudad,ejeX ,ejeY);
    printf( VERDE_T"\t|                                                                       |\n"RESET_COLOR);
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    printf( VERDE_T"\t|    "AMARILLO_T"Sucursales en la ciudad "ROJO_T"->%d \t "AMARILLO_T"Mejor : "RESET_COLOR "%d\t   \t        "VERDE_T"|\n"RESET_COLOR,sucActual,sucMax);
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    #endif
    printf("\n");

}


/*
Funcion que imprime la matriz ingresada por argumento, junto con el tamañano de esta
Entrada:
	ciudad[entero doble puntero]: matriz que representa la ciudad	
	ejeX[entero]: Tamaño del eje X de la matriz
	ejeY[entero]: Tamaño del eje Y de la matriz
Salida: ----
O(n^2)	
*/

void printBoard(int* ciudad[], int ejeX, int ejeY)
{
	//primera barra
	#ifdef LINUX
	printf(RESET_COLOR""CYAN_T"\t\t╔"RESET_COLOR);
	#endif
	#ifdef WINDOWS
			printf(RESET_COLOR""CYAN_T"\t\t*"RESET_COLOR);
	#endif

	for(int i=0; i<ejeX; i++)
	{
		#ifdef LINUX
			printf(RESET_COLOR""CYAN_T"═══"RESET_COLOR);
		#endif
		#ifdef WINDOWS
			printf(RESET_COLOR""CYAN_T"___"RESET_COLOR);
		#endif
	}
	#ifdef LINUX
		printf(RESET_COLOR""CYAN_T"╗\n"RESET_COLOR);
	#endif
	#ifdef WINDOWS
		printf(RESET_COLOR""CYAN_T"*\n"RESET_COLOR);
	#endif


	//tablero

	for(int j=0; j<ejeY; j++)
	{
		#ifdef LINUX
			printf(RESET_COLOR"\t\t"CYAN_T"║"RESET_COLOR);
		#endif
		#ifdef WINDOWS
			printf(RESET_COLOR"\t\t"CYAN_T"|"RESET_COLOR);
		#endif
		
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

					printf(RESET_COLOR" "ROJO_T"X "RESET_COLOR);	
				else
					printf(RESET_COLOR" "VERDE_T"_ "RESET_COLOR);
			#endif				
			
		}
		#ifdef LINUX
			printf(RESET_COLOR""CYAN_T"║\n"RESET_COLOR);
		#endif
		#ifdef WINDOWS
			printf(RESET_COLOR""CYAN_T"|\n"RESET_COLOR);
		#endif
	}

	//Ultima Barra
	#ifdef LINUX
		printf(RESET_COLOR""CYAN_T"\t\t╚"RESET_COLOR);
	#endif
	#ifdef WINDOWS
		printf(RESET_COLOR""CYAN_T"\t\t*"RESET_COLOR);
	#endif

	for(int i=0; i<ejeX; i++)
	{
		#ifdef LINUX
			printf(RESET_COLOR""CYAN_T"═══"RESET_COLOR);
		#endif
		#ifdef WINDOWS
			printf(RESET_COLOR""CYAN_T"___"RESET_COLOR);
		#endif
	}
	#ifdef LINUX
	printf(RESET_COLOR""CYAN_T"╝\n"RESET_COLOR);
	#endif
	#ifdef WINDOWS
			printf(RESET_COLOR""CYAN_T"*\n"RESET_COLOR);
	#endif
}