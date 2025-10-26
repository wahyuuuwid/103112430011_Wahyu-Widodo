#include "ListAngka.h"
#include <iostream>
using namespace std;

int main(){
    linkedList L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = nullptr;
    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC);

    // update
    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);

    // searching
    searchByData(L, 20);
    searchByData(L, 55);
    searchByAddress(L, nodeB);
    searchByAddress(L, nodeA);
    searchByRange(L, 40);

    // Operasi aritmetika
    cout << "=== OPERASI ARITMETIKA ===" << endl;
    cout << "Total penjumlahan : " << totalPenjumlahan(L) << endl;
    cout << "Total pengurangan : " << totalPengurangan(L) << endl;
    cout << "Total perkalian : " << totalPerkalian(L) << endl;

    return 0;
}