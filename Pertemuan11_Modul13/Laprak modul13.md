# <h1 align="center">Laporan Praktikum Modul 13 - Multi-Linked List</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Multi Linked List (Senarai Berkait Majemuk) adalah variasi dari struktur data Linked List di mana setiap node (simpul) memiliki lebih dari satu variabel pointer (penunjuk). Jika pada Single Linked List sebuah node hanya menunjuk ke node berikutnya, dan pada Doubly Linked List menunjuk ke node sebelum dan sesudah secara linear, maka pada Multi Linked List, pointer-pointer tersebut digunakan untuk menghubungkan node dalam berbagai dimensi logis yang berbeda.

Struktur ini memungkinkan terbentuknya relasi data yang kompleks, seperti relasi Many-to-Many (banyak ke banyak), struktur Grid (matriks), atau Graph.[1]

Kelebihan:
    - Efisien dalam penggunaan memori untuk data yang memiliki hubungan kompleks tetapi jarang (sparse), dibandingkan menggunakan Array multidimensi yang harus mengalokasikan memori untuk sel kosong.
    - Fleksibel dalam penambahan dan penghapusan data di tengah struktur tanpa perlu menggeser elemen lain (karakteristik dasar linked list).
Kekurangan:
    - Kompleksitas algoritma yang tinggi (terutama saat traversal, penyisipan, dan penghapusan node yang harus memperbarui banyak pointer sekaligus).
    - Overhead memori tambahan untuk menyimpan variabel pointer di setiap node.

Representasi
Dalam kasus relasi Mahasiswa dan Mata Kuliah:
- List Horizontal: Merepresentasikan seorang mahasiswa yang mengambil banyak mata kuliah.
- List Vertikal: Merepresentasikan satu mata kuliah yang diambil oleh banyak
- Setiap node di tengah adalah titik temu yang menghubungkan data mahasiswa tertentu dengan mata kuliah tertentu.[2]

## Guided 

### 1. guided 1

