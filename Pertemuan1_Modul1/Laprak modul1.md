# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Code::Blocks adalah suatu program IDE(Integrated Development Environment) lingkungan pengembangan bebas terpadu, nirlaba, bersumber terbuka, dan lintas platform untuk pengembangan program dengan bahasa C, C++, dan Fortran.[1]



## Guided 

### 1. Input & Output

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : "; 
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    //penjumlahan
    cout << "Penjumalah : " << angka1 + angka2 << endl;
    //pengurangan
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    //perkalian
    cout << "Perkalian : " << angka1 * angka2 << endl;
    //pembagian
    cout << "Pembagian : " << angka1 / angka2 << endl;
    //modulus
    cout << "Modulus : " << angka1 % angka2 << endl;
    return 0;
}

```
guided 1 menjelaskan bagaimana cara melakukan input dan output menggunakan operasi aritmatika

### 2. Struct

```C++
#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

    struct Rapot {
        string nama;
        int nilai;
    };

    Rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama Siswa: ";
        cin >> siswa[i].nama;
        cout << "Masukkan nilai Siswa: ";
        cin >> siswa[i].nilai;
    }

    cout << endl;
    
    int i = 0;
    while (i < jumlah) {
        cout << "Nama : " << siswa[i].nama << " nilai : " << siswa[i].nilai << endl;
        i++;
    }

    return 0;
}

```
guided 2 menjelaskan bagaimana membuat sebuah tipe data bentukan / struct di c++

### 3. Percabangan

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1,angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << angka1 << " lebih besar dari " << angka2 << endl;
    } else if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 < angka2) {
        cout << angka1 << " lebih kecil dari " << angka2 << endl;        
    } 

    if (angka1 != angka2) {
        cout << angka1 << " tidak sama dengan " << angka2 << endl;
    }

    return 0;
}
```
guided 3 menjelaskan bagimana percabangan digunakan menggunakan if, else dan else if.

### 4. Perulangan for

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1,angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    for (int i = 0; i < angka1; i++){ // increment
        cout << i << " - ";
    }

    cout << endl;

    for (int i = 20; i > angka2; i--){ // decrement
        cout << i << " - ";
    }

    return 0;
}
```
guided 4 menjelaskan bagaimana perulangan for di jalankan.

### 5. Perulangan while

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1,angka2;
    cout << "Masukan angka1 : ";
    cin >> angka1;
    // cout << "Masukan angka2 : ";
    // cin >> angka2;

    int i = 0;
    int j = 11;

    //perulangan while
    while (i < angka1){
        cout << i << " - ";
        i++; //increment
    }

    cout << endl;

    //perulangan do while
    do{
        cout << j << " - ";
        j++; //increment
    } while(j < angka1);

    return 0;
}
```
guided 5 menjelaskan bagaimana perulangan while di jalankan.

## Unguided 

### 1. unguided 1
Buatlah program yang menerima input berupa dua buah bilangan bertipe float, kemudian memberikan output hasil penjumlahan, pengurangan, perkalian, pembagian dari kedua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Hasil penjumlahan: " << a + b << endl;
    cout << "Hasil pengurangan: " << a - b << endl;
    cout << "Hasil perkalian: " << a * b << endl;
    if (b != 0)
        cout << "Hasil pembagian: " << a / b << endl;
    else
        cout << "Pembagian tidak bisa dilakukan (pembagi nol)." << endl;

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan1_Modul1/output/output1.png)

unguided 1 menjelaskan melakukan output dengan operasi dasar aritmatika

### 2. unguided 2
Buatlah sebuah program yang menerima masukan angka, kemudian mengeluarkan output berupa nilai angka tersebut dalam bentuk tulisan.

```C++
#include <iostream>
using namespace std;

string angkaSatuan[] = {
    "nol", "satu", "dua", "tiga", "empat", "lima", 
    "enam", "tujuh", "delapan", "sembilan"
};

string angkaBelasan[] = {
    "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
    "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
};

string angkaPuluhan[] = {
    "", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh",
    "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"
};

string bilangan(int n) {
    if (n < 10) return angkaSatuan[n];
    else if (n < 20) return angkaBelasan[n - 10];
    else if (n < 100) {
        int puluh = n / 10;
        int satuan = n % 10;
        if (satuan == 0) return angkaPuluhan[puluh];
        else return angkaPuluhan[puluh] + " " + angkaSatuan[satuan];
    } else if (n == 100) return "seratus";
    else return "di luar jangkauan";
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 0 || n > 100)
        cout << "Input tidak valid!" << endl;
    else
        cout << n << " : " << bilangan(n) << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan1_Modul1/output/output2.png)

unguided 2 menjelaskan bagaimana cara mengubah bilangan integer ke string

### 3. unguided 3
Buatlah program yang dapat memberikan input dan output sbb.
mirror

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            cout << j << " ";
        }
        cout << "= ";
        for (int j = i; j <= n; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan1_Modul1/output/output3.png)

unguided 3 menjelaskan cara mirror bilangan integer yaitu dengan cara perulangan di balik.

## Kesimpulan
Ketiga soal ini melatih dasar input-output, operasi aritmatika, percabangan, dan perulangan di C++ untuk mengasah logika pemrograman.

## Referensi
[1] Hanief, S., & Jepriana, I. W. (2020). Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Yogyakarta: Penerbit ANDI.
<br>...
