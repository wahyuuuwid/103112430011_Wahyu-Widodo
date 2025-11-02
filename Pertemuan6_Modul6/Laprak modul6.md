# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Berbeda dengan single linked list, pada double linked list setiap node memiliki rujukan pada node sebelumnya dan sesudahnya. Beberapa algoritma memerlukan double linked list, misalnya untuk melakukan proses sorting atau reverse traversing. Setiap elemen saling terhubung menggunakan dua pointer di dalam satu elemen. Struktur ini memungkinkan penelusuran dilakukan ke arah depan maupun ke belakang. Setiap elemen pada double linked list terdiri atas tiga bagian, yaitu data, pointer prev, dan pointer next. Setiap elemen memiliki pointer prev yang menunjuk ke elemen sebelumnya. Double linked list dibentuk dari sejumlah elemen yang saling terhubung, di mana pointer next menunjuk ke elemen berikutnya, dan pointer prev menunjuk ke elemen sebelumnya. Pointer prev dari elemen pertama bernilai NULL untuk menandai posisi head pada double linked list. Sedangkan pointer next dari elemen terakhir bernilai NULL untuk menunjukkan posisi tail dari double linked list tersebut.[1]

Senarai berantai ganda (Double Linked List) merupakan pengembangan dari senarai berantai tunggal, di mana proses navigasi data dapat dilakukan ke dua arah — baik maju maupun mundur — dengan lebih mudah dibandingkan dengan senarai berantai tunggal. Untuk memahami konsep Double Linked List atau senarai berantai ganda, berikut beberapa istilah penting yang digunakan:
1. Link – Setiap elemen dalam linked list memiliki sebuah tautan yang disebut element.
2. Next – Setiap elemen dalam linked list memiliki tautan ke elemen berikutnya yang disebut Next.
3. Prev – Setiap elemen juga memiliki tautan ke elemen sebelumnya yang disebut Prev.
4. Senarai Berantai – Struktur ini memiliki dua tautan utama: tautan pertama yang disebut First dan tautan terakhir yang disebut Last.[2]

## Guided 

### 1. guided 1

