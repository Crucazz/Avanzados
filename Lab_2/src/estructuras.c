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
		aux->siguiente=nuevo;
		movimiento->fin= nuevo;
	}
	mov -> tamano +=1 ;
}