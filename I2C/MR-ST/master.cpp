#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRB=0b11111111;
	TWBR=0x01;
	TWSR=(0<<TWPS0)|(0<<TWPS1);
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & 0xF8)!= 0x08);
	TWDR=0b00000101;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & 0xF8)!= 0x40);
	TWCR= (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	while((TWSR & 0xF8)!=0x58);
	int DATA=TWDR;
	PORTB=DATA;
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	while(!(TWCR & (1<<TWSTO)));
}