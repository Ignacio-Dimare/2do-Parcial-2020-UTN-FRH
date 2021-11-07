#ifndef APLICACION_H_INCLUDED
#define APLICACION_H_INCLUDED

#include "Driver.h"

#define SECTORES 10
#define MEDICIONES 50

typedef struct
{
    int maximo;
    int acum;
    float prom;
    int cant;
    int flagCumple;
}sector_t;

typedef struct
{
    int temperatura;
}standar_t;

typedef struct
{
    int temp[MEDICIONES];
    int cant;
    float desvio;
}medicion_t;

void maxima(sensores_t sensor, sector_t sector[]);
void inicializacion(sector_t sector[], standar_t standar[], medicion_t medicion[]);
void finall(sector_t sector[], standar_t standar[], medicion_t medicion[]);

#endif // APLICACION_H_INCLUDED
