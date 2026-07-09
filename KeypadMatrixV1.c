#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);
#define _XTAL_FREQ 4000000 

void main() {
    
    // --- 1. TETAPAN AWAL ---
    TRISD = 0x00;   // PORTD (LED) sebagai Output
    PORTD = 0x00;   // Padamkan semua LED
    
    // TRISB: Separuh Output (Baris RB4-RB7), Separuh Input (Lajur RB0-RB3)
    // 0x0F = 0b00001111 
    TRISB = 0x0F;   
    
    // Aktifkan Internal Pull-up untuk memastikan Lajur (RB0-RB3) stabil pada 5V
    OPTION_REG &= 0x7F; 
    
    unsigned char nilai_matriks;
    
    // --- 2. GELUNG UTAMA (Pengimbasan) ---
    while(1) {
        
        // Hantar isyarat LOW (0) pada Baris 1 (RB7)
        // Nilai asal: 0b0111 1111 (0x7F)
        PORTB = 0x7F; 
        
        // Rehat 1 kitaran (No Operation) untuk elak pepijat elektronik (signal bounce)
        asm("nop");
        
        // Baca bahagian Lajur (RB0-RB3)
        // Kita guna operasi Bitwise AND (& 0x0F) untuk abaikan nilai Baris, ambil nilai Lajur sahaja
        nilai_matriks = PORTB & 0x0F;
        
        // Jika ada mana-mana butang ditekan di Baris 1, nilai_matriks TIDAK akan sama dengan 1111 (0x0F)
        if (nilai_matriks != 0x0F) {
            
            __delay_ms(20); // Penapis Antul (Debounce Delay)
            
            // Periksa butang mana yang ditekan, kemudian nyalakan LED yang berpadanan!
            if (nilai_matriks == 0x0E) { PORTD = 0x01; } // Butang S1 (Lajur 1: RB0 = 0)
            if (nilai_matriks == 0x0D) { PORTD = 0x02; } // Butang S2 (Lajur 2: RB1 = 0)
            if (nilai_matriks == 0x0B) { PORTD = 0x04; } // Butang S3 (Lajur 3: RB2 = 0)
            if (nilai_matriks == 0x07) { PORTD = 0x08; } // Butang S4 (Lajur 4: RB3 = 0)
            
        } else {
            // Tiada butang ditekan
            PORTD = 0x00;
        }
    }
}
