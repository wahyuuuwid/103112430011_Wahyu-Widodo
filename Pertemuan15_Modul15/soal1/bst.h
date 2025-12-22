#ifndef BST_H
#define BST_H
#define Nil NULL

#include <string>
using namespace std;

typedef struct BSTProduk *node;

struct BSTProduk {
    int idProduk;
    string namaProduk;
    int stok;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int id, string nama, int stok);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchById(BinTree tree, int id);
void searchByProduct(BinTree tree, string nama);

void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int id);
node mostLeft(BinTree tree);
node mostRight(BinTree tree);
void deleteTree(BinTree &tree);

void findMin(BinTree tree);
void findMax(BinTree tree);

#endif
