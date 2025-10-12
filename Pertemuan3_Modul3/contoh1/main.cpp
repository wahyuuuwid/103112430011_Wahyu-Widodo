#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namamapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namamapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}