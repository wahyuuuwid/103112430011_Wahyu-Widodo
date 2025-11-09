# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Wahyu Widodo - 103112430011</p>

## Dasar Teori
Stack atau tumpukan adalah suatu urutan elemen di mana penambahan dan penghapusan elemen hanya dapat dilakukan pada satu posisi, yaitu bagian akhir atau top dari tumpukan. Dengan kata lain, elemen yang terakhir dimasukkan ke dalam tumpukan akan menjadi elemen pertama yang diambil kembali (Last In First Out – LIFO).

Contoh penerapan konsep stack dalam kehidupan sehari-hari dapat ditemukan pada tumpukan piring di restoran. Piring yang baru dicuci akan diletakkan di bagian paling atas tumpukan, dan ketika dibutuhkan, piring yang diambil adalah piring paling atas tersebut. Prinsip ini menggambarkan dengan jelas cara kerja struktur data stack. Ada 2 operasi paling dasar dari stack yang dapat dilakukan, yaitu :
1. Operasi push yaitu operasi menambahkan elemen pada urutan terakhir (paling atas).
2. Operasi pop yaitu operasi mengambil sebuah elemen data pada urutan terakhir dan
menghapus elemen tersebut dari stack.[1]

Sebagai Tipe Data Abstrak, stack adalah sebuah konsep logis. Secara fisik di dalam program,
stack dapat diimplementasikan menggunakan dua struktur data dasar:
1. Menggunakan Array:
- Sebuah array (biasanya dengan ukuran tetap/statis) dialokasikan untuk menyimpan
elemen-elemen stack.
- Sebuah variabel (sering disebut top ) digunakan sebagai pointer atau indeks untuk
melacak elemen teratas.
- Operasi push menambah top dan menyisipkan elemen.
- Operasi pop mengambil elemen dan mengurangi top .
- Kelemahan: Memiliki ukuran yang tetap (risiko overflow jika penuh).

2. Menggunakan Linked List (Daftar Berantai):
- Setiap elemen adalah node yang menyimpan data dan pointer ke node di bawahnya.
. Pointer top menunjuk ke node teratas.
- Operasi push berarti membuat node baru dan mengaturnya sebagai top baru.
- Operasi pop berarti menghapus node top dan menggeser top ke node berikutnya.
- Kelebihan: Ukuran dinamis, dapat bertambah dan berkurang sesuai kebutuhan memori
(risiko overflow lebih kecil, hanya dibatasi memori sistem).[2]

## Guided 

### 1. guided 1

