/*
	Felipe Villalobos Padilla
	20.139.310-8
	Algoritmos Avanzados
	Laboratorio 2 Goloso
	Enunciado 1:la empresa de limpieza Clover Sanity
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/goloso.h"
#include "../inc/debug.h"
#include "../inc/colors.h"



int main (int argc, char *argv[])
{

	FILE *entrada;
	entrada = fopen( argv[1], "r" );
	if( entrada )
		printf( "\n" );
	else
	{
		printf( "Archivo no existe, compuebe si esta bien ingreado el nombre.\n" );
		return 1;
	}

	int cantAcop, cantActivos, subsidio;

	//obtencion del tamaño de la matriz
	fscanf(entrada, "%d", &cantAcop);
	fscanf(entrada, "%d", &cantActivos);
	fscanf(entrada, "%d", &subsidio);
	
	
	int* colocada=(int *)malloc(sizeof(int)*2);
    // Se crea la la ciudad segun el tamaño ingresado
    //ademas se crea una matriz extra para ir almacenando la mejor opcion
	int **ciudad = (int **)malloc(sizeof(int*)*ejeX);
	int **mejorCiudad = (int **)mal	loc(sizeof(int*)*ejeX);
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




	//obtencion si existen sucursales pre-dispuestas
	int cantSucursales,nuevaCoordX, nuevaCoordY;
	fscanf(entrada, "%d", &cantSucursales);		

	for(int i=0; i<cantSucursales; i++)
	{
		fscanf(entrada, "%d", &nuevaCoordX);
		fscanf(entrada, "%d", &nuevaCoordY);
		ciudad[nuevaCoordX][nuevaCoordY]=1;
		colocada[1]=colocada[1]+1;
	}

	guardar(ciudad,mejorCiudad,ejeX,ejeY);


	//recursion utilizando backtracking	
    backtracking(ciudad,mejorCiudad,ejeX,ejeY,0,0,colocada[1],sucursales,colocada);

    //escritura del archivo de salida
    FILE *salida;
	salida = fopen( argv[2], "w" );
/*
	//guardar cantidad de sucursales
	fprintf(salida,"%d" , colocada[1]);
	fprintf(salida,"%s" ,"\n" );

	//lista con las coordenadas de las sucursales
	for(int j=0; j<ejeY; j++)
	{
		for(int i=0; i<ejeX; i++)
		{
			if(mejorCiudad[i][j]!=0)
			{
				fprintf(salida,"%d" , i);
				fprintf(salida,"%s" ,"-" );
				fprintf(salida,"%d" , j);
				fprintf(salida,"%s" ," || " );
			}
		}
	}
	fprintf(salida,"%s" ,"\n" );

	//representacion grafica de la ciudad
	for(int j=0; j<ejeY; j++)
	{
		for(int i=0; i<ejeX; i++)
		{
			if(mejorCiudad[i][j]==0)
				fprintf(salida,"%s" ," _ " );
			else
				fprintf(salida,"%s" ," X " );
		}
		fprintf(salida,"%s" ,"\n" );
	}
	fclose(entrada);
	fclose(salida);
*/
	//Liberacion de memoria
    for(int i=0; i<ejeX; i++) 
	{
		free(ciudad[i]);
		free(mejorCiudad[i]);
	}
	free(ciudad);
	free(mejorCiudad);
	return 0;
	
}