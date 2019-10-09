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
	for(int i=0; i<ejeX; i++)
	{
		for(int j=0; j<ejeY; j++)
		{
			printf(" %d ",ciudad[i][j]);
		}
		printf("\n");
	}
}


// Colocación de una reina
// -----------------------
// Parámetros
//   fila   - Fila de la reina que queremos colocar
//   reinas - Vector con las posiciones de las reinas
//   n      - Número de reinas

void backtracking(int fila, int reinas[], int n)
{
  int ok = 0;

  if (fila<n && listo==0) 
  {
    // Quedan reinas por colocar
    for (reinas[fila]=0; reinas[fila]<n; reinas[fila]++) 
    {
      // Comprobamos si la posición 
      // de la reina actual es válida
      
      if (comprobar(fila,reinas,n) && listo==0) 
      {

        // Si es así, intentamos colocar
        // las reinas restantes
        mostrarTablero(reinas,n);
        colocarReina (fila+1, reinas, n);

      }
    } 
  
  } 
  else
  {
    // No quedan reinas por colocar (solución)
    
    mostrarTablero(reinas,n);
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
	for(int i=0; i<ejeX; i++)
	{
		ciudad[i]=(int *)malloc(sizeof(int)*ejeY);
	}


	//ejeX=i
	//ejeY=j

	// Llena la ciudad de nada
	for(int i=0; i<ejeX; i++)
	{
		for(int j=0; j<ejeY; j++)
		{
			ciudad[i][j]=0;
		}
	}

	imprimir(ciudad,ejeX ,ejeY );
    backtracking(0,ciudad,sucursales);

    for(int i=0; i<ejeX; i++) 
	{
		free(ciudad[i]);
	}
	free(ciudad);


	
}