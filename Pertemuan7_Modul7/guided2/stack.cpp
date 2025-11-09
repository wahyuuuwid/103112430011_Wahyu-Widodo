#include "stack.h"
#include <iostream>

using namespace std;

// Mengecek apakah stack kosong
bool isEmpty(stackTable s) {
    return s.top == -1;
}

// Mengecek apakah stack penuh
bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

// Membuat stack kosong
void createStack(stackTable &s) {
    s.top = -1;
}

// Menambahkan data ke stack (ke atas)
void push(stackTable &s, int angka) {
    if (isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

// Menghapus data dari stack (dari atas)
void pop(stackTable &s) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

// Mengubah data pada posisi tertentu (posisi 1 = paling atas)
void update(stackTable &s, int posisi) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        if (posisi <= 0) {
            cout << "Posisi tidak valid!" << endl;
        } else {
// Menghitung indeks array (0-based) dari posisi stack (1-based from top)
    int idx = s.top - (posisi - 1);

    if (idx < 0 || idx > s.top) {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    } else {
 cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
    }
        }
    }

    

   
}

// Menampilkan semua data di stack (dari atas ke bawah)
void view(stackTable s) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        for (int i = s.top; i >= 0; i--) {
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}

// Mencari data di dalam stack
void searchData(stackTable s, int data) {
    bool found = false;

    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Mencari data " << data << "..." << endl;
        int posisi = 1; // Posisi 1 adalah data paling atas

        for (int i = s.top; i >= 0; i--) {
            if (s.data[i] == data) {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                cout << endl;
                found = true;
                break;
            }
            posisi++;
        }
    }

    
    if (!found) {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}