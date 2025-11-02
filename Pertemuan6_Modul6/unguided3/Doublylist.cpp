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
