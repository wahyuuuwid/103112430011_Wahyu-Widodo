# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Graph adalah struktur data non-linear yang digunakan untuk merepresentasikan hubungan antar objek. Secara matematis, sebuah graph disimbolkan dengan notasi $G = (V, E)$, di mana:$V$ (Vertex) adalah himpunan simpul atau node yang merepresentasikan data atau objek.$E$ (Edge) adalah himpunan sisi atau busur yang menghubungkan sepasang simpul dalam $V$.Berbeda dengan struktur data Tree yang bersifat hierarkis (hubungan orang tua-anak), Graph bersifat lebih umum di mana setiap node dapat terhubung dengan node lainnya tanpa batasan hierarki (many-to-many relationship). Berdasarkan karakteristik busur (edge) yang dimilikinya, Graph dapat dibedakan menjadi beberapa jenis utama:
- Directed Graph (Digraph): Graph di mana setiap sisi memiliki arah.
- Undirected Graph: Graph di mana sisi yang menghubungkan dua simpul tidak memiliki arah.
- Weighted Graph: Graph di mana setiap sisi memiliki nilai atau bobot (weight). Bobot ini sering merepresentasikan jarak, biaya, atau waktu tempuh antar simpul.
- Unweighted Graph: Graph di mana setiap sisi dianggap memiliki bobot yang sama atau tidak memiliki bobot spesifik.[1]

Untuk mengimplementasikan graph dalam pemrograman, terdapat dua metode representasi utama yang umum digunakan:
-  Adjacency Matrix (Matriks Ketetanggaan) menggunakan array 2 dimensi untuk menyimpan hubungan antar simpul.
- Adjacency List (Senarai Ketetanggaan) Menggunakan array dari Linked List. Setiap elemen array merepresentasikan sebuah simpul, dan linked list yang terkait berisi daftar simpul tetangga yang terhubung langsung.

Dua algoritma dasar yang digunakan untuk menelusuri atau mengunjungi setiap simpul dalam graph adalah:
1. Breadth-First Search (BFS): Penelusuran melebar, mengunjungi simpul tetangga terdekat terlebih dahulu sebelum bergerak ke lapisan berikutnya. Menggunakan struktur data Queue.
2. Depth-First Search (DFS): Penelusuran mendalam, menelusuri satu cabang sejauh mungkin sebelum kembali (backtracking). Menggunakan struktur data Stack atau rekursi.[2]

## Guided 

### 1. guided 1

```h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode node1, adrNode node2);
void DeleteNode(Graph &G, infoGraph x);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);


#endif
```

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

```C++
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
```

Penjelasan guided 1
Program dimulai dengan mendefinisikan tiga struktur utama, yaitu ElmNode, ElmEdge, dan Graph. Struktur ElmNode digunakan untuk menyimpan satu simpul dalam graph yang berisi data karakter, penanda visited, pointer ke daftar edge, dan pointer ke node berikutnya. Struktur ElmEdge digunakan untuk menyimpan hubungan ke node lain melalui pointer ke node tujuan dan pointer ke edge berikutnya. Sementara itu, struktur Graph hanya berisi pointer ke node pertama dalam graph.

Fungsi CreateGraph digunakan untuk menginisialisasi graph kosong dengan mengatur pointer first menjadi NULL. Fungsi AlokasiNode bertugas membuat node baru lengkap dengan data, visited bernilai 0, dan tanpa edge serta tanpa hubungan ke node lain. Fungsi AlokasiEdge digunakan untuk membuat sebuah edge baru yang menunjuk ke node tujuan. Selanjutnya, prosedur InsertNode digunakan untuk menambahkan node baru ke dalam graph, yaitu dengan memasukkannya ke bagian akhir dari list node. Untuk mencari node berdasarkan karakter tertentu digunakan fungsi FindNode, yang akan mengembalikan alamat node jika ditemukan atau NULL jika tidak ada.

