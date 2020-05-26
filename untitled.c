#include <mega128.h>

void main(void) {
    DDRC = 0xFF;
    PORTC = 0x55;
    while(1);
}
