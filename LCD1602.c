#include <htc.h>

// Tetapan Konfigurasi Asas
__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);
#define _XTAL_FREQ 4000000 // Kekerapan kristal 12MHz

// Definisi Pin Kawalan LCD1602 (berdasarkan litar HJ-5G)
#define RS RA5
#define RW RA4
#define EN RA3
#define LCD_DATA PORTD

// --- FUNGSI ASAS LCD ---

// 1. Lengah Masa Tambahan
void delay_ms(unsigned int ms) {
    while(ms--) __delay_ms(1);
    }

// 2. Fungsi Menghantar Arahan (Command) ke LCD
void lcd_cmd(unsigned char cmd) {
    RS = 0;             // 0 = Mod Arahan (Contoh: Clear screen, gerak kursor)
    RW = 0;             // 0 = Mod Tulis (Write)
    LCD_DATA = cmd;     // Letak kod arahan pada bas data PORTD
    EN = 1;             // Berikan denyutan HIGH
    __delay_ms(2);      // Tunggu masa untuk LCD memproses
    EN = 0;             // Jatuhkan ke LOW (Latch data)
}

// 3. Fungsi Menghantar Data (Huruf ASCII) ke LCD
void lcd_data(unsigned char data) {
    RS = 1;             // 1 = Mod Data (Karakter/Huruf)
    RW = 0;             // 0 = Mod Tulis (Write)
    LCD_DATA = data;    // Letak kod ASCII pada bas data PORTD
    EN = 1;             // Berikan denyutan HIGH
    __delay_ms(2);      // Tunggu masa untuk LCD memproses
    EN = 0;             // Jatuhkan ke LOW (Latch data)
}

// 4. Fungsi Inisialisasi (Permulaan) LCD1602
void lcd_init() {
    ADCON1 = 0x06;      // WAJIB: Tukar PORTA dari Analog ke Digital I/O
    TRISA = 0x00;       // Jadikan PORTA sebagai Output (RS, RW, EN)
    TRISD = 0x00;       // Jadikan PORTD sebagai Output (Data Bus D0-D7)
    
    delay_ms(20);       // Tunggu voltan LCD stabil selepas kuasa dihidupkan
    
    lcd_cmd(0x38);      // Mod 8-bit, 2 baris paparan, matriks huruf 5x7 dot
    lcd_cmd(0x0C);      // Hidupkan paparan (Display ON), padamkan kursor (Cursor OFF)
    lcd_cmd(0x06);      // Kursor bergerak ke kanan secara automatik selepas setiap huruf
    lcd_cmd(0x01);      // Bersihkan skrin (Clear Display)
    delay_ms(5);        // Arahan Clear perlukan masa pemprosesan lebih panjang
}

// 5. Fungsi Menulis Ayat (String) ke LCD
void lcd_print(const char *str) {
    while(*str) {
        lcd_data(*str++); // Hantar huruf satu demi satu sehingga habis ayat
    }
}

// --- GELUNG UTAMA ---
void main() {
    lcd_init();         // Mula dan siapkan skrin LCD
    
    while(1) {
        // Paparan Pertama
        lcd_cmd(0x80);              // Pergi ke Baris 1, Lajur 1 (Alamat 0x80)
        lcd_print(" SELAMAT DATANG ");
        
        lcd_cmd(0xC0);              // Pergi ke Baris 2, Lajur 1 (Alamat 0xC0)
        lcd_print("  TVET MALAYSIA ");
        
        delay_ms(2000);             // Papar selama 2 saat
        
        lcd_cmd(0x01);              // Bersihkan skrin
        delay_ms(5);
        
        // Paparan Kedua
        lcd_cmd(0x80);              // Baris 1
        lcd_print("  UTM  FEST     ");
        
        lcd_cmd(0xC0);              // Baris 2
        lcd_print(" BOARD HJ-5G v2 ");
        
        delay_ms(2000);             // Papar selama 2 saat
        lcd_cmd(0x01);              // Bersihkan skrin untuk ulang kitaran
        delay_ms(5);
    }
}