Prosedur ConnectNode berfungsi menghubungkan dua node secara dua arah karena graph bersifat undirected. Setiap koneksi ditambahkan ke daftar edge masing-masing node dengan menggunakan metode insert first. Apabila salah satu node tidak ditemukan, program menampilkan pesan bahwa node tidak ada. Untuk memutuskan hubungan dari satu node ke node lainnya digunakan prosedur DisconnectNode, yaitu dengan mencari edge yang mengarah ke node tujuan kemudian menghapusnya dari daftar edge.

Penghapusan sebuah node dilakukan melalui prosedur DeleteNode. Proses penghapusan dimulai dengan mencari node yang ingin dihapus. Setelah ditemukan, program menghapus semua edge pada node lain yang mengarah ke node tersebut. Kemudian program menghapus seluruh edge yang dimiliki oleh node tersebut, menghapus node dari list node graph, dan mendekalokasikannya dari memori.

Program juga menyediakan prosedur PrintInfoGraph yang menampilkan seluruh isi graph dalam bentuk adjacency list, yaitu setiap node akan menampilkan daftar node yang terhubung dengannya. Sebelum melakukan traversal, prosedur ResetVisited mengatur semua nilai visited node kembali menjadi 0. Traversal Breadth First Search dilakukan melalui PrintBFS menggunakan struktur data queue, dimulai dari node tertentu dan menjelajahi tetangga secara melebar. Traversal Depth First Search dilakukan melalui PrintDFS menggunakan stack, di mana penelusuran dilakukan sedalam mungkin sebelum berpindah ke jalur lain.

Di dalam fungsi main, program membuat graph kosong lalu menambahkan node A, B, C, D, E, dan F. Setelah itu beberapa node dihubungkan sehingga terbentuk sebuah graph. Program kemudian menampilkan adjacency list, melakukan traversal BFS dan DFS mulai dari node A, menghapus node E, dan kembali menampilkan graph serta hasil traversal setelah penghapusan node. Dengan demikian, program ini menunjukkan cara membangun, menghubungkan, menghapus, menampilkan, dan menelusuri sebuah graph menggunakan adjacency list dalam C++.


## Unguided 

### 1. unguided 1
Buatlah ADT Graph tidak berarah file “graph.h”:
Type infoGraph: char
Type adrNode : pointer to ElmNode
Type adrEdge : pointer to ElmNode
Type ElmNode <
info : infoGraph
visited : integer
firstEdge : adrEdge
Next : adrNode
>
Type ElmEdge <
Node : adrNode
Next : adrEdge
>
Type Graph <
first : adrNode
>
procedure CreateGraph (input/output G : Graph)
procedure InsertNode (input/output G : Graph,
input X : infotype)
procedure ConnectNode (input/output N1, N2 : adrNode)
procedure PrintInfoGraph (input G : Graph)
Program 4 Graph.h
Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT
pada file “main.cpp


```h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);
void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);


#endif
```

```C++
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

```

