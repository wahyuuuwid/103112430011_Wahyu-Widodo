#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    GraphKota G;
    createGraph(G);
    
    insertNode(G, "Jakarta");
    insertNode(G, "Bogor");
    insertNode(G, "Depok");
    insertNode(G, "Tangerang");
    insertNode(G, "Bekasi");
    
    connectNode(G, "Jakarta", "Bogor", 42);
    connectNode(G, "Jakarta", "Bekasi", 16);
    connectNode(G, "Jakarta", "Depok", 21);
    connectNode(G, "Jakarta", "Tangerang", 24);
    
    connectNode(G, "Bogor", "Bekasi", 60);
    connectNode(G, "Bogor", "Depok", 22);
    
    connectNode(G, "Depok", "Bekasi", 25);
    connectNode(G, "Depok", "Tangerang", 30);
    
    connectNode(G, "Tangerang", "Bekasi", 45);
    
    printGraph(G);
    
    deleteNode(G, "Depok");
    
    printGraph(G);

    cout << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    printBFS(G, "Tangerang");
    printDFS(G, "Tangerang");
    
    return 0;
}