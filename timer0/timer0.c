/**
 * @file timer0.c
 * @brief Funkcije za biblioteku timer0.c
 * @author Jelena Karan
 * @date 28-4-2021
 * @version 1.0
 */

#include "timer0.h"
#include "avr/io.h"

unsigned long timer0DelayMs(unsigned long delay_length)
{
	unsigned long t0; // Trenutak pocevsi od kog se racuna pauza

	// Implementacija pauze
	t0 = ms;
	while ((ms - t0) < delay_length)
		; // Pauza delay_length milisekundi

	return ms;
}

/******************************************************************************************/

void timer0InteruptInit()
{
	// Inicijalizacija tajmera 0 tako da perioda prekida bude 1ms
	TCCR0A = 0x02;
	TCCR0B = 0x03;
	OCR0A = 249;
	TIMSK0 = 0x02;

	// Podesavanje globalne dozvole prekida
	sei();
}

/*****************************************************************************************/

ISR(TIMER0_COMPA_vect)
{
	// Inkrementovanje broja milisekundi koje su prosle od pokretanja aplikacije
	ms++;
}

/****************************************************************************************/

unsigned char kasnjenje(unsigned long miliseconds, unsigned long broj) {
	if (miliseconds == broj) {
		PORTB ^= 1<<5 ;
		return 1;
	}
	return 0;
}
