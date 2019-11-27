/*
	Felipe Villalobos Padilla
	20.139.310-8
	Algoritmos Avanzados
	Laboratorio 1 Backtracking 
	Enunciado de la ciudad y las sucursales
*/

#ifndef GOLOSO_H
#define GOLOSO_H


void guardar(int* ciudad[], int* mejorCiudad[] ,int ejeX,int ejeY);
int minimaDistancia(int* ciudad[],int ejeX,int ejeY,int x,int y);
float goloso(int * acopios[],Movimiento movimientos,int subsidio,int cantAcop,int cantActivos);
#endif