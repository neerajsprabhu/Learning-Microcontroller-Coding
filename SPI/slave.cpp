#include<avr/io.h>
#include<util/delay.h>

int main(){
	DDRB=0b01000000;
	DDRC=0b11111111;
	SPCR=1<<SPE;
	SPSR=0x00;
	SPDR=0b11011101;
	_delay_ms(1000);
	while(!(SPSR & (1<<SPIF)));
	PORTC=SPDR;
}