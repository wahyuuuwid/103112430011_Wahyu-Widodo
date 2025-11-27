# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA)</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Struktur data Tree (Pohon) didefinisikan sebagai pengorganisasian data yang bersifat hierarkis (bertingkat) dan non-linear. Berbeda dengan Array atau Linked List yang datanya berjejer lurus, Tree menyusun data berdasarkan hubungan induk (parent) dan anak (child). Terdapat istilah-istilah kunci untuk memahami struktur ini:
- Root (Akar): Simpul paling atas yang tidak memiliki induk (awal dari struktur).
- Parent (Induk): Simpul yang memiliki cabang atau anak di bawahnya (biasa disebut upline dalam kasus jaringan).
- Child (Anak): Simpul yang berada di bawah parent (biasa disebut downline).
- Leaf (Daun): Simpul yang berada di posisi paling bawah dan tidak memiliki anak lagi.[1]

BST adalah bentuk khusus dari Binary Tree yang memiliki sifat terurut. Struktur ini dirancang untuk mereduksi waktu pencarian data secara signifikan. Dalam jurnal ini dijelaskan bahwa efisiensi BST jauh melampaui pencarian linear biasa, terutama pada dataset yang besar (seperti data penduduk). Setiap simpul (parent) harus mematuhi logika berikut terhadap anak-anaknya:
- Anak Kiri (Left Child): Nilainya SELALU LEBIH KECIL dari nilai Parent.
- Anak Kanan (Right Child): Nilainya SELALU LEBIH BESAR dari nilai Parent.
Contoh: Jika Parent bernilai 10, maka anak kiri harus < 10 (misal: 5, 8) dan anak kanan harus > 10 (misal: 15, 20). Operasi standar pada BST:
- Insert: Memasukkan data baru dengan menelusuri pohon dari akar ke daun sesuai aturan "lebih kecil ke kiri, lebih besar ke kanan".
- Search: Menelusuri jalur spesifik untuk menemukan data.[2]

## Guided 

### 1. guided 1

```h
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ // nama struct nya BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BSTaa)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

```

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

Penjelasan guided 1
Pohon diinisialisasi menggunakan createTree() yang membuat root bernilai NULL. Ketika sebuah nilai baru ingin ditambahkan, fungsi insertNode() akan menempatkan node tersebut pada posisi yang sesuai menggunakan aturan BST, yaitu jika nilainya lebih kecil akan menuju subtree kiri, dan jika lebih besar akan menuju subtree kanan, hingga menemukan posisi kosong.

Program juga menyediakan fungsi pencarian data menggunakan searchByData(). Fungsi ini menelusuri tree seperti binary search sampai data ditemukan atau pohon habis ditelusuri. Jika data ditemukan, program menampilkan nilai node tersebut, parent-nya, sibling-nya, serta child kiri dan kanan. Untuk menampilkan isi tree, tersedia tiga metode traversal yaitu PreOrder, InOrder, dan PostOrder, semuanya dilakukan secara rekursif.

Penghapusan data dilakukan melalui deleteNode(), yang menangani tiga kondisi: node yang dihapus tidak memiliki child (leaf), node memiliki satu child, atau node memiliki dua child. Untuk node yang memiliki dua child, program mencari pengganti dengan mengambil node paling kiri dari subtree kanan (successor), lalu menyalin nilainya dan menghapus node successor tersebut. Program juga memiliki fungsi mostLeft() dan mostRight() untuk mendapatkan nilai terkecil dan terbesar dalam tree. Selain itu, ada fungsi size() yang menghitung jumlah node, dan height() yang menghitung tinggi tree dengan mencari level terdalam.

Program utama atau main menyediakan menu yang memungkinkan pengguna menambah node, menghapus node, mencari data, menampilkan traversal, menampilkan ukuran dan tinggi tree, melihat nilai terkecil atau terbesar, serta menghapus seluruh tree dengan deleteTree(). Seluruh operasi berlangsung sampai pengguna memilih keluar dari program.


## Unguided 

### 1. unguided 1
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file
“bstree.h”:
Type infotype: integer
Type address : pointer to Node
Type Node: <
info : infotype
left, right : address
>
function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address,
input x : infotype )
function findNode( x : infotype, root : address )→address
procedure printInorder( input root : address )
Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil
implementasi ADT pada file “main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
cout << "Hello World" << endl;
address root = Nil;
insertNode(root,1);
insertNode(root,2);
insertNode(root,6);
insertNode(root,4);
insertNode(root,5);
insertNode(root,3);
insertNode(root,6);
insertNode(root,7);
InOrder(root);
return 0;
}

```h
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

void createTree(BinTree &tree);
node alokasi(infotype angkaInput);
void insertNode(BinTree &tree, node nodeBaru);
void inOrder(BinTree tree);

#endif
```

```C++
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
```

