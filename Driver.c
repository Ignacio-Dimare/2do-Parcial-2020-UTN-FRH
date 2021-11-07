#include "Driver.h"
#include "Mock.h"

#define PUERTO_0 0x300
#define PUERTO_1 0x301
#define SHIFT_VALIDO 4
#define MASK_VALIDO 0x03
#define PRIMER_VALIDEZ 0x00
#define SEGUNDA_VALIDEZ 0x01
#define SHIFT_BYTE1 8
#define MASK_BYTE1 0xFF00
#define SHIFT_TEMPERATURA 6
#define MASK_TEMPERATURA 0x03FF
#define MASK_SENSOR 0x0F
#define SALIDA 0x03

sensores_t lectura()
{
    unsigned int byte0, byte1, validez, valorEmpaquetado;
    sensores_t sens;
    sens.flag = 0;
    do
    {
        byte0 = mock(PUERTO_0);
        byte1 = mock(PUERTO_1);

        validez = ((byte0 >> SHIFT_VALIDO) & MASK_VALIDO);
    }while(validez != PRIMER_VALIDEZ);

    do
    {
        byte0 = mock(PUERTO_0);
        byte1 = mock(PUERTO_1);

        validez = ((byte0 >> SHIFT_VALIDO) & MASK_VALIDO);

        if(validez == SALIDA)
        {
            sens.flag = 1;
            return sens;
        }
    }while(validez != SEGUNDA_VALIDEZ);

    valorEmpaquetado = byte1;
    valorEmpaquetado = valorEmpaquetado << SHIFT_BYTE1;
    valorEmpaquetado = valorEmpaquetado & MASK_BYTE1;
    valorEmpaquetado = valorEmpaquetado | byte0;

    sens.temperatura = (valorEmpaquetado >> SHIFT_TEMPERATURA) & MASK_TEMPERATURA;
    sens.sensor = valorEmpaquetado & MASK_SENSOR;

    return sens;
}
