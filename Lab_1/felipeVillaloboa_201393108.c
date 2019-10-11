/*
	Felipe Villalobos Padilla
	20.139.310-8
	Algoritmos Avanzados
	Laboratorio 1 Backtracking 
	Enunciado 1
*/

#include <stdio.h>
#include <stdlib.h>
int listo;



/*
Funcion que imprime la matriz ingresada por argumento, junto con el tamañano de esta
Entrada: entero doble puntero, entero, entero
Salida: ----
O(n**2)	
*/

void imprimir(int* ciudad[], int ejeX, int ejeY)
{
	printf("\n");
	for(int j=0; j<ejeY; j++)
	{
		for(int i=0; i<ejeX; i++)
		{
			printf(" %d ",ciudad[i][j]);
		}
		printf("\n");
	}
}

int comprobar(int* ciudad[],int ejeX,int ejeY,int x,int y)
{
	//comprueba vertical
	for(int j=0; j<ejeY; j++)
	{
		if(ciudad[x][j]!=0)	
		{
			printf("No se puede colocar en %d,%d\n",x,j );
			return (0);
		}
		
	}	

	//comprueba horizontal
	for(int i=0; i<ejeX; i++)
	{
		if(ciudad[i][y]!=0)	
		{
			printf("No se puede colocar en %d,%d\n",i,y );
			return (0);
		}		
		if(ciudad[i][i]!=0)	
		{
			printf("No se puede colocar (diagonal pricnipal) en %d,%d\n",i,i );
			return (0);
		}
	}
	return (1);

}

/*
Descripcion: Colocación de una sucursal en la ciudad
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
void backtracking(int* ciudad[], int* mejorCiudad[], int ejeX, int ejeY, int x, int y, int sucActual, int sucMaximas)
{
	int ok = 0;
	if(sucActual != sucMaximas && listo==0)
	{
		for(int j=y; j<ejeY; j++)
		{
			for(int i=x; i<ejeX; i++)
			{
				printf("\nPosc X: %d  POscY: %d\n",i,j);
				//¿es posible colocar la sucursal?
				if(listo==0 && comprobar(ciudad,ejeX,ejeY,i,j)==1)
				{
					printf("\nSe puede colocar\n");
					sucActual=sucActual+1;
					ciudad[i][j]=1;
					imprimir(ciudad,ejeX ,ejeY);
					backtracking(ciudad,mejorCiudad,ejeX,ejeY,0,j+1,sucActual,sucMaximas);

				}
				
			}
		}

	} 
	else
	{
    	// Se colocan el maximo de sucursales en la ciudad
		//no hay mas opciones, por lo que se retornara desde este punto
    
		imprimir(ciudad,ejeX ,ejeY);
		listo=1;
		printf("\nEsto es todo amigos\n");
		return;
  }

  //return ok;
}


void main (int argc, char *argv[])
{
	int sucursales; 	// Cantidad de sucursales maximos
	listo=0;

	int ejeX =atoi(argv[1]);
	int ejeY =atoi(argv[2]);
	

	//se queda con el minimo tamaño entre ancho y alto
	if( ejeX>ejeY ) 
		sucursales = ejeY;
	else
		sucursales = ejeX;


    // Se crea la la ciudad segun el tamaño ingresado
	int **ciudad = (int **)malloc(sizeof(int*)*ejeX);
	int **mejorCiudad = (int **)malloc(sizeof(int*)*ejeX);
	for(int i=0; i<ejeX; i++)
	{
		ciudad[i]=(int *)malloc(sizeof(int)*ejeY);
		mejorCiudad[i]=(int *)malloc(sizeof(int)*ejeY);
	}


	//ejeX=i
	//ejeY=j

	// Llena la ciudad de nada
	for(int i=0; i<ejeX; i++)
	{
		for(int j=0; j<ejeY; j++)
		{
			mejorCiudad[i][j]=0;
			ciudad[i][j]=0;
		}
	}

//	ciudad[0][1]=1;
	imprimir(ciudad,ejeX ,ejeY);

    backtracking(ciudad,mejorCiudad,ejeX,ejeY,0,0,0,sucursales);

	//Liberacion de memoria
    for(int i=0; i<ejeX; i++) 
	{
		free(ciudad[i]);
		free(mejorCiudad[i]);
	}
	free(ciudad);
	free(mejorCiudad);


	
}