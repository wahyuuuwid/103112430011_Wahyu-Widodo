#include <iostream>
#include "bstree.h"
using namespace std;

bool isEmpty(BinTree tree) {
    if (tree == Nil) {
        return true;
    } else {
        return false;
    }
}

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

int hitungJumlahNode(BinTree tree) {
    if (tree == Nil) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(tree->left) + hitungJumlahNode(tree->right);
    }
}

int hitungTotalInfo(BinTree tree) {
    if (tree == Nil) {
        return 0;
    } else {
        return tree->info + hitungTotalInfo(tree->left) + hitungTotalInfo(tree->right);
    }
}

int hitungKedalaman(BinTree tree) {
    if (isEmpty(tree) == true) {
        return -1;
    } else {
        int hl = hitungKedalaman(tree->left);
        int hr = hitungKedalaman(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
}

void preOrder(node tree) {
    if (tree != NULL) {
        cout << tree->info << " - ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void postOrder(node tree) {
    if (tree != NULL) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->info << " - ";
    }
}