```C++
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

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan12_Modul14/output/output1.png)

Penjelasan unguided 1
Header file graph.h berfungsi sebagai deklarasi struktur data dan fungsi-fungsi yang akan digunakan dalam implementasi graph. Di dalam file ini didefinisikan tipe infoGraph sebagai karakter, serta dua pointer adrNode dan adrEdge yang menunjuk ke struktur node dan edge. Struktur ElmNode menyimpan informasi sebuah simpul berupa karakter, status kunjungan, pointer ke edge pertama, dan pointer ke node berikutnya. Struktur ElmEdge menyimpan pointer menuju node tujuan dan pointer ke edge berikutnya. Struktur Graph hanya memiliki pointer first yang menunjuk ke node pertama dalam daftar linked list.

Di dalam header ini juga dideklarasikan berbagai fungsi, yaitu CreateGraph untuk menginisialisasi graph kosong, AlokasiNode untuk membuat node baru, dan AlokasiEdge untuk membuat edge baru. Fungsi InsertNode digunakan untuk menambahkan simpul baru ke dalam graph, sedangkan FindNode mencari simpul berdasarkan karakternya. Fungsi ConnectNode menghubungkan dua node sehingga terbentuk edge dua arah, PrintInfoGraph menampilkan daftar adjacency setiap simpul, dan ResetVisited mengatur kembali status kunjungan seluruh node.

Pada file graph.cpp, seluruh fungsi yang dideklarasikan di header diimplementasikan secara lengkap. Fungsi CreateGraph mengatur pointer pertama graph menjadi NULL. Fungsi AlokasiNode membuat node baru, mengisi data, mengatur visited menjadi nol, dan menginisialisasi edge serta pointer next sebagai NULL. Fungsi AlokasiEdge membuat edge baru yang menunjuk ke node tujuan. Fungsi InsertNode menambahkan node baru ke akhir list node dalam graph. FindNode menelusuri semua node dalam graph hingga menemukan node dengan nilai info yang sesuai. Fungsi ConnectNode membentuk hubungan dua arah antara dua node dengan menambahkan edge pada kedua simpul tersebut. Fungsi PrintInfoGraph menampilkan isi graph dalam bentuk adjacency list dengan menelusuri setiap node dan seluruh edge miliknya. Fungsi ResetVisited digunakan untuk mengembalikan nilai visited dari semua node menjadi nol.

File main.cpp digunakan untuk menguji ADT graph yang telah dibuat. Program membuat graph kosong, menambahkan node A sampai H, kemudian menghubungkan node-node tersebut sesuai gambar pada soal. Setelah struktur graph terbentuk lengkap, program mencetak representasi adjacency list sehingga pengguna dapat melihat setiap node beserta node-node tetangganya. Program ini memastikan bahwa seluruh fungsi ADT berjalan dengan baik sesuai kebutuhan implementasi graph berbasis adjacency list.


### 2. unguided 2
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintDFS (Graph G, adrNode N);

```h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);
void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);

#endif
```

```C++
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

void PrintDFS(Graph &G, adrNode N) {
    if (N == NULL) {
        cout << "Node tidak ditemukan.\n";
        return;
    }

    stack<adrNode> S;

    ResetVisited(G);

    S.push(N);

    cout << "DFS Traversal: ";

    while (!S.empty()) {
        adrNode P = S.top();
        S.pop();

        if (P->visited == 0) {
            P->visited = 1;
            cout << P->info << " - ";

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }

    cout << endl;
}
```

```C++
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


    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan12_Modul14/output/output2.png)

penjelasan unguided 2
Prosedur PrintDFS melakukan penelusuran graph menggunakan algoritma Depth First Search dengan pendekatan iteratif. Prosedur ini diawali dengan memanggil ResetVisited untuk memastikan bahwa semua node dalam graph berada pada kondisi belum dikunjungi. Setelah itu, prosedur mencari node awal berdasarkan karakter yang diberikan melalui pemanggilan FindNode. Jika node awal tidak ditemukan, proses langsung dihentikan.

Jika node awal valid, prosedur menyiapkan sebuah stack sebagai struktur data yang akan menyimpan urutan node yang akan dikunjungi. Node awal dimasukkan ke dalam stack sebagai titik mulai penelusuran. Selama stack tidak kosong, prosedur mengambil elemen paling atas dari stack, kemudian memeriksa apakah node tersebut sudah pernah dikunjungi atau belum. Jika node belum dikunjungi, node tersebut ditandai sebagai visited dan informasinya dicetak sebagai bagian dari hasil penelusuran DFS.

Setelah node tersebut diproses, prosedur menelusuri seluruh tetangganya melalui adjacency list. Setiap tetangga yang belum dikunjungi dimasukkan ke dalam stack sehingga nantinya akan diproses lebih dahulu sesuai sifat LIFO dari stack. Dengan cara ini, algoritma melakukan penelusuran secara mendalam tanpa menggunakan rekursi, tetapi dengan memanfaatkan stack sebagai pengganti pemanggilan fungsi rekursif. Prosedur ini berakhir ketika stack benar-benar kosong, dan seluruh node yang dapat dicapai dari node awal telah dikunjungi serta ditampilkan secara berurutan sesuai pola penelusuran DFS.

