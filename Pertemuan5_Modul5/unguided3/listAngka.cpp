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