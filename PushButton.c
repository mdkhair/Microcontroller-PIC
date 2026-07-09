#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);
#define _XTAL_FREQ 4000000 

void main() {
    
    // --- 1. TETAPAN AWAL ---
    TRISD = 0x00;   // PORTD (LED) sebagai OUTPUT (0)
    PORTD = 0x00;   // Matikan semua LED pada asalnya
    
    TRISB = 0xFF;   // PORTB (Butang K1-K4) sebagai INPUT (1)
    
    // WAJIB: Aktifkan Internal Pull-Up untuk PORTB
    OPTION_REG &= 0x7F; 
    
    // --- 2. GELUNG UTAMA ---
    while(1) {
        
        // Periksa jika butang K1 (RB0) ditekan (Logik 0)
        if (RB0 == 0) {
            RD0 = 1; // Nyalakan LED L0
        } 
        else {
            // Jika butang K1 dilepaskan (Logik 1)
            RD0 = 0; // Padamkan LED L0
        }
        
    }
}
