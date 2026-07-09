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




