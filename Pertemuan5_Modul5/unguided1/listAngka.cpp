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