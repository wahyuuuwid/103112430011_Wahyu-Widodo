# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Queue (antrian) adalah barisan elemen yang apabila elemen ditambah maka
penambahannya berada di posisi belakang (rear) dan jika dilakukan pengambilan elemen
dilakukan di elemen paling depan (front). Oleh karena itu, queue bersifat FIFO (first in
first out). Operasi-operasi dasar dari sebuah queue adalah :
1. Enqueue : proses penambahan atau memasukkan satu elemen di belakang
2. Dequeue : proses pengambilan atau mengeluarkan satu elemen di posisi depan[1]

Queue dapat diimplementasikan menggunakan beberapa struktur data dasar:
1. Array (Statik/Dinamis):Menggunakan array memerlukan penanganan khusus untuk posisi front dan rear. Pada implementasi statis, biasanya perlu diperhatikan masalah overflow (antrian penuh) dan underflow (antrian kosong).Salah satu teknik yang umum adalah Circular Queue (Antrian Melingkar) untuk mengatasi masalah pergeseran elemen yang lambat pada operasi Dequeue (yang biasanya terjadi pada array biasa) dan memaksimalkan penggunaan ruang array.Linked List (Daftar Berantai):Implementasi menggunakan Linked List dianggap lebih efisien dan fleksibel, terutama karena tidak memiliki batasan ukuran tetap (masalah overflow jarang terjadi selama memori tersedia).Front dan Rear biasanya diwakili oleh pointer ke node yang sesuai. Operasi Enqueue (menambah di belakang) dan Dequeue (menghapus di depan) dapat dilakukan dalam waktu konstan[2]
## Guided 

### 1. guided 1

```h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```

Penjelasan guided 1
Pada bagian header file (queue.h), terdapat deklarasi struktur dan fungsi-fungsi yang digunakan dalam program. Struktur Node merepresentasikan satu elemen dalam antrian yang menyimpan data berupa string bernama nama dan pointer next yang menunjuk ke node berikutnya. Struktur queue memiliki dua pointer yaitu head dan tail yang masing-masing digunakan untuk menandai elemen pertama dan elemen terakhir dalam antrian. Selain itu, terdapat beberapa deklarasi fungsi untuk mengelola operasi pada queue seperti membuat queue, menambah data, menghapus data, menampilkan isi queue, dan mengosongkan queue.

Pada file queue.cpp, fungsi CreateQueue digunakan untuk menginisialisasi queue agar siap digunakan dengan menjadikan head dan tail bernilai nullptr. Fungsi isEmpty berfungsi untuk mengecek apakah queue dalam keadaan kosong dengan memeriksa apakah head bernilai nullptr. Fungsi isFull selalu mengembalikan nilai false karena queue yang berbasis linked list tidak memiliki batasan kapasitas selama memori masih tersedia.

Fungsi enQueue digunakan untuk menambahkan data baru ke dalam queue. Ketika queue masih kosong, node baru akan menjadi elemen pertama dan terakhir sekaligus. Namun, jika queue sudah memiliki elemen, node baru akan ditambahkan di bagian belakang dan pointer tail akan diperbarui agar menunjuk ke node baru tersebut. Setelah data berhasil ditambahkan, program akan menampilkan pesan bahwa nama tersebut telah berhasil dimasukkan ke dalam queue.

Fungsi deQueue digunakan untuk menghapus data dari bagian depan queue. Jika queue kosong, program akan menampilkan pesan bahwa queue kosong. Jika tidak, node yang berada di posisi head akan dihapus, dan pointer head akan digeser ke elemen berikutnya. Jika setelah penghapusan tidak ada elemen yang tersisa, maka tail juga diatur menjadi nullptr untuk menandakan bahwa queue benar-benar kosong.

Fungsi viewQueue menampilkan seluruh isi antrian dengan menelusuri setiap node dari head hingga tail. Jika queue kosong, program akan menampilkan pesan bahwa queue kosong. Sedangkan fungsi clearQueue digunakan untuk menghapus seluruh isi queue dengan cara memanggil fungsi deQueue secara berulang hingga tidak ada elemen yang tersisa.

