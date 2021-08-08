#include <avr/io.h>
#include <util/delay.h>

int main(){
	int DATA=0b10101010;
	TWAR=(1<<TWA1);
	while((TWSR & 0xF8)!= 0xA8){
		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		while(!(TWCR & (1<<TWINT)));
	}
	TWDR=DATA;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWSR & 0xF8)!= 0xC0);
}

