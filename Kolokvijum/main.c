/**
 * @file main.c
 * @brief Glavna funkcija
 * @author Jelena Karan
 * @date 28-4-2021
 * @version 1.0
 */


#include "..\timer0\timer0.h"
#include "pin.h"
#include "..\usart\usart.h"
#include "util.h"
#include <stdlib.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

int main()
{
	usartInit(9600);

	int8_t duzina=0;
	int8_t niz[64];
	int8_t mode = 1;

	usartPutString("Unesite broj elemenata niza\r\n");

	while (!usartAvailable());
	_delay_ms(100);

	duzina = usartParseInt();

	do
	{
		PORTB |= 1 << 5;
	}

	while (!usartAvailable());
	_delay_ms(100);

	usartPutString_P(PSTR("Unesite niz elemenata\r\n"));
	//Unos(niz);

	//Sort(niz, duzina, mode);


	return 0;
}

/*void Unos(int16_t niz[], int16_t duzina)
{
	int16_t tmp[20];

	for (int16_t i = 0; i < duzina; i++)
	{
			sprintf(tmp, "%d\0", i);
			usartPutString(tmp);

			while (usartAvailable() == 0);
			_delay_ms(100);

			niz[i] = usartParseInt();
			sprintf(tmp, "%d\r\n\0", niz[i]);
			usartPutString(tmp);
		}
	}
*/