```h
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack)
{
    if (listStack.top == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createStack(stack &listStack)
{
    listStack.top = Nil;
}

address alokasi(int angka)
{
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru)
{
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack)
{
    address nodeHapus;
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " << nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi)
{
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        if (posisi == 0)
        {
            cout << "Posisi tidak valid!" << endl;
        }
        else
        {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while (nodeBantu != Nil)
            {
                if (count < posisi)
                {
                    nodeBantu = nodeBantu->next;
                    count++;
                }
                else if (count == posisi)
                {
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        while (nodeBantu != Nil)
        {
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while (nodeBantu != Nil)
        {
            if (nodeBantu->dataAngka == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            }
            else
            {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if (found == false)
        {
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Penjelasan guided 1
Program ini medefinisikan beberapa struktur data dan deklarasi fungsi.
Pertama, terdapat struktur makanan yang berisi empat atribut, yaitu nama makanan, jenis makanan, harga, dan rating. Data ini digunakan untuk menyimpan informasi setiap makanan. Kemudian, dibuat struktur node yang mewakili satu elemen dalam linked list. Setiap node memiliki dua pointer, yaitu next untuk menunjuk ke node berikutnya dan prev untuk menunjuk ke node sebelumnya. Dengan adanya dua pointer ini, maka list disebut doubly linked list, karena dapat ditelusuri dari depan maupun dari belakang. Struktur linkedlist berfungsi sebagai penampung awal dan akhir list, dengan dua pointer utama, yaitu first dan last. Selain itu, pada program ini juga dideklarasikan fungsi-fungsi utama seperti membuat list baru, mengalokasikan dan menghapus node, menambahkan node di berbagai posisi (awal, akhir, sebelum, sesudah), mencetak seluruh isi list, serta memperbarui data pada node tertentu.Pada file stack.h, didefinisikan struktur dan deklarasi fungsi-fungsi yang digunakan dalam stack. Terdapat dua struktur utama, yaitu node dan stack. Struktur node berfungsi untuk menyimpan elemen stack, yang terdiri dari satu variabel dataAngka bertipe int untuk menampung nilai, dan satu pointer next yang menunjuk ke node berikutnya. Struktur stack hanya memiliki satu pointer top yang menunjuk ke elemen paling atas dari stack.

File ini juga berisi deklarasi beberapa fungsi penting, seperti:
1. isEmpty() untuk memeriksa apakah stack kosong atau tidak,
2. createStack() untuk menginisialisasi stack,
3. alokasi() untuk membuat node baru,
4. dealokasi() untuk menghapus node dari memori,
5. push() untuk menambahkan elemen ke dalam stack,
6. pop() untuk menghapus elemen paling atas dari stack,
7. update() untuk mengubah nilai elemen pada posisi tertentu,
8. view() untuk menampilkan seluruh isi stack, dan
9. searchData() untuk mencari data tertentu di dalam stack.

Pada file stack.cpp, semua fungsi tersebut diimplementasikan.
Fungsi createStack() digunakan untuk mengosongkan stack dengan mengatur pointer top menjadi NULL.
Fungsi isEmpty() akan mengembalikan nilai true jika stack kosong (tidak memiliki node), dan false jika masih ada data.
Fungsi alokasi() membuat node baru di memori dinamis menggunakan operator new, kemudian mengisi nilai dataAngka sesuai input dan mengatur next menjadi NULL.
Sebaliknya, dealokasi() digunakan untuk menghapus node dari memori menggunakan operator delete.

Fungsi push() menambahkan elemen baru ke dalam stack dengan cara menempatkan node baru di bagian atas. Jika sebelumnya stack sudah berisi data, maka pointer next dari node baru diarahkan ke node yang sebelumnya menjadi top, lalu top diubah menunjuk ke node baru tersebut.
Fungsi pop() menghapus elemen paling atas dari stack. Jika stack kosong, maka akan ditampilkan pesan “Stack kosong!”. Jika tidak, elemen teratas akan dihapus dan memori yang digunakan akan dilepaskan dengan dealokasi().

Fungsi update() digunakan untuk mengubah nilai data pada posisi tertentu dalam stack. Program akan meminta pengguna memasukkan posisi yang ingin diubah dan kemudian mengganti nilainya jika posisi tersebut valid.
Fungsi view() menampilkan semua isi stack mulai dari elemen paling atas hingga paling bawah. Jika stack kosong, maka akan ditampilkan pesan “List kosong!”.
Fungsi searchData() digunakan untuk mencari suatu nilai dalam stack. Jika data ditemukan, program akan menampilkan posisi data tersebut; jika tidak ditemukan, akan muncul pesan bahwa data tidak ada di dalam stack.

Pada file main.cpp, fungsi main() digunakan untuk menguji semua operasi stack. Pertama, stack diinisialisasi dengan createStack(). Kemudian, lima node (nodeA hingga nodeE) dialokasikan dengan nilai 1 sampai 5. Semua node tersebut kemudian dimasukkan ke dalam stack menggunakan fungsi push(). Setelah itu, isi stack ditampilkan dengan fungsi view() untuk memperlihatkan urutan data.

Selanjutnya, program melakukan operasi pop() dua kali untuk menghapus dua elemen teratas dari stack, lalu menampilkan hasilnya kembali. Setelah itu, dilakukan pengujian fungsi update() untuk mengubah nilai pada posisi tertentu, serta searchData() untuk mencari apakah data tertentu ada di dalam stack.

### 2. guided 2

```h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);
void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

