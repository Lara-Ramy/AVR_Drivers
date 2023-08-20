/*
 * REGISTERS.h
 *
 *  Created on: Jul 22, 2023
 *      Author: larar
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "../UTILS/STD_TYPES.h"

#define    PORTA    *((volatile uint8*) 0x3B)
#define    DDRA     *((volatile uint8*) 0x3A)
#define    PINA     *((volatile uint8*) 0x39)

#define    PORTB    *((volatile uint8*) 0x38)
#define    DDRB     *((volatile uint8*) 0x37)
#define    PINB     *((volatile uint8*) 0x36)

#define    PORTC    *((volatile uint8*) 0x35)
#define    DDRC     *((volatile uint8*) 0x34)
#define    PINC     *((volatile uint8*) 0x33)

#define    PORTD    *((volatile uint8*) 0x32)
#define    DDRD     *((volatile uint8*) 0x31)
#define    PIND     *((volatile uint8*) 0x30)


/******************EXT INTERRUPT************/


#define SREG  		*((volatile uint8*)0x5F)

#define GICR   		*((volatile uint8*)0x5B)

#define GIFR   		*((volatile uint8*)0x5A)

#define MCUCR   	*((volatile uint8*)0x55)

#define MCUCSR   	*((volatile uint8*)0x54)

/******************Timer0************/

#define TCNT0   	*((volatile uint8*)0x52)

#define TCCR0   	*((volatile uint8*)0x53)

#define TIFR   		*((volatile uint8*)0x58)

#define TIMSK   	*((volatile uint8*)0x59)

#define OCR0   		*((volatile uint8*)0x5C)

/*******************Timer1*************/

#define TCCR1A   	*((volatile uint8*)0x4F)

#define TCCR1B 	  	*((volatile uint8*)0x4E)

#define OCR1A   	*((volatile uint16*)0x4A)

#define OCR1B		*((volatile uint16*)0x48)

#define ICR1    	*((volatile uint16*)0x46)

#define TCNT1		*((volatile uint16*)0x4C)

/*******************Timer2*************/
#define TCCR2   	*((volatile uint8*)0x45)

#define OCR2   		*((volatile uint8*)0x43)

#define TCNT2		*((volatile uint8*)0x44)

/*******************WD*************/

#define WDTCR		*((volatile uint8*)(0x41))

/*******************ADC*************/


#define ADMUX           (*(volatile uint8 *)(0x27))

#define ADCSRA          (*(volatile uint8 *)(0x26))

#define ADCH            (*(volatile uint8 *)(0x25))

#define ADCL            (*(volatile uint8 *)(0x24))

#define ADC				(*(volatile uint16 *)(0x24))



/*******************UART*************/

#define UCSRA            (*(volatile uint8 *)(0x2B))

#define UCSRB            (*(volatile uint8 *)(0x2A))

#define UDR              (*(volatile uint8 *)(0x2C))

#define UBRRL            (*(volatile uint8 *)(0x29))

#define UBRRH            (*(volatile uint8 *)(0x40))

#define UCSRC            (*(volatile uint8 *)(0x40))


/*******************SPI***************/

#define SPDR			(*(volatile uint8 *)(0x2F))

#define SPSR			(*(volatile uint8 *)(0x2E))

#define SPCR			(*(volatile uint8 *)(0x2D))

/*******************I2C*************/

#define TWDR            (*(volatile uint8 *)(0x23))

#define TWAR            (*(volatile uint8 *)(0x22))

#define TWSR            (*(volatile uint8 *)(0x21))

#define TWBR            (*(volatile uint8 *)(0x20))

#define TWCR            (*(volatile uint8 *)(0x56))


#endif /* REGISTERS_H_ */
