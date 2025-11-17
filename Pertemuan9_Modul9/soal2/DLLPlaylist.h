#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct playlist{
    string Title, Artist;
    int DurationSec, PlayCount;
    float Rating;
};

typedef playlist dataPlaylist;
typedef struct node *address;

struct node{
    dataPlaylist info;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string title, string artist, int durationSec, int playCount, float rating);
void dealokasi(address &node);

void insertLast(linkedlist &List, address nodeBaru);
void deleteLast(linkedlist &List); 

void viewList(linkedlist List);
void updateAtPosition(linkedlist &List, int posisi);

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);
void updateBefore(linkedlist List, address nodeNext);
void deleteBefore(linkedlist &List, address nodeNext);

void searchingbyPopularityScore(linkedlist List, float min, float max);

#endif