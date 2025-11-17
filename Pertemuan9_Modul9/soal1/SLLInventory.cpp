#include "SLLInventory.h"

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List){
    List.first = Nil;
}

address alokasi(string nama, string SKU, int jumlah, float HargaSatuan, float DiskonPersen){
    address nodeBaru = new node;
    nodeBaru->info.Nama = nama;
    nodeBaru->info.SKU = SKU;
    nodeBaru->info.Jumlah = jumlah;
    nodeBaru->info.HargaSatuan = HargaSatuan;
    nodeBaru->info.DiskonPersen = DiskonPersen;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void deleteFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void viewList(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama           : " << nodeBantu->info.Nama << endl;
            cout << "SKU            : " << nodeBantu->info.SKU << endl;
            cout << "Jumlah         : " << nodeBantu->info.Jumlah << endl; 
            cout << "Harga Satuan   : " << nodeBantu->info.HargaSatuan << endl;
            cout << "Diskon Persen  : " << nodeBantu->info.DiskonPersen << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateAtPosition(linkedlist &List, int posisi) {
    if(isEmpty(List)){
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        int i = 1;
        while (i < posisi) {
            nodeBantu = nodeBantu->next;
            i++;
        }
        cout << "Masukkan update data node ke-" << posisi << " : " << endl;
        cout << "Nama : ";
        cin >> nodeBantu->info.Nama;
        cout << "SKU : ";
        cin >> nodeBantu->info.SKU;
        cout << "Jumlah : ";
        cin >> nodeBantu->info.Jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->info.HargaSatuan;
        cout << "Diskon Persen : ";
        cin >> nodeBantu->info.DiskonPersen;
        cout << "Data Berhasil Diupdate!" << endl;
    }
}

void searchingByFinalPrice(linkedlist list, float minPrice, float maxPrice) {
    if(isEmpty(list) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu != Nil) {
            float finalPrice = nodeBantu->info.HargaSatuan - (nodeBantu->info.HargaSatuan * (nodeBantu->info.DiskonPersen / 100));
            if (finalPrice >= minPrice && finalPrice <= maxPrice) {
                cout << "Data ketemu" << endl;
                cout << "Nama           : " << nodeBantu->info.Nama << endl;
                cout << "SKU            : " << nodeBantu->info.SKU << endl;
                cout << "Jumlah         : " << nodeBantu->info.Jumlah << endl; 
                cout << "Harga Satuan   : " << nodeBantu->info.HargaSatuan << endl;
                cout << "Diskon Persen  : " << nodeBantu->info.DiskonPersen << endl;
                cout << "-------------------------------" << endl;
            }
            nodeBantu = nodeBantu->next;
        }
    }
    
}

void maxFinalPrice(linkedlist list) {
    if(isEmpty(list) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        float finalPrice = nodeBantu->info.HargaSatuan - (nodeBantu->info.HargaSatuan * (nodeBantu->info.DiskonPersen / 100));
        float max = finalPrice;
        while (nodeBantu != Nil) {
            if (finalPrice > max) {
                max = finalPrice;
            }
            nodeBantu = nodeBantu->next;
        }
        cout << "Harga Terbesar : " << max << endl;
    }
}