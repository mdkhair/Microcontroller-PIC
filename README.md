Selamat datang ke modul pembelajaran BitWise PIC Microcontroller Kit. Sebelum kita mula menulis kod pengaturcaraan dan mengawal komponen elektronik, adalah sangat penting untuk kita memahami apakah sebenarnya "otak" di sebalik kit ini.

**1. Apakah itu Mikropengawal (Microcontroller)?**

Secara ringkasnya, Mikropengawal (Microcontroller / MCU) adalah sebuah "komputer mini" yang dibina sepenuhnya di atas satu cip litar bersepadu (IC - Integrated Circuit).

Jika komputer peribadi (PC) atau komputer riba anda memerlukan papan induk (motherboard) yang besar untuk menyambungkan pemproses (CPU), memori (RAM), dan cakera keras (Hard Disk) secara berasingan, mikropengawal merangkumkan kesemua komponen ini ke dalam satu cip silikon yang kecil.

Sebuah mikropengawal yang lengkap biasanya mempunyai:

CPU (Unit Pemprosesan Pusat): Bertindak sebagai "otak" yang berfikir, mengira, dan melaksanakan arahan baris demi baris.

Memori ROM / Flash: Tempat kod program (seperti kod C yang kita tulis) disimpan secara kekal. Data di sini tidak akan hilang walaupun bekalan kuasa dimatikan.

Memori RAM: Tempat penyimpanan data sementara (seperti nilai pembolehubah, kiraan masa) semasa cip sedang beroperasi.

Peranti I/O (Input/Output): "Kaki-kaki" cip yang membolehkan ia berkomunikasi dengan dunia luar.

Input: Boleh disambung kepada butang tekan, alat kawalan jauh (Inframerah), atau penderia (suhu, cahaya, pergerakan).

Output: Boleh mengawal lampu LED, skrin LCD, Buzzer (penggera bunyi), atau motor elektrik.

**2. Kegunaan dan Contoh-contoh Aplikasi**

Mikropengawal tidak direka untuk melayari internet atau bermain permainan video grafik tinggi seperti PC. Ia direka khas untuk Sistem Terbenam (Embedded Systems), iaitu melakukan satu tugas yang khusus, berulang kali, dengan sangat cekap dan pantas.

Mungkin anda tidak perasan, tetapi kehidupan harian kita sebenarnya dikelilingi oleh berpuluh-puluh mikropengawal! Berikut adalah contoh penggunaannya:

Peralatan Rumah (Home Appliances): * Mesin Basuh Automatik: Mikropengawal membaca butang tetapan anda, mengawal injap air masuk, memutar motor pada kelajuan tertentu, dan membunyikan penggera apabila kain siap dibasuh.

Ketuhar Gelombang Mikro (Microwave): Mengawal paparan masa digital, memantau suhu, dan mematikan ketuhar secara automatik.

Penghawa Dingin: Membaca suhu bilik menggunakan penderia dan melaras kelajuan pemampat (compressor).

Sistem Automotif (Kenderaan):

Sistem Brek ABS: Mikropengawal memantau kelajuan tayar beratus kali sesaat dan melepaskan brek secara automatik jika tayar terkunci ketika jalan licin.

Sistem Pancitan Bahan Api (Fuel Injection): Mengira jumlah udara dan menyembur jumlah petrol yang paling optimum ke dalam enjin.

Elektronik Pengguna:

Alat Kawalan Jauh (Remote Control): Mikropengawal kecil membaca butang yang anda tekan dan menukarkannya kepada kod cahaya inframerah.

Mainan Kanak-kanak: Kereta kawalan jauh atau patung yang boleh bercakap dan berkelip mata.

Industri dan IoT:

Lengan robotik di kilang, sistem mesin layan diri (vending machine), sistem cap jari, dan alat penggera keselamatan pintar.

**3. Apakah itu PIC?**

Kini kita sudah tahu apa itu mikropengawal, mari kita berkenalan dengan "PIC".

