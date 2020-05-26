#include <mega128.h>
#include <delay.h>

flash char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void count(int);

void main(void)
{
    int num = 9999;
    
    
    DDRB = 0xF0;
    DDRD = 0xF0;
    DDRG = 0x0F;
    

    PORTB = 0x00;
    PORTD = 0x00;
    
    while(1)
    {
        count(num);
        num--;
        if(num > 9999) num = 0;
    }
}   
    
    
    
void count(int num){
    int i, N1000, N100, N10, N1, buf;
    N1000 = num/1000;
    buf = num % 1000;
    
    N100 = buf / 100;
    buf = buf % 100;
         
    N10 = buf/10;
    
    N1 = buf%10;
        for(i = 0; i < 2; i++){
            PORTG = 0x08;
            PORTD = ((seg_pat[N1] & 0x0f) << 4) | (PORTD & 0x0f);
            PORTB = (seg_pat[N1] & 0x70) | (PORTB & 0x0f);
            delay_ms(5);
            
            PORTG = 0x04;
            PORTD = ((seg_pat[N10] & 0x0f) << 4) | (PORTD & 0x0f);
            PORTB = (seg_pat[N10] & 0x70) | (PORTB & 0x0f);
            delay_ms(5);
            
            PORTG = 0x02;
            PORTD = ((seg_pat[N100] & 0x0f) << 4) | (PORTD & 0x0f);
            PORTB = (seg_pat[N100] & 0x70) | (PORTB & 0x0f);
            delay_ms(5);
            
            PORTG = 0x01;
            PORTD = ((seg_pat[N1000] & 0x0f) << 4) | (PORTD & 0x0f);
            PORTB = (seg_pat[N1000] & 0x70) | (PORTB & 0x0f);
            delay_ms(5);
        }    
}
