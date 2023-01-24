# Tugas kecil 1 Strategi Algoritma | Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force

## Deskripsi Permainan Kartu 24

Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24 Permainan ini menarik cukup banyak peminat dikarenakan dapat meningkatkan kemampuan berhitung serta mengasah otak agar dapat berpikir dengan cepat dan akurat. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). Yang perlu diperhatikan hanyalah nilai kartu yang didapat (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas. 
(Paragraf di atas dikutip dari sini: https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2015-2016/Makalah-2016/MakalahStima-2016-038.pdf).


## Deskripsi Program

Program ini berfungsi untuk memberikan solusi dari permainan kartu 24. Program ini akan memberikan total solusi yang ada (bila ada) dan menampilkan seluruh solusinya. Program juga dapat menyimpan solusi dalam bentuk file txt bila user menginginkannya. Untuk input kartunya, user dapat menginputnya secara manual atau menggunakan fitur auto-generator pada program ini.


## Struktur Program

```
│ .vscode
├─── bin
│       │ Tucil.exe
│
├─── doc
│       │ Tucil1_K01_13521143_Raynard Tanadi.pdf
        | Tucil1-Stima-2023.pdf
│
├─── src
│       │ Ascii.txt
│       │ Tucil.cpp
│
├─── test
        │ contoh1.txt
        │ contoh2.txt
        │ contoh3.txt
        │ contoh4.txt
        │ contoh5.txt
        │ contoh6.txt        
                                        
```


## Menggunakan Program

Untuk menjalankan program, buka root directory, lalu jalankan run.bat:
```
./run.bat
```
Jika gagal, hapus file Tucil.exe di folder bin. Lalu, ulangi langkah di atas.

Untuk penggunaan program di dalam akan terdapat instruksi yang jelas di program sehingga user tinggal mengikutinya saja.


## Tampilan User

- Preview 24 Game Solver
<p align = "center">
    <img src="https://i.postimg.cc/pTH9cRzg/24game.jpg">
</p>


## Author

13521143|Raynard Tanadi