# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian kedua)</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
[1]C++ merupakan pengembangan dari bahasa C dengan tambahan fasilitas berupa kelas (class). Program dalam C++ disusun dari sekumpulan fungsi, dengan fungsi utama adalah main(). Bahasa C++ bersifat case sensitive, artinya pembedaan huruf besar dan huruf kecil sangat berpengaruh dalam penulisan kode. Sama seperti bahasa C, C++ termasuk bahasa pemrograman tingkat menengah (middle level language).
[2]Bahasa C++ dikenal sebagai bahasa yang kuat dan fleksibel, serta menjadi fondasi dalam banyak sistem perangkat lunak dan pengembangan aplikasi modern.


## Guided 

### 1. Array 1 dimensi

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];
    
    for (int i = 0; i < 5; i++){
        cout << "Masukkan value indks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
program ini meminta input 5 angka, menyimpannya dalam array, lalu menampilkannya kembali sesuai dengan indeks nya.

### 2. Array 2 dimensi

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4},
    };

    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] {0};

    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program ini menggunakan array 2 dimensi untuk menghitung operasi matriks. Matriks arrA dan arrB dijumlahkan elemen per elemen menjadi arrC, lalu dikalikan dengan aturan baris × kolom untuk menghasilkan arrD. Hasil penjumlahan dan perkalian kemudian ditampilkan.

### 3. Call By Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
program ini menunjukkan cara kerja pointer untuk mengakses alamat variabel dan bagaimana Call by Pointer memungkinkan perubahan nilai variabel asli di luar fungsi. Dengan cara membuat Variabel a dan b masing-masing bernilai 20 dan 30. Kemudian Pointer ptr menyimpan alamat dari a, sehingga *ptr mengakses nilai a. Lalu buat Fungsi tukar(int *x, int *y) menerima alamat dari a dan b. Dengan pointer, nilai asli a dan b bisa ditukar karena fungsi bekerja langsung pada alamat memori. Setelah pemanggilan tukar(&a, &b), nilai a menjadi 30 dan b menjadi 20.

### 4. Call By Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;
    tukar(a,b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
program ini menunjukkan bagaimana reference bisa digunakan untuk mengakses dan mengubah variabel asli, mirip dengan pointer, tetapi dengan sintaks yang lebih sederhana. Dengan cara membuat Variabel a dan b masing-masing bernilai 20 dan 30. Lalu int& ref = a; membuat referensi (alias) untuk a, artinya ref dan a menunjuk ke lokasi memori yang sama. Saat ref = 50;, nilai a juga berubah menjadi 50 karena keduanya adalah alias.Fungsi tukar(int &x, int &y) menukar nilai a dan b menggunakan parameter referensi, sehingga perubahan langsung memengaruhi variabel asli tanpa perlu pointer. Setelah pemanggilan tukar(a, b), nilai a dan b berhasil ditukar.

### 5. Function Prosedur

```C++
#include <iostream>
using namespace std;

int cariMax(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmetika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMax(arr, ukuran) << endl;

    operasiAritmetika(arr, ukuran);
    return 0;
}


```
program ini menunjukkan perbedaan antara function (menghasilkan nilai) dan prosedur (tidak menghasilkan nilai, hanya menampilkan proses/output). Terdapat Function cariMax untuk menerima array dan ukuran, kemudian mengembalikan nilai terbesar dalam array. Karena mengembalikan nilai, ia disebut function. Dan Prosedur operasiAritmetika menerima array dan ukuran, lalu menghitung total penjumlahan dan perkalian semua elemen array. Karena hanya menampilkan hasil tanpa mengembalikan nilai, ia disebut prosedur (void). Lalu Fungsi main meminta user mengisi array, lalu memanggil cariMax untuk mencari nilai terbesar dan operasiAritmetika untuk menampilkan hasil operasi penjumlahan serta perkalian.


## Unguided 

### 1. unguided 1
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan 
perkalian matriks 3x3.

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[3][3];

    cout << "Hasil Penjumlahan Matriks:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan Matriks:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian Matriks:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
    
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan2_Modul2/output/output1.png)

