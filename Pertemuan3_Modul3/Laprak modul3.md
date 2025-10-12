# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Abstract Data Type (ADT) adalah model matematis untuk tipe data yang didefinisikan oleh perilakunya (operasi) dari sudut pandang pengguna, bukan oleh representasi atau implementasinya. Konsep ini menekankan pada "apa" yang bisa dilakukan oleh sebuah data, bukan "bagaimana" hal itu dilakukan di dalam memori[1].

Prinsip Utama Abstract Data Type (ADT)
Enkapsulasi adalah mekanisme untuk membungkus data (atribut) dan operasi (metode) yang bekerja pada data tersebut ke dalam satu unit tunggal. Dalam C++, ini diwujudkan secara langsung melalui penggunaan class atau struct. Dengan enkapsulasi, data dan fungsi yang memanipulasinya terikat erat, menciptakan sebuah "kapsul" logis yang mandiri dan mudah dikelola. Ini mencegah data tersebar di berbagai bagian program dan memastikan bahwa interaksi dengan data hanya terjadi melalui cara yang telah ditentukan[2].

## Guided 

### 1. Contoh1

```.h
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//Prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```


```C++
#include "pelajaran.h"

//impementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel){
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode : " << pel.kodeMapel << endl;
}

```


```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namamapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namamapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
guided 1 menjelaskan penggunaan modular di bahasa cpp. Jadi buat file .h untuk data type, lalu buat file function terpisah, kemudian baru di masukkan ke main program.


## Unguided 

### 1. unguided 1
Buat program yang dapat menyimpan data mahasiswa (max. 10) dengan field nama, nim, uts, uas, tugas, dan nilai_akhir.
Nilai akhir = 0.3×uts + 0.4×uas + 0.3×tugas.

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilai_akhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> mhs[i].nama;
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "UTS   : ";
        cin >> mhs[i].uts;
        cout << "UAS   : ";
        cin >> mhs[i].uas;
        cout << "Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilai_akhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "Daftar Nilai Mahasiswa" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << mhs[i].nama << ' ' 
            << mhs[i].nim << ' '
            << " Nilai Akhir: " << mhs[i].nilai_akhir << endl;
    }

    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan3_Modul3/output/output1.png)

unguided 1 menjelaskan penggunaan struct mahasiswa yg di isi variable nama nim nilai uts,uas,tugas, dan nilai akhir. Lalu ada function hitungNilaiAkhir untuk menghitung nilai akhir dan menyiman nilai akhir di dalam struct mahasiswa. Terakhir loop untuk menampilkan semua data mahasiswa.

### 2. unguided 2
Buatlah ADT pelajaran didalam file "pelajaran.j"
buatlah implementasi ADT pelajaran didalam file "pelajaran.cpp"
cobalah hasil implementasi ADT pada file "main.cpp"

```C++
#include <iostream>
using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel){
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode : " << pel.kodeMapel << endl;
}

int main(){
    string namamapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namamapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan3_Modul3/output/output2.png)

unguided 2 menjelaskan bagaimana ADT di buat. Deklrasi sturct ADT pelajaran kemudian isi variable ada namaMapel dan kodeMapel bertipe string. Lalu ada function create pelajaran dengan tipe data struct pelajaran yg mereturn paramater nama dan kode pelajaran. Lalu ada prosedur tampil pelajaran untuk menampilkan nama dan kode pelajaran menggunakan cout melalui parameter pelajaran pel. Di main program memanggil fungsi dan prosedur yg udah dibuat diawal.

### 3. unguided 3
Program dengan 2 array 2D integer 3×3 dan 2 pointer integer
- Fungsi/prosedur untuk menampilkan isi array 2D
- Fungsi/prosedur untuk menukar isi 2 array 2D pada posisi tertentu
- Fungsi/prosedur untuk menukar isi variabel yang ditunjuk oleh 2 pointer

```C++
#include <iostream>
using namespace std;

const int SIZE = 3;

void tampilkanArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int i, int j) {
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[SIZE][SIZE] = {{9,8,7},{6,5,4},{3,2,1}};

    cout << "Array A:" << endl;
    tampilkanArray(A);
    cout << "\nArray B:" << endl;
    tampilkanArray(B);

    tukarPosisi(A, B, 0, 1);

    cout << "\nSetelah menukar elemen [0][1]:" << endl;
    cout << "Array A:" << endl;
    tampilkanArray(A);
    cout << "\nArray B:" << endl;
    tampilkanArray(B);

    int x = 10, y = 20;
    int *px = &x, *py = &y;
    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(px, py);
    cout << "Setelah tukar pointer : x=" << x << ", y=" << y << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan3_Modul3/output/output3.png)

unguided 3 menjelaskan bagaimana cara manipulasi array 2D dan pointer menggunakan fungsi/prosedur. pertama ada dua array 3×3 (A dan B) disiapkan berisi nilai awal. Lalu ada fungsi tampilkanArray() digunakan untuk menampilkan isi array. Kemudian fungsi tukarPosisi() menukar satu elemen tertentu antara dua array (misalnya elemen [0][1] pada A dan B). Terakhir fungsi tukarPointer() menukar nilai dari dua variabel menggunakan pointer.

## Kesimpulan
Abstract Data Type (ADT) adalah konsep dasar dalam pemrograman yang memisahkan definisi struktur data (apa yang disimpan dan operasi apa yang bisa dilakukan) dari implementasinya (bagaimana operasi tersebut dijalankan). Dengan ADT memungkinkan kita membuat tipe data baru, sehingga program menjadi lebih mudah dipahami, diperluas, dan digunakan kembali.

## Referensi
[1] Liskov, B., & Guttag, J. (1986). Abstraction and Specification in Program Development. MIT Press.
[2] Guttag, J. V. (1977). Abstract Data Types and the Development of Data Structures. Communications of the ACM, 20(6), 396–404.
<br>...
