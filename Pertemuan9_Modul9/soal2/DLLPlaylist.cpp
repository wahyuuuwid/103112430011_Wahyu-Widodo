#include "DLLPlaylist.h"

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

address alokasi(string title, string artist, int durationSec, int playCount, float rating){
    address nodeBaru = new node;
    nodeBaru->info.Title = title;
    nodeBaru->info.Artist = artist;
    nodeBaru->info.DurationSec = durationSec;
    nodeBaru->info.PlayCount = playCount;
    nodeBaru->info.Rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
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

void viewList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Title          : " << nodeBantu->info.Title << endl;
            cout << "Artist         : " << nodeBantu->info.Artist << endl;
            cout << "Duration       : " << nodeBantu->info.DurationSec << endl;
            cout << "Play Count     : " << nodeBantu->info.PlayCount << endl;
            cout << "Rating         : " << nodeBantu->info.Rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->info.Title << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void updateAtPosition(linkedlist &List, int posisi){
    address nodeBantu = List.first;
    int i = 1;
    while (i < posisi) {
        nodeBantu = nodeBantu->next;
        i++;
    }
    cout << "Masukkan update data node ke-" << posisi << " : " << endl;
    cout << "Title          : ";
    cin >> nodeBantu->info.Title;
    cout << "Artist         : ";
    cin >> nodeBantu->info.Artist;
    cout << "Duration       : ";
    cin >> nodeBantu->info.DurationSec;
    cout << "Play Count     : ";
    cin >> nodeBantu->info.PlayCount;
    cout << "Rating         : ";
    cin >> nodeBantu->info.Rating;
    cout << "Data Berhasil Diupdate!" << endl;
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext) {
    address nodeBantu = List.first;
    int i = 1;
    int posisi = 2;
    while (i < posisi) {
        nodeBantu = nodeBantu->next;
        i++;
    }
    nodeBaru->next = nodeBantu;
    nodeBaru->prev = nodeBantu->prev;
    nodeBantu->prev->next = nodeBaru;
    nodeBantu->prev = nodeBaru;
    cout << "Node " << nodeBaru->info.Title << " berhasil ditambahkan sebelum node " << nodeBantu->info.Title << endl;
}

void updateBefore(linkedlist List, address nodeNext) {
    if (nodeNext != Nil && nodeNext->prev != Nil) {
        address nodeBantu = nodeNext->prev;
        cout << "Masukkan update data node sebelum node " << nodeNext->info.Title << " : " << endl;
        cout << "Title          : ";
        cin >> nodeBantu->info.Title;
        cout << "Artist         : ";
        cin >> nodeBantu->info.Artist;
        cout << "Duration       : ";
        cin >> nodeBantu->info.DurationSec;
        cout << "Play Count     : ";
        cin >> nodeBantu->info.PlayCount;
        cout << "Rating         : ";
        cin >> nodeBantu->info.Rating;
        cout << "Data Berhasil Diupdate!" << endl;
    } else {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
}

void deleteBefore(linkedlist &List, address nodeNext) {
    if (nodeNext != Nil && nodeNext->prev != Nil) {
        address pDel = nodeNext->prev;
        nodeNext->prev = pDel->prev;
        pDel->prev->next = nodeNext;
        pDel->next = Nil;
        pDel->prev = Nil;
        cout << "Node " << pDel->info.Title << " berhasil dihapus sebelum node " << nodeNext->info.Title << "." << endl;
        dealokasi(pDel);
    } else {
        cout << "Node sebelumnya (prev) tidak valid atau tidak ada node sebelumnya!" << endl;
    }
}

void searchingbyPopularityScore(linkedlist List, float min, float max) {
    address nodeBantu = List.first;
    int i = 1;
    while (nodeBantu != Nil) {
        if (nodeBantu->info.PlayCount >= min && nodeBantu->info.PlayCount <= max) {
            cout << "Data ditemukan pada node ke-" << i << endl;
            cout << "Title          : " << nodeBantu->info.Title << endl;
            cout << "Artist         : " << nodeBantu->info.Artist << endl;
            cout << "Duration       : " << nodeBantu->info.DurationSec << endl;
            cout << "Play Count     : " << nodeBantu->info.PlayCount << endl;
            cout << "Rating         : " << nodeBantu->info.Rating << endl;
            cout << "-------------------------------" << endl;
        }
        nodeBantu = nodeBantu->next;
        i++;
    }
}