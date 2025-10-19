#include "Singlylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = nullptr;
}

// Mengalokasikan elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

// Dealokasi elemen
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Menampilkan seluruh elemen list
void printInfo(const List &L) {
    address P = L.First;
    cout << "Isi List: ";
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Menyisipkan elemen di awal list
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
