/*
	Felipe Villalobos Padilla
	20.139.310-8
	Algoritmos Avanzados
	Laboratorio 2 Goloso
	Enunciado 1:la empresa de limpieza Clover Sanity
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
#include <ctype.h>



typedef struct Nodos
{
    int origen;
    int destino;
    struct Nodos * siguiente;
}Nodo;

typedef struct Movimientos
{
    int tamano;
    Nodo * inicio;
    Nodo * fin;

}Movimiento;

void iniciarMov(Movimiento * mov)
{
	mov -> inicio = NULL; 
    mov -> fin = NULL;
    mov -> tamano = 0;
}
void anadirNodo(Movimiento * movimiento, int origen, int destino )
{
	Nodo * aux = movimiento->fin;
	Nodo * nuevo;
	nuevo->origen = origen;
	nuevo->destino;
	nuevo->siguiente=NULL;

	if(movimiento->inicio==NULL)
	{
		movimiento->inicio= nuevo;
		movimiento->fin= nuevo;
	}
	if(movimiento->fin==NULL)
	{
		movimiento->fin= nuevo;
	}
	else
	{
		aux->siguiente= nuevo;
		movimiento->fin= nuevo;
	}
	movimiento->tamano +=1 ;
}
int vaciarAcopio(int* acopios[], int cantAcop, int * min, int j)
{
	int minimo = 99999999, operacion;
	for(int i=0; i<cantAcop; i++)
	{
		operacion = acopios[i][0]-acopios[j][0];
		if(operacion<0)
			operacion=(-1)*operacion;
		printf("distancia entre %d y %d =%d\n",i,j,operacion );
		if(operacion<minimo && j!=i && acopios[j][1]!=0 && acopios[i][1]!=0 && acopios[i][2]==1)
		{
			minimo=operacion;
			min[0]=i;
			min[1]=j;

		}
	}
	return(minimo);
}

int minimo(int* acopios[], int cantAcop, int * min)
{
	int minimo = 99999999, operacion;
	for(int i=0; i<cantAcop; i++)
	{
		for(int j=i+1; j<cantAcop; j++)
		{

			operacion = acopios[i][0]-acopios[j][0];
			if(operacion<0)
				operacion=(-1)*operacion;
			printf("distancia entre %d y %d =%d\n",i,j,operacion );
			if(operacion<minimo && j!=i && acopios[j][1]!=0 && acopios[i][1]!=0)
			{
				minimo=operacion;
				min[0]=i;
				min[1]=j;

			}
		}
	}
	return(minimo);
}

/*
recursion utilizando el metodo de backtracking para ir posicionando las sucursales en la ciudad,

Entrada:


Salida:-----
O(n)	
*/
float goloso(int * acopios[],Movimiento * movimientos,int subsidio,int cantAcop,int cantActivos, FILE * salida)
{

	int min[2], activos=0, distancia;
	float costos=0, toneladas=1;
	while(cantActivos != activos)
	{
		distancia=minimo(acopios, cantAcop, min);
		//printf("inicio %d - Fin %d \n",min[0], min[1]);
		
		if (acopios[min[0]][1] > acopios[min[1]][1])
		{
			//printf("Se activo el acopio %d \n", min[0]);
			if(acopios[min[0]][2]==0)
			{
				acopios[min[0]][2]=1;	
				activos += 1;
			}
			toneladas= acopios[min[1]][1] - (acopios[min[1]][1]/subsidio);
			acopios[min[0]][1] += acopios[min[1]][1];
			acopios[min[1]][1] = 0;

			//escritura en el archivo de salida
			fprintf(salida,"%d" ,acopios[min[1]][0] );
			fprintf(salida,"%s" ,"->" );
			fprintf(salida,"%d" ,acopios[min[0]][0] );
			fprintf(salida,"%s" ,"\n" );
			//

		}
		else
		{
			//printf("Se activo el acopio %d \n", min[1]);
			if(acopios[min[1]][2]==0)
			{
				acopios[min[1]][2]=1;	
				activos += 1;
			}
			toneladas= acopios[min[0]][1] - (acopios[min[0]][1]/subsidio);
			acopios[min[1]][1] += acopios[min[0]][1];
			acopios[min[0]][1] = 0;	

			//escritura en el archivo de salida
			fprintf(salida,"%d" ,acopios[min[0]][0] );
			fprintf(salida,"%s" ,"->" );
			fprintf(salida,"%d" ,acopios[min[1]][0] );
			fprintf(salida,"%s" ,"\n" );
			//

		}
		costos += distancia*toneladas;

		//agregar movimiento
	}
	//se consigue que fncionen todos los acopios necesarios
	//ahora se revisara si los acopios que NO estan activados esten sin basura
	//printf("costos: %f\n", costos);
	for(int i=0; i<cantAcop; i++)
	{
		if(acopios[i][2]==0 && acopios[i][1]!=0)
		{
			distancia=vaciarAcopio(acopios, cantAcop, min, i);
			//printf("inicio %d - Fin %d \n",min[0], min[1]);
			toneladas= acopios[min[1]][1] - (acopios[min[1]][1]/subsidio);
			acopios[min[0]][1] += acopios[min[1]][1];
			acopios[min[1]][1] = 0;
			//printf("%d- distancia: %d    toneladas movidas: %f \n", i,distancia,toneladas);
			costos = distancia*toneladas + costos;

			//escritura en el archivo de salida
			fprintf(salida,"%d" ,acopios[min[1]][0] );
			fprintf(salida,"%s" ,"->" );
			fprintf(salida,"%d" ,acopios[min[0]][0] );
			fprintf(salida,"%s" ,"\n" );
			//
		}
	}
	printf("costos: %f \n", costos);

	for(int i=0; i<cantAcop; i++)
		printf("%d- distancia: %d    basura: %d     activo: %d\n", i,acopios[i][0],acopios[i][1],acopios[i][2]);
	
	return (costos);
}



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
		acopios[i]=(int *)malloc(sizeof(int)*3);

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

	Movimiento * movimientos = (Movimiento*) malloc(sizeof(Movimiento));
	iniciarMov(movimientos);

	FILE *salida;
	salida = fopen( argv[2], "w" );
	//recursion utilizando backtracking	
    costos=goloso(acopios, movimientos, subsidio, cantAcop, cantActivos, salida);
    printf("Costo %f \n",costos );

	//escritura en el archivo de salida
    for(int i=0; i<cantAcop; i++)
	{
		if(acopios[i][2]==1)
		{
			fprintf(salida,"%s" ,"Centro " );
			fprintf(salida,"%d" ,acopios[i][0] );
			fprintf(salida,"%s" ,": " );
			fprintf(salida,"%d" ,acopios[i][1] );
			fprintf(salida,"%s" ," Toneladas \n" );
		}
		
	}
	fprintf(salida,"%s" ,"Costo: " );
	fprintf(salida,"%f" ,costos );


	fclose(entrada);
	fclose(salida);

	//Liberacion de memoria
    for(int i=0; i<cantAcop; i++) 
	{
		free(acopios[i]);
	}
	free(acopios);
	free(movimientos);
	return 0;
	
}