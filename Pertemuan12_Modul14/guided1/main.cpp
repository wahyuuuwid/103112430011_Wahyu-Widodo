#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

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

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'D', 'F');
    ConnectNode(G, 'E', 'F');
    
    cout << "=== REPRESENTASI ADJECENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    // mulai travesal dari node A
    PrintBFS(G, 'A'); // BFS
    PrintDFS(G, 'A'); // DFS
    cout << endl;

    cout << "=== HAPUS NODE ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak berhasil dihapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJECENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    // mulai travesal dari node A
    PrintBFS(G, 'A'); // BFS
    PrintDFS(G, 'A'); // DFS

    return 0;
}