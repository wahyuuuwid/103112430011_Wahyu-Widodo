#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BinTree tree){
    return tree == Nil;
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int id, string nama, int stok){
    node newNode = new BSTProduk;
    newNode->idProduk = id;
    newNode->namaProduk = nama;
    newNode->stok = stok;
    newNode->left = newNode->right = Nil;
    return newNode;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        return;
    }
    if(nodeBaru->idProduk < tree->idProduk){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->idProduk > tree->idProduk){
        insertNode(tree->right, nodeBaru);
    }
}

void searchById(BinTree tree, int id){
    if(tree == Nil){
        cout << "Produk tidak ditemukan" << endl;
        return;
    }
    if(id < tree->idProduk){
        searchById(tree->left, id);
    } else if(id > tree->idProduk){
        searchById(tree->right, id);
    } else {
        cout << "Produk ditemukan!" << endl;
        cout << "ID    : " << tree->idProduk << endl;
        cout << "Nama  : " << tree->namaProduk << endl;
        cout << "Stok  : " << tree->stok << endl;
    }
}

void searchByProduct(BinTree tree, string nama){
    if(tree == Nil) return;

    searchByProduct(tree->left, nama);

    if(tree->namaProduk == nama){
        cout << "Produk ditemukan!" << endl;
        cout << "ID    : " << tree->idProduk << endl;
        cout << "Nama  : " << tree->namaProduk << endl;
        cout << "Stok  : " << tree->stok << endl;
    }

    searchByProduct(tree->right, nama);
}

void preOrder(BinTree tree){
    if(tree == Nil) return;
    cout << tree->idProduk << " ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil) return;
    inOrder(tree->left);
    cout << tree->idProduk << " ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil) return;
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->idProduk << " ";
}

node mostLeft(BinTree tree){
    while(tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

node mostRight(BinTree tree){
    while(tree->right != Nil){
        tree = tree->right;
    }
    return tree;
}

bool deleteNode(BinTree &tree, int id){
    if(tree == Nil) return false;

    if(id < tree->idProduk){
        return deleteNode(tree->left, id);
    } else if(id > tree->idProduk){
        return deleteNode(tree->right, id);
    } else {
        if(tree->left == Nil && tree->right == Nil){
            dealokasi(tree);
            tree = Nil;
        }
        else if(tree->left == Nil){
            node tmp = tree;
            tree = tree->right;
            dealokasi(tmp);
        }
        else if(tree->right == Nil){
            node tmp = tree;
            tree = tree->left;
            dealokasi(tmp);
        }
        else {
            node successor = mostLeft(tree->right);
            tree->idProduk = successor->idProduk;
            tree->namaProduk = successor->namaProduk;
            tree->stok = successor->stok;
            deleteNode(tree->right, successor->idProduk);
        }
        return true;
    }
}

void findMin(BinTree tree){
    if(tree == Nil){
        cout << "Tree kosong" << endl;
    } else {
        node min = mostLeft(tree);
        cout << "ID terkecil : " << min->idProduk << endl;
    }
}

void findMax(BinTree tree){
    if(tree == Nil){
        cout << "Tree kosong" << endl;
    } else {
        node max = mostRight(tree);
        cout << "ID terbesar : " << max->idProduk << endl;
    }
}

void deleteTree(BinTree &tree){
    if(tree == Nil) return;
    deleteTree(tree->left);
    deleteTree(tree->right);
    dealokasi(tree);
    tree = Nil;
}
