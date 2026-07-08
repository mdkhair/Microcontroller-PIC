#include <pic.h>

// Config: WDT off, PWRT on, BOR off, LVP off, code-protect on, oscillator HS (4 MHz)
__CONFIG(0xFF32);

/* ============================================================================================
 * PILIHAN MOD PAPARAN
 *   0 = MOD SATU DIGIT  : tekan '5' -> digit paling kanan tunjuk 5 (default, ikut permintaan)
 *   1 = MOD MENAIP      : tekan 1,2,3 -> paparan jadi "123" (digit masuk dari kanan, max 6)
 * Tukar nilai di bawah untuk pilih mod.
 * ============================================================================================ */
#define MULTI_DIGIT   0

#define uchar  unsigned char
#define uint   unsigned int

#define bitset(var,bitno) ((var) |=  (1 << (bitno)))
#define bitclr(var,bitno) ((var) &= ~(1 << (bitno)))

/* --------------------------------------------------------------------------------------------
 * Union bit-field: guna untuk baca satu-satu bit dalam kaunter dengan cepat (cara PICC).
 * -------------------------------------------------------------------------------------------- */
union {
    struct {
        unsigned b0:1; unsigned b1:1; unsigned b2:1; unsigned b3:1;
        unsigned b4:1; unsigned b5:1; unsigned b6:1; unsigned b7:1;
    } oneBit;
    unsigned char allBits;
} myFlag;

#define CNT2_2  myFlag.oneBit.b2      // bit-2 kaunter (dipakai algoritma decode asal)
#define CNT2_3  myFlag.oneBit.b3      // bit-3 kaunter
#define CNT2    myFlag.allBits        // nilai penuh kaunter

static bit Bitin;                     // simpan sementara satu bit yang di-decode

/* --------------------------------------------------------------------------------------------
 * Union 32-bit: tampung data mentah 32-bit yang diterima daripada remote.
 * Csra[0]=addr low, Csra[1]=addr high, Csra[2]=command, Csra[3]=command inverse
 * -------------------------------------------------------------------------------------------- */
union {
    unsigned long i;
    unsigned char Csra[4];
} myCsra;

#define RMT   RE2                     // pin input isyarat IR (aktif-RENDAH bila ada isyarat)

uchar CNT0, CNT3, CNT4;              // kaunter kerja untuk ukur lebar pulsa
uint  CNT1;                          // kaunter 16-bit untuk tempoh leader

uchar CSR1;                          // command (kod butang) yang diterima
uchar CSR0;                          // command inverse (untuk semakan ralat)

uchar key_code   = 0;               // command sah terakhir
bit   key_ready;                    // flag: ada butang baharu diterima (di-set dlm initial)

/* --------------------------------------------------------------------------------------------
 * Jadual segmen 7-segment (common cathode). Index 0..9 = nombor, index 10 = KOSONG (blank).
 * Susunan bit: dp g f e d c b a
 * -------------------------------------------------------------------------------------------- */
const uchar table[] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x6f, // 9
    0x00  // 10 = kosong / blank
};
#define BLANK 10

// Buffer paparan 6 digit (nilai 0..9, atau BLANK). digit[5] = paling kanan.
uchar dispbuf[6] = { BLANK, BLANK, BLANK, BLANK, BLANK, BLANK };

/****************************************************************************
 * initial() : setup IO port
 ****************************************************************************/
void initial(void)
{
    ADCON1 = 0x07;      // PORTA & PORTE jadi digital IO biasa (bukan analog)
    TRISA  = 0x00;      // PORTA output -> pilih digit
    TRISD  = 0x00;      // PORTD output -> segmen a..dp
    TRISE2 = 1;         // RE2 input -> terima isyarat IR

    PORTA = 0x00;
    PORTD = 0x00;

    key_ready = 0;      // belum ada butang diterima
}

/****************************************************************************
 * RCV() : terima & decode isyarat remote (protokol NEC)
 *   - leader 9ms rendah + 4.5ms tinggi
 *   - 32 bit data (addr, addr, command, ~command)
 *   - bit '0': pulsa pendek,  bit '1': pulsa panjang
 * Timing constant di sini SAMA seperti source code asal yang terbukti berfungsi.
 ****************************************************************************/