```h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

Penjelasan guided 1
Program ini medefinisikan beberapa struktur data dan deklarasi fungsi.
Pertama, terdapat struktur makanan yang berisi empat atribut, yaitu nama makanan, jenis makanan, harga, dan rating. Data ini digunakan untuk menyimpan informasi setiap makanan. Kemudian, dibuat struktur node yang mewakili satu elemen dalam linked list. Setiap node memiliki dua pointer, yaitu next untuk menunjuk ke node berikutnya dan prev untuk menunjuk ke node sebelumnya. Dengan adanya dua pointer ini, maka list disebut doubly linked list, karena dapat ditelusuri dari depan maupun dari belakang. Struktur linkedlist berfungsi sebagai penampung awal dan akhir list, dengan dua pointer utama, yaitu first dan last. Selain itu, pada program ini juga dideklarasikan fungsi-fungsi utama seperti membuat list baru, mengalokasikan dan menghapus node, menambahkan node di berbagai posisi (awal, akhir, sebelum, sesudah), mencetak seluruh isi list, serta memperbarui data pada node tertentu.

Pada listMakanan.cpp seluruh fungsi yang telah dideklarasikan sebelumnya diimplementasikan.
Fungsi createList digunakan untuk menginisialisasi list agar kosong, dengan mengatur first dan last menjadi NULL. Fungsi isEmpty memeriksa apakah list masih kosong atau tidak. Fungsi alokasi digunakan untuk membuat node baru secara dinamis menggunakan new. Di dalamnya, nilai atribut nama, jenis, harga, dan rating diisi, sedangkan pointer next dan prev diatur menjadi NULL. Sementara itu, fungsi dealokasi digunakan untuk menghapus node dari memori dengan delete.  Selain itu, terdapat juga empat fungsi untuk memperbarui data node:
1. updateFirst memperbarui data node pertama.
2. updateLast memperbarui data node terakhir.
3. updateAfter memperbarui data node yang berada setelah node tertentu.
4. updateBefore memperbarui data node yang berada sebelum node tertentu.
Keempat fungsi ini meminta input baru dari pengguna, kemudian mengganti data pada node yang bersangkutan.
Selanjutnya terdapat beberapa fungsi untuk menambahkan node ke dalam list:
1. insertFirst menambahkan node di awal list.
2. insertLast menambahkan node di akhir list.
3. insertAfter menambahkan node setelah node tertentu.
4. insertBefore menambahkan node sebelum node tertentu.

Di main.cpp sebagai program utama untuk menjalankan dan menguji fungsi-fungsi yang telah dibuat.
Pertama, program membuat sebuah list kosong dengan memanggil fungsi createList.
Kemudian, program membuat beberapa node berisi data makanan menggunakan fungsi alokasi, seperti “Nasi Rames”, “Ayam Geprek”, “Risol Mayo”, “Mie Ayam”, dan “Donat”.

Selanjutnya, program melakukan serangkaian operasi penyisipan node ke dalam list menggunakan berbagai cara:
1. Menyisipkan node di awal,
2. Menyisipkan di akhir,
3. Menyisipkan di antara node lain (setelah dan sebelum node tertentu).
4. Hasil akhir penyisipan membentuk urutan node: D – A – C – E – B.

### 2. guided 2

```h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```

Penjelasan guided 2
Bagian listMakanan.h mendefinisikan struktur dan fungsi yang akan digunakan dalam program.
Pertama, terdapat pengecekan #ifndef, #define, dan #endif untuk mencegah duplikasi ketika file header di-include lebih dari satu kali. Kemudian didefinisikan Nil sebagai pengganti NULL untuk menandai pointer kosong.Struktur makanan menyimpan informasi berupa nama, jenis, harga, dan rating. Selanjutnya, typedef makanan dataMakanan digunakan agar tipe data makanan dapat dipanggil dengan nama pendek dataMakanan. Struktur node berisi elemen isidata bertipe dataMakanan, serta dua pointer, yaitu next untuk menunjuk ke node berikutnya dan prev untuk menunjuk ke node sebelumnya. Inilah yang membuatnya menjadi doubly linked list.

Bagian  listMakanan.cpp berisi definisi lengkap dari fungsi-fungsi yang telah dideklarasikan di header.
1. Fungsi isEmpty() memeriksa apakah list kosong dengan mengecek apakah pointer first bernilai Nil.
2. Fungsi createList() menginisialisasi list baru dengan mengatur pointer first dan last ke Nil.
3. Fungsi alokasi() membuat node baru di memori menggunakan new, lalu mengisi datanya dengan nilai parameter yang diberikan. Pointer next dan prev diatur ke Nil.
4. Fungsi dealokasi() menghapus node dari memori dengan delete setelah pointer next dan prev diatur ke Nil agar tidak menggantung (dangling pointer).
Fungsi printList() menampilkan semua isi list dengan menelusuri pointer dari first hingga Nil, mencetak setiap elemen satu per satu. Fungsi update (updateFirst, updateLast, updateAfter, dan updateBefore) digunakan untuk mengubah isi data pada node tertentu. Program meminta input baru dari pengguna dan memperbarui nilai atributnya. Fungsi searching (findByName, findByJenis, dan findByMinRating) digunakan untuk mencari data tertentu dalam list. Pencarian dilakukan dengan menelusuri list dari awal hingga akhir, lalu menampilkan data yang cocok berdasarkan nama, jenis, atau rating minimal. Bagian penghapusan (delete) terdiri dari beberapa fungsi:
1. deleteFirst() menghapus node pertama.
2. deleteLast() menghapus node terakhir.
3. deleteAfter() menghapus node setelah node tertentu.
4. deleteBefore() menghapus node sebelum node tertentu.
5. deleteNode() menghapus node tertentu berdasarkan alamat node.
6. deleteByName() mencari node berdasarkan nama dan menghapusnya.

Di bagian utama, dibuat variabel linkedlist List untuk menyimpan keseluruhan list, dan beberapa pointer node (nodeA, nodeB, dst.) untuk mewakili elemen makanan. Pertama, list diinisialisasi dengan createList(List). Kemudian dibuat lima node baru menggunakan alokasi() berisi data makanan seperti "Nasi Rames", "Ayam Geprek", "Risol Mayo", "Mie Ayam", dan "Donat". Setelah itu, node-node tersebut disisipkan ke dalam list dengan berbagai variasi posisi:
insertFirst, insertLast, insertAfter, dan insertBefore. Setelah proses penyisipan, program mencetak seluruh isi list untuk menampilkan hasilnya. Kemudian dilakukan beberapa operasi update, misalnya mengubah data node pertama, terakhir, sebelum node tertentu, dan setelah node tertentu.
Program lalu menampilkan hasil list setelah update, melakukan pencarian data berdasarkan nama, dan menghapus beberapa node, baik berdasarkan nama maupun posisi (misalnya deleteFirst dan deleteBefore).

## Unguided 

### 1. unguided 1
 Buatlah implementasi ADTDoubly Linked list pada file “Doublylist.cpp” dan coba hasil
 implementasiADTpadafile“main.cpp”.

```h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// Deklarasi fungsi & prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printInfo(List L);

