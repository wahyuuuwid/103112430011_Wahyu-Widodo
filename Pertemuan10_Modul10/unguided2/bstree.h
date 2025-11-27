#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;

typedef struct BST *node;

struct BST {
    infotype info;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(infotype angkaInput);
void insertNode(BinTree &tree, node nodeBaru);
void inOrder(BinTree tree);

int hitungJumlahNode(BinTree tree);
int hitungTotalInfo(BinTree tree);
int hitungKedalaman(BinTree tree);


#endif
