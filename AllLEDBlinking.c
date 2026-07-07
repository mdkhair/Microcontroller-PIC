#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);

#define _XTAL_FREQ 4000000 

void main() {
    // 1. Inisialisasi Port
    TRISD = 0x00;  // Tetapkan keseluruhan PORTD sebagai Output
    PORTD = 0x00;  // Pastikan semua LED dalam keadaan terpadam pada awalnya
    
    // 2. Gelung Utama (Infinite Loop)
    while(1) {
        PORTD = 0xFF;       // Nyalakan semua LED (1111 1111)
        __delay_ms(500);    // Lengah masa 500 milisaat (0.5 saat)
        
        PORTD = 0x00;       // Padamkan semua LED (0000 0000)
        __delay_ms(500);    // Lengah masa 500 milisaat (0.5 saat)
    }
}