```h
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        bool ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

Penjelasan guided 1
Pertama, program mendefinisikan dua struktur data utama, yaitu DataMakanan dan KategoriMakanan. Struktur DataMakanan menyimpan informasi makanan seperti ID makanan, nama makanan, dan harga. Sementara itu, struktur KategoriMakanan menyimpan ID kategori dan nama kategorinya.

Setelah itu ditentukan dua tipe pointer, yaitu NodeParent dan NodeChild, yang masing-masing menunjuk pada struktur node parent dan node child. Node child menyimpan data makanan dan memiliki pointer next dan prev, karena list anak menggunakan double linked list. Node parent menyimpan data kategori, memiliki pointer next dan prev, serta menyimpan satu list anak melalui variabel L_Anak. List parent dan list anak masing-masing juga memiliki struktur list (listInduk dan listAnak) yang menyimpan pointer ke elemen pertama dan terakhir dari list tersebut.

Program menyediakan fungsi untuk mengecek apakah list parent atau list anak dalam keadaan kosong. Fungsi createListInduk() dan createListAnak() digunakan untuk menginisialisasi list dengan mengatur pointer first dan last menjadi NULL.

Untuk membuat node baru, program menyediakan fungsi alokasi. Pada fungsi alokasiNodeParent(), dibuat sebuah node parent baru, diisi data kategori, dan pointer-nya diinisialisasi dengan NULL. Fungsi ini juga memanggil createListAnak() agar setiap parent langsung memiliki list anak yang siap digunakan. Sedangkan alokasiNodeChild() membuat node child baru dengan mengisi informasi makanan dan mengatur pointer awalnya menjadi NULL. Terdapat pula fungsi dealokasi yang akan menghapus node parent atau node child dari memori selepas tidak lagi digunakan.

Selanjutnya terdapat serangkaian fungsi operasi untuk manipulasi node parent pada list induk. Fungsi insertFirstParent() menambahkan parent baru ke posisi pertama dari list induk, sedangkan insertLastParent() menambahkannya di posisi terakhir. Fungsi insertAfterParent() menyisipkan node parent baru setelah node parent tertentu. Untuk penghapusan, terdapat fungsi deleteFirstParent(), deleteLastParent(), dan deleteAfterParent(). Setiap kali sebuah parent dihapus, seluruh list anak yang berada di bawah parent tersebut juga ikut dihapus melalui pemanggilan hapusListAnak().

Program juga menyediakan fungsi pencarian dan update berdasarkan ID kategori. Fungsi findParentByID() akan menelusuri list induk dan menampilkan informasi jika ID ditemukan. Sedangkan updateDataParentByID() mengubah nama kategori yang sesuai dengan ID tertentu.

Untuk operasi pada node child, tersedia fungsi serupa dengan parent. Fungsi insertFirstChild() dan insertLastChild() digunakan untuk menambahkan data makanan sebagai node child ke posisi awal dan akhir dari list anak. Fungsi insertAfterChild() menyisipkan child setelah node tertentu. Program juga menyediakan fungsi untuk menghapus child dari awal, akhir, maupun setelah node tertentu.
Selain itu terdapat fungsi findChildByID() yang menelusuri seluruh parent dan anak untuk menemukan data makanan berdasarkan ID. Ketika ditemukan, program menampilkan detail child beserta parent tempatnya berada. Fungsi updateDataChildByID() memungkinkan perubahan nama makanan dan harga berdasarkan ID child.

Untuk menampilkan isi struktur Multi Linked List secara lengkap, fungsi printStrukturMLL() mencetak seluruh parent beserta seluruh anak di bawahnya. Jika hanya ingin menampilkan daftar parent saja, digunakan printListInduk(). Sedangkan fungsi printListAnak() digunakan untuk menampilkan semua node child dari parent tertentu.

Terakhir, terdapat fungsi hapusListInduk() dan hapusListAnak() yang berfungsi menghapus seluruh elemen pada kedua list tersebut sehingga struktur kembali kosong.


## Unguided 

### 1. unguided 1
Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
Type Struct golonganHewan <
 idGolongan : String
 namaGolongan : String
>
Type Struct dataHewan < 
 idHewan : String
 namaHewan : String
 habitat : String
 ekor : Boolean //TRUE jika berekor, FALSE jika tidak berekor
 bobot : float //dalam kg
>
typedef struct nodeParent *NodeParent; //alias pointer ke struct 
 nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct 
 nodeChild
Type Struct nodeChild <
 isidata : dataHewan
 next : NodeChild
 prev : NodeChild
>
Type Struct listChild <
 first : NodeChild 
 last : NodeChild
>
Type Struct nodeParent <
 isidata : golonganHewan
 next : NodeParent
 prev : NodeParent
 L_Child : listChild
>
Type Struct listParent <
 first : NodeParent
 last : NodeParent
>
Function isEmptyParent(input/output LParent : listParent) : Boolean
Function isEmptyChild(input/output LChild : listChild) : Boolean
Procedure createListParent(input/output LParent : listParent)
Procedure createListChild(input/output LChild : listChild)
Function allocNodeParent(input idGol : String, namaGol : String) : NodeParent
Function allocNodeChild(input idHwn : String, namaHwn : String, habitat : 
String, tail : Boolean, weight : float) : NodeChild
Procedure deallocNodeParent(input/output NParent : NodeParent)
Procedure deallocNodeChild(input/output NChild : NodeChild)
Procedure insertFirstParent(input/output LParent : listParent, newNParent : 
NodeParent)
Procedure insertLastParent(input/output LParent : listParent, newNParent : 
NodeParent)
Procedure deleteFirstParent(input/output LParent : listParent)
Procedure deleteAfterParent(input/output LParent : listParent, NPrev : 
NodeParent)
Procedure insertFirstChild(input/output LChild : listChild, newNChild : 
NodeChild)
Procedure insertLastChild(input/output LChild : listChild, newNChild : 
NodeChild)
Procedure deleteFirstChild(input/output LChild : listChild)
Procedure deleteAfterChild(input/output LChild : listChild, NPrev : NodeChild)
Procedure printMLLStructure(input/output LParent : listParent)
Procedure deleteListChild(input/output LChild : listChild)
Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”.
2
3
Kemudian pada file “main.cpp” lakukan operasi INSERT sebagaimana sehingga bentuk 
dari multi linked listnya seperti ini :
Keterangan isi data setiap node :
❖ List Parent : 
1) idGolongan : G001
namaGolongan : Aves
2) idGolongan : G002
namaGolongan : Mamalia
3) idGolongan : G003
namaGolongan : Pisces
4) idGolongan : G004
namaGolongan : Amfibi
5) idGolongan : G005
namaGolongan : Reptil
❖ List Child G001 : 
1) idHewan : AV001
namaHewan : Cendrawasih
habitat : Hutan
ekor : True
bobot : 0,3
2) idHewan : AV002
namaHewan : Bebek
habitat : Air
ekor : True
bobot : 2
❖ List Child G002 : 
1) idHewan : M001
namaHewan : Harimau
habitat : Hutan
ekor : True
bobot : 200
2) idHewan : M003
namaHewan : Gorila
habitat : Hutan
ekor : False
bobot : 160
3) idHewan : M002
namaHewan : Kucing
habitat : Darat
ekor : True
bobot : 4
❖ List Child G004 : 
1) idHewan : AM001
namaHewan : Kodok
habitat : Sawah
ekor : False
bobot : 0,2
Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur 
printMLLStructure().

```h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