### 3. unguided 3
Buatlah prosedur untuk menampilkan hasil penelusuran BFS.
prosedur PrintBFS (Graph G, adrNod N);


```h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);
void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);

#endif
```

```C++
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

void PrintDFS(Graph &G, adrNode N) {
    if (N == NULL) {
        cout << "Node tidak ditemukan.\n";
        return;
    }

    stack<adrNode> S;

    ResetVisited(G);

    S.push(N);

    cout << "DFS Traversal: ";

    while (!S.empty()) {
        adrNode P = S.top();
        S.pop();

        if (P->visited == 0) {
            P->visited = 1;
            cout << P->info << " - ";

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }

    cout << endl;
}

void PrintBFS(Graph &G, adrNode N) {
    if (N == NULL) return;

    ResetVisited(G);
    queue<adrNode> Q;

    N->visited = 1;
    Q.push(N);

    cout << "BFS Traversal: ";

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " - ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }

    cout << endl;
}
```

```C++
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

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan12_Modul14/output/output3.png)

Penjelasan unguided 3
Prosedur BFS dimulai dengan memanggil ResetVisited agar semua node kembali pada kondisi belum dikunjungi. Setelah itu, node awal diberi tanda kunjungan dan dimasukkan ke dalam queue. Selama queue masih berisi node, algoritma mengambil elemen paling depan untuk diproses. Node tersebut dicetak karena sedang dikunjungi, kemudian prosedur memeriksa seluruh edge yang terhubung dengannya. Jika ditemukan node tetangga yang belum pernah dikunjungi, node tersebut diberi tanda visited dan dimasukkan ke dalam queue. Proses ini berlangsung terus hingga queue kosong. Dengan cara ini, BFS menjelajahi graph secara melebar, yaitu mengunjungi semua tetangga terlebih dahulu sebelum bergerak ke lapisan berikutnya. Hasilnya adalah urutan node yang mencerminkan penelusuran BFS mulai dari node yang dipilih.


## Kesimpulan
Secara keseluruhan, proses representasi dan penelusuran graf diawali dari pembentukan adjacency list yang menampilkan setiap node beserta semua node tetangganya sehingga struktur hubungan dalam graf terlihat dengan jelas. Setelah graf terbentuk, penelusuran DFS dilakukan dengan prinsip pendalaman, yaitu menjelajahi suatu jalur hingga mencapai simpul terdalam sebelum kembali dan beralih ke cabang lain, sehingga traversal mengikuti pola eksplorasi yang bersifat menyelam ke dalam. Sebaliknya, penelusuran BFS melakukan proses pembacaan node berdasarkan tingkat kedalaman yang sama, di mana setiap simpul dikunjungi layer demi layer menggunakan bantuan queue, sehingga traversal berlangsung secara melebar. Dengan demikian, adjacency list menyediakan gambaran struktur graf, DFS menggali jalur secara mendalam, dan BFS menelusuri simpul-simpul secara bertingkat, sehingga ketiga proses ini bekerja saling melengkapi untuk memahami hubungan dan urutan traversal dalam graf.


## Referensi
[1] Hartono, H., & Sutardi, D. (2021). "Implementasi Algoritma Dijkstra pada Aplikasi Pencarian Rute Terpendek Lokasi Wisata". Jurnal Ilmiah Teknologi dan Rekayasa, 26(2), 115-124

[2] Permana, A. A., & Nurnawati, E. K. (2019). "Perancangan Aplikasi Pencarian Lokasi Menggunakan Metode Breadth First Search (BFS)". Jurnal Manajemen Informatika dan Sistem Informasi, 2(1), 11-18.
<br>...
