#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#define Nil NULL

#include <iostream>
using namespace std;

struct product{
    string Nama, SKU;
    int Jumlah;
    double HargaSatuan, DiskonPersen;
};

typedef product dataProduct;
typedef struct node *address;

struct node{
    dataProduct info;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string SKU, int jumlah, float HargaSatuan, float DiskonPersen);
void dealokasi(address &node);

void insertLast(linkedlist &List, address nodeBaru);
void deleteFirst(linkedlist &List);

void updateAtPosition(linkedlist &List, int posisi);
void searchingByFinalPrice(linkedlist list, float minPrice, float maxPrice);
void viewList(linkedlist List);

// b
void maxFinalPrice(linkedlist &List);

#endif