program ini menjelaskan bagaimana array 2 dimensi digunakan untuk menghitung penjumlahan, pengurangan, dan perkalian matriks ukuran 3×3. Terdapat 3 perulangan yang pertama untuk penjumlahan kedua pengurangan dan perkalian. untuk Penjumlahan Matriks Setiap elemen C[i][j] dihitung dari A[i][j] + B[i][j]. Lalu untuk Pengurangan Matriks Setiap elemen C[i][j] dihitung dari A[i][j] - B[i][j]. Dan untuk Perkalian Matriks Setiap elemen C[i][j] dihitung dengan rumus: C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + A[i][2]*B[2][j];

### 2. unguided 2
Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat 
menukar nilai dari 3 variabel.

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 1, y = 2, z = 3;

    cout << "Sebelum tukar: x=" << x << " y=" << y << " z=" << z << endl;
    tukarPointer(&x, &y, &z);
    cout << "Setelah tukar (Pointer): x=" << x << " y=" << y << " z=" << z << endl;
    tukarReference(x, y, z);
    cout << "Setelah tukar (Reference): x=" << x << " y=" << y << " z=" << z << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan2_Modul2/output/output2.png)

program ini memperlihatkan bahwa baik pointer maupun reference dapat digunakan untuk memodifikasi nilai variabel asli di luar fungsi, hanya berbeda di cara pemanggilannya. Terdapat fungsi tukarPointer(int *a, int *b, int *c) menggunakan pointer. Parameter menerima alamat variabel (&x, &y, &z), lalu nilai di alamat tersebut diubah dengan dereferensi (*a, *b, *c). Dan Fungsi tukarReference(int &a, int &b, int &c) menggunakan reference. Parameter langsung menjadi alias variabel aslinya, sehingga perubahan otomatis memengaruhi variabel asli. Logika penukaran: nilai a dipindahkan ke temp, lalu a diganti nilai b, b diganti nilai c, dan c diisi dengan nilai awal a (di temp). Lalu Pada fungsi main, nilai awal x=1, y=2, z=3. Setelah tukarPointer, nilai berubah menjadi x=2, y=3, z=1. Setelah tukarReference, nilai kembali bergeser menjadi x=3, y=1, z=2.

### 3. unguided 3
Diketahui sebuah array 1 dimensi sebagai berikut :  
arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} 
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari 
array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan 
function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur 
hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan 
menu switch-case seperti berikut ini : --- Menu Program Array --- 
1. Tampilkan isi array 
2. cari nilai maksimum 
3. cari nilai minimum 
4. Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) maks = arr[i];
    }
    return maks;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    cout << "Nilai Rata-rata: " << total / n << endl;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Isi Array: ";
                for (int i = 0; i < 10; i++) cout << arrA[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Nilai Maksimum: " << cariMaksimum(arrA, 10) << endl;
                break;
            case 3:
                cout << "Nilai Minimum: " << cariMinimum(arrA, 10) << endl;
                break;
            case 4:
                hitungRataRata(arrA, 10);
                break;
        }
    } while(pilihan != 0);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan2_Modul2/output/output3-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan2_Modul2/output/output3-2.png)

program ini bagaimana array dapat digunakan untuk menyimpan data, lalu diolah melalui function (mengembalikan nilai) dan prosedur (menampilkan hasil langsung) dalam menu.

## Kesimpulan
Dalam latihan ini kita dapat mengetahui perbedaan pointer dan reference, dan juga mengetahui kapan menggunakan function dan kapan menggunakan prosedur. Konsep ini menjadi dasar penting dalam pengolahan data serta pembuatan program yang lebih terstruktur.

## Referensi
[1] Sindar, A. (t.t.). Struktur Data dan Algoritma dengan C++. Yogyakarta: CV. AA. Rizky. 
[2]Trianiza, I., Khirdany, E. N., Wahyudi, E., Vandika, A. Y., & Sofyan, S. 2025. Pengenalan Pemrograman Dasar Dunia Koding dengan C++. Yogyakarta: YPAD Penerbit.
<br>...
