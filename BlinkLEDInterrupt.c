#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);
#define _XTAL_FREQ 4000000 

int kiraan_masa = 0; // Pembolehubah untuk mengumpul masa tumpahan (overflow)

// =========================================================
// FUNGSI SAMPUKAN (INTERRUPT SERVICE ROUTINE - ISR)
// Fungsi ini akan berjalan secara automatik setiap kali 
// Timer0 melimpah (overflow), tanpa dipanggil di dalam main!
// =========================================================
void interrupt fungsi_sampukan(void) {
    
    // Semak adakah sampukan ini berpunca daripada Timer0 (T0IF)
    if (T0IF == 1) { 
        
        T0IF = 0; // Wajib: Bersihkan "bendera kecemasan" supaya ia boleh mengira lagi
        
        kiraan_masa++;
        
        // Timer0 melimpah setiap ~21.8 milisaat (dengan prescaler 1:256)
        // 21.8ms x 45 kali = ~1000 milisaat (1 Saat)
        if (kiraan_masa >= 45) { 
            kiraan_masa = 0; // Reset kiraan
            
            RD7 = ~RD7; // Togol (Terbalikkan) keadaan LED L7. Jika 0 jadi 1, jika 1 jadi 0.
        }
    }
}

// =========================================================
// GELUNG UTAMA
// =========================================================
void main() {
    // 1. Tetapan LED
    TRISD = 0x00;  
    PORTD = 0x00;
    
    // 2. Tetapan Pemasa (Timer0)
    // OPTION_REG mengawal "Prescaler". Nilai 0x07 (0b00000111) bermaksud 1:256.
    // Cip akan menabur 1 nombor ke dalam TMR0 untuk setiap 256 kitaran jam.
    OPTION_REG = 0x07; 
    TMR0 = 0;          // Mula mengira dari 0
    
    // 3. Tetapan Sampukan (Interrupts)
    T0IE = 1; // Benarkan sampukan spesifik untuk Timer0 (Timer 0 Interrupt Enable)
    GIE = 1;  // Benarkan sampukan global cip (Global Interrupt Enable)
    
    // 4. Gelung Infiniti
    while(1) {
        
        // Kosong! Tiada delay_ms di sini.
        // Cip kini bebas sepenuhnya untuk membaca Matriks, IR atau melakukan tugas lain.
        // LED RD7 akan terus berkelip sendiri seolah-olah mempunyai nyawanya sendiri!
        
    }
}
