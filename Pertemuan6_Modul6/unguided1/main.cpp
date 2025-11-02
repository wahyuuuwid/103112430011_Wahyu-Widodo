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
