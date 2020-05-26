#include <mega128.h>
#include <delay.h>

flash char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

unsigned char N1 = 0;

void main () {
    DDRB = 0xF0;
    DDRD = 0xF0;     
    DDRG = 0x0F;
    
    EIMSK = 0b11110000;
    EICRB = 0b00000010;
    SREG  = 0x80;
             
    PORTG = 0b00001000;
    
    while(1) {
        PORTD =((seg_pat[N1] & 0x0F) << 4) | (PORTD & 0x0F);
        PORTB =(seg_pat[N1] & 0x70) | (PORTB & 0x0F);
    };
}

interrupt [EXT_INT4] void external_int4 () {
    N1 = (N1 + 1) % 10;
}