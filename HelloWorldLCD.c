#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);
#define _XTAL_FREQ 4000000 

// Takrifkan nama khas untuk pin kawalan supaya mudah dirujuk
#define LCD_RS RA5
#define LCD_RW RA4
#define LCD_EN RA3

// =========================================================
// PUSTAKA LCD KASTAM (CUSTOM LCD LIBRARY)
// =========================================================

// 1. Fungsi Menghantar Denyutan 'Enable'
void lcd_enable() {
    LCD_EN = 1;         // Naikkan Enable
    __delay_ms(2);      // Tunggu LCD baca data (2ms sangat selamat)
    LCD_EN = 0;         // Jatuhkan Enable
}

// 2. Fungsi Menghantar Arahan (Command)
void lcd_cmd(unsigned char cmd) {
    PORTD = cmd;        // Letak kod arahan di PORTD
    LCD_RS = 0;         // RS = 0 (Mod Arahan)
    LCD_RW = 0;         // RW = 0 (Tulis)
    lcd_enable();       // Beri denyutan "Enter"
}

// 3. Fungsi Menghantar 1 Aksara Teks (Data)
void lcd_data(unsigned char data) {
    PORTD = data;       // Letak kod teks ASCII di PORTD
    LCD_RS = 1;         // RS = 1 (Mod Teks)
    LCD_RW = 0;         // RW = 0 (Tulis)
    lcd_enable();
}

// 4. Fungsi Menghantar Ayat Penuh (String)
void lcd_string(const char *str) {
    while(*str != '\0') {   // Selagi belum jumpa hujung ayat
        lcd_data(*str);     // Hantar huruf tersebut ke LCD
        str++;              // Beralih ke huruf seterusnya
    }
}

// 5. Fungsi Tetapan Permulaan LCD
void lcd_init() {
    lcd_cmd(0x38); // Arahan wajib: Tetapkan fungsi 8-bit dan 2 baris paparan
    lcd_cmd(0x0C); // Hidupkan paparan skrin, matikan garisan kursor (Cursor Off)
    lcd_cmd(0x01); // Bersihkan skrin (Clear Display)
    lcd_cmd(0x80); // Letakkan kursor di Baris 1, Petak 1
}

// =========================================================
// GELUNG UTAMA
// =========================================================
void main() {
    // 1. Tetapan Port
    ADCON1 = 0x06; // PENTING: PORTA sebagai Digital I/O
    
    TRISA = 0x00;  // PORTA (Pin Kawalan LCD) sebagai Output
    TRISD = 0x00;  // PORTD (Pin Data LCD) sebagai Output
    
    PORTA = 0x00;
    
    // 2. Hidupkan LCD
    lcd_init();
    
    // 3. Hantar Mesej!
    lcd_string("Hello World!");
    
    // 4. Gelung Infiniti
    while(1) {
        // Skrin LCD mempunyai memorinya sendiri. 
        // Selagi kita tidak menghantar arahan padam, teks akan kekal terpapar.
        // Oleh itu, kita tidak perlu meletakkan fungsi paparan di dalam while(1).
    }
}