```C++
#include "stack.h"
#include <iostream>

using namespace std;

// Mengecek apakah stack kosong
bool isEmpty(stackTable s) {
    return s.top == -1;
}

// Mengecek apakah stack penuh
bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

// Membuat stack kosong
void createStack(stackTable &s) {
    s.top = -1;
}

// Menambahkan data ke stack (ke atas)
void push(stackTable &s, int angka) {
    if (isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

// Menghapus data dari stack (dari atas)
void pop(stackTable &s) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

// Mengubah data pada posisi tertentu (posisi 1 = paling atas)
void update(stackTable &s, int posisi) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        if (posisi <= 0) {
            cout << "Posisi tidak valid!" << endl;
        } else {
// Menghitung indeks array (0-based) dari posisi stack (1-based from top)
    int idx = s.top - (posisi - 1);

    if (idx < 0 || idx > s.top) {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    } else {
 cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
    }
        }
    }

    

   
}

// Menampilkan semua data di stack (dari atas ke bawah)
void view(stackTable s) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        for (int i = s.top; i >= 0; i--) {
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}

// Mencari data di dalam stack
void searchData(stackTable s, int data) {
    bool found = false;

    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Mencari data " << data << "..." << endl;
        int posisi = 1; // Posisi 1 adalah data paling atas

        for (int i = s.top; i >= 0; i--) {
            if (s.data[i] == data) {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                cout << endl;
                found = true;
                break;
            }
            posisi++;
        }
    }

    
    if (!found) {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

Penjelasan guided 2
Pada file stack.h didefinisikan struktur dan deklarasi fungsi-fungsi yang digunakan dalam program. Struktur data utama yang digunakan adalah stackTable, yang terdiri atas:

Sebuah array data[MAX] untuk menyimpan elemen stack dengan ukuran maksimum MAX (dalam program ini diatur bernilai 10), dan

Sebuah variabel top yang menunjukkan posisi elemen teratas dalam stack. Jika nilai top bernilai -1, maka stack dianggap kosong.

Selain struktur, file ini juga mendeklarasikan fungsi-fungsi operasi stack, yaitu:
1. isEmpty() untuk memeriksa apakah stack kosong,
2. isFull() untuk memeriksa apakah stack sudah penuh,
3. createStack() untuk menginisialisasi stack baru,
4. push() untuk menambahkan elemen ke dalam stack,
5. pop() untuk menghapus elemen paling atas,
6. update() untuk memperbarui nilai pada posisi tertentu,
7. view() untuk menampilkan seluruh isi stack, dan
8. searchData() untuk mencari nilai tertentu dalam stack

Di dalam file stack.cpp, semua fungsi dari header diimplementasikan satu per satu.

Fungsi isEmpty() mengembalikan nilai true jika top bernilai -1, menandakan bahwa stack kosong.
Fungsi isFull() mengembalikan true apabila top sudah mencapai MAX - 1, artinya stack telah penuh dan tidak bisa menampung elemen baru.

Fungsi createStack() digunakan untuk membuat stack baru yang kosong dengan cara mengatur nilai top menjadi -1.

Fungsi push() berfungsi untuk menambahkan data ke bagian atas stack. Sebelum menambahkan data, fungsi ini akan memeriksa apakah stack sudah penuh menggunakan isFull(). Jika belum penuh, top akan dinaikkan satu tingkat (top++) dan data baru dimasukkan ke posisi tersebut. Setelah itu, program akan menampilkan pesan bahwa data berhasil dimasukkan ke dalam stack.

Fungsi pop() digunakan untuk menghapus elemen paling atas dari stack. Jika stack kosong, akan muncul pesan “Stack kosong!”. Jika tidak kosong, maka nilai teratas diambil, top dikurangi satu, dan data tersebut dianggap terhapus. Program juga menampilkan data mana yang telah dihapus.

Fungsi update() memungkinkan pengguna untuk mengganti nilai pada posisi tertentu dalam stack. Posisi dihitung dari atas (top) sebagai posisi ke-1. Untuk menentukan indeks array sebenarnya, program menghitungnya dengan rumus idx = s.top - (posisi - 1). Jika posisi yang dimasukkan tidak valid (misalnya lebih besar dari jumlah elemen atau kurang dari 1), maka program akan menampilkan pesan kesalahan. Jika posisi valid, pengguna dapat memasukkan nilai baru, dan program akan menampilkan pesan bahwa data berhasil diperbarui.

Fungsi view() digunakan untuk menampilkan seluruh isi stack dari atas ke bawah. Jika stack kosong, akan muncul pesan “Stack kosong!”. Jika tidak, fungsi akan menampilkan elemen-elemen stack mulai dari indeks top hingga 0, sehingga urutan tampilannya sesuai dengan struktur tumpukan sebenarnya.

Terakhir, fungsi searchData() digunakan untuk mencari nilai tertentu di dalam stack. Pencarian dimulai dari elemen teratas (posisi 1). Jika data yang dicari ditemukan, maka program akan menampilkan posisi data tersebut di dalam stack. Jika tidak ditemukan, akan muncul pesan bahwa data tersebut tidak ada di dalam stack.

Pada file ini, fungsi main() digunakan untuk menguji seluruh operasi stack yang telah dibuat.
Pertama, dibuat variabel s bertipe stackTable, kemudian diinisialisasi dengan createStack(s).
Setelah itu, lima data pertama (1 sampai 5) dimasukkan ke dalam stack menggunakan fungsi push(). Program kemudian menampilkan isi stack dengan memanggil fungsi view().

Selanjutnya, dilakukan dua kali operasi pop() untuk menghapus dua elemen teratas dari stack, lalu hasilnya kembali ditampilkan.
Kemudian, dilakukan pengujian terhadap fungsi update() untuk mengubah isi data pada posisi tertentu dari atas tumpukan. Misalnya, update(s, 2) berarti mengubah nilai data yang berada di posisi kedua dari atas.

Setelah semua perubahan dilakukan, program kembali menampilkan isi stack yang telah diperbarui menggunakan fungsi view().
Terakhir, fungsi searchData() dipanggil dua kali untuk mencari data tertentu, yaitu angka 4 dan 9, untuk menunjukkan bagaimana fungsi pencarian bekerja baik saat data ditemukan maupun saat data tidak ada di dalam stack.

## Unguided 

### 1. unguided 1
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
Type infotype : integer
Type Stack <
info : array [20] of integer
top : integer
>
procedure CreateStack( input/output S : Stack )
procedure push(input/output S : Stack,
input x : infotype)
function pop(input/output t S : Stack )
→ infotype
procedure printInfo( input S : Stack )
procedure balikStack(input/output S :
Stack )

```h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void CreateStack(Stack &S);
void Push(Stack &S, int x);
void pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, int x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

