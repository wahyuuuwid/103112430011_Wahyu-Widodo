# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Linked List adalah struktur data linier, di mana elemen tidak disimpan di lokasi yang berdekatan, tetapi
ditautkan menggunakan pointer. Linked List membentuk rangkaian node yang terhubung, dimana setiap node
menyimpan data dan alamat dari node berikutnya.(GeeksforGeeks, Understanding the basics of Linked List,
2023).Struktur Node: Node dalam linked list biasanya terdiri dari dua komponen:
Data: Ini memegang nilai aktual atau data yang terkait dengan node.
Next Pointer: Ini menyimpan alamat memori (referensi) dari node berikutnya dalam urutan. Head and Tail: linked list diakses melalui simpul kepala, yang menunjuk ke simpul pertama dalam daftar.Node terakhir dalam daftar menunjuk ke NULL, menunjukkan akhir dari daftar. Simpul ini dikenal sebagai[1]

Salah satu bentuk struktur data, berisi kumpulan data (node) yang tersusun secara sekuensial, saling sambung-menyambung, dinamis dan tidak terbatas.Linked List sering disebut juga Senarai Berantai. Linked List saling terhubung dengan bantuan variabel pointer. Masing-masing data dalam Linked List disebut dengan node (simpul) yang menempati alokasi memori secara dinamis dan biasanya berupa record[2]

## Guided 

### 1. guided 1

listBuah.h
```h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

```

main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Penjelasan guided 1
Pada file listBuah.h, didefinisikan beberapa struktur data, antara lain struct buah untuk menyimpan data nama, jumlah, dan harga buah, serta struct node yang berisi satu data buah dan pointer next yang menunjuk ke node berikutnya. Struktur linkedlist digunakan untuk menyimpan alamat node pertama pada list. Di dalam file ini juga terdapat deklarasi fungsi-fungsi yang akan digunakan untuk mengelola list, seperti fungsi untuk membuat list baru, menambahkan node, menghapus node, memperbarui data, dan melakukan pencarian.

File listBuah.cpp berisi implementasi dari semua fungsi yang dideklarasikan pada header. Fungsi createList() digunakan untuk membuat list kosong, sedangkan isEmpty() mengecek apakah list masih kosong atau tidak. Fungsi alokasi() membuat node baru secara dinamis dengan menggunakan operator new, dan dealokasi() menghapus node dengan delete agar memori tidak bocor. Program juga menyediakan berbagai prosedur untuk menambah data seperti insertFirst(), insertAfter(), dan insertLast() serta prosedur untuk menghapus data seperti delFirst(), delAfter(), dan delLast(). Selain itu, terdapat prosedur printList() untuk menampilkan isi list, nbList() untuk menghitung jumlah node, dan deleteList() untuk menghapus seluruh isi list. Pada bagian update, tersedia fungsi updateFirst(), updateLast(), dan updateAfter() yang memungkinkan pengguna memperbarui data buah pada posisi tertentu. Sedangkan untuk pencarian, terdapat fungsi FindNodeByData(), FindNodeByAddress(), dan FindNodeByRange() untuk mencari data berdasarkan nama buah, alamat node, serta rentang harga tertentu.

Pada file main.cpp, seluruh fungsi tersebut diuji melalui berbagai proses. Pertama, program membuat list kosong menggunakan createList() lalu menambahkan beberapa node buah seperti Jeruk, Apel, Pir, Semangka, dan Durian dengan fungsi alokasi(). Node-node ini kemudian dimasukkan ke dalam list menggunakan kombinasi fungsi insertFirst(), insertAfter(), dan insertLast(). Setelah proses insert, isi list ditampilkan menggunakan printList() dan jumlah node dihitung dengan nbList(). Program kemudian melakukan update terhadap data pertama, terakhir, dan data setelah node tertentu dengan memanggil fungsi updateFirst(), updateLast(), dan updateAfter(). Proses pencarian juga dilakukan dengan mencari nama buah tertentu, alamat node tertentu, serta buah-buah dalam rentang harga tertentu. Selanjutnya, program menguji proses penghapusan node melalui delFirst(), delLast(), dan delAfter(). Terakhir, semua node dihapus dengan deleteList() sehingga list menjadi kosong kembali.


