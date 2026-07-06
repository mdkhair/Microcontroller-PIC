Apa itu __CONFIG()?
__CONFIG() merujuk kepada Configuration Bits (atau sering dipanggil Fuses). Ini adalah tetapan asas perkakasan yang perlu dikonfigurasi sebelum cip mula menjalankan sebarang program.

Ia mengawal fungsi penting seperti: Jenis pengayun (oscillator/crystal) yang digunakan, mengaktifkan/mematikan Watchdog Timer, dan perlindungan kod (Code Protection).

Dalam gambar anda, ia ditulis sebagai __CONFIG(0xFF32);. Ini dipanggil kaedah Hexadecimal Masking. Pengaturcara lama terpaksa mengira bit secara manual untuk mendapatkan nilai 0xFF32. Cara ini sangat tidak mesra pengguna kerana anda tidak tahu apa sebenarnya yang diaktifkan atau dimatikan melainkan anda merujuk kepada buku manual (datasheet) cip tersebut.