#endif

```

```C++
#include "MultiLL.h"

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP->isidata.idGolongan = idGol;
    NP->isidata.namaGolongan = namaGol;
    NP->next = NP->prev = NULL;
    createListChild(NP->L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC->isidata.idHewan = idHwn;
    NC->isidata.namaHewan = namaHwn;
    NC->isidata.habitat = habitat;
    NC->isidata.ekor = tail;
    NC->isidata.bobot = weight;
    NC->next = NC->prev = NULL;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    if (NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if (NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;
    NodeParent nodeHapus = LParent.first;
    if (LParent.first == LParent.last) {
        LParent.first = LParent.last = NULL;
    } else {
        LParent.first = LParent.first->next;
        LParent.first->prev = NULL;
        nodeHapus->next = NULL;
    }
    if (!isEmptyChild(nodeHapus->L_Child)) {
        deleteListChild(nodeHapus->L_Child);
    }
    deallocNodeParent(nodeHapus);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent) || NPrev == NULL) return;
    NodeParent nodeHapus = NPrev->next;
    if (nodeHapus == NULL) return;
    NPrev->next = nodeHapus->next;
    if (nodeHapus->next != NULL) {
        nodeHapus->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    nodeHapus->next = NULL;
    if (!isEmptyChild(nodeHapus->L_Child)) {
        deleteListChild(nodeHapus->L_Child);
    }
    deallocNodeParent(nodeHapus);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;
    NodeChild nodeHapus = LChild.first;
    if (LChild.first == LChild.last) {
        LChild.first = LChild.last = NULL;
    } else {
        LChild.first = LChild.first->next;
        LChild.first->prev = NULL;
        nodeHapus->next = NULL;
    }
    deallocNodeChild(nodeHapus);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild) || NPrev == NULL) return;
    NodeChild nodeHapus = NPrev->next;
    if (nodeHapus == NULL) return;
    NPrev->next = nodeHapus->next;
    if (nodeHapus->next != NULL) {
        nodeHapus->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }
    nodeHapus->next = NULL;
    deallocNodeChild(nodeHapus);
}

void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List parent kosong!" << endl;
        return;
    }

    NodeParent np = LParent.first;
    int idxP = 1;
    while (np != NULL) {
        cout << "=== Parent " << idxP << " ===" << endl;
        cout << "ID Golongan : " << np->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << np->isidata.namaGolongan << endl;

        NodeChild nc = np->L_Child.first;
        if (nc == NULL) {
            cout << "  (tidak ada child)" << endl;
        } else {
            int idxC = 1;
            while (nc != NULL) {
                cout << "  - Child " << idxC << " :" << endl;
                cout << "      ID Hewan : " << nc->isidata.idHewan << endl;
                cout << "      Nama Hewan : " << nc->isidata.namaHewan << endl;
                cout << "      Habitat : " << nc->isidata.habitat << endl;
                cout << "      Ekor : " << (nc->isidata.ekor ? "True" : "False") << endl;
                cout << "      Bobot : " << nc->isidata.bobot << " kg" << endl;
                nc = nc->next;
                idxC++;
            }
        }
        cout << "---------------------------" << endl;
        np = np->next;
        idxP++;
    }
}

void deleteListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while (nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

```

```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);

    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);

    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);

    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);

    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C_AV1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f);
    insertLastChild(P1->L_Child, C_AV1);
    NodeChild C_AV2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0f);
    insertLastChild(P1->L_Child, C_AV2);

    NodeChild C_M1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f);
    insertLastChild(P2->L_Child, C_M1);
    NodeChild C_M3 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f);
    insertLastChild(P2->L_Child, C_M3);
    NodeChild C_M2 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0f);
    insertLastChild(P2->L_Child, C_M2);

    NodeChild C_AM1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f);
    insertLastChild(P4->L_Child, C_AM1);

    cout << "=== HASIL PRINT MLL STRUCTURE ===" << endl;
    printMLLStructure(LP);

    return 0;
}
```


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan11_Modul13/output/output1.png)

Penjelasan unguided 1
Pertama, program mendefinisikan dua struktur data utama, yaitu golonganHewan dan dataHewan. Struktur golonganHewan menyimpan ID golongan serta nama golongan seperti Aves, Mamalia, dan sebagainya. Sementara itu, struktur dataHewan menyimpan data detail mengenai hewan, yaitu ID hewan, nama hewan, habitatnya, status memiliki ekor atau tidak, dan bobot tubuh dalam kilogram.

Untuk merepresentasikan relasi antar data, program menggunakan dua jenis node, yaitu nodeParent dan nodeChild. Node parent menyimpan data golongan hewan beserta pointer next dan prev untuk menghubungkannya dengan parent lain dalam list dua arah. Selain itu, setiap node parent memiliki satu komponen bernama L_Child yang merupakan sebuah list anak, yaitu list double linked list yang akan berisi seluruh hewan yang masuk dalam golongan tersebut. Node child memiliki struktur serupa, tetapi menyimpan informasi hewan, dan memiliki pointer next serta prev sebagai pembentuk double linked list.

Untuk memudahkan penggunaan, program menyediakan dua struktur list utama, yaitu listParent yang menyimpan pointer ke parent pertama dan terakhir, dan listChild yang menyimpan pointer ke child pertama dan terakhir di dalam suatu parent.

Program menyediakan fungsi untuk mengecek apakah sebuah list kosong. Fungsi isEmptyParent() akan mengembalikan nilai true jika list parent tidak memiliki elemen, sedangkan isEmptyChild() melakukan pengecekan yang sama pada list anak. Sebelum digunakan, list harus diinisialisasi melalui createListParent() dan createListChild(), yang akan mengatur pointer first dan last menjadi NULL.

Untuk menambahkan elemen, program menyediakan fungsi alokasi. Fungsi allocNodeParent() membuat node parent baru dengan mengisi ID golongan dan nama golongan, menginisialisasi pointer next dan prev menjadi NULL, serta memanggil createListChild() sehingga parent tersebut langsung memiliki list anak yang kosong. Fungsi allocNodeChild() membuat node child baru dengan mengisi data hewan secara lengkap dan juga menginisialisasi pointer next dan prev menjadi NULL.

Program menyediakan fungsi untuk menghapus atau “dealokasi” node parent maupun node child ketika tidak lagi digunakan, meskipun dalam implementasi C++ penghapusan dilakukan dengan menggunakan operator delete.

Untuk memanipulasi list parent, terdapat prosedur seperti insertFirstParent() yang menambahkan node parent ke posisi paling awal di list, insertLastParent() yang menambahkannya ke posisi paling akhir, dan deleteFirstParent() yang menghapus node parent dari posisi awal list. Prosedur deleteAfterParent() menghapus node parent yang berada setelah node tertentu. Ketika sebuah parent dihapus, list anak yang berada di bawah kategori tersebut juga dihapus melalui pemanggilan deleteListChild().

Untuk list child, prosedur insertFirstChild() menambah node child di awal list anak, sedangkan insertLastChild() menambahkannya ke akhir list. Prosedur deleteFirstChild() dan deleteAfterChild() digunakan untuk menghapus elemen pertama anak atau elemen setelah node tertentu.

Setelah seluruh operasi insert dilakukan, program menyediakan satu prosedur khusus bernama printMLLStructure() yang bertugas mencetak seluruh isi struktur multi linked list. Prosedur ini mencetak setiap parent beserta seluruh data hewan yang berada dalam list anaknya. Jika suatu parent tidak memiliki anak sama sekali, prosedur tetap mencetak parent tersebut dan memberikan informasi bahwa list anak untuk parent tersebut kosong.


### 2. unguided 2
Tambahkan prosedur searchHewanByEkor(input/output LParent : 
listParent, input tail : Boolean) yang digunakan untuk melakukan operasi 
SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan
menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil 
prosedur tersebut pada main.cpp.

```h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif

