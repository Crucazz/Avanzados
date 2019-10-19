#ifndef estructuras_h
#define estructuras_h


typedef struct Nodos
{
    int origen;
    int destino;
    struct movimiento * siguiente;
}Nodo;

typedef struct Movimientos
{
    int tamano;
    Nodo * inicio;
    Nodo * fin;

}Movimiento;

#endif