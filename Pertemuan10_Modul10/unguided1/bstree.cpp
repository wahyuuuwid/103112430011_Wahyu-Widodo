#include <iostream>
#include "bstree.h"
using namespace std;

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(infotype angkaInput) {
    node nodeBaru = new BST;
    nodeBaru->info = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(BinTree &tree, node nodeBaru) {
    if (tree == Nil) {
        tree = nodeBaru;
    } else if (nodeBaru->info < tree->info) {
        insertNode(tree->left, nodeBaru);
    } else if (nodeBaru->info > tree->info) {
        insertNode(tree->right, nodeBaru);
    }
}

void inOrder(BinTree tree) {
    if (tree != Nil) {
        inOrder(tree->left);
        cout << tree->info << " - ";
        inOrder(tree->right);
    }
}
