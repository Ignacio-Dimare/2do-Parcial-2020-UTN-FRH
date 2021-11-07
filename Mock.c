#include "Mock.h"
#include <stdio.h>
//#define DEBUG


unsigned char generarValidez(void)
{
    static unsigned char cant_enviados = 0;
    static unsigned int cont_fin = 0;

    unsigned char valorDevuelto ;

    cont_fin ++;

    if (cant_enviados < 2 )
        valorDevuelto = 0 ;

        else if(cant_enviados < 4)
        {
            valorDevuelto = 1 ;
        }

            else
            {
                valorDevuelto = 2 ;
            }


    cant_enviados++;

    if ( cant_enviados == 6 )
    {
        cant_enviados = 0 ;
    }

    if ( cont_fin == 200 )//MODIFICAR ESTA LINEA SEGUN CANTIDAD PARA FINALIZAR
        valorDevuelto = 3;


    return valorDevuelto;
}

unsigned int generarTemperatura( unsigned int sector )
{

    static unsigned int acum[]={22,65,107,120,132,145,162,165,210,169};

    static unsigned int cont[]={0,0,0,0,0,0,0,0,0,0};

    const unsigned int minimas[]={22,65,107,120,132,145,162,160,210,169};

    const unsigned int maximas[]={38,81,123,136,148,161,178,195,226,185};


    if ( acum[sector] < maximas[sector] ){

            acum[sector] = minimas[sector] + cont[sector];
            cont[sector]++;

    }

    else{

            cont[sector] = 1;
            acum[sector] = minimas[sector];

        }

    return acum[sector];
}

unsigned int generarSector()
{
    static unsigned int valor = 0, cont=0;

	if (cont == 6)
	{
		valor += 1 ;
		cont = 0;
	}

    if (valor > 9)
	{
        valor = 0 ;
	}

   	cont++ ;

    return valor ;
}

unsigned char mock (unsigned short int puerto)
{

    static unsigned char byteDevuelto0 = 0, byteDevuelto1 = 0;
    static unsigned char valido = 0;
    static unsigned int sector = 0;
    static unsigned short int temperatura = 0;


    if(puerto== 0X301)
    {

    	return byteDevuelto1;

    }


    if(puerto== 0X300){

	    valido = generarValidez();
        sector = generarSector();
        temperatura = generarTemperatura(sector);

#ifdef DEBUG

        printf("\nValidez: %u \t",valido);

        printf("Sector: %u \t",sector);

        printf("Temperatura: %u \t",temperatura);

#endif

	    byteDevuelto0=byteDevuelto1=0;

    	byteDevuelto0  = (temperatura<<6);
    	byteDevuelto0 |= (valido<<4);
    	byteDevuelto0 |= (sector);

	    byteDevuelto1 = (temperatura>>2);


	return byteDevuelto0;

    }
 return 0;
}
