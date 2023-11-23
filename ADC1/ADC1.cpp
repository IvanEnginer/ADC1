#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

ISR(ADC_vect)
{
	int a=(ADCW+1)/128;
	if (a ==  0)
	PORTB = 0x00;
	else
	PORTB = 1 << (a-1);
}

void ADC_init()
{
	ADMUX = 0x00;
	ADCSRA = 0x8D;
}

unsigned int ADC_result(unsigned char adc_input)
{
	ADMUX=adc_input|(ADMUX & 0xF0);
	_delay_ms(10);
	ADCSRA |= 0x40;
	while((ADCSRA & 0x10)==0);
	ADCSRA|=0x10;
	return ADCW;
}

int main(void)
{
	DDRB = 0xFF;
	ADMUX = 0x00;
	ADCSRA = 0x8D;
	sei();

    while(1)
	{
		
	}
}