```

```C++
#include "MultiLL.h"

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP->isidata.idGolongan = idGol;
    NP->isidata.namaGolongan = namaGol;
    NP->next = NP->prev = NULL;
    createListChild(NP->L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC->isidata.idHewan = idHwn;
    NC->isidata.namaHewan = namaHwn;
    NC->isidata.habitat = habitat;
    NC->isidata.ekor = tail;
    NC->isidata.bobot = weight;
    NC->next = NC->prev = NULL;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    if (NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if (NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;
    NodeParent nodeHapus = LParent.first;
    if (LParent.first == LParent.last) {
        LParent.first = LParent.last = NULL;
    } else {
        LParent.first = LParent.first->next;
        LParent.first->prev = NULL;
        nodeHapus->next = NULL;
    }
    if (!isEmptyChild(nodeHapus->L_Child)) {
        deleteListChild(nodeHapus->L_Child);
    }
    deallocNodeParent(nodeHapus);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent) || NPrev == NULL) return;
    NodeParent nodeHapus = NPrev->next;
    if (nodeHapus == NULL) return;
    NPrev->next = nodeHapus->next;
    if (nodeHapus->next != NULL) {
        nodeHapus->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    nodeHapus->next = NULL;
    if (!isEmptyChild(nodeHapus->L_Child)) {
        deleteListChild(nodeHapus->L_Child);
    }
    deallocNodeParent(nodeHapus);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;
    NodeChild nodeHapus = LChild.first;
    if (LChild.first == LChild.last) {
        LChild.first = LChild.last = NULL;
    } else {
        LChild.first = LChild.first->next;
        LChild.first->prev = NULL;
        nodeHapus->next = NULL;
    }
    deallocNodeChild(nodeHapus);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild) || NPrev == NULL) return;
    NodeChild nodeHapus = NPrev->next;
    if (nodeHapus == NULL) return;
    NPrev->next = nodeHapus->next;
    if (nodeHapus->next != NULL) {
        nodeHapus->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }
    nodeHapus->next = NULL;
    deallocNodeChild(nodeHapus);
}

void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List parent kosong!" << endl;
        return;
    }

    NodeParent np = LParent.first;
    int idxP = 1;
    while (np != NULL) {
        cout << "=== Parent " << idxP << " ===" << endl;
        cout << "ID Golongan : " << np->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << np->isidata.namaGolongan << endl;

        NodeChild nc = np->L_Child.first;
        if (nc == NULL) {
            cout << "  (tidak ada child)" << endl;
        } else {
            int idxC = 1;
            while (nc != NULL) {
                cout << "  - Child " << idxC << " :" << endl;
                cout << "      ID Hewan : " << nc->isidata.idHewan << endl;
                cout << "      Nama Hewan : " << nc->isidata.namaHewan << endl;
                cout << "      Habitat : " << nc->isidata.habitat << endl;
                cout << "      Ekor : " << (nc->isidata.ekor ? "True" : "False") << endl;
                cout << "      Bobot : " << nc->isidata.bobot << " kg" << endl;
                nc = nc->next;
                idxC++;
            }
        }
        cout << "---------------------------" << endl;
        np = np->next;
        idxP++;
    }
}

void deleteListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while (nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "List parent kosong, pencarian tidak bisa dilakukan.\n";
        return;
    }

    NodeParent P = LParent.first;
    int idxParent = 1;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int idxChild = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
            cout << "Data ditemukan pada list anak dari node parent "
            << P->isidata.namaGolongan << " pada posisi ke-" << idxParent << endl;
                cout << "== Data Child ==" << endl;
                cout << "ID Child  : " << C->isidata.idHewan << endl;
                cout << "Nama Hewan: " << C->isidata.namaHewan << endl;
                cout << "Habitat   : " << C->isidata.habitat << endl;
                cout << "Ekor      : " << (C->isidata.ekor ? "True" : "False") << endl;
                cout << "Bobot     : " << C->isidata.bobot << endl;
                cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent   : " << P->isidata.idGolongan << endl;
                cout << "Nama Parent : " << P->isidata.namaGolongan << endl << endl;
            }
            C = C->next;
            idxChild++;
        }


        P = P->next;
        idxParent++;
    }
}

```

```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);

    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);

    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);

    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);

    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C_AV1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f);
    insertLastChild(P1->L_Child, C_AV1);
    NodeChild C_AV2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0f);
    insertLastChild(P1->L_Child, C_AV2);

    NodeChild C_M1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f);
    insertLastChild(P2->L_Child, C_M1);
    NodeChild C_M3 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f);
    insertLastChild(P2->L_Child, C_M3);
    NodeChild C_M2 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0f);
    insertLastChild(P2->L_Child, C_M2);

    NodeChild C_AM1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f);
    insertLastChild(P4->L_Child, C_AM1);

    searchHewanByEkor(LP, false);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan11_Modul13/output/output2.png)

penjelasan unguided 2
Prosedur searchHewanByEkor() dibuat untuk melakukan pencarian hewan berdasarkan status ekornya, yaitu apakah hewan tersebut memiliki ekor atau tidak. Pencarian dilakukan dengan menelusuri seluruh parent yang ada pada list parent, kemudian pada setiap parent, prosedur menelusuri seluruh child yang termasuk ke dalam golongan hewan tersebut. Seluruh child yang memiliki nilai atribut ekor sesuai parameter pencarian (TRUE atau FALSE).

Pertama, prosedur memulai proses penelusuran mulai dari parent paling awal. Untuk setiap node parent, prosedur menampilkan informasi bahwa pencarian sedang dilakukan pada parent tersebut bersamaan dengan posisi indeksnya. Setelah itu, prosedur masuk ke list anak milik parent tersebut dan melakukan penelusuran satu per satu dari child pertama hingga child terakhir. Jika ditemukan child yang nilai atribut ekor-nya sama dengan nilai pencarian, data hewan tersebut ditampilkan lengkap mulai dari ID, nama, habitat, status berekor atau tidak, hingga bobot tubuh dalam kilogram. Selain itu prosedur juga menampilkan posisi child tersebut di dalam list anak, dan mencetak kembali data golongan hewan sebagai identitas parent tempat hewan itu berada.

Jika pada suatu parent tidak ditemukan satupun child yang sesuai kondisi pencarian, maka parent tersebut tetap dilewati dan proses dilanjutkan ke parent berikutnya sampai seluruh parent selesai ditelusuri.

Melalui cara kerja ini, prosedur searchHewanByEkor() memastikan bahwa pencarian dilakukan secara menyeluruh pada seluruh struktur Multi Linked List. Prosedur dapat menemukan lebih dari satu hasil dari berbagai parent yang berbeda. Hasil pencarian yang ditemukan akan ditampilkan secara berurutan sesuai posisi parent dan child di dalam struktur.

Ketika prosedur ini dipanggil dari file main.cpp, output yang dihasilkan akan berbentuk daftar hewan yang tidak memiliki ekor (ekor = FALSE).


### 3. unguided 3
Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list 
child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan 
memanggil prosedur printMLLStructure().Sehingga bentuk dari multi linked 
listnya berubah menjadi seperi ini:


```h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
void deleteParentByID(listParent &LParent, string idGol);

#endif
```

