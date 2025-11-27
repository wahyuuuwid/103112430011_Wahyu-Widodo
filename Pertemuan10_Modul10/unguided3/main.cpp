#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    BinTree root = Nil;

    insertNode(root, alokasi(1));
    insertNode(root, alokasi(2));
    insertNode(root, alokasi(3));
    insertNode(root, alokasi(4));
    insertNode(root, alokasi(5));
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(7));

    cout << "In-Order   : ";
    inOrder(root);

    cout << "\nPre-Order  : ";
    preOrder(root);

    cout << "\nPost-Order : ";
    postOrder(root);

    cout << endl;

    cout << "Kedalaman : " << hitungKedalaman(root) << endl;
    cout << "Jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "Total : " << hitungTotalInfo(root) << endl;

    return 0;
}
