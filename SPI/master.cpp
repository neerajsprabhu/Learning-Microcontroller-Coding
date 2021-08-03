#include<avr/io.h>
#include<util/delay.h>

int main(){
	DDRB=0b10110000;
	DDRC=0b11111111;
	SPCR=(1<<SPE)|(1<<MSTR);
	SPSR=0x00;
	SPDR=0b10101100;
	_delay_ms(1000);
	while(!(SPSR & (1<<SPIF)));
	PORTC=SPDR;
}