#endif
```

```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong!" << endl;
        return;
    }

    address P = L.First;
    cout << endl << "DATA LIST" << endl;
    while (P != Nil) {
        cout << "\nno polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

```

```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

bool nopolSudahAda(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);

    infotype data;
    int i = 0;

    while (i < 4) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        if (!nopolSudahAda(L, data.nopol)) {
            insertLast(L, alokasi(data));
        } else {
            cout << "Nomor Polisi Sudah Terdaftar" << endl;
        }

        cout << endl;

        i++; 
    }

    printInfo(L);
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan6_Modul6/output/output1.png)

Penjelasan unguided 1
Program ini menggunakan struktur data Doubly Linked List untuk menyimpan data kendaraan yang terdiri dari nomor polisi, warna kendaraan, dan tahun pembuatan. Pertama, program memanggil prosedur CreateList(L) untuk menginisialisasi list kosong.

Selanjutnya, program melakukan proses input sebanyak 4 kali. Pada setiap perulangan, pengguna diminta memasukkan data kendaraan berupa nomor polisi, warna kendaraan, dan tahun pembuatan. Setelah data dimasukkan, program akan memeriksa apakah nomor polisi yang dimasukkan sudah ada di dalam list dengan memanggil fungsi nopolSudahAda(L, data.nopol).

Jika nomor polisi belum terdaftar, data tersebut dialokasikan menjadi sebuah node baru dan dimasukkan ke bagian akhir list menggunakan fungsi insertLast(L, alokasi(data)). Namun jika nomor polisi sudah ada sebelumnya, maka program menampilkan pesan “Nomor Polisi Sudah Terdaftar” dan tidak menambahkan data ke list. Setelah proses input selesai untuk 4 kali, program menggunakan printInfo(L) untuk menampilkan seluruh data kendaraan yang berhasil dimasukkan ke dalam list. Terakhir, program selesai dan mengembalikan nilai 0.

### 2. unguided 2
 Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru.
 fungsi findElm( L : List, x : infotype ) : address

```h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// Deklarasi fungsi & prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
address findElm(List L, string nopol);
void printInfo(List L);

#endif
```

```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong!" << endl;
        return;
    }

    address P = L.First;
    cout << endl << "DATA LIST" << endl;
    while (P != Nil) {
        cout << "\nno polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    if (L.First == Nil) {
        return Nil;
    }
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

```

