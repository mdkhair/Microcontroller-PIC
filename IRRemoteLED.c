/***************************************************************************************************
 * Projek   : Remote Control IR (NEC) -> hidupkan LED mengikut nombor
 * Board    : HJ-5G (慧净)      MCU: PIC16F877A      Crystal: 4 MHz (mode HS)
 * Compiler : HI-TECH PICC (MPLAB IDE)
 * ---------------------------------------------------------------------------------------------
 * Fungsi   : Tekan butang nombor pada remote -> LED menyala secara "bar":
 *              1 -> 1 LED     (RD0)
 *              2 -> 2 LED     (RD0..RD1)
 *              3 -> 3 LED     (RD0..RD2)
 *              ...
 *              8 -> 8 LED     (RD0..RD7 semua)
 *              0 -> semua LED PADAM
 *            (butang 9 diabaikan dalam projek ini)
 *
 * Sambungan hardware:
 *   IR1838 OUT -> RE2  (pasang jumper "红外接收跳线")
 *   LED L0..L7 -> PORTD (RD0..RD7), AKTIF-TINGGI (tulis 1 = nyala). PASANG JUMPER JP1.
 *
 * PENTING (dari pinmap HJ-5G): untuk blok LED berfungsi (bukan buzzer berbunyi),
 *   RE0 mesti di-set sebagai INPUT -> TRISE bit0 = 1. Kita juga perlukan RE2 input
 *   untuk IR -> TRISE bit2 = 1. Maka TRISE = 0x05.
 *
 * Keycode remote MP3 kereta:
 *   0=0x16 1=0x0C 2=0x18 3=0x5E 4=0x08 5=0x1C 6=0x5A 7=0x42 8=0x52 9=0x4A
 ***************************************************************************************************/

#include <pic.h>

__CONFIG(0xFF32);       // WDT off, PWRT on, BOR off, LVP off, code-protect on, HS 4MHz

#define uchar  unsigned char
#define uint   unsigned int

#define bitset(var,bitno) ((var) |=  (1 << (bitno)))
#define bitclr(var,bitno) ((var) &= ~(1 << (bitno)))

/* --- kaunter bit-field untuk algoritma decode --- */
union {
    struct {
        unsigned b0:1; unsigned b1:1; unsigned b2:1; unsigned b3:1;
        unsigned b4:1; unsigned b5:1; unsigned b6:1; unsigned b7:1;
    } oneBit;
    unsigned char allBits;
} myFlag;
#define CNT2_2  myFlag.oneBit.b2
#define CNT2_3  myFlag.oneBit.b3
#define CNT2    myFlag.allBits

static bit Bitin;

/* --- data mentah 32-bit --- */
union {
    unsigned long i;
    unsigned char Csra[4];
} myCsra;

#define RMT   RE2                    // pin input IR (aktif-RENDAH bila ada isyarat)

uchar CNT0, CNT3, CNT4;
uint  CNT1;
uchar CSR1;                          // command (kod butang)
uchar CSR0;                          // command inverse (semakan)

uchar key_code  = 0;
bit   key_ready;                     // di-set dalam initial()

/****************************************************************************
 * initial() : setup IO port
 ****************************************************************************/
void initial(void)
{
    ADCON1 = 0x07;      // PORTA & PORTE jadi digital IO biasa
    TRISD  = 0x00;      // PORTD output -> 8 LED
    TRISE  = 0x05;      // RE0 input (enable blok LED) + RE2 input (IR)

    PORTD  = 0x00;      // mula: semua LED padam

    key_ready = 0;
}

/****************************************************************************
 * RCV() : terima & decode isyarat NEC (timing sama seperti asal, terbukti berfungsi)
 ****************************************************************************/
void RCV(void)
{
    if (!RMT)
    {
        CNT1 = 640;
        CNT2 = 0;
        do {
            if (RMT)  CNT2++;
            if (!RMT) CNT2 = 0;
            if (CNT2_2) break;
        } while (CNT1--);

        if (CNT2_2 && (0 < CNT1) && (CNT1 < 320))
        {
            CNT1 = 480;
            CNT2 = 0;
            do {
                if (!RMT) CNT2++;
                if (RMT)  CNT2 = 0;
                if (CNT2_2) break;
            } while (CNT1--);

            if (CNT2_2 && (0 < CNT1) && (CNT1 < 320))
            {
                CNT3 = 32;
                do {
                    CNT2 = 0;
                    CNT0 = 86;
                    CNT4 = 200;
                    do {
                        if (RMT)  CNT2++;
                        if (!RMT) CNT2 = 0;
                        if (CNT2_3) break;
                    } while (CNT0--);
                    if ((CNT0 == 0) || (CNT2_3 == 0)) break;

                    CNT2 = 0;
                    do {
                        if (!RMT) CNT2++;
                        if (RMT)  CNT2 = 0;
                        if (CNT2_3) break;
                    } while (CNT4--);
                    if ((CNT4 == 0) || (CNT2_3 == 0)) break;

                    CNT0 = (86 - CNT0) + (200 - CNT4);
                    if (((70 < CNT0) && (CNT0 < 130)) || ((160 < CNT0) && (CNT0 < 230)))
                    {
                        if ((70 < CNT0) && (CNT0 < 130)) Bitin = 0;
                        else                             Bitin = 1;
                        myCsra.i >>= 1;
                        if (Bitin) bitset(myCsra.Csra[3], 7);
                        else       bitclr(myCsra.Csra[3], 7);
                    }
                    else break;
                } while (CNT3--);

                CSR1 = myCsra.Csra[2];          // command
                CSR0 = myCsra.Csra[3];          // command inverse
                if (((uchar)~CSR0 == CSR1) && (CSR1 != 0)) {
                    key_code  = CSR1;
                    key_ready = 1;
                }
            }
        }
    }
}

/****************************************************************************
 * keycode_to_num() : kod butang -> nombor 0..9 (0xFF = bukan butang nombor)
 ****************************************************************************/
uchar keycode_to_num(uchar code)
{
    switch (code) {
        case 0x16: return 0;
        case 0x0C: return 1;
        case 0x18: return 2;
        case 0x5E: return 3;
        case 0x08: return 4;
        case 0x1C: return 5;
        case 0x5A: return 6;
        case 0x42: return 7;
        case 0x52: return 8;
        case 0x4A: return 9;
        default:   return 0xFF;
    }
}

/****************************************************************************
 * main()
 ****************************************************************************/
void main(void)
{
    uchar num;

    initial();
    while (1) {
        RCV();                                  // sentiasa mengintai pin IR
        if (key_ready) {
            key_ready = 0;
            num = keycode_to_num(key_code);

            if (num == 0) {
                PORTD = 0x00;                   // butang 0 -> semua LED padam
            }
            else if (num >= 1 && num <= 8) {
                // nyalakan 'num' biji LED dari RD0 ke atas.
                // contoh: num=3 -> (1<<3)-1 = 0b00000111 -> RD0,RD1,RD2 nyala
                PORTD = (uchar)((1 << num) - 1);
            }
            // num == 9 atau bukan butang nombor -> tiada perubahan
        }
    }
}
