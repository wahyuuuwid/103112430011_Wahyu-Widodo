#include "DLLPlaylist.h"

int main(){
    linkedlist List;
    address NodeA, NodeB, NodeC = Nil;
    createList(List);

    dataPlaylist dtPlayList;
    NodeA = alokasi("Senja dikota", "Nona Band", 210, 150, 4.2);
    NodeB = alokasi("Langkahmu", "Delta", 185, 320, 4.8);
    NodeC = alokasi("Hujan Minggu", "Arka", 240, 90, 3.9);

    insertLast(List, NodeA);
    insertLast(List, NodeB);
    insertLast(List, NodeC);

    cout << "=== Setelah INSERT ===" << endl;
    viewList(List);
    cout << endl;

    cout << "=== Setelah hapus ===" << endl;
    // deleteLast(List);
    viewList(List);
    cout << endl;

    cout << "=== Setelah update ===" << endl;
    updateAtPosition(List, 2);
    viewList(List);
    cout << endl;

    cout << "Setelah insert Before ===" << endl;
    insertBefore(List, NodeA, NodeC);
    viewList(List);
    cout << endl;

    cout << "Setelah update before === " << endl;
    updateBefore(List, NodeC);
    viewList(List);
    cout << endl;

    cout << "setelah delete before === " << endl;
    deleteBefore(List, NodeC);
    viewList(List);
    cout << endl;

    searchingbyPopularityScore(List, 150.0, 300.0);

    return 0;
}