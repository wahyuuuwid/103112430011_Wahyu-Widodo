#include "mll.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = NULL;
}

NodeParent alokasiNodeParent(string IDGenre, string namaGenre) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.IDGenre = IDGenre;
    nodeBaruParent->isidata.namaGenre = namaGenre;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string IDFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.IDFilm = IDFilm;
    nodeBaruChild->isidata.judulFilm = judulFilm;
    nodeBaruChild->isidata.durasiFilm = durasiFilm;
    nodeBaruChild->isidata.tahunTayang = tahunTayang;
    nodeBaruChild->isidata.ratingFilm = ratingFilm;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeChild) {
    if(nodeChild != NULL) {
        nodeChild->next = nodeChild->prev = NULL;
        delete nodeChild;
        nodeChild = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeParent) {
    if(nodeParent != NULL) {
        nodeParent->next = nodeParent->prev = NULL;
        delete nodeParent;
        nodeParent = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent nodeBaruParent) {
    if(isEmptyParent(LParent)) {
        LParent.first = LParent.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LParent.first;
        LParent.first->prev = nodeBaruParent;
        LParent.first = nodeBaruParent;
    }
    cout << "Genre '" << nodeBaruParent->isidata.namaGenre << "' berhasil ditambahkan!" << endl;
}

void insertLastChild(listChild &LChild, NodeChild nodeBaruChild) {
    if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LChild.last;
        LChild.last->next = nodeBaruChild;
        LChild.last = nodeBaruChild;
    }
    cout << "Film '" << nodeBaruChild->isidata.judulFilm << "' berhasil ditambahkan!" << endl;
}

void deleteAfterParent(listParent &LParent, NodeParent nodePrev) {
    if(isEmptyParent(LParent)) {
        cout << "List parent kosong!" << endl;
        return;
    }
    
    if(nodePrev == NULL || nodePrev->next == NULL) {
        cout << "Node prev tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    
    NodeParent nodeHapus = nodePrev->next;
    
    if(!isEmptyChild(nodeHapus->L_Child)) {
        hapusListChild(nodeHapus->L_Child);
    }
    
    nodePrev->next = nodeHapus->next;
    if(nodeHapus->next != NULL) {
        nodeHapus->next->prev = nodePrev;
    } else {
        LParent.last = nodePrev;
    }
    
    cout << "Genre '" << nodeHapus->isidata.namaGenre << "' berhasil dihapus beserta semua filmnya!" << endl;
    dealokasiNodeParent(nodeHapus);
}

void hapusListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

void searchFilmsByRatingRange(listParent &LParent, float minRating, float maxRating) {
    if(isEmptyParent(LParent)) {
        cout << "Tidak ada genre yang terdaftar!" << endl;
        return;
    }
    
    bool found = false;
    NodeParent currentParent = LParent.first;
    
    cout << "================================================" << endl;
    cout << " FILM DENGAN RATING " << minRating << " - " << maxRating << endl;
    cout << "================================================" << endl;
    
    while(currentParent != NULL) {
        if(!isEmptyChild(currentParent->L_Child)) {
            NodeChild currentChild = currentParent->L_Child.first;
            
            while(currentChild != NULL) {
                if(currentChild->isidata.ratingFilm >= minRating && 
                   currentChild->isidata.ratingFilm <= maxRating) {
                    found = true;
                    
                    cout << "Genre      : " << currentParent->isidata.namaGenre << endl;
                    cout << "ID Film    : " << currentChild->isidata.IDFilm << endl;
                    cout << "Judul      : " << currentChild->isidata.judulFilm << endl;
                    cout << "Durasi     : " << currentChild->isidata.durasiFilm << " menit" << endl;
                    cout << "Tahun      : " << currentChild->isidata.tahunTayang << endl;
                    cout << "Rating     : " << fixed << setprecision(1) << currentChild->isidata.ratingFilm << endl;
                    cout << "--------------------------------" << endl;
                }
                currentChild = currentChild->next;
            }
        }
        currentParent = currentParent->next;
    }
    
    if(!found) {
        cout << "Tidak ditemukan film dengan rating dalam range tersebut!" << endl;
    }
    cout << endl;
}

void printStrukturMLL(listParent &LParent) {
    if(isEmptyParent(LParent)) {
        cout << "Belum ada genre yang terdaftar!" << endl;
        return;
    }
    
    NodeParent currentParent = LParent.last;
    int parentCount = 1;
    
    while(currentParent != NULL) {
        cout << "\n=== " << "Parent " << parentCount << " ===" << endl;
        cout << "ID Genre   : " << currentParent->isidata.IDGenre << endl;
        cout << "Nama Genre : " << currentParent->isidata.namaGenre << endl;
        cout << "--------------------------------" << endl;
        
        if(isEmptyChild(currentParent->L_Child)) {
            cout << "  (Belum ada film dalam genre ini)" << endl;
        } else {
            NodeChild currentChild = currentParent->L_Child.first;
            int childCount = 1;
            
            while(currentChild != NULL) {
                cout << "  Child " << childCount << ":" << endl;
                cout << "    ID Film       : " << currentChild->isidata.IDFilm << endl;
                cout << "    Judul Film    : " << currentChild->isidata.judulFilm << endl;
                cout << "    Durasi Film   : " << currentChild->isidata.durasiFilm << " menit" << endl;
                cout << "    Tahun Tayang  : " << currentChild->isidata.tahunTayang << endl;
                cout << "    Rating Film   : " << fixed << setprecision(1) << currentChild->isidata.ratingFilm << endl;
                currentChild = currentChild->next;
                childCount++;
            }
        }
        cout << "================================================" << endl;
        currentParent = currentParent->prev;
        parentCount++;
    }
}