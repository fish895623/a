#include <mega128.h>
#include <delay.h>

unsigned char led = 0xFE;

void main () {
    DDRC = 0xFF;
    PORTC = led;
    
    EIMSK = 0b10000000;
    EICRB = 0b00000000;
    SREG  = 0x80;
    
    while(1);
}

interrupt [EXT_INT7] void external_int7 () {
    led = led << 1;
    led = led | 0x01;
    if(led == 0xFF) led = 0xFE;
    PORTC = led;
    delay_ms(20);
}