## Unguided 

### 1. unguided 1
Buatlah procedure updateFirst, updateLast, dan updateAfter dengan rincian 
sebagai berikut :
Procedure updateFirst ( input / output L : List )
Procedure updateLast ( input / output L : List )
Procedure updateAfter ( input / output L : List, input nodePrev : address )
Kemudian pada “main.cpp” lakukanlah :
➢ Update data 40 menjadi 50
➢ Update data 8 menjadi 29
➢ Update data 33 menjadi 45
➢ Update data 18 menjadi 20
➢ Tampilkan seluruh list setelah diupdate

ListAngka.h
```h
#ifndef LISTANGKA_H
#define LISTANGKA_H

typedef int dataAngka;
typedef struct node* address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedList L);
void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);
int nbList(linkedList L);
void delAfter(linkedList &L, address nodeHapus, address nodePrev);

// Procedure untuk update data
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

#endif
```

ListAngka.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

#define Nil NULL

// Fungsi untuk cek apakah list kosong
bool isEmpty(linkedList L) {
    return L.first == Nil;
}

// Pembuatan linked list kosong
void createList(linkedList &L) {
    L.first = Nil;
}

// Alokasi node baru
address alokasi(dataAngka x) {
    address nodeBaru = new node;
    nodeBaru->angka = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// Dealokasi node
void dealokasi(address &node) {
    delete node;
    node = Nil;
}

// Menampilkan isi list
void printList(linkedList L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) {
            cout << nodeBantu->angka << " - ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

// Insert node di awal
void insertFirst(linkedList &L, address nodeBaru) {
    nodeBaru->next = L.first;
    L.first = nodeBaru;
}

// Insert node di akhir
void insertLast(linkedList &L, address nodeBaru) {
    if (isEmpty(L)) {
        L.first = nodeBaru;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// Insert node setelah node tertentu
void insertAfter(linkedList &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    }
}

// Menghitung jumlah node
int nbList(linkedList L) {
    int count = 0;
    address nodeBantu = L.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// Delete node setelah node tertentu
void delAfter(linkedList &L, address nodeHapus, address nodePrev) {
    if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        dealokasi(nodeHapus);
    }
}

// Update data node pertama
void updateFirst(linkedList &L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        dataAngka newData;
        cout << "Masukkan update data node pertama : " << endl;
        cout << "masukkan angka : ";
        cin >> newData;
        L.first->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

// Update data node terakhir
void updateLast(linkedList &L) {
    if (isEmpty(L)) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        dataAngka newData;
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> newData;
        nodeBantu->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

// Update data node setelah node tertentu
void updateAfter(linkedList &L, address nodePrev) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeUpdate = nodePrev->next;
        dataAngka newData;
        cout << "masukkan update data node setelah node " << nodePrev->angka << " : " << endl;
        cout << "Masukkan angka : ";
        cin >> newData;
        nodeUpdate->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    } 
}
```

main.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main(){
    linkedList L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = nullptr;
    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    delAfter(L, nodeB, nodeC);
    printList(L);

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);

    printList(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan5_Modul5/output/output1.png)

Penjelasan unguided 1
ada file ListAngka.h, dideklarasikan berbagai fungsi penting, di antaranya:
createList untuk membuat list kosong, alokasi dan dealokasi untuk manajemen memori node, insertFirst, insertLast, dan insertAfter untuk menambahkan node di awal, akhir, atau setelah node tertentu, delAfter untuk menghapus node setelah node tertentu, serta updateFirst, updateLast, dan updateAfter untuk memperbarui nilai data di node pertama, terakhir, atau setelah node tertentu.

Dalam ListAngka.cpp, fungsi-fungsi tersebut diimplementasikan.
Fungsi isEmpty memeriksa apakah list kosong dengan mengecek apakah L.first bernilai NULL. Fungsi createList menginisialisasi linked list agar tidak berisi node apa pun. Fungsi alokasi membuat node baru di heap menggunakan new, lalu mengembalikannya sebagai alamat node baru, sedangkan dealokasi digunakan untuk menghapus node dengan delete agar tidak terjadi kebocoran memori.

Fungsi insertFirst, insertLast, dan insertAfter bertanggung jawab menambahkan node baru di posisi berbeda. Misalnya, insertFirst menambahkan node di awal dengan mengarahkan next dari node baru ke node pertama yang lama. Sebaliknya, insertLast menelusuri list hingga node terakhir sebelum menambahkan node baru di akhir. Fungsi nbList dapat menghitung jumlah elemen dalam list.Fungsi delAfter digunakan untuk menghapus node setelah node tertentu, sedangkan printList mencetak seluruh isi list secara berurutan.
Fungsi updateFirst, updateLast, dan updateAfter memungkinkan pengguna mengganti nilai angka pada node pertama, terakhir, atau node setelah node tertentu dengan input baru dari pengguna.

Pada bagian main.cpp, dibuat beberapa node (nodeA sampai nodeF) dengan nilai tertentu, lalu dimasukkan ke dalam list menggunakan berbagai fungsi insert. Kemudian salah satu node dihapus menggunakan delAfter, dan list dicetak menggunakan printList. Setelah itu, fungsi update dijalankan untuk mengubah beberapa nilai data di dalam list sesuai input pengguna, dan hasil akhirnya ditampilkan kembali.

### 2. unguided 2
. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange dengan 
rincian sebagai berikut :
Procedure SearchByData( input L : List, input data : integer )
Procedure SearchByAddress( input L : List, input node : address )
Procedure SearchByRange( input L : List, input nilaiMin : integer )
Kemudian pada “main.cpp” lakukanlah :
➢ Mencari data nilai 20
➢ Mencari data nilai 55
➢ Mencari data alamat nodeB
➢ Mencari data alamat nodeA
➢ Mencari data dengan nilai minimal 40

ListAngka.h
```h
#ifndef LISTANGKA_H
#define LISTANGKA_H

typedef int dataAngka;
typedef struct node* address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedList L);
void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);
int nbList(linkedList L);
void delAfter(linkedList &L, address nodeHapus, address nodePrev);

// Procedure untuk update data
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

// Procedure untuk searching
void searchByData(linkedList L, dataAngka data);
void searchByAddress(linkedList L, address node);
void searchByRange(linkedList L, dataAngka nilaiMin);

#endif
```

ListAngka.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

#define Nil NULL

// Fungsi untuk cek apakah list kosong
bool isEmpty(linkedList L) {
    return L.first == Nil;
}

// Pembuatan linked list kosong
void createList(linkedList &L) {
    L.first = Nil;
}

// Alokasi node baru
address alokasi(dataAngka x) {
    address nodeBaru = new node;
    nodeBaru->angka = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// Dealokasi node
void dealokasi(address &node) {
    delete node;
    node = Nil;
}

// Menampilkan isi list
void printList(linkedList L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) {
            cout << nodeBantu->angka << " - ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

// Insert node di awal
void insertFirst(linkedList &L, address nodeBaru) {
    nodeBaru->next = L.first;
    L.first = nodeBaru;
}

// Insert node di akhir
void insertLast(linkedList &L, address nodeBaru) {
    if (isEmpty(L)) {
        L.first = nodeBaru;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// Insert node setelah node tertentu
void insertAfter(linkedList &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    }
}

// Menghitung jumlah node
int nbList(linkedList L) {
    int count = 0;
    address nodeBantu = L.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// Delete node setelah node tertentu
void delAfter(linkedList &L, address nodeHapus, address nodePrev) {
    if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        dealokasi(nodeHapus);
    }
}

// Update data node pertama
void updateFirst(linkedList &L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        dataAngka newData;
        cout << "Masukkan update data node pertama : " << endl;
        cout << "masukkan angka : ";
        cin >> newData;
        L.first->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

// Update data node terakhir
void updateLast(linkedList &L) {
    if (isEmpty(L)) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        dataAngka newData;
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> newData;
        nodeBantu->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

// Update data node setelah node tertentu
void updateAfter(linkedList &L, address nodePrev) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeUpdate = nodePrev->next;
        dataAngka newData;
        cout << "masukkan update data node setelah node " << nodePrev->angka << " : " << endl;
        cout << "Masukkan angka : ";
        cin >> newData;
        nodeUpdate->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    } 
}

// Search berdasarkan data
void searchByData(linkedList L, dataAngka data) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->angka == data) {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        
        if (!found) {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

// Search berdasarkan alamat
void searchByAddress(linkedList L, address node) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        
        if (!found) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

// Search berdasarkan range 
void searchByRange(linkedList L, dataAngka nilaiMin) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        
        cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->angka > nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << nodeBantu->angka << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        
        if (!found) {
            cout << "Tidak ada data diatas nilai " << nilaiMin << "!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main(){
    linkedList L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = nullptr;
    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    delAfter(L, nodeB, nodeC);

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);

    searchByData(L, 20);
    searchByData(L, 55);
    searchByAddress(L, nodeB);
    searchByAddress(L, nodeA);
    searchByRange(L, 40);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan5_Modul5/output/output2.png)

penjelasan unguided 2
Pada file ListAngka.h, didefinisikan beberapa tipe data penting, yaitu struct node yang menyimpan sebuah data bertipe int bernama angka dan pointer next yang menunjuk ke node berikutnya. Kemudian terdapat struct linkedList yang menyimpan pointer first sebagai penanda node pertama dalam list. File ini juga berisi deklarasi fungsi dan prosedur utama seperti createList() untuk membuat list kosong, alokasi() dan dealokasi() untuk mengelola memori secara dinamis, serta berbagai prosedur lain untuk operasi dasar seperti penambahan, penghapusan, pembaruan, dan pencarian data dalam list.

Implementasi seluruh fungsi tersebut terdapat pada file ListAngka.cpp. Fungsi createList() digunakan untuk menginisialisasi list kosong, sedangkan isEmpty() mengecek apakah list masih kosong. Fungsi alokasi() membuat node baru dengan nilai tertentu dan dealokasi() digunakan untuk menghapus node agar memori tidak bocor. Operasi penambahan data dilakukan melalui tiga prosedur, yaitu insertFirst() untuk menambah node di awal list, insertLast() untuk menambah node di akhir list, dan insertAfter() untuk menambah node setelah node tertentu. Program juga menyediakan fungsi nbList() untuk menghitung jumlah node, serta delAfter() untuk menghapus node yang berada setelah node tertentu. Selain itu, terdapat prosedur untuk memperbarui isi node seperti updateFirst(), updateLast(), dan updateAfter() yang memungkinkan pengguna mengganti nilai angka di node pertama, terakhir, atau setelah node tertentu. Pada bagian pencarian, fungsi searchByData() digunakan untuk mencari data berdasarkan nilai angka, searchByAddress() untuk mencari posisi node berdasarkan alamat memorinya, dan searchByRange() untuk menampilkan semua data yang lebih besar dari nilai batas tertentu.

Pada file main.cpp, seluruh fungsi tersebut diuji melalui beberapa tahap. Pertama, list dibuat kosong menggunakan createList(), kemudian beberapa node dialokasikan menggunakan alokasi() dengan nilai angka seperti 8, 13, 18, 25, 33, dan 40. Node-node tersebut dimasukkan ke dalam list menggunakan kombinasi fungsi insertFirst(), insertLast(), dan insertAfter() untuk membentuk urutan tertentu. Setelah itu, satu node dihapus dengan delAfter(). Program kemudian melakukan proses pembaruan data menggunakan updateFirst(), updateAfter(), dan updateLast(), di mana pengguna akan diminta memasukkan nilai baru melalui input keyboard. Bagian selanjutnya menguji fitur pencarian dengan memanggil searchByData() untuk mencari angka tertentu, searchByAddress() untuk menemukan posisi node berdasarkan alamatnya, serta searchByRange() untuk menampilkan angka-angka yang lebih besar dari nilai minimum yang ditentukan.

### 3. unguided 3
Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap 
semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, 
untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai 
awal adalah 1.

ListAngka.h
```h
#ifndef LISTANGKA_H
#define LISTANGKA_H

typedef int dataAngka;
typedef struct node* address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedList L);
void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);
int nbList(linkedList L);
void delAfter(linkedList &L, address nodeHapus, address nodePrev);