PIC adalah singkatan kepada Peripheral Interface Controller (atau kadangkala dirujuk sebagai Programmable Intelligent Computer). Ia adalah satu keluarga (jenama) mikropengawal yang sangat popular, direka dan dikeluarkan oleh syarikat Microchip Technology.

Di dalam BitWise PIC Microcontroller Kit, kita menggunakan salah satu cip PIC yang paling ikonik dan meluas digunakan di dunia iaitu siri PIC16F877A.

Kenapa cip PIC ini sangat popular dalam industri dan pendidikan?

Seni Bina RISC (Reduced Instruction Set Computer): Ia mempunyai senarai arahan dalaman yang sangat ringkas (hanya 35 arahan asas). Ini membuatkan ia beroperasi dengan sangat pantas dan cekap.

Kukuh dan Tahan Lasak: Cip PIC sangat terkenal dengan kebolehannya bertahan dalam persekitaran industri yang bising (electrical noise) dan suhu yang ekstrem.

Modul Terbina Dalam (Built-in Modules): PIC16F877A mempunyai pelbagai ciri mewah terbina di dalamnya, seperti:

ADC (Analog-to-Digital Converter): Membolehkan cip "membaca" voltan dari sensor analog (suhu, kelembapan).

PWM (Pulse Width Modulation): Membolehkan cip mengawal kelajuan motor dengan tepat.

UART/I2C/SPI: Modul komunikasi untuk bersembang dengan cip atau peranti lain (seperti modul Bluetooth atau komputer).

Mudah Diprogramkan: Ia sangat mesra pengguna dan mudah diprogramkan menggunakan bahasa C (seperti HI-TECH C) atau bahasa Himpunan (Assembly). Memori Flash di dalamnya membolehkan kita memadam dan memasukkan kod baharu beribu-ribu kali tanpa merosakkan cip.

Dengan menguasai PIC16F877A pada BitWise PIC Microcontroller Kit, anda sebenarnya sedang membina asas yang sangat kukuh. Pemahaman ini akan memudahkan anda menguasai mana-mana sistem mikropengawal lain di pasaran pada masa akan datang!

**4. Perbezaan BitWise PIC Kit dengan Arduino dan Papan Pembangunan Lain**

Mungkin anda tertanya-tanya, "Kenapa saya perlu belajar cip PIC sedangkan Arduino jauh lebih popular dan mudah?" Ini adalah satu persoalan yang sangat relevan. Berikut adalah perbezaan teras di antara keduanya:

Tahap Abstraksi dan Pengaturcaraan:

Arduino (Papan Hobi & Prototaip): Direka khas untuk pemula dan pereka. Ia sangat mudah kerana ia menyembunyikan kerumitan litar elektronik menggunakan "Perpustakaan" (Libraries). Sebagai contoh, jika anda mahu menyalakan lampu LED di Arduino, anda hanya menaip digitalWrite(pin, HIGH);. Anda tidak perlu tahu bagaimana litar dalamannya berfungsi.

BitWise PIC Kit (Tahap Perkakasan Bare-Metal): Memaksa anda untuk berinteraksi terus dengan memori dan litar dalaman mikropengawal (dipanggil Daftar atau Registers). Untuk menyalakan LED pada PIC, anda mesti memahami konsep aliran data dan menaip TRISD = 0x00; diikuti PORTD = 0xFF;. Ia lebih mencabar pada mulanya, tetapi ia mengajar anda bagaimana sebuah cip elektronik benar-benar berfikir dan berfungsi dari akar umbi.

Ekosistem & Sokongan:

Arduino mempunyai komuniti open-source terbesar di dunia. Hampir semua sensor mempunyai kod sedia ada yang boleh dimuat turun.

PIC mempunyai sokongan rasmi yang kuat daripada syarikat korporat (Microchip), menjadikannya lebih profesional dengan dokumentasi manual teknikal (datasheet) yang sangat terperinci dan diiktiraf industri.

Papan Pembangunan Lain (seperti Raspberry Pi):

