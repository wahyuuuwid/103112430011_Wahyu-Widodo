#include <iostream>
#include "bst.h"

using namespace std;

int main(){
    BinTree tree;
    createTree(tree);

    insertNode(tree, alokasi(50,"Monitor LED",10));
    insertNode(tree, alokasi(30,"Keyboard RGB",20));
    insertNode(tree, alokasi(70,"Mouse Gaming",15));
    insertNode(tree, alokasi(20,"Kabel HDMI",50));
    insertNode(tree, alokasi(40,"Headset 7.1",12));
    insertNode(tree, alokasi(60,"Webcam HD",8));
    insertNode(tree, alokasi(80,"Speaker BT",5));

    cout << "InOrder   : "; inOrder(tree); cout << endl;
    cout << "PreOrder  : "; preOrder(tree); cout << endl;
    cout << "PostOrder : "; postOrder(tree); cout << endl;

    cout << endl;
    searchById(tree, 40);
    searchById(tree, 99);

    cout << endl;
    searchByProduct(tree, "Webcam HD");
    searchByProduct(tree, "Printer");

    cout << endl;
    findMin(tree);
    findMax(tree);

    cout << "\nHapus ID 20\n";
    deleteNode(tree, 20);
    inOrder(tree); cout << endl;

    cout << "\nHapus ID 30\n";
    deleteNode(tree, 30);
    inOrder(tree); cout << endl;

    cout << "\nHapus ID 50\n";
    deleteNode(tree, 50);
    inOrder(tree); cout << endl;

    cout << "\nDelete Tree\n";
    deleteTree(tree);

    cout << "\nInOrder   : ";
    inOrder(tree);

    return 0;
}
