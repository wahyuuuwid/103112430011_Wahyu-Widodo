#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AlokasiNode(infoGraph x) {
    adrNode N = new ElmNode;
    N->info = x;
    N->visited = 0;
    N->firstEdge = NULL;
    N->next = NULL;
    return N;
}

adrEdge AlokasiEdge(adrNode tujuan) {
    adrEdge E = new ElmEdge;
    E->node = tujuan;
    E->next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph x) {
    adrNode N = AlokasiNode(x);
    if (G.first == NULL) {
        G.first = N;
    } else {
        adrNode P = G.first;
        while (P->next != NULL) {
            P = P->next;
        }
        P->next = N;
    }
}

adrNode FindNode(Graph G, infoGraph x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x) return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph x, infoGraph y) {
    adrNode A = FindNode(G, x);
    adrNode B = FindNode(G, y);

    if (A == NULL || B == NULL) {
        cout << "Node tidak ditemukan.\n";
        return;
    }

    adrEdge E1 = AlokasiEdge(B);
    E1->next = A->firstEdge;
    A->firstEdge = E1;

    adrEdge E2 = AlokasiEdge(A);
    E2->next = B->firstEdge;
    B->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;

        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}