```C++
#include "MultiLL.h"

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP->isidata.idGolongan = idGol;
    NP->isidata.namaGolongan = namaGol;
    NP->next = NP->prev = NULL;
    createListChild(NP->L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC->isidata.idHewan = idHwn;
    NC->isidata.namaHewan = namaHwn;
    NC->isidata.habitat = habitat;
    NC->isidata.ekor = tail;
    NC->isidata.bobot = weight;
    NC->next = NC->prev = NULL;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    if (NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if (NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;
    NodeParent nodeHapus = LParent.first;
    if (LParent.first == LParent.last) {
        LParent.first = LParent.last = NULL;
    } else {
        LParent.first = LParent.first->next;
        LParent.first->prev = NULL;
        nodeHapus->next = NULL;
    }
    if (!isEmptyChild(nodeHapus->L_Child)) {
        deleteListChild(nodeHapus->L_Child);
    }
    deallocNodeParent(nodeHapus);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent) || NPrev == NULL) return;
    NodeParent nodeHapus = NPrev->next;
    if (nodeHapus == NULL) return;
    NPrev->next = nodeHapus->next;
    if (nodeHapus->next != NULL) {
        nodeHapus->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    nodeHapus->next = NULL;
    if (!isEmptyChild(nodeHapus->L_Child)) {
        deleteListChild(nodeHapus->L_Child);
    }
    deallocNodeParent(nodeHapus);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;
    NodeChild nodeHapus = LChild.first;
    if (LChild.first == LChild.last) {
        LChild.first = LChild.last = NULL;
    } else {
        LChild.first = LChild.first->next;
        LChild.first->prev = NULL;
        nodeHapus->next = NULL;
    }
    deallocNodeChild(nodeHapus);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild) || NPrev == NULL) return;
    NodeChild nodeHapus = NPrev->next;
    if (nodeHapus == NULL) return;
    NPrev->next = nodeHapus->next;
    if (nodeHapus->next != NULL) {
        nodeHapus->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }
    nodeHapus->next = NULL;
    deallocNodeChild(nodeHapus);
}

void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List parent kosong!" << endl;
        return;
    }

    NodeParent np = LParent.first;
    int idxP = 1;
    while (np != NULL) {
        cout << "=== Parent " << idxP << " ===" << endl;
        cout << "ID Golongan : " << np->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << np->isidata.namaGolongan << endl;

        NodeChild nc = np->L_Child.first;
        if (nc == NULL) {
            cout << "  (tidak ada child)" << endl;
        } else {
            int idxC = 1;
            while (nc != NULL) {
                cout << "  - Child " << idxC << " :" << endl;
                cout << "      ID Hewan : " << nc->isidata.idHewan << endl;
                cout << "      Nama Hewan : " << nc->isidata.namaHewan << endl;
                cout << "      Habitat : " << nc->isidata.habitat << endl;
                cout << "      Ekor : " << (nc->isidata.ekor ? "True" : "False") << endl;
                cout << "      Bobot : " << nc->isidata.bobot << " kg" << endl;
                nc = nc->next;
                idxC++;
            }
        }
        cout << "---------------------------" << endl;
        np = np->next;
        idxP++;
    }
}

void deleteListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while (nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

void deleteParentByID(listParent &LParent, string idGol) {
    if (isEmptyParent(LParent)) {
        cout << "List parent kosong!\n";
        return;
    }

    NodeParent P = LParent.first;

    if (P->isidata.idGolongan == idGol) {
        deleteListChild(P->L_Child);
        deleteFirstParent(LParent);
        cout << "Parent " << idGol << " berhasil dihapus.\n";
        return;
    }

    while (P != NULL) {
        if (P->isidata.idGolongan == idGol) {
            deleteListChild(P->L_Child);
            deleteAfterParent(LParent, P->prev);
            cout << "Parent " << idGol << " berhasil dihapus.\n";
            return;
        }
        P = P->next;
    }

    cout << "Parent dengan ID " << idGol << " tidak ditemukan.\n";
}
```

