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
#include "../inc/estructuras.h"



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
	float costos;
	//obtencion del tamaño de la matriz
	fscanf(entrada, "%d", &cantAcop);
	fscanf(entrada, "%d", &cantActivos);
	fscanf(entrada, "%d", &subsidio);
	
	
    // Se crea una matriz con la 
    //ademas se crea una matriz extra para ir almacenando la mejor opcion
	int **acopios = (int **)malloc(sizeof(int*)*cantAcop);
	for(int i=0; i<cantAcop; i++)
	{
		acopios[i]=(int *)malloc(sizeof(int)*3);
	}
	//acopios[i][0]= Distancia del centro 
	//acopios[i][1]= basura
	//acopios[i][2]= Activado? 0=no; 1=si


	// Llenado con informacion de los acopios
	for(int i=0; i<cantAcop; i++)
	{
		fscanf(entrada, "%d", &acopios[i][0]);
		fscanf(entrada, "%d", &acopios[i][1]);
		acopios[i][2]=0;
		
	}

	Movimientos * movimientos;
	//recursion utilizando backtracking	
    costos=goloso(acopios, movimientos, subsidio, cantAcop, cantActivos);

/*
    //escritura del archivo de salida
    FILE *salida;
	salida = fopen( argv[2], "w" );
	
	//imprimir movimientos

	Nodo * aux = movimientos->inicio;
	while(aux->siguiente != NULL)
  	{
		fprintf(salida,"%d" , aux->origen);
		fprintf(salida,"%s" ,"->" );
		fprintf(salida,"%d" , aux->destino);
		aux=aux->siguiente;
		fprintf(salida,"%s" ,"\n" );
  	}
  	fprintf(salida,"%d" , aux->origen);
	fprintf(salida,"%s" ,"->" );
	fprintf(salida,"%d" , aux->destino);
	fprintf(salida,"%s" ,"\n" );


	//imprimir Centros de acopio activos

	for(int j=0; j<cantAcop; j++)
	{
		if(acopios[i][2]==0)
		{
			fprintf(salida,"%s" ,"centro " );
			fprintf(salida,"%d" , acopios[i][0]);
			fprintf(salida,"%s" ,": " );
			fprintf(salida,"%d" , acopios[i][1]);
			fprintf(salida,"%s" ," toneladas \n " );
		}

	}
	fprintf(salida,"%s" ,"Costo: " );
	fprintf(salida,"%d" , costos );

	fclose(entrada);
	fclose(salida);
*/
	//Liberacion de memoria
    for(int i=0; i<acopios; i++) 
	{
		free(acopios[i]);
	}
	free(acopios);
	return 0;
	
}