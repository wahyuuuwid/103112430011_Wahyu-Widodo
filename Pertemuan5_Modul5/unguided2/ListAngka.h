#ifndef LISTANGKA_H
#define LISTANGKA_H

typedef int dataAngka;
typedef struct node* address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedList L);
void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);
int nbList(linkedList L);
void delAfter(linkedList &L, address nodeHapus, address nodePrev);

// Procedure untuk update data
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

// Procedure untuk searching
void searchByData(linkedList L, dataAngka data);
void searchByAddress(linkedList L, address node);
void searchByRange(linkedList L, dataAngka nilaiMin);

#endif