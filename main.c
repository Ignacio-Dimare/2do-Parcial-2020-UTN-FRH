#include <stdio.h>
#include <stdlib.h>
#include "Mock.h"
#include "Aplicacion.h"
#include "Driver.h"

int main()
{
    sensores_t sensor;
    sensores_t aux;
    medicion_t medicion[SECTORES];
    sector_t sector[SECTORES];
    standar_t standar[SECTORES];

    inicializacion(sector, standar, medicion);

    do
    {
        aux = lectura();
        if(aux.flag == 0)
        {
            sensor = aux;
            printf("Sensor: %d \t", sensor.sensor);
            printf("Temperatura: %d\n", sensor.temperatura);
            maxima(sensor, sector);
            sector[sensor.sensor].acum += sensor.temperatura;
            sector[sensor.sensor].cant++;
            medicion[sensor.sensor].temp[medicion[sensor.sensor].cant] = sensor.temperatura;
            medicion[sensor.sensor].cant++;
        }
    }while(aux.flag == 0);

    finall(sector, standar, medicion);

    for(int i=0; i<SECTORES; i++)
    {
        printf("Sensor %d\tMaximo: %d\tPromedio: %.3f\t Mediciones: %d\t Cumple: %d\tMedia desvio: %f\n", i, sector[i].maximo, sector[i].prom, sector[i].cant, sector[i].flagCumple, medicion[i].desvio);
    }


    return 0;
}