void pop(Stack &S, int &x) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        x = S.info[S.top];
        S.top--;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    int i = 0;
    int j = S.top;
    while (i < j) {
        int tmp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = tmp;
        i++; j--;
    }
}

```

```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    Push(S, 3);
    Push(S, 4);
    Push(S, 2);
    Push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S); 

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan7_Modul7/output/output1.png)

Penjelasan unguided 1
File stack.h berfungsi untuk mendefinisikan struktur data Stack dan deklarasi fungsi-fungsi yang digunakan. Stack didefinisikan dengan array info[MAX] berukuran maksimum 20 elemen, serta variabel top sebagai penanda posisi elemen teratas pada stack. Fungsi-fungsi yang dideklarasikan antara lain:
1. CreateStack() untuk membuat stack baru.
2. Push() untuk menambahkan data ke dalam stack.
3. pop() untuk menghapus data dari stack.
4. printInfo() untuk menampilkan isi stack.
5. balikStack() untuk membalik urutan elemen di dalam stack

File stack.cpp berisi definisi dari fungsi-fungsi yang telah dideklarasikan sebelumnya:
1. CreateStack(Stack &S) menginisialisasi stack agar kosong dengan mengatur S.top = -1.
2. Push(Stack &S, int x) menambahkan elemen baru ke dalam stack. Jika stack sudah penuh, ditampilkan pesan “Stack penuh!”.
3. pop(Stack &S, int &x) menghapus elemen teratas dari stack dan menyimpannya ke variabel x. Jika stack kosong, muncul pesan “Stack kosong!”.
4. printInfo(Stack S) menampilkan isi stack mulai dari elemen teratas hingga terbawah.
5. balikStack(Stack &S) menukar posisi elemen dari atas ke bawah (membalik urutan isi stack) menggunakan algoritma pertukaran dua arah (swap) dari indeks awal dan akhir.