Raspberry Pi BUKAN mikropengawal. Ia adalah sebuah komputer mikro (Mikropemproses) berskala penuh yang menjalankan sistem operasi seperti Windows atau Linux. Ia sesuai untuk kecerdasan buatan (AI) atau pemprosesan imej, tetapi ia terlalu "mahal dan perlahan" untuk mengawal suis motor dalam masa nyata (real-time) jika dibandingkan dengan PIC.

**5. Bila Ia Sesuai Digunakan?**

Setiap platform mempunyai peranan dan bidang kekuatannya yang tersendiri:

Pilih Arduino atau Papan IoT (seperti ESP32) jika:

Anda mahu membina prototaip idea (Proof of Concept) dengan pantas.

Anda membuat projek hobi hujung minggu (seperti sistem pam penyiram pokok pintar) di rumah.

Anda memerlukan akses ke Internet atau WiFi dengan cepat tanpa perlu memahami selok-belok isyarat radio.

Pilih BitWise PIC Microcontroller Kit jika:

Pendidikan Kejuruteraan & TVET: Anda berada di institusi latihan kemahiran atau universiti. Mempelajari PIC akan menjadikan anda seorang "Jurutera Elektronik" sebenar yang boleh mencipta sistem sendiri, bukannya sekadar "Pengguna Kod" (Code Assembler).

Persekitaran Industri Lasak: Anda perlu mereka bentuk litar untuk dipasang di kilang perkilangan yang panas atau di dalam enjin kenderaan. Mikropengawal PIC terbukti mempunyai tahap ketahanan (robustness) dan imuniti terhadap gangguan elektrik (noise immunity) yang sangat cemerlang.

Kerjaya Penyelenggaraan (Maintenance): Ribuan sistem legasi (legacy systems) industri berkuasa tinggi, panel kawalan lif, dan perkakasan perubatan di luar sana dibina menggunakan mikropengawal PIC. Menguasainya memberi anda kelebihan yang besar di pasaran pekerjaan teknikal.

**6. Kenali Papan BitWise PIC Microcontroller Kit**

Papan pembangunan BitWise PIC Microcontroller Kit (berasaskan reka bentuk HJ-5G) adalah sebuah makmal elektronik serba lengkap (All-in-One Trainer Board). Ia direka supaya pelajar boleh terus menulis kod dan melihat hasilnya tanpa perlu membuat pendawaian breadboard yang berselirat dan sering terdedah kepada masalah litar pintas.

Papan ini didatangkan dengan pelbagai modul perkakasan sedia ada (on-board modules), antaranya:

Modul Output Visual: * 8 unit Lampu LED Berderet (Untuk latihan logik asas).

6-Digit Paparan 7-Segmen (Untuk memaparkan nombor dan sensor).

Soket Skrin LCD 1602 (Untuk memaparkan teks dan mesej).

Modul Input Berangka: * 4 unit Butang Tekan Bebas (Independent Keys).

16 unit Butang Papan Kekunci Matriks 4x4 (Matrix Keypad).

Modul Bunyi & Isyarat: * Pembaz Aktif (Buzzer).

Penerima Alat Kawalan Jauh Inframerah (IR Receiver - IR1838).

Modul Lanjutan: Cip memori EEPROM (AT24C02), Jam Masa Nyata / RTC (DS1302), dan input penderia analog (Potentiometer).
<img width="1024" height="767" alt="image" src="https://github.com/user-attachments/assets/d830033d-039e-4620-88f8-d12bab37b5cf" />

**7. Jadual Pemetaan Pin (Pin Mapping)**

Ini adalah rujukan paling krikital sepanjang anda menggunakan kit ini. Oleh kerana papan ini merangkumkan banyak modul, beberapa pin dikongsi bersama. Jadual ini menunjukkan pin mikropengawal PIC16F877A mana yang bersambung kepada modul fizikal di atas papan.
<img width="640" height="473" alt="image" src="https://github.com/user-attachments/assets/36123df7-cc92-40d5-9743-a6a0ae1f5744" />