```C++
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

    inOrder(root);

    cout << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan10_Modul10/output/output1.png)

Penjelasan unguided 1
Pada file bstree.h, didefinisikan sebuah struktur bernama BST yang merepresentasikan sebuah node dalam tree. Setiap node memiliki satu nilai (info) serta dua pointer left dan right yang menunjuk ke anak kiri dan anak kanan. Selain itu, disediakan tipe alias bernama node dan BinTree untuk memudahkan penggunaan pointer ke struktur BST. Tiga fungsi utama yang diimplementasikan adalah alokasi, insertNode, dan inOrder.

Pada file bstree.cpp, fungsi alokasi bertugas membuat node baru dengan nilai tertentu, mengisi child kiri dan kanan dengan NULL, lalu mengembalikan pointer node tersebut. Fungsi insertNode melakukan proses penyisipan node ke dalam tree dengan menerapkan aturan BST, yaitu nilai yang lebih kecil ditempatkan di subtree kiri dan nilai yang lebih besar ditempatkan di subtree kanan. Proses ini dilakukan secara rekursif hingga menemukan posisi yang kosong. Sedangkan fungsi inOrder digunakan untuk menampilkan seluruh nilai dalam tree menggunakan traversal inorder, yang mengunjungi subtree kiri terlebih dahulu, kemudian node saat ini, dan terakhir subtree kanan. Traversal ini menghasilkan urutan data yang sudah terurut dari kecil ke besar.

Pada file main.cpp, program dimulai dengan mencetak tulisan “Hello World” kemudian membuat sebuah tree yang awalnya bernilai NULL. Selanjutnya, node bernilai 1 hingga 7 dimasukkan satu per satu ke dalam tree menggunakan fungsi insertNode. Setelah semua node masuk, fungsi inOrder dipanggil untuk menampilkan isi tree. Karena traversal inorder menghasilkan data secara terurut, output yang ditampilkan adalah 1 2 3 4 5 6 7. Dengan demikian, program ini menunjukkan cara membangun tree, menambahkan node, dan menampilkan isi tree dengan benar menggunakan konsep Binary Search Tree.

### 2. unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer

```h
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
```

```C++
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

```

```C++
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

    inOrder(root);

    cout << endl;

    cout << "Kedalaman : " << hitungKedalaman(root) << endl;
    cout << "Jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "Total : " << hitungTotalInfo(root) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan10_Modul10/output/output2.png)

penjelasan unguided 2
Fungsi hitungJumlahNode digunakan untuk menghitung jumlah seluruh node yang ada pada sebuah Binary Search Tree (BST). Fungsi ini bekerja secara rekursif, di mana setiap kali dipanggil, fungsi akan menghitung 1 node (node saat ini), kemudian menambahkan hasil perhitungan node di subtree kiri dan subtree kanan.
Jika node bernilai NULL, maka fungsi mengembalikan angka 0 karena tidak ada node pada bagian tersebut.

Fungsi hitungTotalInfo bertugas menghitung total keseluruhan nilai (info) dari setiap node dalam tree.
Caranya adalah dengan menjumlahkan root->info dari node saat ini, lalu menambahkan hasil dari pemanggilan rekursif untuk subtree kiri dan subtree kanan. Jika root kosong (NULL), maka tidak ada nilai yang ditambahkan dan fungsi akan mengembalikan nilai awal (biasanya 0).

Fungsi hitungKedalaman digunakan untuk mencari kedalaman maksimal dari sebuah BST. Kedalaman (depth / height) adalah panjang jalur dari root hingga ke node leaf yang paling jauh. Fungsi memeriksa kedalaman subtree kiri dan kedalaman subtree kanan secara rekursif, lalu memilih kedalaman terbesar di antara keduanya, kemudian menambahkan 1 untuk menghitung level node saat ini.
Jika root adalah NULL, kedalamannya 0.

### 3. unguided 3
Print tree secara pre-order dan post-order.

```h
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

void preOrder(node tree);
void postOrder(node tree);

#endif

```

```C++
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
```

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan10_Modul10/output/output3.png)

Penjelasan unguided 3
Untuk menampilkan struktur pohon dalam berbagai urutan, program menambahkan traversal pre-order dan post-order. Fungsi preOrder mencetak node dengan urutan root, kiri, kanan sehingga struktur pohon dapat terlihat dari akar kemudian turun ke cabang-cabangnya. Sedangkan postOrder mencetak node dengan urutan kiri, kanan, root sehingga node akan ditampilkan setelah seluruh subtree-nya selesai diproses.

## Kesimpulan
Program ini mengimplementasikan Binary Search Tree (BST) menggunakan struktur node sederhana di C++. Melalui fungsi-fungsi seperti insertNode, inOrder, preOrder, dan postOrder, program dapat membangun tree, menambahkan data secara terurut, serta menampilkan isi tree dalam berbagai urutan traversal. Selain itu, fungsi tambahan untuk menghitung jumlah node, total nilai, dan kedalaman tree menunjukkan bahwa BST dapat dianalisis dengan mudah menggunakan rekursi. Secara keseluruhan, program ini menunjukkan bagaimana BST bekerja dalam menyimpan data secara terstruktur, melakukan pencarian yang efisien, dan menampilkan hasil traversal dengan berbagai metode untuk memahami bentuk dan isi tree.

## Referensi
[1] Implementasi Algoritma Binary Tree dan Sequential Searching pada Aplikasi Web Multilevel Marketing Penulis: Iyan Hadi Mulyana & Mohammad Rifqi Jurnal: Jurnal Informatika: Jurnal Pengembangan IT (JPIT), Vol. 5, No. 3 Tahun: 2020.
[2] Implementasi Teknik Binary Search Tree Pada Pencarian Data Penduduk Penulis: Emersen P. Malau & Hendra P. Sirait Jurnal: KAKIFIKOM (Kumpulan Artikel Karya Ilmiah Fakultas Ilmu Komputer), Vol. 03, No. 02 Tahun: 2021.
<br>...