Pada bagian main, program memulai dengan membuat sebuah queue menggunakan CreateQueue. Kemudian beberapa nama seperti "Dhimas", "Arvin", "Rizal", "Hafizh", "Fathur", dan "Atha" dimasukkan ke dalam antrian menggunakan enQueue. Setelah itu, isi antrian ditampilkan dengan viewQueue. Beberapa elemen dihapus dari antrian menggunakan deQueue, lalu isi queue setelah penghapusan ditampilkan kembali. Di akhir program, fungsi clearQueue dipanggil untuk mengosongkan seluruh isi antrian.

### 2. guided 2

```h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

Penjelasan guided 2
Fungsi CreateQueue bertugas menginisialisasi queue dalam keadaan kosong dengan mengatur head dan tail ke -1. Kondisi kosong dicek dengan membandingkan apakah kedua nilai tersebut sama-sama -1, sedangkan kondisi penuh dicek dengan melihat apakah tail telah mencapai indeks terakhir array, yaitu MAKSIMAL - 1.

Ketika proses enQueue dipanggil, program terlebih dahulu memeriksa apakah queue penuh. Jika penuh, maka pesan bahwa queue sudah penuh akan ditampilkan. Jika belum penuh, data baru akan dimasukkan ke dalam array. Apabila queue masih kosong, maka head dan tail diatur ke 0 sehingga data pertama akan langsung berada pada index pertama. Jika queue sudah berisi elemen, tail akan ditambah satu dan nilai baru akan disimpan di posisi tersebut. Setiap penambahan data akan memberi pesan bahwa data berhasil dimasukkan.

Proses deQueue bekerja dengan menghapus elemen paling depan, yaitu elemen pada indeks head. Pada implementasi ini, setelah data depan dihapus, semua elemen di belakangnya akan digeser satu posisi ke depan agar struktur queue tetap rapi dengan head tetap berada pada indeks nol. Setelah pergeseran selesai, nilai tail dikurangi satu. Jika setelah penghapusan posisi tail menjadi -1, itu berarti queue telah benar-benar kosong sehingga head dan tail dikembalikan ke nilai awal -1.

Fungsi viewQueue bertugas menampilkan seluruh isi queue dari elemen paling depan hingga elemen yang berada pada indeks tail. Penomoran ditampilkan mulai dari angka satu sesuai urutan elemen yang ada, bukan berdasarkan indeks array.

Pada fungsi main, program membuat sebuah queue, menginisialisasinya, kemudian melakukan beberapa operasi enQueue untuk menambahkan nama seperti “Dhimas”, “Arvin”, “Rizal”, “Hafizh”, dan “Fathur”. Ketika data keenam (“Daffa”) dimasukkan, queue sudah penuh sehingga muncul pesan bahwa queue tidak dapat menampung data tambahan. Setelah itu program menampilkan isi queue, lalu melakukan empat kali deQueue untuk menghapus empat elemen terdepan. Setelah proses penghapusan dilakukan, queue hanya menyisakan satu elemen dan keadaan akhirnya ditampilkan kembali melalui fungsi viewQueue.

## Unguided 

### 1. unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
 Type infotype: integer
 Type Queue: <
 info : array [5] of infotype {index array dalam C++
 dimulai dari 0}
 head, tail : integer
 >
 procedure CreateQueue (input/output Q: Queue)
 function isEmptyQueue (Q: Queue) → boolean
 function isFullQueue (Q: Queue) → boolean
 procedure enqueue (input/output Q: Queue, input x: infotype)
 function dequeue (input/output Q: Queue) → infotype
 procedure printInfo (input Q: Queue)
  Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
 queue Alternatif 1 (head diam, tail bergerak).

```h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;
typedef int infotype;

struct Queue {
    infotype info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAKSIMAL - 1);
}

