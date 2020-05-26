#include <mega128.h>
#include <delay.h>


void main(void){
    unsigned char o_sw, n_sw;
    unsigned char led = 0xFE;
    
    DDRC = 0xFF;
    DDRE = 0x00;
    
    PORTC = led;
    
    o_sw = PINE & 0b00010000;
    
    while(1){
        n_sw = PINE & 0b00010000;
        if(o_sw != 0 && n_sw == 0){
            led = (led << 1) | 0x01;
            if(led == 0xFF) led = 0xFE;
            
            PORTC = led;
        }
        o_sw = n_sw;
    }
}