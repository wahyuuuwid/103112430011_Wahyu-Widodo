#include "SLLInventory.h"

int main(){
    linkedlist List;
    address NodeA, NodeB, NodeC = Nil;
    createList(List);

    dataProduct dtProduct;
    NodeA = alokasi("Pulpen", "A001", 20, 2500, 0);
    NodeB = alokasi("Buku Tulis", "A002", 15, 5000, 0);
    NodeC = alokasi("Penghapus", "A003", 30, 10000, 0);

    insertLast(List, NodeA);
    insertLast(List, NodeB);
    insertLast(List, NodeC);

    cout << "=== Setelah INSERT ===" << endl; 
    viewList(List);
    cout << endl;

    // deleteFirst(List); 
    cout << "=== Setelah hapus ===" << endl;
    viewList(List);
    cout << endl;

    // updateAtPosition(List,2);
    cout << "=== setelah update ===" << endl;
    viewList(List);
    cout << endl
    
    searchingByFinalPrice(List, 2000, 7000);
    cout << "=== setelah searching ===" << endl;
    viewList(List);
    cout << endl;

    // b
    maxFinalPrice(List);
    cout << "=== setelah searching max final price ===" << endl;
    viewList(List);
    cout << endl;

    return 0;
}