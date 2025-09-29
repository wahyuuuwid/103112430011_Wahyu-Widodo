#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

    struct Rapot {
        string nama;
        int nilai;
    };

    Rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama Siswa: ";
        cin >> siswa[i].nama;
        cout << "Masukkan nilai Siswa: ";
        cin >> siswa[i].nilai;
    }

    cout << endl;
    
    int i = 0;
    while (i < jumlah) {
        cout << "Nama : " << siswa[i].nama << " nilai : " << siswa[i].nilai << endl;
        i++;
    }

    return 0;
}