```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);

    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);

    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);

    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);

    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C_AV1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f);
    insertLastChild(P1->L_Child, C_AV1);
    NodeChild C_AV2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0f);
    insertLastChild(P1->L_Child, C_AV2);

    NodeChild C_M1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f);
    insertLastChild(P2->L_Child, C_M1);
    NodeChild C_M3 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f);
    insertLastChild(P2->L_Child, C_M3);
    NodeChild C_M2 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0f);
    insertLastChild(P2->L_Child, C_M2);

    NodeChild C_AM1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f);
    insertLastChild(P4->L_Child, C_AM1);

    cout << "\n=== Menghapus Parent G004 (Amfibi) ===\n";
    deleteParentByID(LP, "G004");

    cout << "=== HASIL PRINT MLL STRUCTURE ===" << endl;
    printMLLStructure(LP);


    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan11_Modul13/output/output3.png)

Penjelasan unguided 3
Prosedur deleteParentByID() digunakan untuk menghapus sebuah node parent berdasarkan ID golongan yang dicari. Pertama, prosedur memeriksa apakah list parent kosong. Jika tidak, prosedur memulai pencarian dari node parent pertama. Jika node pertama merupakan parent yang ingin dihapus, maka seluruh child yang berada di bawah parent tersebut dihapus terlebih dahulu melalui pemanggilan deleteListChild(). Sesudah itu, node parent dihapus dari list menggunakan deleteFirstParent().

Jika parent yang dicari bukan parent pertama, prosedur menelusuri list parent dari awal hingga akhir. Ketika node parent yang sesuai ditemukan, list child milik parent tersebut dihapus terlebih dahulu lalu parent tersebut dihapus menggunakan deleteAfterParent(), karena parent tidak berada pada posisi pertama.

Apabila seluruh parent telah ditelusuri dan parent yang dimaksud tidak ditemukan, prosedur menampilkan pesan bahwa ID parent tidak ditemukan.


## Kesimpulan
Pertama, prosedur searchHewanByEkor() digunakan untuk melakukan pencarian hewan berdasarkan kondisi ekor = FALSE. Pencarian dilakukan dengan menelusuri setiap node parent dan seluruh node child pada parent tersebut. Hasil pencarian kemudian ditampilkan lengkap beserta data parent–child yang terkait. Proses ini menunjukkan bagaimana traversal MLL bekerja secara menyeluruh melalui semua jalur linked list yang saling terhubung.

Selanjutnya, dilakukan operasi DELETE terhadap salah satu node parent, yaitu node G004. Penghapusan parent pada MLL secara otomatis juga menghapus seluruh child yang berada di bawah node tersebut, karena pointer child tidak lagi dapat diakses setelah parent dilepas. Hal ini membuktikan bahwa struktur MLL memiliki sifat cascade delete, yaitu ketika induk dihapus maka seluruh turunannya ikut terhapus untuk menjaga konsistensi data.

Setelah operasi delete, prosedur printMLLStructure() kembali dijalankan untuk memastikan bahwa struktur MLL telah berubah sesuai dengan operasi penghapusan. Output menunjukkan bahwa node G004 beserta seluruh child-nya sudah tidak ada dalam list, sementara node lain tetap tampil dengan benar.

Secara keseluruhan, implementasi ini menjelaskan bagaimana MLL mampu mengelola data bertingkat secara efisien menggunakan pointer, serta bagaimana operasi insert, search, delete, dan print bekerja secara terintegrasi dalam struktur yang saling berhubungan. Struktur MLL sangat berguna untuk merepresentasikan data yang bersifat hierarkis seperti kategori–subkategori, keluarga, atau klasifikasi hewan seperti pada studi kasus ini.

## Referensi
[1] Greathouse, J. L., & Daga, M. (2014). Efficient sparse matrix-vector multiplication on GPUs using the CSR-Adaptive approach. Proceedings of the International Conference for High Performance Computing, Networking, Storage and Analysis, 769-780.

[2] Pratama, A., & Wibowo, S. (2019). Implementasi Struktur Data Multi Linked List pada Aplikasi Penjadwalan Mata Kuliah. Jurnal Teknologi Informasi dan Ilmu Komputer (JTIIK), 6(2), 120-128.
<br>...