Tips: Pin pada mikropengawal adalah terhad. Oleh itu, pereka papan ini mengamalkan Perkongsian Bas (Bus Sharing). Sebagai contoh, PORTD digunakan oleh LED, 7-Segmen, dan LCD. Anda tidak boleh menggunakan ketiga-tiga modul ini secara serentak tanpa logik kawalan (multiplexing) yang betul.

**8. Perisian dan Alat Pembangunan (Software & Tools)**

Untuk menjadikan mikropengawal ini "hidup", kita memerlukan gabungan perisian komputer (Software) dan alat perkakasan (Hardware). Dalam modul ini, kita menggunakan perisian MPLAB IDE v8.92 dan alat pemprogram PICkit 2.

Apakah fungsi mereka dan bagaimana kod anda dibaca oleh mikropengawal?

a) Perisian: MPLAB IDE v8.92 dan Pengkompil (Compiler)

MPLAB IDE adalah sebuah meja kerja maya (Integrated Development Environment). Di sinilah anda akan menaip kod anda menggunakan bahasa manusia (Bahasa C).

Namun, cip mikropengawal PIC tidak faham bahasa Inggeris atau Bahasa C. Ia hanya faham bahasa mesin, iaitu nombor 0 dan 1 (Binary). Di sinilah Pengkompil (Compiler) memainkan peranan.

Apakah Pengkompil (Compiler)? Ia bertindak seperti seorang penterjemah. Dalam kes kita, kita menggunakan pengkompil HI-TECH C. Apabila anda menekan butang "Build" di MPLAB, Pengkompil akan menterjemah kod bahasa C anda ke dalam kod mesin (0 dan 1) dan menghasilkan satu fail baharu yang dipanggil fail .hex (Hexadecimal).

b) Perkakasan: PICkit 2 Programmer

Setelah kita mendapat fail .hex, bagaimana kita nak masukkannya ke dalam cip fizikal? Kita perlukan sebuah jambatan penghubung yang dipanggil Pemprogram (Programmer).

Apakah Programmer? PICkit 2 adalah sebuah alat elektronik kecil yang bersambung ke komputer anda melalui kabel USB. Tugasnya adalah mengambil fail .hex dari komputer, dan menyuntik / "membakar" (burn) kod tersebut terus ke dalam Memori Flash mikropengawal PIC secara elektronik menggunakan isyarat voltan tertentu.

c) Kitaran Penuh: Bagaimana Kod Dibaca oleh PIC?

Berikut adalah ringkasan proses dari papan kekunci anda sehingga ke nyalaan LED:

Menulis Kod (Code): Anda menaip logik anda dalam bahasa C di MPLAB IDE v8.92. (Contoh: RD0 = 1;)

Terjemahan (Compile): HI-TECH C Compiler menukarkan fail C tersebut menjadi fail .hex yang mengandungi siri nombor binari yang tidak difahami manusia.

Memuat Turun (Burn/Flash): Anda menekan butang muat turun. PICkit 2 Programmer akan menghantar fail .hex ini melalui kabel USB dan menyimpannya secara kekal di dalam memori ROM cip PIC16F877A.

Perlaksanaan (Execute): Sebaik sahaja cip PIC diberikan kuasa (bateri/USB), CPU di dalamnya akan mula membaca memori tersebut baris demi baris, beribu-ribu kali sesaat, dan menterjemahkannya kepada tindakan fizikal (seperti menyalakan LED atau membunyikan penggera).

**Tutorial 1: Asas Pengaturcaraan PIC (Bahasa C)**

Sebelum kita mengawal modul-modul canggih di atas BitWise PIC Microcontroller Kit, kita perlu memahami "tatabahasa" (sintaks) bagaimana untuk bercakap dengan mikropengawal ini.

Dalam kit ini, kita menggunakan Bahasa C dan pengkompil HI-TECH C.

1. Struktur Asas Kod PIC (Kerangka Wajib)

