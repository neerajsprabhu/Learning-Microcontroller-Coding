#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRC=0b00000000;
	DDRB=0b11111111;
	TWAR=(1<<TWA0);
	while((TWSR & 0xF8)!= 0x60){
		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		while (!(TWCR & (1<<TWINT)));
	}
    TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
	while((TWSR & 0xF8)!=0x80);
	int DATA=TWDR;
	PORTB=DATA;
}

