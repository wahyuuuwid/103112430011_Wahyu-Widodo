#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void createGraph(GraphKota &G) {
    G.First = NULL;
}

adrKota alokasiNode(string nama) {
    adrKota kotaBaru = new ElmKota;
    kotaBaru->namakota = nama;
    kotaBaru->visited = 0;
    kotaBaru->firstEdge = NULL;
    kotaBaru->next = NULL;
    return kotaBaru;
}

adrEdge alokasiEdge(adrKota kotaTujuan, int jarak) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->kotaTujuan = kotaTujuan;
    edgeBaru->jarak = jarak;
    edgeBaru->next = NULL;
    return edgeBaru;
}

void insertNode(GraphKota &G, string nama) {
    adrKota kotaBaru = alokasiNode(nama);
    if (G.First == NULL) {
        G.First = kotaBaru;
    } else {
        adrKota kotaBantu = G.First;
        while (kotaBantu->next != NULL) {
            kotaBantu = kotaBantu->next;
        }
        kotaBantu->next = kotaBaru;
    }
}

adrKota findNode(GraphKota G, string nama) {
    adrKota kotaBantu = G.First;
    while (kotaBantu != NULL) {
        if (kotaBantu->namakota == nama) {
            return kotaBantu;
        }
        kotaBantu = kotaBantu->next;
    }
    return NULL;
}

void connectNode(GraphKota &G, string kota1, string kota2, int jarak) {
    adrKota node1 = findNode(G, kota1);
    adrKota node2 = findNode(G, kota2);
    
    if (node1 != NULL && node2 != NULL) {
        adrEdge edge1 = alokasiEdge(node2, jarak);
        edge1->next = node1->firstEdge;
        node1->firstEdge = edge1;
        
        adrEdge edge2 = alokasiEdge(node1, jarak);
        edge2->next = node2->firstEdge;
        node2->firstEdge = edge2;
    } else {
        cout << "Kota tidak ditemukan!" << endl;
    }
}

void disconnectNode(GraphKota &G, string kota1, string kota2) {
    adrKota node1 = findNode(G, kota1);
    adrKota node2 = findNode(G, kota2);
    
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge prevEdge = NULL;
        
        while (edgeBantu != NULL && edgeBantu->kotaTujuan != node2) {
            prevEdge = edgeBantu;
            edgeBantu = edgeBantu->next;
        }
        
        if (edgeBantu != NULL) {
            if (prevEdge == NULL) {
                node1->firstEdge = edgeBantu->next;
            } else {
                prevEdge->next = edgeBantu->next;
            }
            delete edgeBantu;
        }
        
        edgeBantu = node2->firstEdge;
        prevEdge = NULL;
        
        while (edgeBantu != NULL && edgeBantu->kotaTujuan != node1) {
            prevEdge = edgeBantu;
            edgeBantu = edgeBantu->next;
        }
        
        if (edgeBantu != NULL) {
            if (prevEdge == NULL) {
                node2->firstEdge = edgeBantu->next;
            } else {
                prevEdge->next = edgeBantu->next;
            }
            delete edgeBantu;
        }
    }
}

void deleteNode(GraphKota &G, string namaKota) {
    adrKota nodeHapus = findNode(G, namaKota);
    
    if (nodeHapus == NULL) {
        cout << "Kota tidak ditemukan!" << endl;
        return;
    }
    
    adrKota kotaBantu = G.First;
    while (kotaBantu != NULL) {
        if (kotaBantu != nodeHapus) {
            disconnectNode(G, kotaBantu->namakota, namaKota);
        }
        kotaBantu = kotaBantu->next;
    }
    
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge temp = edgeBantu;
        edgeBantu = edgeBantu->next;
        delete temp;
    }
    nodeHapus->firstEdge = NULL;
    
    if (G.First == nodeHapus) {
        G.First = nodeHapus->next;
    } else {
        adrKota prevNode = G.First;
        while (prevNode->next != nodeHapus) {
            prevNode = prevNode->next;
        }
        prevNode->next = nodeHapus->next;
    }
    
    delete nodeHapus;
    cout << "Kota " << namaKota << " berhasil dihapus!" << endl;
}

void printGraph(GraphKota G) {
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    adrKota kotaBantu = G.First;
    while (kotaBantu != NULL) {
        cout << "Node " << kotaBantu->namakota << " terhubung ke: ";
        adrEdge edgeBantu = kotaBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->kotaTujuan->namakota << "(" << edgeBantu->jarak << " KM)";
            edgeBantu = edgeBantu->next;
            if (edgeBantu != NULL) {
                cout << ", ";
            }
        }
        cout << "," << endl;
        kotaBantu = kotaBantu->next;
    }
    cout << endl;
}

void resetVisited(GraphKota &G) {
    adrKota kotaBantu = G.First;
    while (kotaBantu != NULL) {
        kotaBantu->visited = 0;
        kotaBantu = kotaBantu->next;
    }
}

void printBFS(GraphKota G, string startKota) {
    resetVisited(G);
    
    adrKota startNode = findNode(G, startKota);
    if (startNode == NULL) {
        cout << "Kota awal tidak ditemukan!" << endl;
        return;
    }
    
    queue<adrKota> q;
    
    q.push(startNode);
    startNode->visited = 1;
    
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        adrKota current = q.front();
        q.pop();
        
        cout << current->namakota;
        
        adrEdge edgeBantu = current->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->kotaTujuan->visited == 0) {
                edgeBantu->kotaTujuan->visited = 1;
                q.push(edgeBantu->kotaTujuan);
            }
            edgeBantu = edgeBantu->next;
        }
        
        if (!q.empty()) {
            cout << " - ";
        }
    }
    cout << endl;
}

void printDFS(GraphKota G, string startKota) {
    resetVisited(G);
    
    adrKota startNode = findNode(G, startKota);
    if (startNode == NULL) {
        cout << "Kota awal tidak ditemukan!" << endl;
        return;
    }
    
    stack<adrKota> s;
    
    s.push(startNode);
    
    cout << "DFS Traversal: ";
    while (!s.empty()) {
        adrKota current = s.top();
        s.pop();
        
        if (current->visited == 0) {
            current->visited = 1;
            cout << current->namakota;
            
            adrEdge edgeBantu = current->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->kotaTujuan->visited == 0) {
                    s.push(edgeBantu->kotaTujuan);
                }
                edgeBantu = edgeBantu->next;
            }
            
            if (!s.empty()) {
                cout << " - ";
            }
        }
    }
    cout << endl;
}