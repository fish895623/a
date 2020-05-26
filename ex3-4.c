#include <mega128.h>
#include <delay.h>

void main(){
    int i;
    unsigned char led;
    
    DDRC = 0xFF;
    
    while(1){
        led = 0xFE;
        for(i = 0; i < 8;i++) {
            PORTC = led;
            delay_ms(500);
            
            led = led << 2;
            led = led | 0x03;
        }
    }
}