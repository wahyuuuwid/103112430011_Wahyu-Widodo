#include "pelajaran.h"

//impementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel){
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode : " << pel.kodeMapel << endl;
}