// Procedure untuk update data
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

// Procedure untuk searching
void searchByData(linkedList L, dataAngka data);
void searchByAddress(linkedList L, address node);
void searchByRange(linkedList L, dataAngka nilaiMin);

// Procedure untuk operasi aritmetika
int totalPenjumlahan(linkedList L);
int totalPengurangan(linkedList L);
long long totalPerkalian(linkedList L);

#endif
```

ListAngka.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

#define Nil NULL

// Fungsi untuk cek apakah list kosong
bool isEmpty(linkedList L) {
    return L.first == Nil;
}

// Pembuatan linked list kosong
void createList(linkedList &L) {
    L.first = Nil;
}

// Alokasi node baru
address alokasi(dataAngka x) {
    address nodeBaru = new node;
    nodeBaru->angka = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// Dealokasi node
void dealokasi(address &node) {
    delete node;
    node = Nil;
}

// Menampilkan isi list
void printList(linkedList L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) {
            cout << nodeBantu->angka << " - ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

// Insert node di awal
void insertFirst(linkedList &L, address nodeBaru) {
    nodeBaru->next = L.first;
    L.first = nodeBaru;
}

// Insert node di akhir
void insertLast(linkedList &L, address nodeBaru) {
    if (isEmpty(L)) {
        L.first = nodeBaru;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// Insert node setelah node tertentu
void insertAfter(linkedList &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    }
}

// Menghitung jumlah node
int nbList(linkedList L) {
    int count = 0;
    address nodeBantu = L.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// Delete node setelah node tertentu
void delAfter(linkedList &L, address nodeHapus, address nodePrev) {
    if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        dealokasi(nodeHapus);
    }
}

// Update data node pertama
void updateFirst(linkedList &L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        dataAngka newData;
        cout << "Masukkan update data node pertama : " << endl;
        cout << "masukkan angka : ";
        cin >> newData;
        L.first->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

// Update data node terakhir
void updateLast(linkedList &L) {
    if (isEmpty(L)) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        dataAngka newData;
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> newData;
        nodeBantu->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

// Update data node setelah node tertentu
void updateAfter(linkedList &L, address nodePrev) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeUpdate = nodePrev->next;
        dataAngka newData;
        cout << "masukkan update data node setelah node " << nodePrev->angka << " : " << endl;
        cout << "Masukkan angka : ";
        cin >> newData;
        nodeUpdate->angka = newData;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    } 
}

// Search berdasarkan data
void searchByData(linkedList L, dataAngka data) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->angka == data) {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        
        if (!found) {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

// Search berdasarkan alamat
void searchByAddress(linkedList L, address node) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        
        if (!found) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

// Search berdasarkan range 
void searchByRange(linkedList L, dataAngka nilaiMin) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        
        cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->angka > nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << nodeBantu->angka << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        
        if (!found) {
            cout << "Tidak ada data diatas nilai " << nilaiMin << "!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

// Operasi aritmetika - Penjumlahan
int totalPenjumlahan(linkedList L) {
    int total = 0;
    address nodeBantu = L.first;
    while (nodeBantu != Nil) {
        total += nodeBantu->angka;
        nodeBantu = nodeBantu->next;
    }
    return total;
}

// Operasi aritmetika - Pengurangan
int totalPengurangan(linkedList L) {
    if (isEmpty(L)) return 0;
    
    int total = L.first->angka;
    address nodeBantu = L.first->next;
    
    while (nodeBantu != Nil) {
        total -= nodeBantu->angka;
        nodeBantu = nodeBantu->next;
    }
    return total;
}

// Operasi aritmetika - Perkalian
long long totalPerkalian(linkedList L) {
    long long total = 1;
    address nodeBantu = L.first;
    while (nodeBantu != Nil) {
        total *= nodeBantu->angka;
        nodeBantu = nodeBantu->next;
    }
    return total;
}
```

