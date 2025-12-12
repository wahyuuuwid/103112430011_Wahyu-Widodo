#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "=== REPRESENTASI ADJACENCY LIST ===\n";
    PrintInfoGraph(G);
    cout << endl;

    cout << "\n=== HASIL DFS DARI NODE A ===\n";
    PrintDFS(G, FindNode(G, 'A'));
    cout << endl;

    cout << "\n=== HASIL BFS DARI NODE A ===\n";
    PrintBFS(G, FindNode(G, 'A'));
    cout << endl;


    return 0;
}
