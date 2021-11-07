#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED

typedef struct
{
    unsigned int temperatura;
    unsigned int sensor;
    unsigned int flag;
}sensores_t;

sensores_t lectura();

#endif // DRIVER_H_INCLUDED