void RCV(void)
{
    if (!RMT)                                   // mula bila dikesan tepi turun (leader)
    {
        CNT1 = 640;                             // tingkap masa untuk leader rendah
        CNT2 = 0;
        do {                                    // tunggu leader rendah ~9ms habis
            if (RMT)  CNT2++;
            if (!RMT) CNT2 = 0;
            if (CNT2_2) break;                  // dah jadi tinggi (leader rendah tamat)
        } while (CNT1--);

        if (CNT2_2 && (0 < CNT1) && (CNT1 < 320))   // sah: leader rendah cukup panjang
        {
            CNT1 = 480;                         // tingkap masa untuk leader tinggi 4.5ms
            CNT2 = 0;
            do {
                if (!RMT) CNT2++;
                if (RMT)  CNT2 = 0;
                if (CNT2_2) break;              // dah jadi rendah (leader tinggi tamat)
            } while (CNT1--);

            if (CNT2_2 && (0 < CNT1) && (CNT1 < 320))   // sah: leader tinggi cukup panjang
            {
                CNT3 = 32;                      // 32 bit data perlu diterima
                do {
                    CNT2 = 0;
                    CNT0 = 86;                  // rujukan tempoh RENDAH
                    CNT4 = 200;                 // rujukan tempoh TINGGI
                    do {                        // ukur tempoh tinggi bit ini
                        if (RMT)  CNT2++;
                        if (!RMT) CNT2 = 0;
                        if (CNT2_3) break;
                    } while (CNT0--);
                    if ((CNT0 == 0) || (CNT2_3 == 0)) break;

                    CNT2 = 0;
                    do {                        // ukur tempoh rendah bit ini
                        if (!RMT) CNT2++;
                        if (RMT)  CNT2 = 0;
                        if (CNT2_3) break;
                    } while (CNT4--);
                    if ((CNT4 == 0) || (CNT2_3 == 0)) break;

                    // jumlah tempoh -> tentukan bit 0 atau 1
                    CNT0 = (86 - CNT0) + (200 - CNT4);
                    if (((70 < CNT0) && (CNT0 < 130)) || ((160 < CNT0) && (CNT0 < 230)))
                    {
                        if ((70 < CNT0) && (CNT0 < 130))
                            Bitin = 0;          // pulsa pendek -> '0'
                        else
                            Bitin = 1;          // pulsa panjang -> '1'

                        myCsra.i >>= 1;         // geser masuk bit baharu dari MSB
                        if (Bitin) bitset(myCsra.Csra[3], 7);
                        else       bitclr(myCsra.Csra[3], 7);
                    }
                    else break;
                } while (CNT3--);

                CSR1 = myCsra.Csra[2];          // command (kod butang)
                CSR0 = myCsra.Csra[3];          // command inverse

                // Semakan ralat: command mesti = balikan command-inverse
                if (((uchar)~CSR0 == CSR1) && (CSR1 != 0)) {
                    key_code  = CSR1;
                    key_ready = 1;
                }
            }
        }
    }
}

/****************************************************************************
 * keycode_to_num() : tukar kod butang -> nombor 0..9
 *   Pulang 0xFF kalau butang itu bukan butang nombor.
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
        default:   return 0xFF;      // bukan butang nombor
    }
}

/****************************************************************************
 * update_display() : kemas kini buffer paparan bila ada butang baharu
 ****************************************************************************/
void update_display(void)
{
    uchar num = keycode_to_num(key_code);

#if MULTI_DIGIT
    // ---- MOD MENAIP: geser digit ke kiri, masukkan yang baharu di kanan ----
    if (num != 0xFF) {                          // butang nombor -> taip
        uchar k;
        for (k = 0; k < 5; k++) dispbuf[k] = dispbuf[k + 1];
        dispbuf[5] = num;
    } else if (key_code == 0xD9) {              // EQ -> clear semua
        uchar k;
        for (k = 0; k < 6; k++) dispbuf[k] = BLANK;
    }
#else
    // ---- MOD SATU DIGIT: tunjuk nombor ditekan pada digit paling kanan ----
    if (num != 0xFF) {
        uchar k;
        for (k = 0; k < 5; k++) dispbuf[k] = BLANK;
        dispbuf[5] = num;
    }
#endif
}

/****************************************************************************
 * display() : imbas dinamik 6 digit 7-segment (satu pusingan)
 *   Perlu dipanggil berulang-ulang supaya paparan nampak stabil.
 ****************************************************************************/
void display(void)
{
    uchar i, j;
    uchar sel = 0x01;                           // mula dari digit 1 (RA0)
    for (i = 0; i < 6; i++) {
        PORTA = 0x00;                           // padam dulu (elak bayang/ghosting)
        PORTD = table[dispbuf[i]];              // letak corak segmen
        PORTA = sel;                            // hidupkan digit i
        for (j = 0; j < 60; j++);               // lengah ~ untuk keterangan
        sel <<= 1;                              // ke digit seterusnya
    }
    PORTA = 0x00;
}

/****************************************************************************
 * main()
 ****************************************************************************/
void main(void)
{
    initial();
    while (1) {
        RCV();                                  // cuba terima isyarat remote
        if (key_ready) {                        // ada butang baharu?
            key_ready = 0;
            update_display();                   // kemas kini apa yang nak dipapar
        }
        display();                              // refresh paparan 7-segment
    }
}
