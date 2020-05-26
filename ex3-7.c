#include <mega128.h>
#include <delay.h>

void main(void)
{
    unsigned char key;
    
    DDRC = 0xFF;
    DDRE = 0x0;
    
    PORTC = 0xFF;
    
    while(1)
    {
        key = PINE & 0xF0;
        switch(key)
        {
            case 0b11100000 : // sw 1
                PORTC = 0x00;
                delay_ms(500);
                PORTC = 0xFF;
                delay_ms(500);
                break;
            // case 0b11010000 :
            //    PORTC = 0xFF;
            //    break;
            case 0b10110000 :
                PORTC = 0b01010101; delay_ms(500);
                PORTC = 0b10101010; delay_ms(500);                
                break;
            //case 0b01110000 :
              //  PORTC = 0b10101010;
                //break;
        }
    }
}