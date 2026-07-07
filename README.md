<img width="1024" height="767" alt="image" src="https://github.com/user-attachments/assets/d830033d-039e-4620-88f8-d12bab37b5cf" />



Apa itu __CONFIG()?
__CONFIG() merujuk kepada Configuration Bits (atau sering dipanggil Fuses). Ini adalah tetapan asas perkakasan yang perlu dikonfigurasi sebelum cip mula menjalankan sebarang program.

Ia mengawal fungsi penting seperti: Jenis pengayun (oscillator/crystal) yang digunakan, mengaktifkan/mematikan Watchdog Timer, dan perlindungan kod (Code Protection).

Ia boleh juga ditulis sebagai __CONFIG(0xFF32);. Ini dipanggil kaedah Hexadecimal Masking. Pengaturcara lama terpaksa mengira bit secara manual untuk mendapatkan nilai 0xFF32. Cara ini sangat tidak mesra pengguna kerana anda tidak tahu apa sebenarnya yang diaktifkan atau dimatikan melainkan anda merujuk kepada buku manual (datasheet) cip tersebut.

Jenis CONFIG:
FOSC_HS (High-Speed Oscillator): Ini wajib ada. Papan HJ-5G menggunakan pengayun kristal (crystal oscillator) luaran berkelajuan tinggi. Jika tidak ditulis, mikropengawal tidak akan mendapat isyarat denyut nadi (clock) yang betul dan program langsung tidak akan berjalan.

WDTE_OFF (Watchdog Timer Disable): Ini juga wajib dimatikan. Jika dibiarkan (tetapan kilang adalah ON), program anda akan sentiasa restart (terset semula) dengan sendirinya setiap beberapa milisaat.

LVP_OFF (Low Voltage Programming Disable): Ini sangat penting untuk cip PIC16F877A. Jika tidak dimatikan, pin RB3 akan dikunci khas untuk fungsi pengaturcaraan. Anda tidak akan boleh menggunakan pin RB3 untuk input/output biasa (merujuk kepada rajah litar papan HJ-5G, butang kekunci K4 bersambung terus ke RB3).

Parameter yang digugurkan seperti PWRTE_ON, BOREN_OFF, CP_OFF (Code Protection), dan WRT_OFF lebih menjurus kepada perlindungan memori cip dan penstabilan bekalan kuasa industri.

Jika anda membuangnya dari baris kod, pengkompil (compiler HI-TECH C) akan secara automatik membiarkan fungsi tersebut pada nilai lalai kilang (factory default). Untuk silibus pembelajaran seperti kerlipan LED, membaca suis, atau paparan LCD, ketiadaan parameter tambahan ini tidak akan memberi kesan negatif kepada kelancaran logik program anda.

Maka, cukup untuk anda menulis __CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);


**4. Memahami Kod Arahan Hex LCD (Command Glossary)**

_Matikan Fungsi Analog (ADCON1 = 0x06;): Seperti yang kita pelajari sebelum ini, pin kawalan LCD iaitu RA5, RA4, dan RA3 terletak pada PORTA. Anda wajib menukarnya ke mod Digital, jika tidak skrin LCD langsung tidak akan bertindak balas!_

_Cabut Pelompat JP1: Memandangkan bas data PORTD dikongsi bersama modul 8 LED (Running Lights), disyorkan untuk mencabut pelompat JP1 supaya LED tidak menarik arus atau mengganggu isyarat data LCD_

Dalam kod di atas, kita banyak menggunakan nilai Heksadesimal seperti 0x38, 0x0C, 0x80, dan 0xC0. Berikut adalah senarai rujukan pantas arahan LCD yang paling berguna untuk pengajaran dalam makmal:

<img width="476" height="383" alt="image" src="https://github.com/user-attachments/assets/d984709e-6817-45dd-9b76-8a51c4520364" />




