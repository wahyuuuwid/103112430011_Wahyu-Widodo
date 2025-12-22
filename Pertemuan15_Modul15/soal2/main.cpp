#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent genre1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(L, genre1);

    NodeParent genre2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(L, genre2);

    NodeParent genre3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(L, genre3);

    NodeParent genre4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(L, genre4);
    
    cout << endl;

    NodeChild film1 = alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(genre1->L_Child, film1);
    
    NodeChild film2 = alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    insertLastChild(genre2->L_Child, film2);
    
    NodeChild film3 = alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(genre2->L_Child, film3);
    
    NodeChild film4 = alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(genre3->L_Child, film4);
    
    NodeChild film6 = alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    insertLastChild(genre4->L_Child, film6);
    
    NodeChild film7 = alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(genre4->L_Child, film7);
    
    cout << endl;

    printStrukturMLL(L);
    cout << endl;

    cout << "=== PENCARIAN FILM BERDASARKAN RATING ===" << endl;
    
    cout << "\n1. Film dengan rating 8.0 - 8.5:" << endl;
    searchFilmsByRatingRange(L, 8.0, 8.5);

    cout << "=== TEST DELETE AFTER PARENT ===" << endl;
    cout << "\nMenghapus genre setelah 'Action' (yaitu 'Comedy'):" << endl;
    deleteAfterParent(L, genre3);
    
    cout << "\n=== DATA SETELAH DELETE ===" << endl;
    printStrukturMLL(L);

    return 0;
}