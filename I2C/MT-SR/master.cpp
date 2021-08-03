#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRC=(1<<0)|(1<<1);
	TWBR=0x01;
	TWSR=(0<<TWPS1)|(0<<TWPS0);
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	int DATA=0b10111001;
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & 0xF8)!= 0x08);
	TWDR=0b00000010;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & 0xF8)!= 0x18);
	TWDR=DATA;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & 0xF8)!= 0x28);
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	while(!(TWCR & (1<<TWSTO)));
}