```c
// 1. Fail Pengepala (Header File)
#include <htc.h> 

// 2. Tetapan Fius (Configuration Bits)
__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

// 3. Kelajuan Jam / Kristal (Clock Speed)
#define _XTAL_FREQ 4000000 

// 4. Fungsi Utama (Main Function)
void main() {
    
    // (A) Ruang Tetapan Awal (Initialization)
    // Kod di sini hanya dibaca SEKALI sahaja apabila cip dihidupkan.
    
    // 5. Gelung Infiniti (Infinite Loop)
    while(1) {
        
        // (B) Ruang Kerja (Super Loop)
        // Kod di sini akan diulang beribu-ribu kali sesaat selagi cip mempunyai bekalan kuasa.
        
    }
}
```

Setiap kali anda memulakan projek baharu di MPLAB, anda mesti membina "kerangka" kod ini. Tanpa kerangka ini, cip anda tidak akan dapat berfungsi.

Penerangan Kerangka:

#include <htc.h> : Arahan kepada pengkompil untuk memuatkan "kamus" rahsia PIC. Tanpa ini, perisian tidak akan faham apa itu PORTD atau TRISA.

__CONFIG(...) : Ini adalah "fius perkakasan". FOSC_HS memberitahu cip untuk menggunakan kristal kelajuan tinggi luaran. WDTE_OFF mematikan pemasa anjing pengawal (Watchdog Timer) supaya cip tidak restart sendiri secara rawak.

_XTAL_FREQ : Memberitahu pengkompil bahawa kristal pada papan kita berkelajuan 12MHz. Ini sangat penting supaya fungsi lengah masa (__delay_ms) dapat dikira dengan tepat.

while(1) : Mikropengawal mesti mempunyai gelung yang tidak berkesudahan. Jika tiada gelung ini, mikropengawal akan membaca kod sehingga ke bawah, dan kemudian "tertidur" atau crash.

2. Kunci Utama PIC: Daftar TRIS dan PORT

Ini adalah konsep PALING PENTING dalam pengaturcaraan mikropengawal. Kaki (pin) mikropengawal boleh menjadi Input (telinga/mata untuk mendengar sensor) ATAU Output (tangan/suara untuk mengawal lampu/motor).

Anda sebagai pengaturcara yang mesti menentukan sifat setiap kaki tersebut!

a) Daftar TRIS (Data Direction Register)

Fungsi TRIS adalah untuk menentukan arah. Adakah pin itu Input atau Output?

Tips Menghafal: * Logik 1 = Input (Menyerupai huruf I)

Logik 0 = Output (Menyerupai huruf O)

Contoh Penulisan:

TRISD = 0xFF; (Semua 8 pin pada PORTD menjadi Input)

TRISD = 0x00; (Semua 8 pin pada PORTD menjadi Output)

TRISD0 = 0; (Hanya 1 pin iaitu RD0 menjadi Output)

b) Daftar PORT (Data Register)

Selepas anda menetapkan arah (TRIS), fungsi PORT digunakan untuk melakukan tindakan.

Jika pin adalah Output (TRIS = 0): PORT menentukan nilai voltan yang dikeluarkan.

PORTD = 0xFF; (Keluarkan 5V / HIGH pada semua pin PORTD)

PORTD = 0x00; (Keluarkan 0V / LOW pada semua pin PORTD)

RD0 = 1; (Keluarkan 5V pada pin RD0 sahaja)

Jika pin adalah Input (TRIS = 1): PORT digunakan untuk membaca voltan luar.

if (RB0 == 1) (Membaca adakah suis pada pin RB0 sedang ditekan atau tidak)

3. Sistem Nombor (Binary vs Hexadecimal)

Dalam pengaturcaraan PIC, setiap PORT mempunyai 8 pin (Bit 0 hingga Bit 7). Untuk mengawal 8 pin ini serentak, kita biasanya tidak menulis kod panjang berjela. Kita menggunakan sistem Hexadecimal (Perenambelasan).

<img width="866" height="164" alt="image" src="https://github.com/user-attachments/assets/fcb83190-4744-47e6-8c1d-2a9b77e5dcc0" />

