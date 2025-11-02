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
