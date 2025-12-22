#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataFilm {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
};

struct DataGenre {
    string IDGenre;
    string namaGenre;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataFilm isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    DataGenre isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};


bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent alokasiNodeParent(string IDGenre, string namaGenre);
NodeChild alokasiNodeChild(string IDFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm);
void dealokasiNodeChild(NodeChild &nodeChild);
void dealokasiNodeParent(NodeParent &nodeParent);
void insertFirstParent(listParent &LParent, NodeParent nodeBaruParent);
void insertLastChild(listChild &LChild, NodeChild nodeBaruChild);
void deleteAfterParent(listParent &LParent, NodeParent nodePrev);
void hapusListChild(listChild &LChild);
void searchFilmsByRatingRange(listParent &LParent, float minRating, float maxRating);
void printStrukturMLL(listParent &LParent);

#endif