```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

bool nopolSudahAda(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);

    infotype data;
    int i = 0;

    while (i < 4) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        if (!nopolSudahAda(L, data.nopol)) {
            insertLast(L, alokasi(data));
        } else {
            cout << "Nomor Polisi Sudah Terdaftar" << endl;
        }

        cout << endl;

        i++; 
    }

    printInfo(L);

    string cari;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> cari;

    address hasil = findElm(L, cari);

    if (hasil != Nil) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
    
    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan6_Modul6/output/output2.png)

penjelasan unguided 2
Program ini menggunakan struktur data Doubly Linked List untuk menyimpan data kendaraan. Pada awal program, list diinisialisasi menjadi kosong dengan CreateList(L). Kemudian, program melakukan proses input sebanyak 4 kali. Pada setiap iterasi, pengguna diminta memasukkan nomor polisi, warna kendaraan, dan tahun pembuatan. Setelah data diinput, program memeriksa apakah nomor polisi tersebut sudah ada dalam list dengan memanggil fungsi nopolSudahAda(L, data.nopol). Jika nomor polisi belum terdaftar, maka data dialokasikan menjadi node baru dan dimasukkan ke bagian akhir list menggunakan insertLast(L, alokasi(data)). Namun jika nomor polisi sudah terdaftar, program menampilkan pesan bahwa nomor polisi sudah ada dan tidak menambahkan data tersebut ke dalam list.

Setelah selesai memasukkan data, program menampilkan seluruh isi list menggunakan printInfo(L). Kemudian, pengguna diminta memasukkan nomor polisi yang ingin dicari. Program melakukan pencarian data dengan memanggil fungsi findElm(L, cari). Jika data ditemukan, maka informasi lengkap kendaraan berupa nomor polisi, warna, dan tahun pembuatan ditampilkan. Namun jika data tidak ditemukan dalam list, program menampilkan pesan bahwa data tidak ada. Setelah semua proses selesai, program berakhir dan mengembalikan nilai 0.

### 3. unguided 3
 Hapus elemen dengan nomor polisi D003 dengan procedure delete.
procedure deleteFirst( input/output L : List,
 P : address )--
 procedure deleteLast( input/output L : List,
 P : address )
 procedure deleteAfter( input Prec : address,
 input/output P : address )

```h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// Deklarasi fungsi & prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address prev, address &P);
void deleteBefore(List &L, address nodeNext, address &P);
void printInfo(List L);

#endif

```

```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong!" << endl;
        return;
    }

    address P = L.First;
    cout << endl << "DATA LIST" << endl;
    while (P != Nil) {
        cout << "\nno polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    if (L.First == Nil) {
        return Nil;
    }
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = L.Last = Nil;
    } else {
        P = L.First;
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First == L.Last) {
        P = L.Last;
        L.First = L.Last = Nil;
    } else {
        P = L.Last;
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
    P->next = Nil;
}

