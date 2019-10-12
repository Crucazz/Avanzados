#ifndef BACKTRACKING_H
#define BACKTRACKING_H


void guardar(int* ciudad[], int* mejorCiudad[] ,int ejeX,int ejeY);
int comprobar(int* ciudad[],int ejeX,int ejeY,int x,int y);
void backtracking(int* ciudad[], int* mejorCiudad[], int ejeX, int ejeY, int x, int y, int sucActual, int sucMaximas, int* colocada);
#endif