// Head diam, tail bergerak
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        // Geser semua elemen ke kiri
        for(int i = 0; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){
            Q.head = -1;
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(Queue Q){
    cout << Q.head << "  " << Q.tail << " | ";

    if(isEmptyQueue(Q)){
        cout << "empty queue" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}

```

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H - T \t| Queue info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan8_Modul8/output/output1.png)

Penjelasan unguided 1
Pada implementasi queue alternatif 1, posisi head selalu berada pada indeks awal array dan tidak pernah bergerak, sedangkan tail akan bertambah setiap kali elemen baru dimasukkan. Ketika queue masih kosong, nilai head dan tail bernilai –1. Saat elemen pertama ditambahkan melalui operasi enqueue, head dan tail berubah menjadi 0 sehingga elemen pertama ditempatkan pada indeks ke-0. Setiap proses enqueue berikutnya hanya akan menambah nilai tail satu per satu sehingga elemen baru selalu ditempatkan pada indeks setelah elemen sebelumnya.

Ketika operasi dequeue dijalankan, elemen yang berada di posisi head (yaitu indeks 0) akan dihapus. Karena implementasi ini mempertahankan head agar tetap diam, seluruh elemen di dalam array harus digeser ke kiri satu posisi untuk mengisi ruang kosong yang sebelumnya ditempati elemen pertama. Setelah penggeseran selesai, tail dikurangi 1. Jika setelah penghapusan elemen nilai tail menjadi –1, berarti queue kembali kosong dan head serta tail disetel ulang menjadi –1.

Pada proses penampilan data menggunakan prosedur printInfo, program selalu menampilkan nilai head dan tail dalam format “head – tail”, kemudian menunjukkan isi queue. Jika queue kosong, maka yang ditampilkan adalah “empty queue”. Jika queue berisi data, maka elemen ditampilkan dari indeks head sampai tail secara berurutan.

### 2. unguided 2
 Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
 queue Alternatif 2 (head bergerak, tail bergerak).

```h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;
typedef int infotype;

struct Queue {
    infotype info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAKSIMAL - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        Q.head++;

        if (Q.head > Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "    : ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}

```

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H - T \t| Queue info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan8_Modul8/output/output2.png)

penjelasan unguided 2
Pada implementasi queue alternatif 2, baik head maupun tail akan bergerak mengikuti operasi yang dilakukan terhadap queue. Pada kondisi awal, queue dinyatakan kosong ketika nilai head dan tail bernilai –1. Ketika elemen pertama dimasukkan melalui operasi enqueue, head dan tail sama-sama diatur menjadi 0 sehingga elemen pertama menempati indeks 0 dalam array. Setiap operasi enqueue berikutnya hanya akan menaikkan nilai tail satu posisi, sehingga elemen baru selalu ditempatkan pada indeks tail yang baru tanpa perlu menggeser elemen sebelumnya.

Proses dequeue pada alternatif ini berbeda dengan implementasi sebelumnya. Ketika sebuah elemen dihapus, elemen yang diambil adalah elemen pada posisi head, lalu head dinaikkan satu langkah ke indeks berikutnya. Tidak ada pergeseran data di dalam array karena implementasi ini memperbolehkan head untuk terus maju. Jika setelah melakukan dequeue nilai head menjadi lebih besar daripada nilai tail, berarti semua elemen dalam queue telah habis, sehingga queue kembali dianggap kosong dan nilai head serta tail dikembalikan menjadi –1.

Pada prosedur printInfo, program menampilkan posisi head dan tail dalam bentuk “head – tail”, kemudian menampilkan elemen-elemen queue mulai dari indeks head sampai indeks tail. Jika queue kosong, maka program akan menampilkan tulisan “empty queue”. Karena head dapat bergerak maju dari indeks awal hingga indeks akhir, tampilan queue dapat menunjukkan bahwa sebagian elemen di awal array sudah tidak aktif lagi setelah beberapa kali dequeue.

### 3. unguided 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
 queue Alternatif 3 (head dan tail berputar).

```h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;
typedef int infotype;

struct Queue {
    infotype info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return ( (Q.tail + 1) % MAKSIMAL == Q.head );
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL;   // bergerak melingkar
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];

        if (Q.head == Q.tail) { 
            // hanya 1 elemen → kosong lagi
            Q.head = Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL;   // bergerak melingkar
        }

        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "    : ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;

    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAKSIMAL;
    }

    cout << endl;
}

```

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H - T \t| Queue info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan8_Modul8/output/output3.png)

Penjelasan unguided 3
Pada implementasi queue alternatif 3, struktur array digunakan sebagai circular buffer, yaitu bagian akhir array dianggap terhubung kembali ke bagian awal. Dengan mekanisme ini, baik head maupun tail dapat berputar dari indeks terakhir kembali ke indeks pertama tanpa harus melakukan shifting elemen. Pada kondisi awal, head dan tail bernilai –1. Ketika elemen pertama dimasukkan, head dan tail diatur ke indeks 0. Setiap operasi enqueue akan menambah tail dengan rumus (tail + 1) % MAKSIMAL, sehingga ketika tail mencapai indeks paling akhir, nilai tail secara otomatis kembali ke 0 selama masih ada ruang kosong dalam queue.

Operasi dequeue juga menggunakan prinsip yang sama. Ketika sebuah elemen dikeluarkan, nilai head akan digeser ke indeks berikutnya dengan rumus (head + 1) % MAKSIMAL. Jika setelah proses dequeue nilai head dan tail menjadi sama, artinya queue hanya memiliki satu elemen, maka setelah elemen tersebut dikeluarkan queue kembali kosong dan head serta tail dikembalikan menjadi –1.

Kondisi penuh pada circular queue terjadi ketika posisi (tail + 1) % MAKSIMAL sama dengan head. Artinya, posisi berikutnya untuk tail sudah terisi sehingga tidak ada lagi ruang untuk menambahkan elemen baru meskipun secara fisik masih terdapat ruang kosong di bagian belakang array yang sudah dilewati oleh head. Saat menampilkan isi queue melalui printInfo, program akan mencetak elemen mulai dari indeks head hingga tail dengan pergerakan melingkar menggunakan operasi modulo.

## Kesimpulan
Implementasi Queue dapat dilakukan dengan tiga pendekatan berbeda, masing-masing memiliki karakteristik dan efisiensi yang berbeda dalam menangani operasi antrian. Pada Alternatif 1, head dibuat tetap berada di posisi awal dan hanya tail yang bergerak. Setiap kali dequeue dilakukan, semua elemen harus digeser satu posisi ke kiri agar head tetap berada di indeks awal. Mekanisme ini sederhana namun kurang efisien karena membutuhkan proses shifting setiap kali menghapus elemen.

Pada Alternatif 2, baik head maupun tail bergerak maju mengikuti operasi yang dilakukan. Ketika enqueue, tail bertambah; ketika dequeue, head bertambah. Tidak ada shifting elemen, sehingga proses dequeue lebih efisien dibandingkan alternatif pertama. Namun, karena array bersifat linear, queue dianggap penuh ketika tail mencapai indeks terakhir, meskipun masih ada ruang kosong di awal array yang sudah dilewati head.

Pada Alternatif 3, digunakan konsep circular queue, di mana array diperlakukan sebagai struktur melingkar. Head dan tail dapat berputar kembali ke indeks awal ketika mencapai batas akhir array. Pendekatan ini merupakan yang paling efisien karena seluruh kapasitas array dapat dimanfaatkan tanpa perlu shifting elemen. Kondisi penuh ditentukan dengan mendeteksi apakah posisi setelah tail bertepatan dengan head.

Secara keseluruhan, ketiga alternatif menunjukkan perbedaan dalam cara memanipulasi head dan tail serta cara memanfaatkan ruang array. Alternatif 3 adalah metode yang paling optimal karena memaksimalkan ruang penyimpanan dan meminimalkan operasi tambahan, sedangkan Alternatif 1 adalah metode paling sederhana namun paling tidak efisien. Alternatif 2 berada di tengah-tengah, lebih baik dari alternatif pertama tetapi masih terbatas oleh sifat linear array.

## Referensi
[1] Dharmayanti, D. (2011). Struktur Data - Queue (Antrian). Diambil dari Repositori Universitas Komputer Indonesia: https://repository.unikom.ac.id/35976/1/Bab%201%20Queue.pdf
[2] Tim Algoritma & Pemrograman IF. (2020). Algoritma & Pemrograman: Linked List. Universitas Komputer Indonesia (UNIKOM). Diakses dari https://repository.unikom.ac.id/35520/1/Linked%20List.pdf.
<br>...
