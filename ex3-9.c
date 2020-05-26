#include <mega128.h>
#include <delay.h>

void main(void)
{
    char i, val;
    
    DDRB = 0xF0;
    DDRD = 0xF0;
    DDRG = 0x0F;
    
    PORTG = 0x0F;
    PORTB = 0x0;
    PORTD = 0x0;
    
    while(1)
    {
        val = 0x01;
        
        for(i=0;i<8;i++)
        {
            PORTD = (val & 0x0F) << 4;
            PORTB = (val & 0xF0);
            delay_ms(500);
            val = val << 1;
        }
    }
}