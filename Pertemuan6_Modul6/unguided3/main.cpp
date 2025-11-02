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