Di dalam main(), program diawali dengan menampilkan teks “Hello world!”. Selanjutnya, dibuat sebuah objek stack S dan dipanggil fungsi CreateStack(S) untuk menginisialisasinya.
Kemudian, beberapa nilai dimasukkan ke dalam stack menggunakan fungsi Push(), yaitu 3, 4, 2, dan 9. Setelah itu, printInfo(S) digunakan untuk menampilkan isi stack dari atas ke bawah.
Program lalu menampilkan teks “balik stack” dan memanggil balikStack(S) untuk membalik urutan elemen dalam stack. Terakhir, printInfo(S) dipanggil kembali untuk menampilkan isi stack setelah dibalik.

### 2. unguided 2
Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

```h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void CreateStack(Stack &S);
void Push(Stack &S, int x);
void pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);

#endif
```

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, int x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

void pop(Stack &S, int &x) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        x = S.info[S.top];
        S.top--;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    int i = 0;
    int j = S.top;
    while (i < j) {
        int tmp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = tmp;
        i++; j--;
    }
}

void pushAscending(Stack &S, int x) {
    Stack temp;
    CreateStack(temp);
    int y;

    while (S.top != -1 && S.info[S.top] > x) {
        pop(S, y);
        Push(temp, y);
    }

    Push(S, x);

    while (temp.top != -1) {
        pop(temp, y);
        Push(S, y);
    }
}
```

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan7_Modul7/output/output2.png)

penjelasan unguided 2
File ini berfungsi untuk mendefinisikan struktur dan deklarasi fungsi yang digunakan dalam stack.
Isi pentingnya:
1. Konstanta MAX = 20 → batas maksimum jumlah elemen stack.
2. Struktur Stack → terdiri dari:
3. int info[MAX] : array untuk menyimpan data.
   int top : penanda posisi elemen teratas dalam stack.

Deklarasi fungsi-fungsi:
1. CreateStack() → membuat stack kosong.
2. Push() → menambahkan elemen ke stack.
3. pop() → menghapus elemen dari stack.
4. printInfo() → menampilkan isi stack.
5. balikStack() → membalik urutan isi stack.
6. pushAscending() → menyisipkan elemen secara berurutan (ascending) di dalam stack.

File ini berisi definisi logika setiap fungsi dari stack.h.
Berikut penjelasan fungsi-fungsinya:
- CreateStack(Stack &S)
Menginisialisasi stack agar kosong dengan cara mengatur S.top = -1.
- Push(Stack &S, int x)
Menambahkan elemen baru x ke dalam stack.
Jika stack penuh (S.top == MAX - 1), maka ditampilkan pesan "Stack penuh!".
- pop(Stack &S, int &x)
Menghapus elemen teratas stack dan menyimpannya ke variabel x.
Jika stack kosong (S.top == -1), muncul pesan "Stack kosong!".
- printInfo(Stack S)
Menampilkan seluruh isi stack dari elemen teratas ke terbawah.
Jika kosong, menampilkan "Stack kosong!".
- balikStack(Stack &S)
Menukar posisi elemen dari atas ke bawah (membalik urutan isi stack) menggunakan metode pertukaran dua arah (swap).
- pushAscending(Stack &S, int x)
Inilah bagian tambahan utama pada program ini.
Fungsi ini menambahkan elemen baru x dalam urutan menaik (ascending) tanpa mengubah struktur stack secara langsung:
1. Membuat stack sementara temp.
2. Memindahkan sementara elemen-elemen dari S ke temp selama elemen teratas S lebih besar dari x.
3. Setelah posisi yang tepat ditemukan, x dimasukkan ke stack S.
4. Elemen-elemen dari temp kemudian dikembalikan lagi ke S.

Dengan cara ini, setiap kali pushAscending() dipanggil, elemen-elemen di dalam stack akan tetap tersusun secara ascending (kecil → besar) dari bawah ke atas.

File ini berfungsi untuk menjalankan program utama:
1. Program menampilkan "Hello world!".
2. Membuat objek stack S dan memanggil CreateStack(S).
3. Memasukkan beberapa nilai dengan pushAscending() → 3, 4, 8, 2, 3, 9. Berkat fungsi pushAscending, stack akan otomatis tersusun menaik.
4. Menampilkan isi stack dengan printInfo(S).
5. Menampilkan teks "balik stack" dan memanggil balikStack(S) untuk membalik urutan stack.
6. Menampilkan kembali isi stack setelah dibalik.

### 3. unguided 3
Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan
menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan
tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

```h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void CreateStack(Stack &S);
void Push(Stack &S, int x);
void pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif
```

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, int x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

void pop(Stack &S, int &x) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        x = S.info[S.top];
        S.top--;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "[TOP] (kosong)" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << char(S.info[i]) << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    int i = 0;
    int j = S.top;
    while (i < j) {
        int tmp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = tmp;
        i++; j--;
    }
}

void pushAscending(Stack &S, int x) {
    Stack temp;
    CreateStack(temp);
    int y;

    while (S.top != -1 && S.info[S.top] > x) {
        pop(S, y);
        Push(temp, y);
    }

    Push(S, x);

    while (temp.top != -1) {
        pop(temp, y);
        Push(S, y);
    }
}

void getInputStream(Stack &S) {
    char ch;
    while (true) {
        ch = cin.get();
        if (ch == '\n') break;

        if (S.top < 19) { 
            S.top++;
            S.info[S.top] = ch; 
        } else {
            cout << "Stack penuh, karakter '" << ch << "' tidak dimasukkan.\n";
            break;
        }
    }
}
```

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wahyuuuwid/103112430011_Wahyu-Widodo/blob/main/Pertemuan7_Modul7/output/output3.png)

