#include<avr/io.h>
int main(){
	DDRA = 0b00000010;
	PORTA = 0b00000000;
	TCCR1B |= 1<<CS10 | 1<<CS11;
	while(1){
		if(TCNT1>2232){
			TCNT1=0;
			PORTA ^= 1<<PINA1;
		}
	}
}