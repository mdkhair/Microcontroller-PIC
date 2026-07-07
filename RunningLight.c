#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);

#define _XTAL_FREQ 4000000 

void main() {
    TRISD = 0x00;
    PORTD = 0x00;
    
    while(1) {
        for(int i = 0; i < 8; i++) {
            PORTD = (1 << i);   // Menganjak logik '1' dari RD0 hingga RD7
            __delay_ms(200);
        }
    }
}
