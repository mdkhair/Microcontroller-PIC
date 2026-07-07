#include <htc.h>

// Tetapan asas (Configuration Bits) yang ringkas dan padat
__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

#define _XTAL_FREQ 4000000 

void main() {
    // 1. Inisialisasi Port
    TRISD = 0x00;  // Tetapkan keseluruhan pin pada PORTD sebagai Output
    PORTD = 0x00;  // Padamkan semua LED pada awalnya (Reset state)
    
    // 2. Gelung Utama (Infinite Loop)
    while(1) {
        RD0 = 1;            // Menghantar isyarat logik HIGH (1) ke pin RD0 -> LED menyala
        __delay_ms(1000);   // Lengah masa selama 1000 milisaat (1 saat)
        
        RD0 = 0;            // Menghantar isyarat logik LOW (0) ke pin RD0 -> LED padam
        __delay_ms(1000);   // Lengah masa selama 1000 milisaat (1 saat)
    }
}
