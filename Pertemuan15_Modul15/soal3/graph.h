#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;

struct ElmKota {
    string namakota;
    int visited;
    adrEdge firstEdge;
    adrKota next;
};

struct ElmEdge {
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};

struct GraphKota {
    adrKota First;
};

void createGraph(GraphKota &G);
adrKota alokasiNode(string nama);
adrEdge alokasiEdge(adrKota kotaTujuan, int jarak);

void insertNode(GraphKota &G, string nama);
adrKota findNode(GraphKota G, string nama);
void connectNode(GraphKota &G, string kota1, string kota2, int jarak);
void disconnectNode(GraphKota &G, string kota1, string kota2);
void deleteNode(GraphKota &G, string namaKota);

void printGraph(GraphKota G);
void resetVisited(GraphKota &G);
void printBFS(GraphKota G, string startKota);
void printDFS(GraphKota G, string startKota);

#endif