Penjelasan unguided 3
Pada file stack.h, didefinisikan struktur data Stack yang berisi array info dengan ukuran maksimum 20 elemen dan variabel top untuk menandai posisi elemen teratas. Di dalamnya juga dideklarasikan beberapa fungsi, yaitu CreateStack, Push, pop, printInfo, balikStack, pushAscending, dan getInputStream. File ini berfungsi sebagai antarmuka antara implementasi dan program utama agar lebih terstruktur dan mudah digunakan.

File stack.cpp berisi implementasi dari seluruh fungsi tersebut. Fungsi CreateStack menginisialisasi stack dalam keadaan kosong dengan mengatur nilai top menjadi -1. Fungsi Push digunakan untuk menambahkan data baru ke dalam stack, dengan pemeriksaan apakah stack sudah penuh. Fungsi pop berfungsi untuk menghapus elemen teratas dan mengambil nilainya. Fungsi printInfo menampilkan isi stack dari elemen teratas hingga terbawah, namun dalam versi ini setiap elemen ditampilkan sebagai karakter (menggunakan char(S.info[i])), sehingga cocok untuk menampilkan input berupa teks atau huruf.

Fungsi balikStack menukar urutan elemen di dalam stack sehingga isi stack menjadi terbalik dari kondisi semula. Fungsi pushAscending merupakan versi pengurutan otomatis, di mana elemen baru akan dimasukkan ke dalam posisi yang tepat agar urutan stack tetap menaik. Proses ini dilakukan dengan bantuan stack sementara yang digunakan untuk memindahkan elemen-elemen yang lebih besar dari elemen baru. Setelah elemen baru dimasukkan, elemen-elemen dari stack sementara dikembalikan ke stack utama.

