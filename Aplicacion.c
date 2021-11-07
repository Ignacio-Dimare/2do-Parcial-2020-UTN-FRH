#include "Aplicacion.h"

#define SECTOR_0 30
#define SECTOR_1 73
#define SECTOR_2 115
#define SECTOR_3 128
#define SECTOR_4 140
#define SECTOR_5 153
#define SECTOR_6 170
#define SECTOR_7 177
#define SECTOR_8 218
#define SECTOR_9 177
#define TOLERANCIA 10

void inicializacion(sector_t sector[], standar_t standar[], medicion_t medicion[])
{
    for(int i=0; i<SECTORES; i++)
    {
        sector[i].maximo = 0;
        sector[i].acum = 0;
        sector[i].cant = 0;
        sector[i].prom = 0;
        medicion[i].cant = 0;
        medicion[i].desvio = 0;
    }
    standar[0].temperatura = SECTOR_0;
    standar[1].temperatura = SECTOR_1;
    standar[2].temperatura = SECTOR_2;
    standar[3].temperatura = SECTOR_3;
    standar[4].temperatura = SECTOR_4;
    standar[5].temperatura = SECTOR_5;
    standar[6].temperatura = SECTOR_6;
    standar[7].temperatura = SECTOR_7;
    standar[8].temperatura = SECTOR_8;
    standar[9].temperatura = SECTOR_9;
}

void maxima(sensores_t sensor, sector_t sector[])
{
    if((int)sensor.temperatura > sector[sensor.sensor].maximo)
    {
        sector[sensor.sensor].maximo = sensor.temperatura;
    }
    return;
}

void finall(sector_t sector[], standar_t standar[], medicion_t medicion[])
{
    for(int i=0; i<SECTORES; i++)
    {
        sector[i].prom = ((float)(sector[i].acum)/(sector[i].cant));

    if((sector[i].prom > (standar[i].temperatura - TOLERANCIA)) && (sector[i].prom < (standar[i].temperatura + TOLERANCIA)))
        sector[i].flagCumple = 1;
    else
        sector[i].flagCumple = 0;
    }
    for(int i=0; i<SECTORES; i++)
    {
        for(int j=0; j<medicion[i].cant; j++)
            medicion[i].desvio += medicion[i].temp[j] - sector[i].prom;
    }
    for(int i=0; i<SECTORES; i++)
        medicion[i].desvio = medicion[i].desvio/medicion[i].cant;

    return;
}
