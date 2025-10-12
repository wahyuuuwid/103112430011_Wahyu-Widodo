#include <iostream>
using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel){
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode : " << pel.kodeMapel << endl;
}

int main(){
    string namamapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namamapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}