main.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main(){
    linkedList L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = nullptr;
    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC);

    // update
    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);

    // searching
    searchByData(L, 20);
    searchByData(L, 55);
    searchByAddress(L, nodeB);
    searchByAddress(L, nodeA);
    searchByRange(L, 40);

    // Operasi aritmetika
    cout << "=== OPERASI ARITMETIKA ===" << endl;
    cout << "Total penjumlahan : " << totalPenjumlahan(L) << endl;
    cout << "Total pengurangan : " << totalPengurangan(L) << endl;
    cout << "Total perkalian : " << totalPerkalian(L) << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan5_Modul5/output/output3.png)

Penjelasan unguided 3
Pada bagian header file (ListAngka.h), terdapat dua struktur utama yaitu node dan linkedList. Struktur node berfungsi untuk menyimpan satu data integer (angka) dan pointer next yang menunjuk ke node berikutnya. Sedangkan struktur linkedList hanya memiliki satu atribut yaitu first yang menunjuk ke node pertama dalam list.

Pada bagian ListAngka.cpp, berisi implementasi dari fungsi-fungsi yang sudah dideklarasikan di header file.
Fungsi createList digunakan untuk membuat list kosong dengan mengatur pointer first menjadi NULL.
Fungsi alokasi digunakan untuk membuat node baru dan mengembalikannya ke alamat memori yang baru dialokasikan, sedangkan dealokasi digunakan untuk menghapus node agar tidak terjadi kebocoran memori.
Fungsi isEmpty digunakan untuk mengecek apakah list kosong atau tidak, dan printList digunakan untuk menampilkan seluruh isi list dari awal sampai akhir.
Selain operasi dasar, program ini juga memiliki fungsi untuk melakukan operasi aritmetika terhadap seluruh data dalam list.
1. totalPenjumlahan digunakan untuk menjumlahkan semua data.
2. totalPengurangan digunakan untuk menghitung hasil pengurangan secara berurutan dari node pertama hingga terakhir.
3. totalPerkalian digunakan untuk menghitung hasil perkalian semua nilai yang ada di dalam list