4. Program Pertama Anda: "Hello World" Mikropengawal

Dalam dunia perisian komputer, program pertama anda biasanya adalah mencetak perkataan "Hello World" ke skrin. Dalam dunia mikropengawal elektronik, "Hello World" kita adalah menghidupkan dan mengerdipkan seketul lampu LED.

Mari kita kerdipkan Lampu LED pertama (L0) yang disambungkan pada pin RD0.

Kod Latihan 1: LED Berkelip (Blink)
```c
#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);
#define _XTAL_FREQ 4000000 // Kristal 12MHz

void main() {
    
    // --- TETAPAN AWAL ---
    TRISD = 0x00;   // Tetapkan semua pin PORTD sebagai OUTPUT (0)
    PORTD = 0x00;   // Matikan semua LED sebagai permulaan
    
    // --- GELUNG UTAMA ---
    while(1) {
        
        RD0 = 1;         // Berikan logik HIGH (5V) -> LED L0 Menyala
        __delay_ms(1000); // Tunggu selama 1000 milisaat (1 saat)
        
        RD0 = 0;         // Berikan logik LOW (0V) -> LED L0 Padam
        __delay_ms(1000); // Tunggu selama 1 saat
        
    }
}
```
Cabaran Makmal:

Cuba salin kod di atas ke dalam MPLAB, tekan butang Build, dan muat turun (Burn) ke dalam BitWise PIC Kit anda menggunakan PICkit 2.
(Peringatan: Pastikan jumper JP1 untuk LED telah dipasang di atas papan!)

Jika lampu LED L0 berkelip 1 saat menyala dan 1 saat padam, TAHNIAH! Anda kini telah sah menjadi seorang pengaturcara mikropengawal.

Eksperimen Sendiri:

Cuba tukarkan RD0 kepada RD7. Apa yang berlaku?

Cuba tukarkan masa __delay_ms(1000) kepada __delay_ms(100). Apa perbezaan pada mata anda?

# Modul 1: Kawalan LED Lanjutan (Running Lights)

Selepas berjaya mengerdipkan satu LED, mari kita gunakan kesemua 8 biji LED (L0 hingga L7) yang bersambung pada PORTD. Corak nyalaan yang paling popular untuk dipelajari ialah Running Lights (Lampu Berlari).

Dalam latihan ini, kita akan belajar satu operasi tatabahasa C yang sangat berguna dipanggil Anjakan Bit (Bitwise Shift).

Pengaturcaraan: Lampu Berlari (Bitwise Shift)

Simbol << digunakan untuk menolak (shift) nilai binari ke arah kiri.
Sebagai contoh, jika nilai awal lampu adalah 0b00000001 (hanya LED L0 menyala), operasi << 1 akan menolaknya menjadi 0b00000010 (LED L1 pula menyala).

Sila buat projek baharu di MPLAB dan masukkan kod berikut:
[Running Lights Programming](/RunningLight.c)

Untuk faham asas LED tunggal, boleh rujuk kepada kod ini:
[Single LED](/singleLED.c)

Cabaran Makmal Modul 1:

Eksperimen Arah: Bolehkah anda ubah suai kod di atas supaya lampu berlari dari arah kanan ke kiri (menggunakan simbol >>)?
Eksperimen Corak: Cuba tukarkan nilai awal kepada unsigned char lampu = 0x03; (0b00000011). Apakah corak pergerakan baharu yang terhasil pada 8 biji LED tersebut?

# Modul 2: Kawalan Input - Butang Bebas (Independent Keys)

Selepas berjaya mengawal Output (LED), kini masa untuk kita belajar bagaimana cip PIC "membaca" keadaan persekitaran menggunakan Input. Input yang paling mudah dan asas adalah Butang Tekan (Push Button).

Pada papan BitWise PIC Kit, terdapat 4 butang bebas (K1 hingga K4) yang disambungkan pada pin RB0 hingga RB3 di port PORTB.

