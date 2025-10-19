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

// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.First;
        L.First = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First->next == nullptr) {
        P = L.First;
        L.First = nullptr;
    } else {
        address Q = L.First;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

// Menghapus elemen setelah Prec
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

// Menghitung jumlah elemen list
int nbList(const List &L) {
    int count = 0;
    address P = L.First;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

// Menghapus seluruh isi list
void deleteList(List &L) {
    address P;
    while (L.First != nullptr) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}