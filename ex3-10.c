#include <mega128.h>
#include <delay.h>

flash unsigned char seg_pat[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                                    0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

void main(void)
{
    int i;
    int j;
    
    DDRB = 0xF0;
    DDRD = 0xF0;
    DDRG = 0x0F;
    

    PORTB = 0x00;
    PORTD = 0x00;
    
    while(1)
    {
        for(i = 0; i < 16; i++){
            PORTD = ((seg_pat[i] & 0x0f) << 4) | (PORTD & 0x0f);
            PORTB = (seg_pat[i] & 0x07) | (PORTB & 0x0f);
            delay_ms(500);
        }    
    }
}