Konsep "Active-Low" dan "Pull-Up Resistor"

Active-Low: Butang pada papan ini direka menggunakan logik Active-Low. Maksudnya:

Apabila butang TIDAK ditekan = Cip membaca logik 1 (HIGH)

Apabila butang DITEKAN = Cip membaca logik 0 (LOW)

Perintang Tarik-Naik (Pull-Up Resistor): Untuk memastikan pin PORTB membaca nilai '1' secara stabil apabila butang tidak ditekan (tiada arus), kita wajib mengaktifkan perintang tarik-naik dalaman (Internal Pull-Up Resistor) di dalam cip PIC dengan baris kod OPTION_REG &= 0x7F;.

Pengaturcaraan: Kawal LED menggunakan Butang

Mari kita tulis kod supaya apabila butang K1 (RB0) ditekan, LED L0 (RD0) akan menyala bersamanya.

[Push Button Programming](/PushButton.c)

Cabaran Makmal Modul 2:

Kawalan Silang: Bolehkah anda ubah kod supaya butang K1 menyalakan LED L7 (RD7) di hujung sana?
Fungsi Terbalik: Cuba tukarkan logik supaya LED L0 sentiasa menyala, dan ia hanya terpadam apabila anda menekan butang K1.
Tambah Butang (Bonus): Gunakan butang K2 (RB1) untuk menyalakan LED L1 (RD1) secara serentak dan berasingan. (Petunjuk: Anda perlu menambah struktur blok if...else yang baharu di bawah blok K1 di dalam gelung utam

# Modul 3: Paparan 7-Segmen (Asas Multiplexing)

Pada papan BitWise PIC Kit anda, terdapat 6 digit paparan bernombor merah yang dipanggil 7-Segmen. Sebenarnya, setiap "digit" ini hanyalah 8 biji lampu LED biasa yang disusun membentuk angka '8' dan satu titik perpuluhan (dp).

Konsep Perkakasan (Katod Sepunya & Suis Pemilih)


<img width="300" height="271" alt="image" src="https://github.com/user-attachments/assets/d4da264a-ac89-4f82-957f-f0a15b01aa5a" />

PORTD (Bentuk Nombor): Pin RD0 hingga RD7 mengawal corak lampu (Segmen A-G dan DP). Untuk membentuk angka '1', kita perlu menyalakan Segmen B dan C (0x06).

PORTA (Pemilih Digit): Oleh kerana kita ada 6 digit, kita tidak mempunyai cukup pin untuk mengawal kesemuanya secara berasingan. Jadi, jurutera menyambungkan semua segmen secara selari (Multiplexing). Kita menggunakan PORTA (RA0 hingga RA5) sebagai Suis Transistor untuk memilih digit mana yang ingin dihidupkan.

Kunci Perkakasan Wajib: Papan ini mempunyai litar perlindungan/penimbal (Buffer IC) yang dikawal oleh PORTC. Anda mesti mengaktifkannya dalam kod! Selain itu, PORTA asalnya adalah pin Analog, kita mesti menukarkannya kepada Digital menggunakan ADCON1.

**Kawalan Digit (Pemultipleks / Multiplexer) pada PORTA**
Jika semua Segmen A dikongsi pada satu wayar RD0, macam mana kita nak paparkan nombor yang berbeza pada digit berbeza (contoh: 123456)?Di sinilah sistem pemultipleks / imbasan dinamik (dynamic scanning) memainkan peranan. Daripada menghidupkan semua digit serentak, mikropengawal mengawal suis kuasa untuk setiap blok digit secara berasingan menggunakan cip pemandu ULN2003A yang disambungkan ke PORTA.  Pemetaan pin suis kuasa (Digit):
RA5 = Suis untuk Digit 1 (Paling Kiri)
RA4 = Suis untuk Digit 2
RA3 = Suis untuk Digit 3
RA2 = Suis untuk Digit 4
RA1 = Suis untuk Digit 5 (Melalui pelompat SE1/JP3)
RA0 = Suis untuk Digit 6 (Paling Kanan, melalui pelompat SE2/JP3)3. 

**Bagaimana Konsep Pemultipleksan Berfungsi?**
Prinsip utamanya adalah "Satu pada satu masa, tetapi ditukar dengan sangat pantas."   Mikropengawal tidak pernah menghidupkan dua digit secara serentak. Ia bekerja dalam kitaran gelung (loop) seperti ini:
1. Mikropengawal menghantar isyarat bentuk nombor pertama ke PORTD. Ia menghidupkan HANYA suis Digit 1 (RA5 = 1), dan digit lain dimatikan.
2. Ia mengekalkan nyalaan itu selama lebih kurang 1 hingga 5 milisaat (delay).
3. Ia memadamkan Digit 1 semula (ini dipanggil blanking untuk elak bayang nombor).
4. Kemudian, ia menghantar isyarat bentuk nombor kedua ke PORTD.Ia menghidupkan HANYA suis Digit 2 (RA4 = 1).
5. Proses ini diulang untuk Digit 3 hingga 6, dan berpatah balik semula ke Digit 1 berulang kali dengan kelajuan yang melampau.

Pengaturcaraan: Memaparkan Semua Digit [7 Segment Programming](/7Segment.c)

**Kenapa perlu Matikan fungsi Analog ADCON1 = 0x06?**
Apabila mikropengawal PIC16F877A dihidupkan, pihak kilang (Microchip) telah menetapkan pin-pin pada PORTA dan PORTE supaya berfungsi sebagai Input Analog secara automatik.

Fungsi Analog: Digunakan untuk membaca nilai voltan yang berubah-ubah (seperti sensor suhu, perintang peka cahaya, atau tombol kelantangan dari 0V hingga 5V).

Fungsi Digital: Digunakan untuk isyarat ON dan OFF sahaja (Logik 1 atau 0).

Seperti yang kita bincangkan sebelum ini, papan ini menggunakan pin RA0 hingga RA5 (PORTA) untuk menghidupkan dan mematikan suis pemandu digit (ULN2003) bagi skrin 7-segmen.

Jika anda cuba mengarahkan RA5 = 1; (minta cip keluarkan isyarat HIGH) tetapi pin tersebut masih berada dalam mod Analog, cip tidak akan mengendahkan arahan anda. Akibatnya, arus tidak akan keluar dan skrin 7-segmen anda akan terus bergelap.

ADCON1 merujuk kepada Analog-to-Digital Control Register 1. Dalam buku manual (datasheet) PIC16F877A, pengeluar telah menyediakan satu jadual khas.

Jika anda memasukkan kod hex 0x06 (yang bersamaan dengan binari 0B00000110) ke dalam ADCON1, ia adalah kata laluan rasmi untuk memberitahu cip:

"Tolong matikan semua fungsi bacaan sensor analog, dan tukarkan kesemua pin PORTA dan PORTE kepada mod Input/Output Digital biasa."

Sebaik sahaja fungsi ini dimatikan, barulah PORTA boleh berfungsi seperti suis biasa untuk mengawal nyalaan digit 7-segmen tersebut dengan sempurna.

Sebagai contoh, dengan mengubah nilai ADCON1, kita boleh memilih kombinasi berikut:

1. ADCON1 = 0x00 (Lalai Kilang): * Semua pin pada PORTA dan PORTE bertindak sebagai Analog.
2. ADCON1 = 0x06 (100% Digital): Semua pin pada PORTA dan PORTE bertindak sebagai Digital I/O. (Ini yang kita gunakan untuk projek 7-segmen tadi).
3. ADCON1 = 0x04 (Campuran): Pin RA0, RA1, dan RA3 menjadi Analog (anda boleh sambungkan 3 sensor analog di sini). Baki pin yang lain di PORTA dan semua pin di PORTE menjadi Digital.
4. ADCON1 = 0x0E (Hanya Satu Analog):Hanya pin RA0 menjadi Analog. Semua pin PORTA yang lain dan PORTE menjadi Digital.

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




