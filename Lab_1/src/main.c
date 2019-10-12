/*
	Felipe Villalobos Padilla
	20.139.310-8
	Algoritmos Avanzados
	Laboratorio 1 Backtracking 
	Enunciado 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/backtracking.h"
#include "../inc/debug.h"
#include "../inc/colors.h"



void main (int argc, char *argv[])
{
	int sucursales; 	// Cantidad de sucursales maximos

	int ejeX =atoi(argv[1]);
	int ejeY =atoi(argv[2]);
	

	//se queda con el minimo tamaño entre ancho y alto
	if( ejeX>ejeY ) 
		sucursales = ejeY;
	else
		sucursales = ejeX;

	int* colocada=(int *)malloc(sizeof(int)*2);
    // Se crea la la ciudad segun el tamaño ingresado
    //ademas se crea una matriz extra para ir almacenando la mejor opcion
	int **ciudad = (int **)malloc(sizeof(int*)*ejeX);
	int **mejorCiudad = (int **)malloc(sizeof(int*)*ejeX);
	for(int i=0; i<ejeX; i++)
	{
		ciudad[i]=(int *)malloc(sizeof(int)*ejeY);
		mejorCiudad[i]=(int *)malloc(sizeof(int)*ejeY);
	}


	// Llena la ciudad de nada
	for(int i=0; i<ejeX; i++)
	{
		for(int j=0; j<ejeY; j++)
		{
			mejorCiudad[i][j]=0;
			ciudad[i][j]=0;
		}
	}

	colocada[0]=0; //utilizada para comprobar si se a cumplido la cantidad de sucursales macimas en la ciudad
	colocada[1]=0; //utilizada para contar la cantidad maxima de sucursales colocadas en la ciudad

	//recursion utilizando backtracking
    backtracking(ciudad,mejorCiudad,ejeX,ejeY,0,0,0,sucursales,colocada);
    /*
    #ifdef DEBUG
		printCurrent(mejorCiudad,ejeX ,ejeY);
	#endif
	*/

	//Liberacion de memoria
    for(int i=0; i<ejeX; i++) 
	{
		free(ciudad[i]);
		free(mejorCiudad[i]);
	}
	free(ciudad);
	free(mejorCiudad);
	
}