#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);
#define _XTAL_FREQ 4000000

// Susunan kod hex untuk paparan 0 hingga 9
const unsigned char paparan[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //Hex bagi nombor 0-9

void main() {
    // 1. Matikan fungsi Analog (Wajib)
    ADCON1 = 0x06;  
    
    // 2. Tetapkan arah Port
    TRISD = 0x00;   // PORTD sebagai output (Segmen A-G)
    TRISA = 0x00;   // PORTA sebagai output (Kawal Digit 1 hingga 6)
    
    // 3. Bersihkan paparan pada awalnya
    PORTD = 0x00;
    PORTA = 0x00;
    
    while(1) {
        // --- Imbasan Digit 1 ---
        PORTD = paparan[1];  
        RA5 = 1;             
        __delay_ms(2);       
        RA5 = 0;             
        
        // --- Imbasan Digit 2 ---
        PORTD = paparan[2];  
        RA4 = 1;             
        __delay_ms(2);
        RA4 = 0;             
        
        // --- Imbasan Digit 3 ---
        PORTD = paparan[3];  
        RA3 = 1;             
        __delay_ms(2);
        RA3 = 0;             
        
        // --- Imbasan Digit 4 ---
        PORTD = paparan[4];  
        RA2 = 1;             
        __delay_ms(2);
        RA2 = 0;             
        
        // --- Imbasan Digit 5 ---
        PORTD = paparan[5];  
        RA1 = 1;             // DIKEMAS KINI KE RA1
        __delay_ms(2);
        RA1 = 0;             
        
        // --- Imbasan Digit 6 ---
        PORTD = paparan[6];  
        RA0 = 1;             // DIKEMAS KINI KE RA0
        __delay_ms(2);
        RA0 = 0;             
    }
}