void deleteAfter(List &L, address prev, address &P) {
    if (prev == Nil || prev->next == Nil) {
        P = Nil;
    } else if (prev->next == L.Last) {
        deleteLast(L, P);
    } else {
        P = prev->next;
        prev->next = P->next;
        P->next->prev = prev;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteBefore(List &L, address nodeNext, address &P) {
    if (nodeNext == Nil || nodeNext->prev == Nil) {
        P = Nil;
    } else if (nodeNext->prev == L.First) {
        deleteFirst(L, P);
    } else {
        P = nodeNext->prev;
        nodeNext->prev = P->prev;
        P->prev->next = nodeNext;
        P->next = Nil;
        P->prev = Nil;
    }
}

```

```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

bool nopolSudahAda(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);

    infotype data;
    address P;
    string cari, noPol;
    int i = 0;

    cout << "=== INPUT DATA KENDARAAN ===" << endl;
    while (i < 4) {
        cout << "Masukkan Nomor Polisi : ";
        cin >> data.nopol;
        cout << "Masukkan Warna Kendaraan : ";
        cin >> data.warna;
        cout << "Masukkan Tahun Kendaraan : ";
        cin >> data.thnBuat;

        if (!nopolSudahAda(L, data.nopol)) {
            insertLast(L, alokasi(data));
        } else {
            cout << "Nomor Polisi Sudah Terdaftar!" << endl;
        }

        cout << endl;
        i++;
    }

    cout << "\n=== DATA LIST KENDARAAN ===" << endl;
    printInfo(L);

    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> cari;
    P = findElm(L, cari);

    if (P != Nil) {
        cout << "\nNomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    cin >> noPol;
    P = findElm(L, noPol);

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(L, P->prev, P);
        }
        cout << "Data dengan nomor polisi " << noPol << " berhasil dihapus." << endl;
        dealokasi(P);
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    cout << "\n=== DATA LIST SETELAH DIHAPUS ===" << endl;
    printInfo(L);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan6_Modul6/output/output3.png)

Penjelasan unguided 3
Program ini menggunakan struktur data Doubly Linked List untuk menyimpan dan mengelola data kendaraan. Pertama, program menginisialisasi list kosong dengan CreateList(L). Kemudian dilakukan proses input sebanyak 4 kali, dimana pengguna diminta memasukkan nomor polisi, warna, dan tahun kendaraan. Setelah data dimasukkan, program memeriksa apakah nomor polisi sudah ada di dalam list menggunakan fungsi nopolSudahAda(). Jika belum ada, data akan dialokasikan menjadi node baru dan ditambahkan ke bagian akhir list dengan insertLast(). Jika sudah terdaftar sebelumnya, program menampilkan pesan bahwa nomor polisi sudah ada dan data tidak dimasukkan ke list.

Setelah proses input selesai, program menampilkan seluruh data kendaraan dalam list menggunakan printInfo(). Selanjutnya, pengguna diminta memasukkan nomor polisi untuk dilakukan pencarian data. Program memanggil fungsi findElm() dan apabila data ditemukan, informasi kendaraan ditampilkan. Namun jika node tidak ditemukan, program memberi informasi bahwa data tidak ada.

Kemudian program meminta nomor polisi kendaraan yang ingin dihapus dari list. Jika data ditemukan, maka dilakukan proses penghapusan node. Mekanisme penghapusan disesuaikan dengan posisi node dalam list: jika node merupakan elemen pertama maka digunakan deleteFirst(), jika merupakan elemen terakhir digunakan deleteLast(), dan jika berada di tengah digunakan deleteAfter(). Setelah node berhasil dihapus, program menampilkan pesan sukses dan melakukan dealokasi(P) untuk melepas memori node yang dihapus.

## Kesimpulan
Dengan mengimplementasikan struktur data Doubly Linked List kita bisa mengelola data kendaraan yang terdiri dari nomor polisi, warna kendaraan, dan tahun pembuatan. Program mampu melakukan beberapa operasi penting pada list, yaitu:
1. Menambahkan data kendaraan ke dalam list dengan pengecekan duplikasi nomor polisi.
2. Menampilkan seluruh data kendaraan yang tersimpan dalam list.
3. Mencari data berdasarkan nomor polisi yang diinput pengguna.
4. Menghapus data tertentu dari list sesuai posisi elemen (awal, tengah, atau akhir).
5. Menampilkan kembali data list setelah proses penghapusan sebagai pembuktian perubahan data.
Dengan demikian, program ini menunjukkan penggunaan Doubly Linked List secara efektif untuk proses penyimpanan, pencarian, dan penghapusan data dalam bentuk node yang saling terhubung secara dua arah.

## Referensi
[1] Buana, I. K. S., Nata, G. N. M., & Arnawa, I. B. K. S. (2018). Struktur Data. Yogyakarta: Penerbit ANDI.
[2] Tim Algoritma & Pemrograman IF. (2020). Algoritma & Pemrograman: Linked List. Universitas Komputer Indonesia (UNIKOM). Diakses dari https://repository.unikom.ac.id/35520/1/Linked%20List.pdf.
<br>...