Pada bagian program utama (main.cpp), seluruh fungsi tersebut diujicobakan secara berurutan. Program dimulai dengan membuat list kosong, kemudian menambahkan beberapa data menggunakan fungsi insertFirst, insertLast, dan insertAfter. Selanjutnya dilakukan penghapusan data menggunakan delAfter, lalu menampilkan seluruh isi list dengan printList.
Setelah itu, program juga menampilkan proses pembaruan data, pencarian data berdasarkan nilai dan alamat, serta menampilkan hasil operasi aritmetika berupa penjumlahan, pengurangan, dan perkalian.

## Kesimpulan
Dari hasil implementasi ADT Singly Linked List pada program di atas dapat disimpulkan bahwa struktur data linked list memungkinkan pengelolaan data secara dinamis tanpa batasan ukuran tertentu seperti pada array. Dengan menggunakan pointer, setiap elemen (node) dapat dihubungkan secara fleksibel, sehingga operasi penambahan, penghapusan, dan pembaruan data dapat dilakukan dengan efisien tanpa perlu menggeser elemen lain.

Selain itu, implementasi prosedur seperti insertFirst, insertLast, insertAfter, dan delAfter menunjukkan bahwa manipulasi posisi data dalam list dapat dilakukan dengan mudah. Penambahan fitur update dan search memperluas kemampuan list untuk melakukan perubahan dan pencarian data secara spesifik, baik berdasarkan nilai, alamat, maupun rentang nilai tertentu.

Proses aritmetika terhadap seluruh elemen list (penjumlahan, pengurangan, dan perkalian) membuktikan bahwa linked list juga dapat digunakan untuk operasi numerik secara terstruktur. Dengan demikian, penggunaan ADT Singly Linked List memberikan efisiensi, fleksibilitas, dan kemudahan dalam pengelolaan data secara dinamis dalam pemrograman C++.

## Referensi
[1] Subhan, H. N., Effendi, H., Kumar, S., Marsino, W., Sitanggang, Y. R. U., Anwar, K., Santiani, N. P. L., Setyobowono, S., Sigar, T. R., Atho’illah, I., Setyantoro, D., & Smrti, N. N. E. (2023). Pengantar Struktur Data. Penerbit Mifand Mandiri. Diakses dari https://jurnal.mifandimandiri.com/index.php/penerbitmmd/article/view/39/33
[2] Tim Algoritma & Pemrograman IF. (2020). Algoritma & Pemrograman: Linked List. Universitas Komputer Indonesia (UNIKOM). Diakses dari https://repository.unikom.ac.id/35520/1/Linked%20List.pdf.
<br>...
