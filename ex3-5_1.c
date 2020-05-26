#include <mega128.h>
#include <delay.h>

void main(){
    DDRC = 0xFF;
    PORTC = 0x55;
    while(1){
        PORTC.0 = 1;
        delay_ms(500);
        PORTC.0 = 0;
        delay_ms(500);
    }
}