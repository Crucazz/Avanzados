#ifndef estructuras_h
#define estructuras_h

typedef struct acopios
{
    int basura;
    int distacia;
    int activado;
    struct acopio * siguiente;
}acopio;

typedef struct movimientos
{
    int origen;
    int destino;
    struct movimiento * siguiente;
}movimiento;

#endif