Fungsi tambahan getInputStream berfungsi untuk membaca input dari pengguna secara langsung menggunakan cin.get(). Fungsi ini akan terus menerima karakter satu per satu hingga pengguna menekan tombol Enter (\n). Setiap karakter yang dimasukkan akan disimpan ke dalam stack, kecuali jika stack sudah penuh, maka program menampilkan pesan bahwa karakter berikutnya tidak dapat dimasukkan.

Pada file main.cpp, program dimulai dengan menampilkan pesan “Hello world!”. Kemudian dibuat sebuah variabel Stack S, yang diinisialisasi menjadi kosong dengan memanggil CreateStack(S). Setelah itu, fungsi getInputStream(S) dijalankan untuk membaca input dari pengguna. Data yang dimasukkan langsung disimpan dalam stack, lalu ditampilkan menggunakan printInfo(S). Setelah itu, program menampilkan teks “balik stack” dan memanggil fungsi balikStack(S) untuk membalik urutan elemen, kemudian menampilkan hasilnya kembali dengan printInfo(S).

## Kesimpulan
Program ini merupakan implementasi Abstract Data Type (ADT) Stack menggunakan array sebagai tempat penyimpanan data. Stack bersifat LIFO (Last In, First Out), yaitu data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan. Program ini terdiri dari beberapa prosedur utama yang bekerja sama untuk mengelola data di dalam stack.

Pertama, prosedur createStack() digunakan untuk menginisialisasi stack agar kosong dengan memberi nilai awal top = -1. Selanjutnya, push() berfungsi menambahkan data baru ke atas stack selama stack belum penuh, sedangkan pop() digunakan untuk menghapus data dari bagian atas stack jika tidak kosong.

Prosedur update() memungkinkan pengguna mengganti nilai data pada posisi tertentu dalam stack, dan view() atau printInfo() digunakan untuk menampilkan seluruh isi stack dari posisi atas ke bawah. Prosedur searchData() mencari data tertentu di dalam stack dan menampilkan posisinya jika ditemukan.

Selain itu, terdapat prosedur tambahan seperti balikStack(), yang berfungsi untuk membalik urutan isi stack, sehingga data yang berada di atas berpindah ke bawah dan sebaliknya. Prosedur pushAscending() menambahkan data ke dalam stack dengan memperhatikan urutan menaik, hanya akan menambahkan nilai baru jika nilainya lebih besar dari elemen sebelumnya.

Terakhir, prosedur getInputStream() memungkinkan pengguna memasukkan serangkaian karakter atau angka secara langsung dari keyboard hingga menekan tombol Enter. Setiap karakter atau angka yang dimasukkan akan disimpan dalam stack, kemudian dapat ditampilkan dan dibalik urutannya menggunakan balikStack().

## Referensi
[1] Universitas Komputer Indonesia. (n.d.). Struktur Data – Bab VIII: Stack (Tumpukan). Repositori Universitas Komputer Indonesia. Diakses dari https://repository.unikom.ac.id/35898/1/Bab%20VIII%20-%20Stack.pdf
[2] Tim Algoritma & Pemrograman IF. (2020). Algoritma & Pemrograman: Linked List. Universitas Komputer Indonesia (UNIKOM). Diakses dari https://repository.unikom.ac.id/35520/1/Linked%20List.pdf.
<br>...
