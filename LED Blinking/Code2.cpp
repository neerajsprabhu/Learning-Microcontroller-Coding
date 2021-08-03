#include<avr/io.h>
#include<util/delay.h>

int main(){
	DDRA = 0b00000010;
	PORTA = 0b00000000;
	while(1){
		_delay_ms(500);
		PORTA ^= 1<<PINA1;
	}
}
